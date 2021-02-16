#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,a,b) for(ll i=a; i<b; i++)
typedef tree < ll, null_type, less < ll >,
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//
const int N=1e5;


vector<ll>G[N+50];
bool vis[N+5];
ll finish[N+5];
ll start[N+5];
ll somoy=1;

void dfs(ll root){
	vis[root]=true;
	start[root]=somoy++;
	for(auto child:G[root]){
		if(vis[child]==false){
			dfs(child);
		}
	}
	finish[root]=somoy++;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	rep(T,1,t+1){
		ll node,edge;
		cin>>node>>edge;
		ll u,v;
		rep(i,0,edge){
			cin>>u>>v;
			G[u].pb(v);
		}
		vector<ll>cost(node),hospital;
		rep(i,0,node){
			cin>>cost[i];
			if(cost[i]==0){
				hospital.pb(i);
			}
		}
		rep(i,0,node){
			if(vis[i]==false){
				dfs(i);
			}
		}
		vector<pair<ll,ll>>P;
		rep(i,0,node){
			P.pb({finish[i],i});
		}
		sort(all(P));
		reverse(all(P));
		memset(vis,0,sizeof(vis));
		ll sz=hospital.size();
		rep(i,0,sz){
			dfs(hospital[i]);
		}
		ll res=0;
		rep(i,0,node){
			if(vis[P[i].S]==false){
				res+=cost[P[i].S];
				dfs(P[i].S);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
