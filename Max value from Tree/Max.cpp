/*

-> Finding Maximum from a Directed Binary Tree

*/

#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back
#define clr clear

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const int mod = 1000007;
const int high = 500;
const int inf = 0;

vii adj[high];
int visited[high], nodevalues[high], nval=0;

void cln()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clr();
        visited[i] = 0;
        nodevalues[i] = 0;
    }
}

int DFS(int u)
{
    int v;

    visited[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];
        nval = nodevalues[v];

        if(!visited[v])
        {
            nodevalues[u] = max(DFS(v) , nodevalues[u]);
        }
    }

    return max(nodevalues[u] , nval);
}

int main()
{
    fast;
    int Node;

    cout << "Enter Number of Node: ";

    while(cin >> Node)
    {
        cln();

        int i , edge = Node - 1;

        for(i=0; i<edge; i++)
        {
            int u , v;
            cin >> u >> v;
            adj[u].psb(v);
            //adj[v].psb(u);
            nodevalues[u] = inf;
        }

        cout << "Enter Node values:\n";

        for(i=1; i<=(edge/2)+1; i++)
        {
            int x , y;
            cin >> x >> y;
            nodevalues[x] = y;
        }

        int root = 0;

        DFS(root);

        cout << "After DFS, node values are:\n";

        for(i=0; i<Node; i++)
        {
            cout << "for node " << i << ": " << nodevalues[i] << "\n";
        }

        cout << "Maximum = " << nodevalues[root] << "\n";

        cout << "Enter Number of Node: ";
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
4 9
4 10
5 11
5 12
6 13
6 14

7 10
8 12
9 16
10 3
11 2
12 5
13 7
14 9


*/
