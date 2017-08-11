/*

-> Finding Minimum from a Binary Directed Tree

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
const int inf = 1e5;

vii adj[high];
int visited[high] , nodevalues[high] , mini = inf , nval=0;

void clnset()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clr();
        visited[i] = 0;
    }
}

int DFS(int u)
{
    int i=0, v=0;

    visited[u] = 1;

    for(i=0; i<adj[u].size(); i++)
    {
        v = adj[u][i];
        nval = nodevalues[v];

        if(!visited[v])
        {
            nodevalues[u] = min(DFS(v) , nodevalues[u]);
        }
    }

    return min(nodevalues[u] , nval);
}

int main()
{
    fast;
    int Node;
    cout << "Enter Number of Node: ";
    while(cin >> Node)
    {
        clnset();

        mini = inf;
        nval = 0;

        int edge = Node - 1 , i=0 , j=0;

        for(i=0; i<edge; i++)
        {
            int u , v;
            cin >> u >> v;

            adj[u].psb(v);

            nodevalues[u] = inf;
        }

        cout << "Enter Node values:\n";

        for(i=1; i<=((edge)/2)+1; i++)
        {
            int x , y;
            cin >> x >> y;
            nodevalues[x] = y;
        }

        int root = 0;

        DFS(root);

        for(i=0; i<Node; i++)
        {
            cout << "for " << i << ": " << nodevalues[i] << "\n";
        }

        cout << "Minimum = " << nodevalues[root] << "\n";

        cout << "Enter Number of Node: ";
    }

    return 0;
}
