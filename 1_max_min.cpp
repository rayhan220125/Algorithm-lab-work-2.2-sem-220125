#include<iostream>
using namespace std;
pair<int,int>maxmin(int arr[], int n)
{
    int max=arr[0];
    int min=arr[0];
    for(int i=1; i<n; i++)
    {
        if (arr[i]>=max)
            max=arr[i];
        if (arr[i]<=min)
            min=arr[i];
    }
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
