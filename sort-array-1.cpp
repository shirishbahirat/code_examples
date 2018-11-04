#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void print_array(uint32_t* parr, uint32_t len);

void quick_sort(uint32_t arr[], uint32_t low, uint32_t high); // https://en.wikipedia.org/wiki/Quicksort
void selection_sort(uint32_t arr[], uint32_t len);
void bubble_sort(uint32_t arr[], uint32_t len);
void cycle_sort(uint32_t arr[], uint32_t len);
void heap_sort(uint32_t arr[], uint32_t len);
void insertion_sort(uint32_t arr[], uint32_t len);
void odd_even_sort(uint32_t arr[], uint32_t len);
void bucket_sort(uint32_t arr[], uint32_t len);
void merge_sort(uint32_t arr[], uint32_t l, uint32_t r);


void inplace_merge_sort(uint32_t* parr);
void intro_sort(uint32_t *parr);
void tim_sort(uint32_t *parr);
void cube_sort(uint32_t *parr);
void shell_sort(uint32_t *parr);
void binary_tree_sort(uint32_t *parr);
void library_sort(uint32_t *parr);
void patience_sort(uint32_t *parr);
void smpoth_sort(uint32_t *parr);
void strand_sort(uint32_t *parr);
void tournament_sort(uint32_t *parr);
void cocktail_sort(uint32_t *parr);
void comb_sort(uint32_t *parr);
void gnome_sort(uint32_t *parr);
void unshuffle_sort(uint32_t *parr);
void franceschinis_sort(uint32_t *parr);
void block_sort(uint32_t *parr);


void print_array(uint32_t* parr, uint32_t len)
{
	for (uint32_t i = 0; i < len; ++i)
	{
		cout << *parr << " " << flush;
		++parr;
	}

	cout << endl;

}

void swap(uint32_t arr[], uint32_t l, uint32_t h)
{

	if (l != h)
	{
		arr[l] ^= arr[h] ^= arr[l] ^= arr[h];
	}

}

void selection_sort(uint32_t arr[], uint32_t len)
{

	for (uint32_t i = 0; i<len; ++i)
	{
		uint32_t index = i;
		for (uint32_t j=i; j<len; ++j)
		{
			if (arr[index] > arr[j])
				index = j;
		}
		swap(arr, index, i);
	}
}

uint32_t partation(uint32_t arr[], uint32_t low, uint32_t high)
{

	// divide and concure algorithm, start with highest element in array
	uint32_t pivot = arr[high];
	uint32_t index = low; // if array element is less that pivot then only increment index

	for (uint32_t j = low; j < high; ++j)
	{
		if (arr[j] < pivot)
		{
			swap(arr, index, j);			
			++index;
		} 
	}
	swap(arr, index, high); // this is because the index is at heighest element

	return index;
}


void quick_sort(uint32_t arr[], uint32_t low, uint32_t high)
{
	if (low < high)
	{
		uint32_t pivot = partation(arr, low, high);
		if (pivot > 0) quick_sort(arr, low, pivot-1);
		if (pivot < high) quick_sort(arr, pivot+1, high);		
	}

}

uint32_t rnd()
{
	return(uint32_t) rand()%15;
}

void arry_with_random_length(uint32_t arr[], uint32_t len)
{
	for (uint32_t i = 0; i < len; ++i)
	{
		arr[i] = rnd();
	}
}


void bubble_sort(uint32_t arr[], uint32_t len)
{
	for(uint32_t i = 0; i < len-1; ++i)
	{
		bool swap_done = false;
		for (uint32_t j = 0; j < len-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr, j, j+1);
				swap_done = true;
			}
		}
		if (!swap_done) break;
	}
}

