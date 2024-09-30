//grif[i-1][j]->vertical sum
//grid[i][j-1]->horizontal sum
//gird[i-1][j-1]->grid[i-1][j] and grid[i][j-1], you're adding the sum of all elements above and to the left of the current cell (i, j)
//subtract grid[i-1][j-1] to correct for this overcounting.
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i-1>=0)grid[i][j]+=grid[i-1][j];
        if(j-1>=0)grid[i][j]+=grid[i][j-1];
        if(i-1>=0 && j-1>=0)grid[i][j]-=grid[i-1][j-1];
    }
}