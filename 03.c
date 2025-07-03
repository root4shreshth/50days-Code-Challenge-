#include <stdio.h>
#include <string.h>

int main(){
    int size, a , num;
    int output = 0;

    scanf("%d", &size);

    for(a=0; a< size; a++){
        scanf("%d",&num);
        output = output ^ num;
    }

    printf("%d\n", output);
    return 0;
}