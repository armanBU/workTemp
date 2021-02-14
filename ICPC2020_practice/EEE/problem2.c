#include<stdio.h>
int main(){
    float imran[4][3]={{1.1,2.2,3.3},
                      {1.1,2.2,3.3},
                      {1.1,2.2,3.3},
                      {1.1,2.2,3.3}
                     };
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%.2f ",imran[i][j]);
        }
        printf("\n");
    }
    return 0;
}
