#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream cin("ctc.in");
ofstream cout("ctc.out");

const int nmax = 2e5 + 7;
int lowlink[nmax], id[nmax], timer = 0;
int onstack[nmax], ctc = 0;
vector<int>adj[nmax];
stack<int>st;
vector <int>ans[nmax];

void dfs(int node)
{
    lowlink[node] = id[node] = ++timer;
    onstack[node] = 1;
    st.push(node);
    for(auto next:adj[node])
    {
        if(!id[next])
        {
            dfs(next);
            lowlink[node] = min(lowlink[node], lowlink[next]);
        }
        else
        {
            if(onstack[next])
                lowlink[node] = min(lowlink[node], id[next]);
        }
    }
    if(id[node] == lowlink[node])
    {
        ctc++;
        while(true)
        {
            int u = st.top();
            st.pop();
            onstack[u] = 0;
            ans[ctc].push_back(u);
            if(u == node)
                break;

        }
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
    }
    for(i = 1; i <= n; i++)
        if(!id[i])
            dfs(i);
    cout << ctc << '\n';
    for(i = 1; i <= ctc; i++)
    {
        for(auto it: ans[i])
            cout << it << " ";
        cout << '\n';
    }
    return 0;
}
