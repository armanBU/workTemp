#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define mod 4294967296
bitset<100000010>ck;
vector<unsigned int>prime;
vector<unsigned int>precal;
void seive()
{
    prime.PB(2);
    int sq=sqrt(100000010);
    for(int i=3; i<=sq; i+=2)
    {
        if(!ck[i])
        {
            prime.PB(i);
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
            prime.PB(j);
        }
    }
    int siz=prime.size();
    precal.PB(2);
    for(int i=1; i<siz; i++)
    {
        precal.PB(precal[i-1]*prime[i]);
    }
}
int main()
{
    seive();
    /// memory Calculation
    /*
    cout<<prime.size()<<" "<<precal.size()<<"  \n";
    int x=(sizeof(ck))/1000;
    int y=sizeof(unsigned int)*prime.size();
    y/=1000;
    int z=sizeof(unsigned int)*precal.size();
    z/=1000;
    cout<<(x+y+z)<<endl;
    */


    int tcase=1;
    cin>>tcase;
    for(int test=1; test<=tcase; test++)
    {
        int n;
        unsigned int ans=1;
        cin>>n;
        int pos=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        pos--;
        if(pos>=0)
            ans=precal[pos];
        int sq=sqrt(n+1);
        int siz=prime.size();
        for(int i=0; i<siz&&prime[i]<=sq; i++)
        {
            int paici=0;
            int num=n;
            while(num>=prime[i])
            {
                num/=prime[i];
                if(paici>0)
                {
                    ans*=prime[i];
                }
                paici=1;
            }
        }
        cout<<"Case "<<test<<": "<<ans<<endl;
    }
    return 0;
}
