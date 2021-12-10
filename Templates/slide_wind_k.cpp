
int slide_wind_k(vi v,int k,int n){
   int max_sum=0;
   int wind_sum=0;
   //find sum of first window from 0-k
   rep(i,k){
wind_sum+=v[i];
   }
max_sum=max(max_sum,wind_sum);


for(int i=k;i<n;i++){
      wind_sum+=(v[i]-v[i-k]);
max_sum=max(max_sum,wind_sum);
}

return max_sum;

}