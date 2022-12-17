// vector<vector<int> > K(n + 1, vector<int>(k + 1, 0));

// // Build table K[][] in bottom up manner
// for (i = 1; i <= n; i++)
// {
//     for (int j = 0; j <= k; j++)
//     {
//         if (j >= b[i - 1])
//         {
//             K[i][j] = K[i - 1][j - b[i - 1]] + c[i - 1];
//         }
//         K[i][j] = max(K[i][j], K[i - 1][j]);
//     }
// }
// cout << K[n][k] << endl;
// }


// space otpimized knapsack
// input wt={1,3,3,5} W=12
// output=True
// return if we can make W sum from given weights

bool knapsack(vector<int>&wt,int W){
    vector<int>possible(W+1,0);
    possible[0]=1;
    int n=wt.size();
    for(int k=1;k<=n;k++){
        for(int x=W;x>=0;x--){
            if(possible[x]){
                if(x+wt[k]<=W){
                    possible[x+wt[k]]=1;
                }
                
            }
        }
    }
    return possible[W];
}
