// Extra 9_4_1
// C-out # num comparisons 
// C-out # swaps

// Menu
// 	- Bubble 
// 	- Selection
// 	- Insertion
// 	- Merge 

// Print CPU time of each method
// Include <time>
// clock_t


#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int num_comparisons = 0;
    clock_t start = clock();
    for(int i = 0; i < size-1; i++)
    {
        num_comparisons++;
        int j = i;
        while(j > 0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    clock_t end = clock();
    double time_elapsed = 1000.0 * (end-start) / CLOCKS_PER_SEC;
    cout << "Insertion Sort CPU time used: " << time_elapsed << " ms" << endl;
    cout << "number of comparisons " << num_comparisons << endl;
}   
void selection_sort(int arr[], int size)
{
    int num_comparisons = 0;
    int num_swaps = 0;
    clock_t start = clock();
    for(int i = 1; i < size; i++)
    {
        int minID = i;
        for(int j = i+1; j < size; j++)
        {
            num_comparisons++;
            if(arr[minID] > arr[j])
            {
                minID = j;
            }
        }
        if(minID != i)
        {
            num_swaps++;
            swap(arr[minID],arr[i]);
        }
    }
    clock_t end = clock();
    double time_elapsed = 1000.0 * (end-start) / CLOCKS_PER_SEC;
    cout << "Selection Sort CPU time used: " << time_elapsed << " ms" << endl;
    cout << "number of comparisons " << num_comparisons << endl;
    cout << "Number of swaps = " << num_swaps << endl;
}
void bubble_sort(int arr[], int size)
{
    clock_t start = clock();
    bool flag = false;
    int i = 0;
    int num_comparisons = 0;
    int num_swaps = 0;
    while(!flag)
    {
        flag = true;
        for(int j = 0; j < size-i-1; j++)
        {
            num_comparisons++;
            if(arr[j+1] > arr[j])
            {
                num_swaps++;
                swap(arr[j+1],arr[j]);
                flag = false;
            }
        }
        i++;
    }
    clock_t end = clock();
    double time_elapsed = 1000.0 * (end-start) / CLOCKS_PER_SEC;
    cout << "Bubble Sort CPU time used: " << time_elapsed << " ms" << endl;
    cout << "Number of comparisons = " << num_comparisons << endl;
    cout << "Number of swaps = " << num_swaps << endl;
}



int main() {

    int option;
    int size;
    cout << "Choose sorting method" << endl;
    cout << "1: selection sort" << endl;
    cout << "2: insertion sort" << endl;
    cout << "3: bubble sort" << endl;
    cin >> option;
    cout << "Choose size of array" << endl;
    cin >> size;


    int *arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }


    switch(option)
    {
        case 1: selection_sort(arr,size);
            break;
        case 2: insertion_sort(arr,size);
            break;
        case 3: bubble_sort(arr,size);
            break;
        default: return 0;
    }


    return 0;
}