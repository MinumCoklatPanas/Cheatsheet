//Base Case ketika panjangnya = 1
for (int i = 2 ; i < n ; i++)
{
   for (int l = 0 ; l + i < n  ; l++)
   {
      int r = l + i;
      int mn = INF;
      int ix = -1;
      for (int j = max(l + 1,opt[l][r - 1]) ; j <= min(r - 1,opt[l + 1][r]) ; j++)
      {
 int cost = DP[l][j] + DP[j][r] + (potong[r] - potong[l]);
        if (cost <= mn)
        {
         	mn = cost;
       	ix = j;
      	 }
      }
                DP[l][r] = mn;
                opt[l][r] = ix;
   }
}
cout << DP[0][n - 1] << endl;

//opt[i][j - 1] <= opt[i][j] <= opt[i + 1][j]