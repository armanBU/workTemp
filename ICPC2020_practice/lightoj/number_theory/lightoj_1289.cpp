/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define PB push_back
#define mod 4294967296
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
bitset<100000019>bs;
vector<ull>primes,pre;
ll pow_u(ll n,ll po){
    ll ans=1;
    for(ll i=1;i<=po;i++){
        ans*=n;
    }
    return ans;
}
void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    ll sq=sqrt(100000001);
    for(ll i=3; i<=sq; i+=2)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=100000000; j+=(i+i))
            {
                bs[j]=0;
            }
            primes.push_back((ull)i);
        }
    }
    if(sq%2==0)sq++;
    for(ll j=sq; j<=100000000; j+=2)
    {
        if(bs[j])
        {
            primes.push_back((ull)j);
        }
    }
    ull ans=1;
    for(auto i:primes)
    {
        ans=((ans%mod)*((ull)i%mod))%mod;
        pre.PB(ans);
    }
}
int main()
{
    sieve();
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //scanf("%lld",&tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        //scanf("%lld",&n);
        cin>>n;
        ll sq=sqrt(n);
        ll siz=primes.size();
        ull ans=1;
        ll pos=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
        pos--;
        ans=pre[pos];
        for(ll i=0; primes[i]<=sq; i++)
        {
            if(primes[i]*primes[i]>n||primes[i]>sq)break;
            ll cnt=0;
            ll num=n;
            while(num>=primes[i])
            {
                num/=primes[i];
                if(cnt==1){
                    ans*=primes[i];
                    ans%=mod;
                }
                cnt=1;
            }
        }
        //printf("Case %lld: %llu\n",test,ans);
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



