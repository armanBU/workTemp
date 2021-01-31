//Problem 4 : 1/1! + 2/2! + 3/3!+4/4!+.......+N/N!
#include<stdio.h>

int main(){
    int n,i;
    double sum=0;
    int factorial[20];
    scanf("%d",&n);
    factorial[1]=1;
    for(i=2;i<=n;i++){
        factorial[i]=i*factorial[i-1];
    }
    for(i=1;i<=n;i++){
        double fact=factorial[i];
        sum+=(1.0/fact);
    }
    printf("Sum is : %.2lf\n",sum);
    return 0;
}

