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
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>alice,bob;
        ll n,m;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            if(a%2==0)
            {
                alice.PB(a);
            }
            else
            {
                bob.PB(a);
            }
        }
        ll al=alice.size();
        ll bo=bob.size();
        ll left=al-1;
        ll right=bo-1;
        ll ck=1;
        VST(alice);
        VST(bob);
        ll sum_alice=0,sum_bob=0;
        while(left>=0&&right>=0)
        {
            if(ck)
            {
                if(alice[left]>=bob[right])
                {
                    sum_alice+=alice[left--];
                }
                else
                {
                    right--;
                }
            }
            else
            {
                if(alice[left]<=bob[right])
                {
                    sum_bob+=bob[right--];
                }
                else
                {
                    left--;
                }
            }
            ck^=1;
            //cout<<sum_alice<<" "<<sum_bob<<" f\n";
        }
        //cout<<left<<" "<<right<<" x\n";
        while(left>=0)
        {
            if(ck)
            {
                sum_alice+=alice[left--];
            }
            else
            {
                left--;
            }
            ck^=1;
        }
        while(right>=0)
        {
            if(!ck)
            {
                sum_bob+=bob[right--];
            }
            else
            {
                right--;
            }
            ck^=1;
        }
        //cout<<sum_alice<<" "<<sum_bob<<" t\n";
        if(sum_alice>sum_bob)
        {
            cout<<"Alice\n";
        }
        else if(sum_alice<sum_bob)
        {
            cout<<"Bob\n";
        }
        else
        {
            cout<<"Tie\n";
        }


    }
///*****************************  ALHAMDULILLAH  *****************************/
}



