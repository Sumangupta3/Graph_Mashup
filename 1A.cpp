//Qstn Link--->https://codeforces.com/problemset/problem/1365/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n, m;
char G[55][55];
int vis[1001][1001] = {0};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int c = 0, cb = 0;
int isvalid(int x, int y)
{
    if (x > n || x < 1 || y > m || y < 1)
        return -1;

    if (vis[x][y] == 1 || G[x][y] == '#')
        return -1;

    else
        return 1;
}
int dfs(int x, int y)
{
    vis[x][y] = 1;
    if (G[x][y] == 'G')
        c++;
    if (G[x][y] == 'B')
        cb++;

    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i], y + dy[i]) == 1)
            dfs(x + dx[i], y + dy[i]);
    }
    if (cb == 0)
        return c;
    else
        return -1;
}

int main()
{
    long long int testcases;
    cin >> testcases;
    while (testcases--)
    {
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
                vis[i][j] = 0;
        }
        c = 0, cb = 0;
        int cg = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> G[i][j];
                if (G[i][j] == 'G')
                    cg++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (G[i][j] == 'B')
                {
                    if (i - 1 >= 1 && G[i - 1][j] == '.')
                        G[i - 1][j] = '#';
                    if (i + 1 <= n && G[i + 1][j] == '.')
                        G[i + 1][j] = '#';
                    if (j - 1 >= 1 && G[i][j - 1] == '.')
                        G[i][j - 1] = '#';
                    if (j + 1 <= m && G[i][j + 1] == '.')
                        G[i][j + 1] = '#';
                }
            }
        }
        if (G[n][m] == '.')
        {
            int res = dfs(n, m);
            if (res == -1)
                cout << "No";
            else
            {
                if (res == cg)
                    cout << "Yes";
                else
                    cout << "No";
            }
        }
        else
          {
              if(cg==0) cout<<"Yes";
              else cout<<"No";
          }
        cout << endl;
    }

return 0;
}