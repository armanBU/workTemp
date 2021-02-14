#include<stdio.h>
int main(){
    char imran[6][8]={{'a','b','c','d','e','f','g','h'},
                      {'i','j','k','l','m','n','o','p'},
                      {'a','b','c','d','e','f','g','h'},
                      {'i','j','k','l','m','n','o','p'},
                      {'a','b','c','d','e','f','g','h'},
                      {'i','j','k','l','m','n','o','p'}
                     };
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<8;j++){
            printf("%c ",imran[i][j]);
        }
        printf("\n");
    }
    return 0;
}
