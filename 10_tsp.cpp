#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&graph,int n,vector<int>&minpath)
{
    vector<int>temppath;
    for(int i=1; i<n; i++)
    {
        temppath.push_back(i);
    }
    vector<int>bestpath;
    int mincost= INT_MAX;
    do
    {
        int currentnode=0;
        int currentcost=0;
        vector<int>currentpath= {0};
        for(int i=0; i<temppath.size(); i++)
        {
            currentcost+=graph[currentnode][temppath[i]];
            currentnode=temppath[i];
            currentpath.push_back(currentnode);
        }
        currentcost+=graph[currentnode][0];

        currentpath.push_back(0);

        if(currentcost<mincost)
        {
            mincost=currentcost;
            bestpath=currentpath;
        }


    }
    while (next_permutation(temppath.begin(),temppath.end()));
    minpath=bestpath;
    return mincost;


}
int main()
{
    int n;
    cout<<"Enter the city: ";
        cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>graph[i][j];
    }
    vector<int>minpath;
    int mincost= solve(graph,n,minpath);
    cout<<"Minimum cost: "<<mincost<<endl;
    cout<<"Minimum path: ";
    for(int i=0; i<n; i++)
    {
        cout<<minpath[i]<<" ";

    }
}
