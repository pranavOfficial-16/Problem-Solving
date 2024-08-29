#include <iostream>
using namespace std;
void swapAlternate(int *arr, int size)
{
    int end, j = 0;
    size % 2 == 0 ? end = size : end = size - 1;
    int temp[end];
    for (int i = 1; i < end; i += 2)
    {
        temp[j] = arr[j];
        arr[j] = arr[i];
        arr[i] = temp[j];
        j += 2;
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];
    swapAlternate(arr,size);
    for (int i = 0; i < size; i++)
        cout<< arr[i]<<" ";
    return 0;
}