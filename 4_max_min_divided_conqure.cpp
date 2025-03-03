
#include<iostream>
using namespace std;

int findmin(int arr[], int low,int high)
{

        if(low==high) return arr[low];
        int mid=(low+high)/2;
       int leftmin=findmin(arr,low, mid);
       int rightmin= findmin(arr,mid+1,high);

    return min(leftmin, rightmin);
}
int findmax(int arr[], int low,int high)
{
      if(low==high) return arr[low];
        int mid=(low+high)/2;
       int leftmax=findmax(arr,low, mid);
       int rightmax=findmax(arr,mid+1,high);

    return max(leftmax, rightmax);
}
pair<int,int>maxmin(int arr[], int n)
{  int low=0, high=n-1;
   int max= findmax(arr, low, high);
   int min= findmin(arr, low, high);
    return {max,min};
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    pair<int,int>result=maxmin(arr, n);
    cout<< "Maximun:"<<result.first<<endl;
    cout<< "Min:"<<result.second<<endl;
}
