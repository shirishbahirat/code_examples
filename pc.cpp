#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define pass true
#define fail false

typedef bool status;

typedef struct node {
  void *data;
  struct node *prev;
} Node;

typedef struct info {
  int size;
  int limit;
} Info;

typedef struct queue {
  node *head;
  node *tail;
  info qmgmt;
} Queue;

typedef struct qport {
  Queue *que;
  int max;
  int count;

  pthread_cond_t cond;
  pthread_mutex_t lock;
} Qport;

pthread_t moduleThread;
pthread_t producerThread;

Qport *inputPort;
Qport *outputPort;

Queue *constructQueue(int limit) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  if (queue == NULL)
    return NULL;

  queue->head = NULL;
  queue->tail = NULL;

  queue->qmgmt.size = 0;

  if ((limit > 0) && (limit < 0xFF))
    queue->qmgmt.limit = limit;
  else
    queue->qmgmt.limit = 0xFE;

  return queue;
}

bool isEmpty(Queue *queue) {
  if (queue == NULL)
    return true;
  if (queue->qmgmt.size == 0)
    return true;
  return false;
}

bool isFull(Queue *queue) {
  if (queue == NULL)
    return false;
  if (queue->qmgmt.size == queue->qmgmt.limit)
    return true;
  return false;
}

status enqueue(Queue *queue, Node *item) {
  assert(queue && item);
  if (queue->qmgmt.size >= queue->qmgmt.limit)
    return fail;
  item->prev = NULL;

  if (queue->qmgmt.size == 0) {
    queue->head = item;
    queue->tail = item;
    item->prev = item;
  } else {
    queue->tail->prev = item;
    queue->tail = item;
  }
  queue->qmgmt.size++;

  return pass;
}

Node *dequeue(Queue *queue) {
  Node *item;

  if (isEmpty(queue))
    item = NULL;

  item = queue->head;
  queue->head = (queue->head)->prev;
  queue->qmgmt.size--;

  return item;
}

typedef struct cmd {
  int dest;
} command;

Qport *constructPortQ(int max) {
  Qport *qport = (Qport *)malloc(sizeof(Qport));
  qport->count = 0;
  if (max > 0xFF)
    max = 0xFE;
  qport->max = max;

  Queue *pqueue = constructQueue(max);
  qport->que = pqueue;

  pthread_cond_init(&qport->cond, NULL);
  pthread_mutex_init(&qport->lock, NULL);

  return qport;
}

status portqEnqueue(Qport *pqueue, Node *item) {
  assert(pqueue && item); // todo add check for counts

  pthread_mutex_lock(&pqueue->lock);
  while (pqueue->count >= pqueue->max)
    pthread_cond_wait(&pqueue->cond, &pqueue->lock);

  enqueue(pqueue->que, item);

  pthread_cond_broadcast(&pqueue->cond);
  pthread_mutex_unlock(&pqueue->lock);

  return pass;
}

Node *portqDequeue(Qport *pqueue) {
  Node *item;

  assert(pqueue); // todo add check for counts

  pthread_mutex_lock(&pqueue->lock);
  while (pqueue->count == 0)
    pthread_cond_wait(&pqueue->cond, &pqueue->lock);

  item = dequeue(pqueue->que);

  pthread_cond_broadcast(&pqueue->cond);
  pthread_mutex_unlock(&pqueue->lock);

  return item;
}

status inputPortEnqueue(Node *item) {
  portqEnqueue(inputPort, item);
  return pass;
}

status outputPortEnqueue(Node *item) {
  portqEnqueue(outputPort, item);
  return pass;
}

void moduleExecuteFunction() {
  sleep(10);
  printf("Executing Module\n");
}

void producerExecuteFunction() { sleep(50); }

void *moduleThreadFunction(void *arg) {
  Node *item;
  command cmmd;
  cmmd.dest = 111;
  item = (Node *)malloc(sizeof(Node));
  item->data = (void *)&cmmd;

  while (1) {
    portqEnqueue(inputPort, item);
    moduleExecuteFunction();
    portqEnqueue(outputPort, item);
  }

  return NULL;
}

void *producerThreadFunction(void *arg) {
  Node *item;

  while (1) {
    producerExecuteFunction();
  }

  return NULL;
}

int main(int argc, const char *argv[]) {

  Queue *pqueue = constructQueue(10);

  command cmmd;
  cmmd.dest = 111;
  Node *pnode = (Node *)malloc(sizeof(Node));
  pnode->data = (void *)&cmmd;

  enqueue(pqueue, pnode);

  pnode = NULL;
  pnode = dequeue(pqueue);

  printf("node size %d data %d\n", ((cmd *)(pnode->data))->dest,
         pqueue->qmgmt.size);

  inputPort = constructPortQ(10);
  outputPort = constructPortQ(10);

  pthread_create(&moduleThread, NULL, moduleThreadFunction, NULL);
  pthread_create(&producerThread, NULL, producerThreadFunction, NULL);

  pthread_join(moduleThread, NULL);
  pthread_join(producerThread, NULL);

  printf("Model thread init\n");
  return 0;
}
