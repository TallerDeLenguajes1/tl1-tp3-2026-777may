// Git Branch <>, Checkout <> y Commit
// Git Merge y Git Rebase
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>

#define CantNombres 5

void MostrarPersonas(char* vector[]);
char* BuscarNombre(char* palabraClave, char* vector[]);

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
    // printf("\nEl buscado es %s", BuscarNombre("mar", V));
    
    return 0;
}
void MostrarPersonas(char* vector[]){
    for (int i = 0; i < CantNombres; i++)
    {
        printf("El %d° nombre es: %s\n", i+1, vector[i]);
    }
    
}
char* BuscarNombre(char* palabraClave, char* vector[]){
    for (int i = 0; i < CantNombres; i++)
    {
        if (strstr(vector[i], palabraClave) != NULL) 
        {
            return vector[i];
        }
        
    }
    return "-1";    
}