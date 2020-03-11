/*
    Sk arman Hossain
    University of Barisal

    Problem name : toph-Taju Kage Bunshin No Jutsu
    Algorithm : Merge Sort Tree
 */
#include<bits/stdc++.h>;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>V,V2,V3,tree[500000];
ll ar[100010];
void merg(vector<ll>v1,vector<ll>v2,ll n)
{
    ll siz1=v1.size();
    ll siz2=v2.size();
    ll left=0,right=0;
    tree[n].clear();
    while(left<siz1)
    {
        if(v1[left]!=-1)
            break;
        left++;
    }
    while(right<siz2)
    {
        if(v2[right]!=-1)
            break;
        right++;
    }
    while(left<siz1&&right<siz2)
    {
        if(v1[left]<=v2[right])
        {
            tree[n].PB(v1[left]);
            left++;
        }
        else
        {
            tree[n].PB(v2[right]);
            right++;
        }
    }
    while(left<siz1)
    {
        tree[n].PB(v1[left]);
        left++;
    }
    while(right<siz2)
    {
        tree[n].PB(v2[right]);
        right++;
    }
}
void merg2(vector<ll>v1,vector<ll>v2)
{
    ll siz1=v1.size();
    ll siz2=v2.size();
    ll left=0,right=0;
    //V.clear();
    while(left<siz1)
    {
        if(v1[left]!=-1)
            break;
        left++;
    }
    while(right<siz2)
    {
        if(v2[right]!=-1)
            break;
        right++;
    }
    while(left<siz1&&right<siz2)
    {
        if(v1[left]<=v2[right])
        {
            //V.PB(v1[left]);
            left++;
        }
        else
        {
            //V.PB(v2[right]);
            right++;
        }
    }
    while(left<siz1)
    {
        //V.PB(v1[left]);
        left++;
    }
    while(right<siz2)
    {
        //V.PB(v2[right]);
        right++;
    }
}
ll merge_sort_tree(ll n,ll b,ll e)
{


    if(b==e)
    {
        tree[n].PB(ar[b]);
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=merge_sort_tree(left,b,mid);
    ll q=merge_sort_tree(right,mid+1,e);
    merg(tree[left],tree[right],n);
    return 0;
}
ll update(ll n,ll b,ll e,ll i,ll r,ll val)
{

    if(b==e&&b==i)
    {
        tree[n].clear();
        ar[b]=val;
        tree[n].PB(ar[b]);
        return 0;
    }
    if(b>r||e<i)
    {
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=update(left,b,mid,i,r,val);
    ll q=update(right,mid+1,e,i,r,val);
    merg(tree[left],tree[right],n);
    return 0;
}
ll query(ll n,ll b,ll e,ll i,ll r,ll val)
{
    if(b>=i&&e<=r)
    {
        ll x=lower_bound(tree[n].begin(),tree[n].end(),val)-tree[n].begin();
        return x;
    }
    if(b>r||e<i)
    {
        return 0;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid = (b+e)/2;
    ll p=query(left,b,mid,i,r,val);
    ll q=query(right,mid+1,e,i,r,val);
    return p+q;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    memset(ar,-1,sizeof(ar));
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&ar[i]);
        V.PB(ar[i]);
    }
    VST(V);cout<<(ll)V.size()<<endl;
    for(ll i=0; i<n; i++)
    {
        printf("%lld ",V[i]);
    }
    cout<<endl;
    ll xxx=merge_sort_tree(1,1,100001);
    ll quy;
    scanf("%lld",&quy);
    for(ll i=0; i<quy; i++)
    {
        ll a;
        scanf("%lld",&a);
        if(a==1)
        {

            ll b;
            scanf("%lld",&b);
            for(ll j=0; j<n; j++)
            {
                printf("%lld ",V[j]);
            }
            cout<<endl; n++;
            //ll tt=update(1,1,100001,n,n,b);

            ll pos1=lower_bound(V.begin(),V.end(),10)-V.begin();
            //V.insert(V.begin()+pos1,b);
            printf("%lld t\n",pos1);


//             for(ll j=0; j<n; j++)
//            {
//                printf("%lld ",V[j]);
//            }
//            cout<<endl;
        }
        else if(a==2)
        {
            ll tt=update(1,1,100001,n,n,(ll)-1);
            ll po=lower_bound(V.begin(),V.end(),ar[n])-V.begin();
            V.erase(V.begin()+po);

            n--;
            for(ll j=0; j<n; j++)
            {
                printf("%lld ",V[j]);
            }
            cout<<endl;
        }
        else
        {
            ll l,r,pos;
            V.clear();
            scanf("%lld %lld %lld",&l,&r,&pos);

            //
            //ll tt=query(1,1,100001,l,r);
            //
            ll l2,r2;
            ll idx,b=1,e=n;
            ll k=r-l+1;
            k-=pos;
            while(b<=e)
            {
                ll  mid=b+(e-b)/2;
                ll index=query(1,1,100001,l,r,V[mid]);
                if(index<=k)
                {
                    idx=mid;
                    b=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            printf("%lld\n",V[idx]);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


