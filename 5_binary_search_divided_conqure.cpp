
#include<iostream>
using namespace std;
int binary_search(int arr[], int low,int high, int key)
{
    if(low>high) return -1;

    int mid;

    mid=(low+high)/2;
    if(arr[mid]==key)
        return mid;

    if(arr[mid]>key)
        return binary_search(arr,low, mid-1,key);

    return  binary_search(arr,mid+1,high,key);



}
int main()
{
    int n;
    cout<<"How many number you enter: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"find the key number : "<<endl;
    cin>>key;

    int result=binary_search(arr,0,n-1, key);

    if(result == -1)
        cout<<"Element not found"<<endl;
    else cout<<"Element found in index : "<< result<<endl;


}

