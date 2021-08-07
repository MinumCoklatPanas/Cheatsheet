int dfs(int u,int par)
{
	// cout << u << " " << par << endl;
	parent[u] = par;
	int ret = 1;
	int mx = -1;
	for (int i = 0 ; i < adj[u].size() ; i++) if (adj[u][i] != parent[u])
	{
		depth[adj[u][i]] = depth[u] + 1;
		int sz = dfs(adj[u][i],u);
		ret += sz;
		if (sz > mx)
		{
			mx = sz;
			heavy[u] = adj[u][i];
		}
	}
	return ret;
}

void decompose(int node,int h)
{
	head[node] = h;
	pos[node] = curPos;
	rata[curPos++] = val[node];
	if (heavy[node] != -1)
		decompose(heavy[node],h);
	for (int i = 0 ; i < adj[node].size() ; i++)
		{	
			if (adj[node][i] != parent[node]
				&& adj[node][i] != heavy[node])
			{
				decompose(adj[node][i],adj[node][i]);
			}
		}

}

//kalau udah rata,tambahin DS