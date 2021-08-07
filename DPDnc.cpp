void rec(int k,int l,int r,int optl,int optr)
{
	if (l > r) return;
	int mid = (l + r) >> 1;
	DP[mid][k] = INF;
	int Opt = -1;
	for (int i = optl ; i <= min(optr,mid) ; i++)
	{
		int val = DP[i - 1][k - 1] + cost(i,mid);
		if (val < DP[mid][k])
		{
			DP[mid][k] = val;
			Opt = i;
		}
	}
	// cout << mid << " " << DP[mid][k] << " " << Opt << endl;
	rec(k,l,mid - 1,optl,Opt);
	rec(k,mid + 1,r,Opt,optr);
}

//opt[i][j] <= opt[i][j + 1]