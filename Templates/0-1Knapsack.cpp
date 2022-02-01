vector<vector<int> > K(n + 1, vector<int>(k + 1, 0));

// Build table K[][] in bottom up manner
for (i = 1; i <= n; i++)
{
    for (int j = 0; j <= k; j++)
    {
        if (j >= b[i - 1])
        {
            K[i][j] = K[i - 1][j - b[i - 1]] + c[i - 1];
        }
        K[i][j] = max(K[i][j], K[i - 1][j]);
    }
}
cout << K[n][k] << endl;
}
