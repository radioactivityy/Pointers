#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 100

void histogram(int *array,int len, int n, int p, char location){
    if(location=='h'){
        if(len == 0){
            for (int i = n; i < n+9; i++)
            {
                printf("%d \n", i);
            }
            
        }
        else{
        for(int i=0;i<9;i++){
            printf("%d ",n+i);
            for (int j = 0; j < array[i]; j++)
            {
                printf("# ");
            }
            printf("\n");
            
        }
        if(p != 0){
            printf("invalid: ");
        for (int i = 0; i < p; i++)
        {
           printf("#");
        }
        }
        
        }
        
    }
    else if(location == 'v'){
        int max = array[0];
       
        for (int i = 1; i < 9; i++)
        {
            if(array[i]>max){
                max = array[i];
                
            }
        }
        if(p > max){
            max = p;
         
        }
        int tmpMax=max;
        for (int j = 0; j < max; j++)
        {
         
        if(p>=tmpMax){
            printf("#");
        }
        else{
            printf(" ");
        }
        for (int i = 0; i < 9; i++)
        {
            if(array[i]>=tmpMax){
                printf("#");
            }else{
                printf(" ");
            }
            
        }
        tmpMax--;
        printf("\n");
        }
        printf("i");
        for (int i = 0; i < 9; i++)
    {
        printf("%d",n+i);
    }
    
        }

    else{
        printf("Invalid mode");
    }
    
}
int storing(int *array,int *array2, int len, int n){
    int invalid=0;
    for (int i = 0; i < 9; i++)
    {
        array2[i]=0;
    }
    
     int number;
    for (int i = 0; i < len; i++) {
        // Process the number directly without storing it in the array
        scanf("%d", &number);

        if (number >= n && number <= (n + 8)) {
            array2[number - n]++;
        } else {
            invalid++;
        }
    }
    return invalid;
}
int main(){
    char c;
    int a, b;
    scanf("%c", &c);
    if(c=='h'||c=='v'){
        scanf("%d%d", &a,&b);
    
    }
    int array[MAX_SIZE];  // Define the array here
    int r[9];
    int invalid; 
    invalid=storing(array, r, a, b);
    
    histogram(r, a, b, invalid ,c);

    return 0;
}
