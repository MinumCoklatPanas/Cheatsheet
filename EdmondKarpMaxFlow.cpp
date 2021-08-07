void AddEdge(int From,int To,int Cap)
{
	adj[From].push_back(cnt++);
	adj[To].push_back(cnt++);
	edges.push_back(make_pair(To,Cap));
	edges.push_back(make_pair(From,0));
	return;
}

int augment(int now,int MinSoFar)
{
if (now == sink) return MinSoFar;
	while (ptr[now] < adj[now].size())
	{
		int idx = adj[now][ptr[now]];
		int To = edges[idx].to;
		int Cap = edges[idx].cap;
	if (dist[To] != dist[now] + 1 || Cap <= 0)
			++ptr[now];
		else
		{
			int tmp = augment(To,min(MinSoFar,Cap));
			if (tmp > 0)
			{
				edges[idx].cap -= tmp;
				edges[idx + 1].cap += tmp;
				return tmp;
			}
			else
				++ptr[now];
		}
	}
	return 0;
}

void MaxFlow()
{
	while (1)
	{
		for (int i = 0 ; i <= N ; i++)
		{
			dist[i] = -1;
			ptr[i] = 0;
		}
		queue< int > q;
		q.push(source);
		dist[source] = 1;
		while (!q.empty())
		{
			int now = q.front(); q.pop();
			for (int i = 0 ; i < adj[now].size() ; i++)
			{
				int idx = adj[now][i];
				int To = edges[idx].to;
				int Cap = edges[idx].cap;
				if (dist[To] == -1 && Cap > 0)
				{
					q.push(To);
					dist[To] = dist[now] + 1;
				}
			}
		}
		if (dist[sink] == -1) return;
		f = augment(source,INF);
		while (f > 0)
		{
			MF += f;
			f = augment(source,INF);
		}
	}	
}
