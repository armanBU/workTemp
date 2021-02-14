#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define mp pair<ll,ll>
#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d %d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sfu(n) scanf("%llu", &n)
#define sffl(n, m) scanf("%lld %lld",&n,&m)
#define pfn(n) printf("%d\n",n)
#define pf(n) printf("%d ",n)
#define pfl(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define pb push_back
#define pi 3.1415926536
#define vst(v) sort(v.begin(),v.end())
#define fori(n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
int dx[]={0,0,1,1};
int dy[]={1,1,0,0};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int>v,v2,v3;
vector<int> :: iterator it1,it2;
int main()
{
    ///freopen("input.txt","r",stdin);
    ///while(1){
    int n,cntl=0,cntu=0,cntd=0;
    sf(n);
    string s;
    for(int j=0;j<n;j++){
            cntl=cntu=cntd=0;
        cin>>s;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]>96){
                cntl++;continue;}
            else if(s[i]>55){
                cntu++;continue;}
            else
                cntd++;
        }
        for(int i=0;s[i]!='\0';i++){
            if(!cntl){
                if(s[i]>64&&cntu>1){
                    s[i]='a';cntl=1;}
                else if(s[i]<64&&cntd>1){
                    s[i]='a';cntl=1;}
            }
            if(!cntu){
                if(s[i]>96&&cntl>1){
                    s[i]='A';cntl=1;}
                else if(s[i]<64&&cntd>1){
                    s[i]='A';cntu=1;}
            }
            if(!cntd){
                if(s[i]>96&&cntl>1){
                    s[i]='1';cntd=1;}
                else if(s[i]>64&&cntu>1){
                    s[i]='1';cntd=1;}
            }
        }
        cout<<s<<endl;
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
