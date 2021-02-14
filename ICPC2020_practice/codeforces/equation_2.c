/*
    id : 200116485
*/
#include<stdio.h>
#include<math.h>
int main(){
    int x,y,h;
    double Z,a,b,c;
    scanf("%d%d%d",&x,&y,&h);
    a=x+y+(3*h);
    b=5*a;
    c=b/4;
    Z=sqrt(c);
    printf("%.2lf\n",Z);
    return 0;
}

