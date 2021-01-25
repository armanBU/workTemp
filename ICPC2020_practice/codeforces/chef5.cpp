/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        ll ar[4];
        cin>>n>>m>>ar[0]>>ar[1]>>ar[2];
        map<ll,char>mp;
        mp[0]='R';
        mp[1]='G';
        mp[2]='B';
        ll cnt=0;
        ll cnt_in=0;
        char s[55][55];
        ll tm1=0,tm2=1,ck=0;
        for(ll i=0; i<n; i++)
        {
            ll k=0;
            for(ll j=i; j>=0&&k<m; j--)
            {
                if(ar[tm1]>0)
                {
                    s[j][k]=mp[tm1];
                    ar[tm1]--;
                }
                else
                {
                    if(ck==0)
                    {
                        tm1=2;
                        ck++;
                        if(ar[tm2]>=ar[2]){
                            swap(tm1,tm2);
                        }

                        if(ar[tm1]>0)
                        {
                            s[j][k]=mp[tm1];
                            ar[tm1]--;
                        }
                        else
                        {
                            tm1=tm2;
                            s[j][k]=mp[tm1];
                            ar[tm1]--;
                        }

                    }
                    else
                    {
                        tm1=tm2;
                        s[j][k]=mp[tm1];
                        ar[tm1]--;
                    }
                }//cout<<j<<" "<<k<<" x\n";
                k++;

            }
            if(ck!=1){
               swap(tm1,tm2);
            }
            if(ck==1)ck=2;

        }
        ll nn=m-1;
        for(ll i=0; i<nn; i++)
        {
            ll k=i+1;
            for(ll j=n-1; j>=0&&k<m; j--)
            {
                if(ar[tm1]>0)
                {
                    s[j][k]=mp[tm1];
                    ar[tm1]--;
                }
                else
                {
                    if(ck==0)
                    {
                        tm1=2;
                        ck++;
                        if(ar[tm2]>=ar[2]){
                            swap(tm1,tm2);
                        }
                        if(ar[tm1]>0)
                        {
                            s[j][k]=mp[tm1];
                            ar[tm1]--;
                        }
                        else
                        {
                            tm1=tm2;
                            s[j][k]=mp[tm1];
                            ar[tm1]--;
                        }

                    }
                    else
                    {
                        tm1=tm2;
                        s[j][k]=mp[tm1];
                        ar[tm1]--;
                    }
                }//cout<<j<<" "<<k<<" x\n";
                k++;

            }
            if(ck!=1){
               swap(tm1,tm2);
            }
            if(ck==1)ck=2;
        }

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cout<<s[i][j];
            }
            cout<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



