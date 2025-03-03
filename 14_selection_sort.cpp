#include<iostream>
#include<vector>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
                index=j;
        }
        swap(arr[index],arr[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the Size: "<<endl;
    cin>>n;
       int arr[n];
    cout<<"Enter the Number: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);

     cout<<"Sorted Number: "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";;
    }




}
