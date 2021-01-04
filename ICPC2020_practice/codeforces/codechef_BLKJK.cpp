#include<bits/stdc++.h>
using namespace std;
#define PB push_back
struct st
{
    bitset<1010>bt;
    int ans;
    int total;
};
st mem[1010][1010];
int n,x,y;
vector<int>V;
st dp(int i,int sum,int cnt,bitset<1010>bset)
{
    if(sum>=x&&sum<=y)
    {
        int val=0;
        for(int j=0; j<cnt; j++)
        {
            if(bset[j]==0)val++;
        }
        st tm3;
        tm3.total=cnt;
        tm3.ans=val;
        tm3.bt=bset;
        return tm3;
    }
    if(i>=n||sum>y)
    {
        st xy;
        xy.ans=999999;
        xy.bt.set(0);
        xy.total=0;
        return xy;
    }
    if(mem[i][sum].ans!=-1)
    {
        if(mem[i][sum].ans<=n)
        {
            bitset<1010>tm;
            tm=mem[i][sum].bt;
            int pre=0,cur=0;
            for(int j=0; j<i; j++)
            {
                if(tm[j]==1)pre++;
                if(bset[j]==1)cur++;
                tm[j]=bset[j];
            }
            int pre_2seg=mem[i][sum].total-pre;
            int cur_total=pre_2seg+cur;
            int val=0;
            for(int j=0; j<cur_total; j++)
            {
                if(tm[j]==0)val++;
            }
            if(mem[i][sum].ans>val)
            {
                mem[i][sum].ans=val;
                mem[i][sum].total=cur_total;
                mem[i][sum].bt=tm;
            }
        }
        return mem[i][sum];
    }
    bset[i]=1;
    st tm=dp(i+1,sum+V[i],cnt+1,bset);
    bset[i]=0;
    st tm2=dp(i+1,sum,cnt,bset);
    if(tm.ans<=tm2.ans)
    {
        mem[i][sum]=tm;
    }
    else
    {
        mem[i][sum]=tm2;
    }
    return mem[i][sum];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tcase;
    cin>>tcase;
    for(int test=1; test<=tcase; test++)
    {
        V.clear();
        cin>>n>>x>>y;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            V.PB(a);
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=y; j++)
            {
                mem[i][j].ans=-1;
                mem[i][j].total=0;
                mem[i][j].bt.set(0);
            }
        }
        bitset<1010>bit;
        bit.set(0);
        st an=dp(0,0,0,bit);
        if(an.ans>n)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<an.ans<<"\n";
        }

    }

    return 0;
}
