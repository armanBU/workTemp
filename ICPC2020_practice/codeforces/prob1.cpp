#include<stdio.h>
int main(){
    int n;
    printf("Please Enter Your number: ");
    scanf("%d",&n);
    if(n>=80){
        printf("Letter Grade: A+\n");
        printf("Grade Point: 5\n");
    }
    else if(n>=70){
        printf("Letter Grade: A\n");
        printf("Grade Point: 4\n");

    }
    else if(n>=60){
        printf("Letter Grade: A-\n");
        printf("Grade Point: 3.5\n");
    }
    else if(n>=50){
        printf("Letter Grade: B\n");
        printf("Grade Point: 3\n");
    }
    else if(n>=40){
        printf("Letter Grade: C\n");
        printf("Grade Point: 2\n");

    }
    else if(n>=33){
        printf("Letter Grade: D\n");
        printf("Grade Point: 1\n");
    }
    else{
        printf("Letter Grade: F\n");
        printf("Grade Point: 0\n");
    }
    return 0;
}


