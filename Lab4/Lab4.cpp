#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void mergeSort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);
void mergeSortIterative(int array[], int size);

int main()
{
    const int len = 15000;
    int arr[len];

    int tempArray[len];
    srand(time(NULL));

    // for (int i = 0; i < len; i++)
    // {
    //     arr[i] = rand();
    // }

    int sumOfTimeRec = 0;
    int sumOfTimeIter = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = rand();
        }
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, len - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        sumOfTimeRec += duration.count();

        start = high_resolution_clock::now();
        mergeSortIterative(arr, len);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        sumOfTimeIter += duration.count();
    }

    int averageTimeRec = sumOfTimeRec / 100;
    int averageTimeIter = sumOfTimeIter / 100;
    cout << "Time taken by merge sort(rec) for " << len << " elements : " << averageTimeRec << endl;
    cout << "Time taken by merge sort for(iter) " << len << " elements : " << averageTimeIter << endl;
    return 0;
}

void mergeSortIterative(int array[], int size)
{

    int left, right, mid;
    int len = 1;
    while (len < size)
    {
        int i = 0;
        while (i < size - 1)
        {
            left = i;
            mid = i + len - 1;
            right = i + 2 * len - 1;
            if ((mid + 1) >= size)
            {
                break;
            }
            if (right >= size)
            {
                right = size - 1;
            }
            merge(array, left, mid, right);
            i = i + 2 * len;
        }
        len = 2 * len;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(int array[], int left, int mid, int right)
{
    vector<int> leftArray(mid - left + 1);
    vector<int> rightArray(right - mid);

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int l = 0, r = 0;
    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    int k = left;
    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            array[k] = leftArray[l];
            l++;
        }
        else
        {
            array[k] = rightArray[r];
            r++;
        }
        k++;
    }
    while (l < leftSize)
    {
        array[k] = leftArray[l];
        k++;
        l++;
    }
    while (r < rightSize)
    {
        array[k] = rightArray[r];
        k++;
        r++;
    }
    return;
}