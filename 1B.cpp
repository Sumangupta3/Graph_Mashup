#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define n 1000005
vector<ll> adj[n], vis(n, 0);
ll c, ans=0;

void dfs(ll node)
{
    vis[node] = 1;
    if (adj[node].size() != 2)
        c = 0;
    for (auto child : adj[node])
    {
        if (!vis[child])
            dfs(child);
    }
}

void solve()
{
    ll node, edge;
    cin >> node >> edge;
    int u, v;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= node; i++)
    {

        if (vis[i] != 1)
        {
            c = 1;
            dfs(i);
            ans += c;
        }
    }
    cout << ans;
}
int main()
{
    solve();
    return 0;
}