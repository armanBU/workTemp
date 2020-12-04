#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;

vector<pair<ll,ll>>pr;
vector<ll>prime,v;
bool isPrime[N+5];

void sieve(){
	prime.push_back(2);
	for(ll i=3; i<N; i+=2){
		if(isPrime[i]==0){
			prime.push_back(i);
			for(ll j=(i*2); j<N; j+=i){
				isPrime[j]=1;
			}
		}
	}
}

void factor(ll n){
	ll srt=sqrt(n);
	for(ll i=0; prime[i]<=srt; i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				n/=prime[i];
				v.push_back(prime[i]);
			}
		}
	}
	if(n>1){v.push_back(n);}
	sort(v.begin(),v.end());
	ll cnt=1;
	for(ll i=0; i<n-1; i++){
		if(v[i]==v[i+1]){
			cnt++;
		}
		else{
			pr.push_back({v[i],cnt});
			cnt=1;
		}
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	sieve();
	ll t; cin>>t;
	while(t--){
		ll p,q; cin>>p>>q;
		if(p%q!=0){
			cout<<p<<"\n"; continue;
		}
		factor(q);
		ll res=1,sz=pr.size();
		for(ll i=0; i<sz; i++){
			ll a=pr[i].first,b=pr[i].second-1,temp=p;
			while(temp%a==0){
				temp/=a;
			}
			if(b>0){temp*=(a*b);
			}
			res=max(res,temp);
		}
		cout<<res<<"\n";
		v.clear(); pr.clear();
	}

	return 0;
}

