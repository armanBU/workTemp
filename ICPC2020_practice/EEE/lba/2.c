2)
#include<stdio.h>
int main(){
    int n;
    printf("Please enter your percent: ");
    scanf("%d",&n);
    if(n>=80){
        printf("Grade: A\n");
        printf("Grade Point: 4\n");
        printf("Division or Class: Distinction\n");
    }
    else if(n>=60){
        printf("Grade: A-\n");
        printf("Grade Point: 3.7\n");
        printf("Division or Class: First Division\n");
    }
    else if(n>=55){
        printf("Grade: B+\n");
        printf("Grade Point: 3.3\n");
        printf("Division or Class: Second Division, Upper\n");
    }
    else if(n>=50){
        printf("Grade: B-\n");
        printf("Grade Point: 2.7\n");
        printf("Division or Class: Second Division, Lower\n");
    }
    else if(n>=33){
        printf("Grade: C\n");
        printf("Grade Point: 2\n");
        printf("Division or Class: Third Class\n");
    }
    else{
        printf("Grade: F\n");
        printf("Grade Point: 0\n");
        printf("Division or Class: Fail\n");
    }
    return 0;
}


