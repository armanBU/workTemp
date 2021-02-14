//problem 1 : 1+2+3+4+.....+N
#include<stdio.h>
int main(){
    int n,sum=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=i;
    }
    printf("Sum is : %d\n",sum);
    return 0;
}
