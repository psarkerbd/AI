/*

-->> Finding Minimum and Maximum for every Root in a Directed Binary Tree

-->> Used Algorithm: DFS (Recursive)


*/


#include<bits/stdc++.h>
using namespace std;

const int high = 100;
const int inf = 100000;
const int iinff = 0;
typedef vector<int>vii;

#define psb push_back
#define clr clear()

vii adj[high];

int nval = 0 , visited[high], nodevalues[high];

void cln()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clr;
        visited[i] = 0;
        nodevalues[i] = 0;
    }
}

int DFS(int u , int depth)
{
    //if(depth == 0) return 0;

    visited[u] = 1;

    //cout << "shurur depth = " << depth << "\n";

    if(depth & 1)
    {
        if(!nodevalues[u]) nodevalues[u] = 0;
    }

    else
    {
        if(!nodevalues[u]) nodevalues[u] = inf;
    }

    int v = 0;

    //cout << "u = " << u <<  " nodevalue = " << nodevalues[u]  << "\n";

    for(int i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];
        nval = nodevalues[v];

        if(!visited[v])
        {
            if(depth & 1)
            {
                nodevalues[u] = max(DFS(v , depth-1) , nodevalues[u]);

                //cout << "1. then , nodevalue for u = " << u << " nodevalue = " << nodevalues[u] << "\n";
                //cout << "1. condition depth = " << depth << "\n";
            }

            else
            {
                nodevalues[u] = min(DFS(v , depth-1) , nodevalues[u]);

                //cout << "1. then , nodevalue for u = " << u << " nodevalue = " << nodevalues[u] << "\n";

                //cout << "2. condition depth = " << depth << "\n";
            }
        }
    }

    if(depth & 1)
    {
        //nodevalues[u] = max(DFS(v , depth-1) , nodevalues[u]);

        //depth--;

        //cout << "u = " << u << " nval = " << nval << " nodevalue = " << nodevalues[u]  << "\n";

        //cout << "1 . return depth = " << depth << "\n";

        return max(nval , nodevalues[u]);
    }

    else
    {
        //nodevalues[u] = min(DFS(v , depth-1) , nodevalues[u]);

        //depth--;

        //cout << "u = " << u << " nval = " << nval << " nodevalue = " << nodevalues[u]  << "\n";

        //cout << "2. return depth = " << depth << "\n";

        if(!nodevalues[u]) nodevalues[u] = inf;

        //cout << "u = " << u << " nval = " << nval << " nodevalue = " << nodevalues[u]  << "\n";


        return min(nval , nodevalues[u]);
    }
}

int main()
{
    int Node;
    while(cin >> Node)
    {
        cln();

        int i , Edge = Node - 1;

        for(i=0; i<Edge; i++)
        {
            int u , v;

            cin >> u >> v;

            adj[u].psb(v);
            //adj[v].psb(u);
        }

        cout << "Enter Node values:\n";

        int last = (Edge / 2) + 1;

        while(last--)
        {
            int x , y;

            cin >> x >> y;

            nodevalues[x] = y;
        }

        int Depth = ceil( log(Node) / log(2) );

        //Depth-=1; // where, root has no depth

        cout << "Depth = " << Depth << "\n";

        int root = 0;

        DFS(root , Depth);

        cout << "After DFS, Node values are:\n";

        for(i=0; i<Node; i++)
        {
            cout << "for node " << i << ": " << nodevalues[i] << "\n";
        }
    }

    return 0;
}

/*

15
0 1
0 2
1 3
1 4
2 5
2 6
3 7
3 8
5 11
5 12
4 9
4 10
6 13
6 14

7 5
8 4
9 2
10 3
11 1
12 7
13 4
14 8


*/
