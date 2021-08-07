bool vis[MAXN];
bool connect[MAXN][MAXN];
int matched[MAXN];
int n,m; //n = left m = right

bool dfs(ll u)
{
    for (ll i = 1 ; i <= m ; i++)
    {
        if (!vis[i] && connect[u][i] != 0)
        {
            vis[i] = 1;
            if (matched[i] == -1 || dfs(matched[i]))
            {
                matched[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int match()
{
    memset(matched,-1,sizeof(matched));
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        memset(vis,0,sizeof(vis));
        ans += dfs(i);
    }
    return ans;
}