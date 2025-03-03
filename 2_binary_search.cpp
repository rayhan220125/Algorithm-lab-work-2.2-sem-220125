#include<iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int low=0;
    int high=n-1;
    int mid;


    while(low<=high)
    {
        mid= low+high)/2;
        if (arr[mid]==key)
            return mid;

       else if(key<arr[mid])

            high=mid-1;
        else low=mid+1;
    }
    return -1;

}
int main()
{
    int n;
    cout<<"How many number you enter: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"find the key number : "<<endl;
    cin>>key;

    int result=binary_search(arr,n, key);

    if(result == -1)
        cout<<"Element not found"<<endl;
    else cout<<"Element found in index : "<< result<<endl;


}

