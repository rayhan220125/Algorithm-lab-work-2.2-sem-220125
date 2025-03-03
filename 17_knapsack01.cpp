#include<iostream>
#include<vector>
using namespace std;
int knapsack(int W,vector<int>&wt,vector<int>&value,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
            if(i==0||w==0) return dp[n][w] ;
            else if(wt[i-1]<=w)
                dp[i][w]=max(dp[i-1][w],value[i-1]+dp[i-1][w-wt[i-1]]);
            else
            dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];

}

int main()
{
    int W,n;

    cout<<" how many weights and : ";
    cin>>n;
    cout<<" Enter the capacity of Knapsack: ";
    cin>>W;
    vector<int>wt;
    cout<<" Enter the weights: ";
    for(int i =0;i<n;i++)
    {   int temp;
        cin>>temp;
        wt.push_back(temp);

    }
    vector<int>value;
    cout<<" Enter the value: ";
    for(int i =0;i<n;i++)
    {
       int temp;
        cin>>temp;
        value.push_back(temp);

    }

    cout<<"Maximum profit: "<<knapsack(W,wt,value,n);
}
