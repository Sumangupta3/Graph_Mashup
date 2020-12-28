#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define n 1000000
vector<ll> adj[n], vis(n, 0), col(n, -1);

bool dfs(ll node, ll c)
{
    vis[node] = 1;
    col[node] = c;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1) == false)
                return false;
        }

        else
        {
            if (col[child] == col[node])
                return false;
        }
    }
    return true;
}

void solve()
{
    ll node, edge;
    cin >> node >> edge;
    ll u, v;
    vector<pair<ll, ll>> ei(edge);
    for (ll i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ei[i]=make_pair(u, v);
    }
    if(dfs(1, 1)==true)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<edge;i++)
        {
              if(col[ei[i].first]==1)
              cout<<"0";
              else cout<<"1";
        }
    }
    else cout<<"NO";
}
int main()
{
    solve();

    return 0;
}