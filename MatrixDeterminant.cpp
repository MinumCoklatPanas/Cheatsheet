int getDeterminant(vector< vector<int> > &matrix)
{
	int n = matrix.size();
	vector<int> tmp;
	int tot = 1;
	int ret = 1;
	for (int i = 0 ; i < n ; i++)
	{
		if (matrix[i][i] == 0)
		{
			bool ada = 0;
			for (int j = i + 1 ; j < n ; j++) if (matrix[j][i] != 0)
			{
				ada = 1;
				swap(matrix[i],matrix[j]);
				if ((j - i) % 2 == 1)
					ret *= -1;
				break;
			}
			if (!ada) return 0;
		}
		tmp = matrix[i];

		for (int j = i + 1 ; j < n ; j++)
		{
			int pengali = tmp[i];
			int fix = matrix[j][i];

			for (int k = 0 ; k < n ; k++)
			{
				matrix[j][k] = (pengali * matrix[j][k]) - (fix * tmp[k]);
			}
			tot *= pengali;
		}
	}

	for (int i = 0 ; i < n ; i++)
		ret *= matrix[i][i];
	return (ret / tot);
}