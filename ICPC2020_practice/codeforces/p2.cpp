//problem 2 : 1^2 + 2^2 + 3^2+......+ N^2
#include<stdio.h>
int main(){
    int n,sum=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=(i*i);
    }
    printf("Sum is : %d\n",sum);
    return 0;
}
