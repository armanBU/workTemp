#include<stdio.h>
int main ()
{
    int x[2][2]={{1,2},{2,3}};
    int n;
    printf("Please enter your birth year: ");
    scanf("%d",&n);
    if(n>=1936 && n<=1945)
    {
        printf("Birth Year Range: 1936-1945\n");
        printf("Age Group Name: Pre Baby Room\n");
    }
    else if(n>=1946 && n<=1955)
    {
        printf("Birth Year Range: 1946-1955\n");
        printf("Age Group Name: Classic Baby Room\n");
    }
    else if(n>=1956 && n<=1965)
    {
        printf("Birth Year Range: 1956-1965\n");
        printf("Age Group Name: Late Baby Room\n");
    }
    else if(n>=1966 && n<=1975)
    {
        printf("Birth Year Range: 1966-1975\n");
        printf("Age Group Name: Genaration X\n");
    }
    else if(n>=1976 && n<=1985)
    {
        printf("Birth Year Range: 1976-1985\n");
        printf("Age Group Name: Pre Millennials\n");
    }
    else if(n>=1986 && n<=1995)
    {
        printf("Birth Year Range: 1986-1995\n");
        printf("Age Group Name: Millennials\n");
    }
    return 0;
}
