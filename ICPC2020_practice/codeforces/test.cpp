#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    ll n;
    char s[310][310];
    ll arr[310][310];
    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>s[i];
        }

///////////////////////////////////////////////////////////////

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                arr[i][j]=0;
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(s[i][j]=='X'){
                    ll ct1=0;
                    for(ll k=j+1;k<j+3;k++){
                        if(k>=n)break;
                        if(s[i][k]=='X')ct1++;
                    }
                    if(ct1==2){
                        for(ll k=j;k<j+3;k++){
                            arr[i][k]++;
                        }
                    }
                    ll ct2=0;
                    for(ll k=i+1;k<i+3;k++){
                        if(k>=n)break;
                        if(s[k][j]=='X')ct2++;
                    }
                    if(ct2==2){
                        for(ll k=i;k<i+3;k++){
                            arr[k][j]++;
                        }
                    }
                    ll ct3=0;
                    for(ll k=i+1, l=j+1;k<i+3&&l<j+3;k++,l++){
                            if(k>=n||l>=n)break;
                            if(s[k][l]=='x')ct3++;
                    }
                    if(ct3==2){
                        for(ll k=i, l=j;k<i+3&&l<j+3;k++,l++){
                            arr[k][l]++;
                        }
                    }
                    ll ct4=0;
                    for(ll k=i-1, l=j-1;k>i-3&&l>j-3;k--,l--){
                            if(k<0||l<0)break;
                            if(s[k][l]=='x')ct4++;
                    }
                    if(ct4==2){
                        for(ll k=i, l=j;k>i-3&&l>j-3;k--,l--){
                            arr[k][l]++;
                        }
                    }
                }

            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(arr[i][j]==4){
                    s[i][j]='O';
                }
            }
        }

//////////////////////////////////////////////////////////////

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                arr[i][j]=0;
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(s[i][j]=='X'){
                    ll ct1=0;
                    for(ll k=j+1;k<j+3;k++){
                        if(k>=n)break;
                        if(s[i][k]=='X')ct1++;
                    }
                    if(ct1==2){
                        for(ll k=j;k<j+3;k++){
                            arr[i][k]++;
                        }
                    }
                    ll ct2=0;
                    for(ll k=i+1;k<i+3;k++){
                        if(k>=n)break;
                        if(s[k][j]=='X')ct2++;
                    }
                    if(ct2==2){
                        for(ll k=i;k<i+3;k++){
                            arr[k][j]++;
                        }
                    }
                    ll ct3=0;
                    for(ll k=i+1, l=j+1;k<i+3&&l<j+3;k++,l++){
                            if(k>=n||l>=n)break;
                            if(s[k][l]=='x')ct3++;
                    }
                    if(ct3==2){
                        for(ll k=i, l=j;k<i+3&&l<j+3;k++,l++){
                            arr[k][l]++;
                        }
                    }
                    ll ct4=0;
                    for(ll k=i-1, l=j-1;k>i-3&&l>j-3;k--,l--){
                            if(k<0||l<0)break;
                            if(s[k][l]=='x')ct4++;
                    }
                    if(ct4==2){
                        for(ll k=i, l=j;k>i-3&&l>j-3;k--,l--){
                            arr[k][l]++;
                        }
                    }
                }

            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(arr[i][j]==3){
                    s[i][j]='O';
                }
            }
        }

//////////////////////////////////////////////////////////////
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                arr[i][j]=0;
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(s[i][j]=='X'){
                    ll ct1=0;
                    for(ll k=j+1;k<j+3;k++){
                        if(k>=n)break;
                        if(s[i][k]=='X')ct1++;
                    }
                    if(ct1==2){
                        for(ll k=j;k<j+3;k++){
                            arr[i][k]++;
                        }
                    }
                    ll ct2=0;
                    for(ll k=i+1;k<i+3;k++){
                        if(k>=n)break;
                        if(s[k][j]=='X')ct2++;
                    }
                    if(ct2==2){
                        for(ll k=i;k<i+3;k++){
                            arr[k][j]++;
                        }
                    }
                    ll ct3=0;
                    for(ll k=i+1, l=j+1;k<i+3&&l<j+3;k++,l++){
                            if(k>=n||l>=n)break;
                            if(s[k][l]=='x')ct3++;
                    }
                    if(ct3==2){
                        for(ll k=i, l=j;k<i+3&&l<j+3;k++,l++){
                            arr[k][l]++;
                        }
                    }
                    ll ct4=0;
                    for(ll k=i-1, l=j-1;k>i-3&&l>j-3;k--,l--){
                            if(k<0||l<0)break;
                            if(s[k][l]=='x')ct4++;
                    }
                    if(ct4==2){
                        for(ll k=i, l=j;k>i-3&&l>j-3;k--,l--){
                            arr[k][l]++;
                        }
                    }
                }

            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(arr[i][j]==2){
                    s[i][j]='O';
                }
            }
        }

//////////////////////////////////////////////////////////////
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(s[i][j]=='X'){
                    ll ct1=0;
                    for(ll k=j+1;k<j+3;k++){
                        if(k>=n)break;
                        if(s[i][k]=='X')ct1++;
                    }
                    if(ct1==2)s[i][j+2]='O';
                    ll ct2=0;
                    for(ll k=i+1;k<i+3;k++){
                        if(k>=n)break;
                        if(s[k][j]=='X')ct2++;
                    }
                    if(ct2==2)s[i+2][j]='O';
                    ll ct3=0;
                    for(ll k=i+1, l=j+1;k<i+3&&l<j+3;k++,l++){
                            if(k>=n||l>=n)break;
                            if(s[k][l]=='x')ct3++;
                    }
                    if(ct3==2)s[i+2][j+2]='O';
                    ll ct4=0;
                    for(ll k=i-1, l=j-1;k>i-3&&l>j-3;k--,l--){
                            if(k<0||l<0)break;
                            if(s[k][l]=='x')ct4++;
                    }
                    if(ct4==2)s[i-2][j-2]='O';
                    //if(ct1==2||ct2==2||ct3==2||ct4==2)s[i][j]='O';
                }

            }
        }
        for(ll i=0;i<n;i++){
            cout<<s[i]<<"\n";
        }
    }
    return 0;
}
