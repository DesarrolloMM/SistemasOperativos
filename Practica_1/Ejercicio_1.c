#pragma region Ejercicio 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

//funciones para comparar los elementos del arreglo
int compareAscendant(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int compareDescendant(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x < y) - (x > y);
}

int compareAscendantAbsolute(const void *a, const void *b){
    int x = abs(*(const int*)a);
    int y = abs(*(const int*)b);
    return (x > y) - (x < y);
}

int compareDescendantAbsolute(const void *a, const void *b){
    int x = abs(*(const int *)a);
    int y = abs(*(const int *)b);
    return (x < y) - (x > y);
}

//Acción dependiendo del puntero a funcion
void orden(int *arreglo, size_t size, int (*compare)(const void *, const void *)){
    qsort(arreglo, size, sizeof(int), compare);
}

int main(void){
    int ingreso[MAX];
    int numero, i, opcion = 0;

    printf("Ingrese una secuencia de numeros\n");

    for (i = 0; i < MAX; i++) {
        scanf("%d", &numero);
        ingreso[i] = numero;
    }

    do {
        printf("Como desea ordenar el arreglo?\n");
        printf("1-Ascendente\n");
        printf("2-Descendente\n");
        printf("3-Ascendente valor absoluto\n");
        printf("4-Descendente valor absoluto\n");
        printf("0-Salir\n");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida\n");
            return 1;
        }

        switch (opcion) {
            case 1:
                orden(ingreso, MAX, compareAscendant);
                break;
            case 2:
                orden(ingreso, MAX, compareDescendant);
                break;
            case 3:
                orden(ingreso, MAX, compareAscendantAbsolute);
                break;
            case 4:
                orden(ingreso, MAX, compareDescendantAbsolute);
                break;
            case 0:
                break;
            default:
                printf("Opcion no valida\n");
                continue;
        }

        if (opcion != 0) {
            printf("Arreglo ordenado:\n");

            for (i = 0; i < MAX; i++) {
                printf("%d\n", ingreso[i]);
            }
        }

    } while (opcion != 0);

    return 0;
}

#pragma endregion