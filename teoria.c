#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    int largoNombre;
    char buff[50];
    for (int i = 0; i < 5; i++)
    {
        printf("nombre estudiante %d", i);
        scanf("%s", buff);
        largoNombre = strlen(buff);
        nombreAlumno[i] = (char*)malloc(sizeof(char)*largoNombre);
        strcpy(nombreAlumno[i], buff);
        free(nombeAlumno);
    }
    
    return 0;
}
