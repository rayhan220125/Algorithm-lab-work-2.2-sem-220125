#include<iostream>
using namespace std;
void heapify(int arr[],int index,int n)
{
    int largest=index;
    int left=2*index+1;
    int right =2*index+2;

    if(left<n&&arr[left]>arr[largest])
        largest=left;

    if(right<n&&arr[right]>arr[largest])
        largest=right;

    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}

void buildheap(int arr[],int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr,i,n);
    }
}
void sortheap(int arr[],int n)
{
    for(int i=n-1; i>0; i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}
void print(int arr[],int n)
{
    cout<<" Sorted: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]= {12,33,4,22,23,5,6,65,77,34};
    int n=10;
    buildheap(arr,n);
    sortheap(arr,n);
    print(arr,n);

}
