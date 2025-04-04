/// https://codeforces.com/blog/entry/68138

#include <iostream>
#include <vector>
using namespace std;

const int nmax = 2e5 + 7;
vector <int> adj[nmax];
int lvl[nmax], dp[nmax], par[nmax];

void dfs(int node)
{
    for(auto next:adj[node]){
        if(lvl[next] == 0)
        {
            par[next] = node;
            lvl[next] = lvl[node] + 1;
            dfs(next);
            dp[node] += dp[next];
        }
        else if(lvl[node] > lvl[next])
        {
            dp[node]++;
        }
        else if(lvl[node] < lvl[next])
        {
            dp[node]--;
        }
    }
    dp[node]--;
    if(dp[node] == 0 && lvl[node] > 1)
    {
        cout << "BRIDGE\n";
        cout << par[node] << "->" << node << endl;
    }
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    for(i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lvl[1] = 1;
    dfs(1);
    return 0;
}

