#include<bits/stdc++.h>
using namespace std;

#define clr clear()
#define psb push_back

typedef vector<int>vii;
const int high = 100;

vii adj[high];
int visited[high];

void DFS(int u , int target, int depth)
{
    int v = 0;

    if(depth == 1 || depth == 0) return;

    visited[u] = 1;

    if(u == target)
    {
        //cout << " checking .. \n";
        return;
    }

    //if(depth == 1 || depth == 0) return false;

    for(int i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];

        if(!visited[v])
        {
            if(v == target)
            {
                visited[v] = 1;
                return;
            }

            DFS(v , target, depth-1);
        }
    }
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

        int givenDepth , target;
        cout << "Enter Depth and Target Node: ";
        cin >> givenDepth >> target;

        int root = 1;

        DFS(root , target , givenDepth);

        if(visited[target]) cout << "Yes! Found " << target << " at depth " << givenDepth << "\n";
        else cout << "Not Found !\n";
    }

    return 0;
}
