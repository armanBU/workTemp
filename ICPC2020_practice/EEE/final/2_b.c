#include <stdio.h>
int main()
{
    int i;
    for(i=1; i<30; i++)
    {
        if(i%6==0)
        {
            printf("\nSkipping %d from display using continue statement\n",i);
            continue;
        }
        if(i>20)
        {
            printf("\nEnding loop for i=%d using break statement\n",i);
            break;
        }
        printf("%d ",i);
    }
    return 0;
}
2)b)
output of the following program is :

1 2 3 4 5
Skipping 6 from display using continue statement
7 8 9 10 11
Skipping 12 from display using continue statement
13 14 15 16 17
Skipping 18 from display using continue statement
19 20
Ending loop for i=21 using break statement
