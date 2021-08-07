void tarjan(int u)
{
	dfs_low[u] = dfs_num[u] = num++;
	stak.push_back(u);
	for (auto next : graphAdj[u])
	{
		if (dfs_num[next])
			dfs_low[u] = min(dfs_low[u],dfs_num[next]);
		else
		{
			tarjan(next);

			if (dfs_low[next] >= dfs_num[u])
			{
				arti[u] = (dfs_num[u] > 1 || dfs_num[next] > 2);
				components.push_back({u});
				while (components.back().back() != next)
				{
					components.back().push_back(stak.back());
					stak.pop_back();
				}
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[next]);
		}
	}
}

void dfs(int u,int prev)
{
	for (auto next : treeAdj[u]) if (next != prev)
	{
		depth[next] = depth[u] + 1;
		parent[next] = u;
		dfs(next,u);
	}
}

void makeBCT()
{
	num = 1;
	for (int i = 0 ; i < n ; i++) if (dfs_num[i] == 0)
		tarjan(i);
	int curId = 0;
	for (int i = 0 ; i < n ; i++) if (arti[i])
	{
		isCut[curId] = 1;
		componentsElement[curId].push_back(i);
		treeId[i] = curId++;
	}

	for (auto it : components)
	{
		int nodeId = curId++;
		isBlock[nodeId] = 1;
		for (auto u : it)
		{
			if (!arti[u]) 
			{
				treeId[u] = nodeId;
			}
			else
			{
				treeAdj[nodeId].push_back(treeId[u]);
				treeAdj[treeId[u]].push_back(nodeId);
			}
			componentsElement[nodeId].push_back(u);
		}
	}
	for (int i = 0 ; i < curId ; i++) if (depth[i] == 0)
	{
		depth[i] = 1;
		dfs(i,-1);
	}
}