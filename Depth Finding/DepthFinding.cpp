#include<bits/stdc++.h>
using namespace std;

#define clr clear()
#define psb push_back

typedef vector<int>vii;
const int high = 100;

vii adj[high];
int visited[high] , Depth=0;

int DFS(int u , int depth)
{
    int v = 0;

    visited[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];

        if(!visited[v])
        {
            Depth = max(DFS(v, depth+1) , Depth);
        }
    }

    return depth;
}

void cln()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clr;
        visited[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i , Node;
    while(cin >> Node)
    {
        int edge = Node - 1;

        cln();

        for(i=0; i<edge; i++)
        {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].psb(u);
        }

//        int givenDepth , target;
//        cout << "Enter Depth and Target Node: ";
//        cin >> givenDepth >> target;

        int root = 1;

        Depth = 0;

        DFS(root , 1);

        cout << "Depth = " << Depth << "\n";
    }

    return 0;
}

