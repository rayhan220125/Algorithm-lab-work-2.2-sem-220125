#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int start,int mid,int end)
{
    vector<int>temp(end-start+1) ;
    int left=start;
    int right=mid+1;
    int index=0;
    while(left<=mid && right<=end)
    {
        if(arr[left]<arr[right])
        {
            temp[index]=arr[left];
            left++;
            index++;
        }
        else
        {
            temp[index]=arr[right];
            right++;
            index++;
        }
    }
    //left extra element
    while(left<=mid)
    {
        temp[index]=arr[left];
        index++, left++;
    }
      //right extra element
       while(right<=end)
    {
        temp[index]=arr[right];
        index++, right++;
    }

    index=0;
     while(start<=end)
    {
        arr[start]=temp[index];
        index++, start++;
    }
}
void merge_sort( int arr[],int start, int end)
{
    if (start==end) return;

    int mid=(start+end)/2;
    //left side
    merge_sort(arr,start, mid);
    //right side
    merge_sort(arr, mid+1,end);
    //merge
    merge(arr, start,mid,end);


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
    merge_sort(arr, 0, n-1);

     cout<<"Sorted Number: "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";;
    }




}
