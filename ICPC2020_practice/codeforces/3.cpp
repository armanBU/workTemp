/*
    Sk arman Hossain
    University of Barisal
    Problem name : Disjoint Set Union Editorial
    Solution : DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 20002
ll rep[N+10];
ll node_cnt[N+10];
ll Find(ll node){
    return (rep[node]==node)?node:rep[node]=Find(rep[node]);
}
void joint (ll u,ll v){
    ll ru=Find(u);
    ll rv=Find(v);
    if(ru!=rv){
        if(node_cnt[ru]>node_cnt[rv]){
            node_cnt[ru]+=node_cnt[rv];
            rep[rv]=ru;
        }
        else{
            node_cnt[rv]+=node_cnt[ru];
            rep[ru]=rv;
        }
    }
}
int main(){
 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);

    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,A,B;
        cin>>n>>m;
        cin>>A>>B;
        for(ll i=0;i<=n;i++){
            rep[i]=i;
            node_cnt[i]=1;
        }
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            joint(a,b);
        }
        ll parent,mx=0;
        set<ll>st;
        for(ll i=1;i<=n;i++){
            ll tm=Find(i);
            if(node_cnt[tm]>mx){
                parent=tm;
                mx=node_cnt[tm];
            }
            st.insert(tm);
        }
        ll ans=A;
        for(ll i:st){
            if(i!=parent){
                ans+=min(A,B);
            }
            //cout<<i<<"\n";
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
