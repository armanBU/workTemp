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
const int N=1e6;



int main(){


	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	rep(T,1,t+1){
		ll n; cin>>n;
		ll cube=cbrt(n);
		ll L=1,R=cube,ok=0;
		while(L<=R){
			//cout<<L<<" "<<R<<"\n";
			ll currL=L*L*L;
			ll currR=R*R*R;
			if((currL+currR)==n){
				ok=1; break;
			}
			else if((currL+currR)<n){
				L++;
			}
			else{
				R--;
			}
		}
		yesNo(ok);
	}
	return 0;
}


