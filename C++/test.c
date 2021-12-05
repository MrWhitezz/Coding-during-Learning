#include<stdio.h>
int main(){
    char c, cc;
    while (c = getchar() != 'N')
    {
        putchar(c + '0');
    }
    
    return 0;

}