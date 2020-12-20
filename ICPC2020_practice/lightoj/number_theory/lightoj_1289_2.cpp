#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define mod 4294967296
bitset<100000010>ck;
vector<unsigned int>prime(5761558),precal(5761558);
int cnt=0;
void seive()
{
    prime[cnt++]=2;
    int sq=sqrt(100000010);
    for(int i=3; i<=sq; i+=2)
    {
        if(!ck[i])
        {
            prime[cnt++]=i;
            for(int j=i*i; j<=100000010; j+=(2*i))
            {
                ck[j]=1;
            }
        }
    }
    if(sq%2==0)sq++;
    for(int j=sq; j<=100000008; j+=2)
    {
        if(!ck[j])
        {
            prime[cnt++]=j;
        }
    }
    //int siz=prime.size();
    precal[0]=2;
    for(int i=1; i<cnt; i++)
    {
        precal[i]=precal[i-1]*prime[i];
    }
}

int main()
{
    seive();
    //cout<<prime.size()<<" "<<precal.size()<<" siz\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    /// memory Calculation

    cout<<prime.size()<<" "<<precal.size()<<"  \n";
    int x=(sizeof(ck))/1000;
    int y=sizeof(unsigned int)*prime.size();
    y/=1000;
    int z=sizeof(unsigned int)*precal.size();
    z/=1000;
    cout<<(x+y+z)<<endl;


    int tcase=1;
    //cin>>tcase;
    scanf("%d",&tcase);
    for(int test=1; test<=tcase; test++)
    {
        int n;
        unsigned int ans=1;
        //cin>>n;
        scanf("%d",&n);
        int pos=upper_bound(prime.begin(),prime.begin()+cnt,n)-prime.begin();
        pos--;
        ans=precal[pos];
        int sq=sqrt(n+1);
        int siz=prime.size();
        for(int i=0; i<siz&&(int)prime[i]<=sq; i++)
        {
            int num=n;
            num/=prime[i];
            while(num>=prime[i])
            {
                num/=prime[i];
                ans*=prime[i];
            }
        }
        //cout<<"Case "<<test<<": "<<ans<<endl;
        printf("Case %d: %u\n",test,ans);
    }
    return 0;
}
