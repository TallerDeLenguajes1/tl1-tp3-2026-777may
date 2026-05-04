// Git Branch <>, Checkout <> y Commit
// Git Merge y Git Rebase
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CantNombres 5

void MostrarPersonas(char* vector[]);
char* BuscaNombrePorPalabra(char* palabraClave, char* vector[]);
void BuscaNombrePorId(unsigned int ID, char* vector[]);
void InterfazInteractiva(char* vector[]);

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
    InterfazInteractiva(V);
    // BuscaNombrePorId(3,V);
    
    // printf("\nEl buscado es %s", BuscaNombrePorPalabra("mar", V));
    
    return 0;
}


void MostrarPersonas(char* vector[]){
    for (int i = 0; i < CantNombres; i++)
    {
        printf("El %d° nombre es: %s\n", i+1, vector[i]);
    }
    
    
}
char* BuscaNombrePorPalabra(char* palabraClave, char* vector[]){
    int tama = strlen(palabraClave)+1;
    //auxiliares para convertir copias en mayusculas
	char* auxPalabraClave = (char*) malloc(sizeof(char)*tama);
	char* auxVector;
    char letra;
    // Copia de palabra clave a mayusculas
    for (int i = 0; i < tama; i++)
    {
        auxPalabraClave[i] = toupper(palabraClave[i]);
    }
    //Busqueda en el texto
    for (int i = 0; i < CantNombres; i++)
    {
        //Auxiliar para convertir copia de vector[i] en mayusculas
        tama = strlen(vector[i])+1;
        auxVector = (char*) malloc(sizeof(char)*tama);
        //Copia de vector[i] a mayusculas
        for (int j = 0; j < tama; j++)
        {
            auxVector[j] = toupper(vector[i][j]);
        }
        //Compara los textos en mayusculas
        auxVector = strstr(auxVector, auxPalabraClave);
        if (auxVector != NULL) 
        {
            //Si la palabra clave es inicio de cadena
            letra = vector[i][auxVector-vector[i]-1]; // Palabra del vector, posicion del texto encontrado - posicion de la palabra
            if (letra == ' '|| letra ==  vector[i][-1])
            {
                return vector[i];
            }
        } 
    }
    return "-1";    
}
void BuscaNombrePorId(unsigned int ID, char* vector[]){
    if (ID < CantNombres)
    {
        printf("\nEl nombre del ID \"%d\" es: \"%s\".", ID, vector[ID]);
    }else{
        printf("\nNo se encontro el ID \"%d\".\n", ID);
    }
    
    
}
void InterfazInteractiva(char* vector[]){
    int aux = 0;
    char texto[100];
    char auxTxt[100];

    while (aux != 1 && aux != 2)
    {
        printf("\nBusqueda de nombres: \n    Marque \"1\" para buscar por ID o \"2\" para buscar por palabra clave.\n");
        scanf("%d",&aux);
        fflush(stdin);
    }
    
    switch (aux)
    {
    case 1:
        printf("\nIngrese el numero de ID a buscar:\n");
        fflush(stdin);
        scanf("%d",&aux);
        while (aux < 0)
        {
            printf("\nNumero de ID invalido, pruebe nuevamente.\n");
            scanf("%d",&aux);
        }
        BuscaNombrePorId(aux, vector);
        break;
    case 2:
        printf("\nIngrese la palabra clave a buscar:\n");
        fflush(stdin);
        gets(texto);
        strcpy(auxTxt, BuscaNombrePorPalabra(texto, vector));
        if (strcmp(auxTxt,"-1") == 0)
        {
            printf("\nNo se ha encontrado nombre con la palabra clave \"%s\".\n", texto);
        }else{
            printf("\nSe ha encontrado el nombre: \"%s\" relacionado con la palabra clave \"%s\".\n", auxTxt, texto);
            
        }
    default:
    break;
}
// // //! cambiar antes de commit
// //     InterfazInteractiva(vector);
}
