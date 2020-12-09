#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
bitset<1000010>ck;
vector<ll>temp,prime;
void seive(){
    prime.PB(2);
    for(ll i=3;i<=1000000;i+=2){
        if(ck[i]==false){
            prime.PB(i);
            for(ll j=i*i;j<=1000000;j+=(i+i)){
                ck[j]=true;
            }
        }
    }
}
ll nod(){
    ll ans=1;
    ll siz=temp.size();
    for(ll i=0;i<siz;i++){
        ans*=(temp[i]+1);
    }
    ans-=1;
    return ans;
}
ll fac(ll n){
    temp.clear();
    ll sq=sqrt(n+1);
    ll siz=prime.size();
    for(ll i=0;i<siz&&prime[i]<=sq;i++){
        if(n%prime[i]==0){
            ll cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            temp.PB(cnt);
        }
        sq=sqrt(n);
    }
    if(n>1){
        temp.PB(1);
    }
    return nod();
}
int main(){
    seive();
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll test=1;test<=tcase;test++){
        ll n;
        cin>>n;
        ll ans=fac(n);
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
    return 0;
}
