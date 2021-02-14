//problem 3 : 1+ 1/2+1/3+1/4+......+1/N
#include<stdio.h>
int main(){
    int n,i;
    double sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        double temp=i;
        sum+=(1.0/temp);
    }
    printf("Sum is : %.2lf\n",sum);
    return 0;
}
