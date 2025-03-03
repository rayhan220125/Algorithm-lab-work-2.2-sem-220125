#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MX 100

struct node
{
    int val;
    int cost;

};
vector<node>G[MX];
bool visited[MX];
int dist[MX];

class cmp
{
public:
    bool operator()(node &A,node&B)
    {
        if(A.cost>B.cost)return true;

        return false;
    }

};
void dijkstra(int source)
{
    priority_queue<node,vector<node>,cmp>PQ;

    PQ.push({source,0});

    while(!PQ.empty())
    {
        node current = PQ.top();
        PQ.pop();
        int val= current.val;
        int cost= current.cost;
        if(visited[val]==1) continue;

        dist[val]=cost;
        visited[val]=1;

        for(int i=0; i<G[val].size(); i++)
        {
            int next= G[val][i].val;
            int nextcost= G[val][i].cost;

            if(!visited[next])
            {
                PQ.push({next,cost+nextcost});
            }
        }

    }


}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;


    // u,v,w
    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }

    cout<<"Enter the source node: "<<endl;
    int source,des;

    cin>>source;
     cout<<"Enter the distination: "<<endl;
     cin>>des;
    dijkstra(source);
    /*
    for(int i=1; i<=nodes; i++)
    {
        cout<<"Node "<<i<< " Distance: "<<dist[i]<<endl;
    }
*/
cout<<"Node "<<source<< " Distance: "<<dist[des]<<endl;

    return 0;
}
