
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node,vector<int>adj[],vector<int>&ans, vector<bool>&visited)
{
   visited[node] = 1;
    ans.push_back(node);
    for(int i=0; i<adj[node].size();i++)
        {
          if(!visited[adj[node][i]])
          {
               DFS(adj[node][i],adj,ans,visited);
          }
        }

}
vector<int>DFSGraph(int v, vector<int>adj[])
{
    vector<bool>visited(v,0);

    vector<int>ans;

    int n;
    cout<<"enter the starting point: "<<endl;
    cin >> n;

     DFS(n,adj,ans,visited);

    return ans;
}
int main()
{
  int v,e;
  cout<<"Enter the vertex and edges: "<<endl;
  cin>>v>>e;

  vector<int>adj[v];
   cout << "Enter edges (u ,v) where 0 <= u, v < " << v << ":\n";
   for(int i=0; i<e;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }

   vector<int> result = DFSGraph(v,adj);

   cout<<"DFS Travers: "<<endl;
   for(int i=0; i<result.size();i++)
   {
       cout<<result[i]<<" ";
   }
}