void cycle_sort(uint32_t arr[], uint32_t len)
{

    int writes = 0;
    int cycleStart = 0;

    for (cycleStart = 0; cycleStart <len - 1; cycleStart++)
    {
        int item = arr[cycleStart];

        int pos = cycleStart,i;

        for (i= cycleStart + 1; i < len; i++)
            if (arr[i] < item)
                pos += 1;

        if (pos == cycleStart)
            continue;

        while (item == arr[pos])
            pos += 1;

        arr[pos]^= item;
        item^=arr[pos];
        arr[pos]^= item;
        writes += 1;

        while (pos != cycleStart)
        {

            pos = cycleStart;
            for (i=cycleStart + 1;i< len;i++)
                if (arr[i] < item)
                    pos += 1;

            while (item == arr[pos])
                pos += 1;

            arr[pos]^= item;
            item^=arr[pos];
            arr[pos]^= item;
            writes += 1;
        }
    }
}


void heapify(uint32_t arr[], uint32_t n, uint32_t i)
{
    uint32_t largest = i;
    uint32_t l = 2*i + 1;
    uint32_t r = 2*i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }

}

void heap_sort(uint32_t arr[], uint32_t len)
{

    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(arr, len, (uint32_t)i);   	
    }	
 

   for (int i=len-1; i>=0; i--)
   {
       swap(arr, 0, (uint32_t)i);
     
       heapify(arr, (uint32_t)i, 0);
   }

}


void insertion_sort(uint32_t arr[], uint32_t len)
{
    for (uint32_t i = 1; i < len; i++)
    {
        for (uint32_t j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            uint32_t tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}


void odd_even_sort(uint32_t arr[], uint32_t len)
{ 
    bool isSorted = false;
  
    while (!isSorted) 
    { 
        isSorted = true; 
  
        for (uint32_t i=1; i<=len-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
             { 
                swap(arr, i, i+1); 
                isSorted = false; 
              } 
        } 
  
        for (uint32_t i=0; i<=len-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
            { 
                swap(arr, i, i+1); 
                isSorted = false; 
            } 
        } 
    } 
} 


void bucket_sort(uint32_t arr[], uint32_t len)
{

    uint32_t count[len+1];

    for (uint32_t i = 0; i < len; i++)
        count[i] = 0;
 
    for (uint32_t i = 0; i < len; i++)
        (count[arr[i]])++;
 
    for (uint32_t i = 0, j = 0; i < len; i++)  
        for(; count[i] > 0; (count[i])--)
            arr[j++] = i;
}

void merge(uint32_t arr[], uint32_t l, uint32_t m, uint32_t r) 
{ 
    uint32_t i, j, k; 
    uint32_t n1 = m - l + 1; 
    uint32_t n2 =  r - m; 
  
    /* create temp arrays */
    uint32_t L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(uint32_t arr[], uint32_t l, uint32_t r) 
{ 
    if (l < r) 
    {
        uint32_t m = l+(r-l)/2; 
  
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}


int main(int argc, const char* argv[])
{
	srand (time(NULL));
	uint32_t len = (uint32_t) (rand()%15 + 7);
	uint32_t arr[len];

	cout << "Quick sort" << endl;
	arry_with_random_length(arr, len);
	quick_sort(arr, 0, (sizeof(arr)/sizeof(uint32_t))-1);
	print_array(arr, len);

	cout << "Selection sort" << endl;
	arry_with_random_length(arr, len);
	selection_sort(arr, len);
	print_array(arr, len);

	cout << "Bubble sort" << endl;
	arry_with_random_length(arr, len);
	bubble_sort(arr, len);
	print_array(arr, sizeof(arr)/sizeof(uint32_t));

	cout << "Cycle sort" << endl;
	arry_with_random_length(arr, len);
	cycle_sort(arr, len);
	print_array(arr, len);
	
	cout << "Heap sort" << endl;
	arry_with_random_length(arr, len);
	heap_sort(arr, len);
	print_array(arr, len);	

	cout << "Insertion sort" << endl;
	arry_with_random_length(arr, len);
	insertion_sort(arr, len);
	print_array(arr, len);	

	cout << "Odd Even sort" << endl;
	arry_with_random_length(arr, len);
	odd_even_sort(arr, len);
	print_array(arr, len);	

	cout << "Bucket sort" << endl;
	arry_with_random_length(arr, len);
	bucket_sort(arr, len);
	print_array(arr, len);	


	cout << "Merge sort" << endl;
	arry_with_random_length(arr, len);
	merge_sort(arr, 0, len);
	print_array(arr, len);
	return 0;
}
