#include <stdio.h>
#include <stdbool.h>
void imprimirFibonacci(int n) {
    int t1 = 0, t2 = 1, siguiente;

    printf("Serie de Fibonacci:\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        siguiente = t1 + t2;
        t1 = t2;
        t2 = siguiente;
    }
    printf("\n");
}

int main() {
    int n;
    char cont;
    bool continuar=true;
    do
    {
         printf("Ingrese el número de términos: ");
    scanf("%d",&n);

    if (n <= 0) {
        printf("Por favor, ingrese un número positivo.\n");
        continuar=false;
    } else {
        imprimirFibonacci(n);
    }
    while (getchar() != '\n');
    printf("¿volver a ejecutar?(y/n)");
    scanf("%c",&cont);
    if (cont!='y')
    {
        continuar=false;
    }
    
    } while (continuar);
    return 0;
   
}
