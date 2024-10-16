#include <stdio.h>
#include <stdlib.h>

int main(){

    char c;
    long long  right,left;
    

    do{
        printf("Please enter the cost of going left:");
        
        if (scanf("%lld%c", &left,&c) == EOF)
        {
            printf("Terminated.");
            return 0;
        }else{
            if(c == '\n')
            {
                printf("Please enter the cost of going right:");

                if (scanf("%lld%c", &right, &c) == 2 && c == '\n'){
                    if(left<=right){
                        printf("Go left!\n");
                    }
                    else{
                        printf("Go right!\n");
                    }
                }else{
                    printf("No right cost provided.");
                    return 1;
                    }

            }else{
                return 1;
                }
    }
    }while(1);
    
    return 0;
}
