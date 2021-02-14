3)a)
#include<stdio.h>
int main()
{
    int i;
    for(i=1;i<=50;i++)
    {
        if(i%2==0&&i%4==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
Output is: 4 8 12 16 20 24 28 32 36 40 44 48




