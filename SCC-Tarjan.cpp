void Tarjan(int u)
{
	dfs_low[u]=dfs_num[u]=VisitKe++;
	st.push(u); ada[u]=1;
	vis[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (!vis[v])
		 Tarjan(v);
		if (ada[v])
		 dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}
	if (dfs_low[u]==dfs_num[u])
	{
		vector<int> tmp;
		while (st.top()!=u)
		{
			tmp.push_back(st.top());
			ada[st.top()]=0;
			st.pop();
		}
		st.pop();
		tmp.push_back(u);
		ada[u]=0;
		SCC.push_back(tmp);
	}
}
