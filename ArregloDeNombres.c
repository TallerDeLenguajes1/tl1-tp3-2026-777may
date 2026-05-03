// Git Branch <>, Checkout <> y Commit
// Git Merge y Git Rebase
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CantNombres 5

void MostrarPersonas(char* vector[]);
void BuscarNombre(unsigned int ID, char* vector[]);

int main()
{
    char* V[CantNombres];
    char Buff[100];
    printf("Bienvenido, por favor ingrese los nombres de las personas.");
    for (int i = 0; i < CantNombres; i++)
    {
        printf("\nIngrese el %d° nombre: \n", i+1);
        gets(Buff);
        V[i] = (char*) malloc(sizeof(char)*strlen(Buff) +1);
        strcpy(V[i], Buff);
    }
    MostrarPersonas(V);
    // BuscarNombre(3,V);
    
    
    return 0;
}
void MostrarPersonas(char* vector[]){
    for (int i = 0; i < CantNombres; i++)
    {
        printf("El %d° nombre es: %s\n", i+1, vector[i]);
    }
    
}
void BuscarNombre(unsigned int ID, char* vector[]){
    if (ID < CantNombres)
    {
        printf("\nEl nombre del ID %d es: %s", ID, vector[ID]);
    }else{
        printf("\nNo se encontro el valor buscado.\n");
    }
    
    
}
