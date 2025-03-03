#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>BFS(int v, vector<int>adj[])
{
    queue<int>q;
    vector<bool>visited(v,0);
    q.push(0);
    visited[0] = 1;
    vector<int>ans;
    int node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0; i<adj[node].size();i++)
        {
          if(!visited[adj[node][i]])
          {
            visited[adj[node][i]]=1;
            q.push(adj[node][i]);

          }
        }
    }
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
   vector<int> result = BFS(v,adj);
   cout<<"BFS Travers: "<<endl;
   for(int i=0; i<result.size();i++)
   {
       cout<<result[i]<<" ";
   }



}
