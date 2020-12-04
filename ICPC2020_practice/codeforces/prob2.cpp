#include<stdio.h>
int main()
{
    int i;
    for(i=0; i<100; i++)
    {
        if(i%6==0)
        {
            printf("Value of i: %d\n",i);
        }
    }
    return 0;
}
