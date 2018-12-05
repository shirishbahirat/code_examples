#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>


std::mutex mutex_;
std::condition_variable cont_var;

bool data_ready;

void do_work()
{
  std::cout << "Processing shared data." << std::endl;
}

void wait_to_notify()
{
    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    cont_var.wait(lck,[]{return data_ready;});
    do_work();

    std::cout << "Work done." << std::endl;
}

void set_data_ready()
{
    std::lock_guard<std::mutex> lck(mutex_);
    data_ready=true;
    std::cout << "Sender: Data is ready."  << std::endl;
    cont_var.notify_one();
}

int main(int argc, const char* argv[])
{

  std::cout << std::endl;

  std::thread t1(wait_to_notify);
  std::thread t2(set_data_ready);

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}
 