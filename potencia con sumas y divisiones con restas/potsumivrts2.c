#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int potsum(int, int);
int multi(int, int);
int division(int, int);

int potsum(int num, int n) {
    if (n == 0) {
        return 1;  
    } else {
        return multi(num, potsum(num, n - 1)); 
    }
}


int multi(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + multi(num1, num2 - 1);
    }
}
int division(int dividendo,int divisor){
    if ((dividendo-divisor)<0)
    {
        return 0;
    }
    else
    {
        return 1+division(dividendo-divisor,divisor);
    }
    
}

int main() {
    //

    printf("%d\n", potsum(2, 3));
    printf("%d\n",division(10,3));
    return 0;
}
