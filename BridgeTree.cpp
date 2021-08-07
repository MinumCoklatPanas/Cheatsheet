void FindBridge(int u)
{
	dfs_num[u]=dfs_low[u]=num++;
	vis[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		if (!vis[adj[u][i].first])
		{
			parent[adj[u][i].first]=u;
			FindBridge(adj[u][i].first);
			dfs_low[u]=min(dfs_low[u],dfs_low[adj[u][i].first]);
			if (dfs_low[adj[u][i].first] > dfs_num[u])
			{	
				adj[u][i].second = 1;
				mp[make_pair(u,adj[u][i].first)] = mp[make_pair(adj[u][i].first,u)] = 1;
				++bridge;
			}
			
		}
		else
		 if (parent[u]!=adj[u][i].first)
		  dfs_low[u]=min(dfs_low[u],dfs_num[adj[u][i].first]);
	}
	return;
}

void dfs(int u)
{
	int currcmp = ConnectedComponent;
	q[currcmp].push(u);
	vis[u] = 1;
	while (!q[currcmp].empty())
	{
		int v = q[currcmp].front();
		q[currcmp].pop();
		for (int i = 0 ; i < adj[v].size() ; i++)
		{
			if (vis[adj[v][i].first]) continue;
			if (mp[make_pair(v,adj[v][i].first)])
			{
				++ConnectedComponent;
				tree[currcmp].push_back(ConnectedComponent);
				tree[ConnectedComponent].push_back(currcmp);
				dfs(adj[v][i].first);
			}
			else
			{
				q[currcmp].push(adj[v][i].first);
				vis[adj[v][i].first] = 1;
			}
		}
	}
}
//dalam int main() setelah input
FindBridge(1);	
memset(vis,0,sizeof(vis));
ConnectedComponent = 1;
for (int i = 1 ; i <= n ; i++)
	tree[i].clear();
dfs(1);
