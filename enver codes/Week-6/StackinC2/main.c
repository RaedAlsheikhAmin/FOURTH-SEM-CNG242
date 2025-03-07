#include <stdio.h>
#include"Mystack.h"
int main() {
    printf("Popping:%d\n",pop());
    int i;
    for(i=0;i<10;i++)
        push(i*i);
    top=2;
    push(1000);
    stckprint();
    return 0;
}
