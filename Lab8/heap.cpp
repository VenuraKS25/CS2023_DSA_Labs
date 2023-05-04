#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2 * root + 1;
   int right = 2 * root + 2;
   int largest;
   if (arr[root] < arr[left] && left < n)
   {
      largest = left;
   }
   else
   {
      largest = root;
   }
   if (arr[largest] < arr[right] && right < n)
   {
      largest = right;
   }
   if (largest != root)
   {
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   for (int i = floor(n / 2); i > -1; i--)
   {
      heapify(arr, n, i);
   }
   for (int i = n-1; i > -1; i--)
   {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      n--;
      heapify(arr, n, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   vector<int> inputArr;
   string userInput;
   getline(cin, userInput);

   istringstream userInputStream(userInput);
   int inputNumber;
   while(userInputStream >> inputNumber)
   {
      inputArr.push_back(inputNumber);
   }
   
   int n = inputArr.size();
   int* heap_arr = new int[7];
   for(int i = 0; i<n; i++)
   {
      heap_arr[i] = inputArr[i];
   }   
   cout << "Input array" << endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);

   cout << "Sorted array" << endl;
   displayArray(heap_arr, n);

   delete[] heap_arr;
}