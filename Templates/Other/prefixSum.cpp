// find sum form index l to r in 1D
void prefix_sum(int n, int l, int r)
{

    vi psum(n + 1, 0);

    int sum = 0;
    rep1(i, n)
    {
        int x;
        cin >> x;
        sum += x;
        psum[i] = sum;
    }

    cout << psum[r] - psum[l - 1] << endl;
}

//find sum from (a,b) to (c,d) in 2D

void prefix_sum2D(int n){
    rep1(i,n){
        rep1(j,n){
cin>>arr[i][j];

psum[i][j]=arr[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]; 

        }
    }


}


cout<<psum[c][d]-psum[a-1][d]-psum[c][b-1]+psum[a-1][b-1];