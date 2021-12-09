struct Matrix{
    int a[2][2];
    Matrix(){
        rep(i,2){
            rep(j,2){
                a[i][j]=0;
            }
        }
    }

    Matrix operator*(const Matrix& other){
Matrix product=Matrix();
     rep(i,2){
        rep(j,2){
            rep(k,2){

//simple mattrix multiplication multiply every row(i) by every column(j) and its val(k)
product.a[i][k]+=a[i][j]*other.a[j][k];
product.a[i][k]%=mod;
            }
        }
     }
     return product;

    }
};


Matrix expo_power(Matrix a,int n){
    Matrix result=Matrix();
   rep(i,2)result.a[i][i]=1;
 
 
 
    while(n>0){
        if(n%2==1){
            result=result*a;
        }
 
        a=a*a;
        n/=2;
    }
    return result;
}
bool inside(int row,int col){
    return 0<=min(row,col) && max(row,col)<8;
}