#include<bits/stdc++.h>
using namespace std;
int cmb[100][100];
int combination(int n,int r){
    if(r==1)
        return n;
    if(r==n)
        return 1;
    if(cmb[n][r]){
        return cmb[n][r];
    }
    return cmb[n][r]=combination(n-1,r)+combination(n-1,r-1);
}
int main (){
    int n=1,r,ans;
    while(n){
        n=0;
        for(int i=1;i<=20;i++){
            for(int j=1;j<=i;j++){
                cout<<combination(i,j)<<" ";
            }
            cout<<"\n";
        }
       // ans=combination(n,r);
       // cout<<ans<<endl;
    }
}

