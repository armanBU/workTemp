/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define PB push_back
#define mod 4294967296
typedef unsigned long long int ll;
using namespace std;
bitset<100000019>bs;
vector<ll>primes,pre;
void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    ll sq=sqrt(100000000);
    for(ll i=3; i<=sq; i+=2)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=100000000; j+=(i+i))
            {
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
    if(sq%2==0)sq++;
    for(ll j=sq; j<=100000000; j+=2)
    {
        if(bs[j])
        {
            primes.push_back(j);
        }
    }
    ll ans=1;
    for(ll i:primes)
    {
        ans=((ans%mod)*(i%mod))%mod;
        pre.PB(ans);
    }
}
int main()
{
    sieve();
    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);
    ll tcase=1;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        scanf("%lld",&n);
        ll sq=sqrt(n);
        ll siz=primes.size();
        ll ans=1;
        for(ll i=0; primes[i]<=sq; i++)
        {
            if(primes[i]*primes[i]>n||primes[i]>sq)break;
            ll cnt=0;
            ll num=n;
            while(num>=primes[i])
            {
                cnt++;
                num/=primes[i];
            }
            if(cnt<1)cnt=1;
            ll tm=powl(primes[i],cnt-1);
            tm%=mod;
            ans%=mod;
            ans=(ans*tm)%mod;

        }
        ll pos=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
        pos--;
        ans%=mod;
        ll p=pre[pos]%mod;
        ans=(ans*p)%mod;
        printf("Case %llu: %llu\n",test,ans);
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



