struct query
{
    int L;
    int R;
    int ix;
    int lca;
    int tipe;
    int c;
};

void dfs(int now,int papa,int deep)
{
    euler[Free_Index] = now;
    ST[now] = Free_Index++;
    par[now] = papa;
    depth[now] = deep;
    for (int i = 0 ; i < adj[now].size() ; i++)
    {
        if (adj[now][i] != papa)
        {
            dfs(adj[now][i],now,deep + 1);
        }
    }
    euler[Free_Index] = now;
    EN[now] = Free_Index++;
}

void prepare()
{
    dfs(1,-1,1);
    precom();
    for (int i = 1 ; i <= m ; i++)
    {
        if (ST[ask[i].L] > ST[ask[i].R]) swap(ask[i].L,ask[i].R);
        ask[i].lca = LCA(ask[i].L,ask[i].R);
        if (ask[i].lca == ask[i].L || ask[i].lca == ask[i].R)
        {
            ask[i].tipe = 1;
            ask[i].L = ST[ask[i].L];
            ask[i].R = ST[ask[i].R];
        }
        else
        {
            ask[i].tipe = 2;
            ask[i].L = EN[ask[i].L];
            ask[i].R = ST[ask[i].R];
        }
    }
    sort(ask + 1,ask + m  + 1,cmp);
}

void update(int node)
{
    if (vis[node]) --frek[val[node]];
    else{
        // cout << val[node] << endl;
        ++frek[val[node]];
        // cout << frek[5] << endl;
    }
    vis[node] ^= 1;
}

void work()
{
    int CurrL = 1;
    int CurrR = 1;
    for (int i = 1 ; i <= m ; i++)
    {
        int L = ask[i].L; int R = ask[i].R;
        while (CurrL > L)
        {
            update(euler[CurrL - 1]);
            --CurrL;
        }
        while (CurrR <= R)
        {
            update(euler[CurrR]);
            ++CurrR;
        }
        while (CurrL < L)
        {
            update(euler[CurrL]);
            ++CurrL;
        }
        while (CurrR > R + 1)
        {
            update(euler[CurrR - 1]);
            --CurrR;
        }
        if (ask[i].tipe == 2)
            update(ask[i].lca);
        ans[ask[i].ix] = (frek[ask[i].c] > 0);
        if (ask[i].tipe == 2)
            update(ask[i].lca);
    }
    for (int i = 1 ; i <= m ; i++)
    {
        if (ans[i])
            cout << "Find\n";
        else
            cout << "NotFind\n";
    }
}
