//extra_10_2_0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(float arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(vector<float> arr, int size)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
void bucketSort(float arr[], int size)
{

    vector<float> buckets[size];

    for(int i = 0; i < size; i++)
    {
        int bucket_index = arr[i] * size;
        buckets[bucket_index].push_back(arr[i]);
    }
    for(int i = 0; i < 10; i++)
        insertionSort(buckets[i],buckets[i].size());
        
    int index = 0;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
}


int main()
{
    float arr[] = {0.234,0.12,0.4,0.12,0.593,0.3495,0.11,0.9,0.234,0.9234,0.23942,0.2920,0.99};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "before: ";
    print(arr,size);
    bucketSort(arr,size);
    cout << "after: ";
    print(arr,size);
    return 0;
}