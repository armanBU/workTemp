/*
*   Judge       : LightOJ
*   Problem     : 1024 - Eid
*   Algorithms  : LCM(Euclid)
*   Solved By   : Abu Rifat Muhammed Al Hasib
*   Website     : aburifat.com
*   Email       : rifat.cse4.bu@gmail.com
*   GitHub      : github.com/abu-rifat
*   Codeforces  : codeforces.com/profile/AbuRifatMuhammed
*   Education   : University of Barishal
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<10509>bs;
vector<ll>primes;

void sieve(ll ub)
{
    bs.set();
    bs[0]=bs[1]=0;
     primes.push_back(2);
     for(ll i=4;i<=ub;i+=2)bs[i]=0;
     for(ll i=3;i<=ub;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=(2*i))bs[j]=0;
            primes.push_back(i);
        }
     }
}

string rev_mul_str_num(string s, ll num)
{
    string tmpS;
    ll TSSize=0;
    while(num){
        ll dgt=num%10;
        num/=10;
        ll carr=0;
        ll ins=0;
        ll len=s.size();
        for(ll i=0;i<len;i++){
            ll tmp=s[i]-'0';
            tmp*=dgt;
            tmp+=carr;
            carr=tmp/10;
            tmp%=10;
            if((TSSize-1)<(i+ins)){
                tmpS+=('0'+tmp);
                TSSize++;
            }
        }
        if(carr){
            tmpS+=('0'+carr);
            TSSize++;
        }
        ins++;
    }
    return tmpS;
}

int main()
{
    sieve(10500);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        map<ll,ll>pDiv;
        string ans="1";
        for(ll i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            for(ll j=0;primes[j]<=tmp;j++){
                ll ct=0;
                while(tmp%primes[j]==0){
                    ct++;
                    tmp/=primes[j];
                }
                if(ct>pDiv[primes[j]])pDiv[primes[j]]=ct;
            }
            if(tmp>1){
                if(!pDiv[tmp])pDiv[tmp]=1;
            }
        }
        ll len=primes.size();
        for(ll i=0;i<len;i++){
            if(pDiv[primes[i]]){
                ll val=powl(primes[i],pDiv[primes[i]]);
                ans=rev_mul_str_num(ans,val);
            }
        }
        reverse(ans.begin(),ans.end());

        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}
