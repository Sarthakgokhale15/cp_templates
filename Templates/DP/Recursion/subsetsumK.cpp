void rec(int i,int arr[],vi &ans,int n,int sum,int s){
    if(i==n){

       
        if(s==sum){
            for(int x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }

        
    return; 
    
    }
    
    
    // take
   ans.pb(arr[i]);
   s+=arr[i];
    rec(i+1,arr,ans,n,sum,s);
     
    // not take
     ans.pop_back();
     s-=arr[i];
    rec(i+1,arr,ans,n,sum,s);
   
}

void solve()
{
int arr[]={3,1,2,2,4,6,8,10};
int n=8;
int sum=8;
vi ans;
rec(0,arr,ans,n,sum,0);

}