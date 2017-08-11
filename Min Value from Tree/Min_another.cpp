#include<bits/stdc++.h>
using namespace std;

const int high = 100;
const int inf = 1e5;

typedef vector<int>vii;

vii adj[high];

int nodevalue[high] , visited[high] , mini = inf , nval=0;

void clnset()
{
    int i=0;

    for(i=0; i<high; i++)
    {
        adj[i].clear();
        visited[i] = 0;
        nodevalue[i] = 0;
    }
}

int DFS(int u)
{
    visited[u] = 1;

    //mini = nodevalue[u];

    int i , v=0;

    cout << "1 . u = " << u << " nval = " << nval << "-" << nodevalue[u] << "\n";

    for(i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];
        nval = nodevalue[v];

        if(!visited[v])
        {
            nodevalue[u] = min(DFS(v) , nodevalue[u]);

            cout << "2 . u = " << u << " nval = " << nval << "-" << nodevalue[u] << "\n";
        }
    }

    //nodevalue[v] = mini;

    //nodevalue[u] = mini;

    //mini = min(mini , nval);

    cout << "3 . u = " << u << " nval = " << nval << "-" << nodevalue[u] << "\n";

    return min(nodevalue[u] , nval);
}


int main()
{
    int N;
    while(cin >> N)
    {
        int i=0, edge = N-1;

        mini = inf;
        nval = 0;

        clnset();

        for(i=0; i<edge; i++)
        {
            int u , v;
            cin >> u >> v;

            adj[u].push_back(v);

            nodevalue[u] = inf;
        }

        cout << "Enter Node value:\n";

        for(i=1; i<=(edge / 2)+1; i++)
        {
            int x , y;
            cin >> x >> y;

            nodevalue[x] = y;
        }

        for(i=0; i<N; i++)
        {
            cout << "for " << i << "-"  << nodevalue[i] << "\n";
        }

        cout << "\n";

        int root = 0;

        DFS(root);

        cout << "\nAfter DFS:\n";

        for(i=0; i<N; i++)
        {
            cout << "for " << i << "-" << nodevalue[i] << "\n";
        }
    }

    return 0;
}
