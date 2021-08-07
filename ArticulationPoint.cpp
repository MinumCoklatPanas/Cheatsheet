void FindArti(int u)
{
//	cout<<u<<" u\n";
	dfs_num[u]=dfs_low[u]=num++;
	vis[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		if (!vis[adj[u][i]])
		{
			parent[adj[u][i]]=u;
			if (u==root)
			 RootChildren++;
			FindArti(adj[u][i]);
//			if (u!=root)
			if (dfs_low[adj[u][i]]>=dfs_num[u])
			 Articulation[u]=1;
			dfs_low[u]=min(dfs_low[u],dfs_low[adj[u][i]]);
		}
		else
		 if (parent[u]!=adj[u][i])
		 {
		 	dfs_low[u]=min(dfs_low[u],dfs_num[adj[u][i]]);
		 }
	}
	return;
}
