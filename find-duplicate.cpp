#include <iostream>
#include <cmath>




void printRepeating1(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; ++i)
    {
        for (int j = i+1; j < arr_size; ++j)
        {
            if (arr[i] == arr[j])
            {
                std::cout << arr[i] << " ";
            }
        }
    }
    
    std::cout << std::endl;
}

void printRepeating2(int arr[], int arr_size)
{

    int *count = new int[arr_size - 2]();
    for (int i = 0; i < arr_size; ++i)
    {
        ++count[arr[i]];
        if (count[arr[i]] > 1)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int factorial(int idx)
{
   return (idx == 0)? 1 : idx*factorial(idx-1);
}

void printRepeating3(int arr[], int arr_size)
{

  int sum = 0;
  int product = 1;
  int x,  y;
  int delta;
  int idx = arr_size - 2,  i;
 
  for(int i = 0; i < arr_size; i++)
  {
    sum = sum + arr[i];
    product = product*arr[i];
  }        
   
  sum = sum - idx*(idx+1)/2;
  product = product/factorial(idx);
   
  delta = sqrt(sum*sum - 4*product);
   
  x = (delta + sum)/2;
  y = (sum - delta)/2;
   
  std::cout << x << " " << y << std::endl;

}

void printRepeating4(int arr[], int arr_size)
{
  int xor_all = 0;
  int set_bit_no;
  int n = arr_size - 2;
  int x = 0, y = 0;
   
  for(int i = 0; i < arr_size; i++)
    xor_all ^= arr[i];  

  for(int i = 0; i <= n; i++)
    xor_all ^= i;
 
  set_bit_no = xor_all & ~(xor_all-1);
 
  for(int i = 0; i < arr_size; i++)
  {
    if(arr[i] & set_bit_no)
      x = x ^ arr[i];
    else
      y = y ^ arr[i];
  }

  for(int i = 0; i <= n; i++)
  {
    if(i & set_bit_no)
      x = x ^ i;
    else
      y = y ^ i;
  }

  std::cout << x << " " << y << std::endl;
}     


int main(int argv, const char* argc[])
{

    int arr[] = {4, 3, 4, 5, 2, 3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printRepeating1(arr, arr_size);

    printRepeating2(arr, arr_size);

    printRepeating3(arr, arr_size);

    printRepeating4(arr, arr_size);

    return 0;
}

