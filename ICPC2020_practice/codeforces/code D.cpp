/*
    template prepared by amir
*/

#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=200010;
ll n,logn[N];
vector<ll>v;
ll ma[22][N];
ll mi[22][N];
void build_sparse_table(){
	logn[1]=0;
	for(ll i=2; i<=n; i++){
		logn[i]=logn[i/2]+1;
	}
	for(ll i=0; i<=logn[n]; i++){
		ll curr_len=(1<<i); //2^i
		for(ll j=0; (j+curr_len)<=n; j++){
			if(curr_len==1){
				mi[i][j]=v[j];	//table[i][j],i=2^i elements,j=start pont
				ma[i][j]=v[j];	//table[i][j],i=2^i elements,j=start pont
			}
			else{
				mi[i][j]=min(mi[i-1][j], mi[i-1][j+(curr_len/2)]);
				ma[i][j]=max(ma[i-1][j], ma[i-1][j+(curr_len/2)]);
			}
		}
	}
}

ll get_min(ll L,ll R){
	ll p=logn[R-L+1];
	ll len=1<<p;	//2^p
	return min(mi[p][L], mi[p][R-len+1]);
}
ll get_max(ll L,ll R){
	ll p=logn[R-L+1];
	ll len=1<<p;	//2^p
	return max(ma[p][L], ma[p][R-len+1]);
}
ll ve(ll a,ll b){
    if((a<0&&b<0)||(a>0&&b>0)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("1input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	cin>>t;
	while(t--){
        ll q;
		cin>>n>>q;
		string s;
		cin>>s;
		v.resize(n);
		ll cnt=0;
		for(ll i=0; i<n; i++){
			if(s[i]=='-')cnt--;
			else cnt++;
			v[i]=cnt;
		}
//		for(ll i=0;i<n;i++){
//            cout<<v[i]<<" ";
//		}
//		cout<<"\n";
		build_sparse_table();
		ll L,R;
		while(q--){
			cin>>L>>R; L--,R--;
			ll res_mi,res_ma,ans=0;
			if(L>0){
                res_mi=get_min(0,L-1);
			    res_ma=get_max(0,L-1);
			    if(ve(res_mi,res_ma)==1){
                    ans=abs(res_ma)+abs(res_mi);
			    }
			    else{
                    ans=max(ans,max(abs(res_ma),abs(res_mi)));
			    }
			}
            if(R+1<n){
                res_mi=get_min(R+1,n-1);
			    res_ma=get_max(R+1,n-1);
			    //cout<<R+1<<" "<<n-1<<"\n";
			    //cout<<res_mi<<" "<<res_ma<<"\n";
                res_mi-=v[R];
                res_ma-=v[R];
                if(L>0){
                    res_mi+=v[L-1];
                    res_ma+=v[L-1];
                }

			    if(ve(res_mi,res_ma)==1){
                    ans=max(ans,(abs(res_ma)+abs(res_mi)));
			    }
			    else{
                    ans=max(ans,max(abs(res_ma),abs(res_mi)));
			    }
            }

			cout<<ans+1<<"\n";
		}
	}

	return 0;
}
