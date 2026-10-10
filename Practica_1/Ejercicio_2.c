#pragma region Ejercicio_2

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}


int main (){
    int ingreso[MAX];
    int numero, i, numeroBuscar = 0;

    size_t nroElementos = sizeof(ingreso) /sizeof(ingreso[0]);

    printf("Ingrtese una secuencia de numeros\n");

    for ( i = 0; i < MAX; i++)
    {
        scanf("%d", &numero);
        ingreso[i] = numero;
    }

    qsort(ingreso, nroElementos, sizeof(ingreso[0]), compare);

    printf("Arreglo Ordenado de manera ascendente: \n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", ingreso[i]);
    }
    
    printf("Ingrese un valor para buscar dentro del arreglo: \n");
    scanf("%d", &numeroBuscar);

    int *resultado = (int *)bsearch(&numeroBuscar, ingreso, nroElementos, sizeof(int), compare);

    if(resultado != NULL){
        printf("El núnmero %d fue encontrado con exito\n", numeroBuscar);
    }
    else{
        printf("El número %d no se encontró en el array\n", numeroBuscar);
    }

    return 0;
}


#pragma endregion