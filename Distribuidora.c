#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MaxClientes 5
#define MaxProductos 10


//*Producto
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;
//

//*Cliente
    typedef struct  {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de //*@var CantidadProductosAPedir *// 
    }Cliente;
//
float costoTotalDeUnProducto(Producto prod);
Cliente* crearCliente(int cantidad);
void cargarCliente(Cliente* lista, int tama);
void cargarProducto(Producto* lista, int tama, int ultimoID);
void mostarTodo(Cliente* listaClientes, int cantClientes);


int main()
{
    int cantidadDeClientes = 1;
    while (cantidadDeClientes!= 0)
    {
        //Trabajar con los clientes
        srand(time(NULL));
        //Solicitar numero valido de clientes
        printf("Bienvenido.\n Porfavor ingrese la cantidad de clientes:\n");
        scanf("%d", &cantidadDeClientes);
        while (cantidadDeClientes>MaxClientes || cantidadDeClientes<0)
        {
            printf("Numero invalido, porfavor ingrese la cantidad de clientes:\n");
            scanf("%d", &cantidadDeClientes);
        }
        //Crear y cargar los clientes
        Cliente* clientes = crearCliente(cantidadDeClientes);
        cargarCliente(clientes, cantidadDeClientes);
        mostarTodo(clientes, cantidadDeClientes);
    }
    //Fin del programa
    printf("Adios.");
    return 0;
}


void mostarTodo(Cliente* listaClientes, int cantClientes){
    Cliente auxC;
    Producto auxP;
    float totalAPagar, totalProducto;
    for (int i = 0; i < cantClientes; i++)
    {
        totalAPagar = 0;
        auxC = listaClientes[i];
        printf("\n------------------------------------------------------------------------------------------\n");
        printf("\nCliente n° %d, ID: %d, Nombre: %s", i+1, auxC.ClienteID, auxC.NombreCliente);
        printf("\nEl cliente lleva %d productos: \n", auxC.CantidadProductosAPedir);
        for (int j = 0; j < auxC.CantidadProductosAPedir; j++)
        {
            auxP = auxC.Productos[j];
            totalProducto = costoTotalDeUnProducto(auxP);
            printf("  %d  %s por %d unidades, ID del producto %d\n", j+1 , auxP.TipoProducto, auxP.Cantidad, auxP.ProductoID);
            printf("      Precio por unidad: %.3f, total del producto: %.3f\n\n", auxP.PrecioUnitario, totalProducto);
            totalAPagar += totalProducto;
        }
        
        printf("        -- El total a pagar por el cliente es: %.3f -- \n\n", totalAPagar);
    }
}
void cargarProducto(Producto* lista, int tama, int ultimoID){
    //Recibe una lista de productos y crea y/o carga sus atributos
    int cantidad;
    int aux;
    for (int i = 0; i < tama; i++)
    {
        //ID numerado en ciclo iterativo teniendo en cuenta que no se repita entre clientes
        lista[i].ProductoID = ultimoID + i + 1;
        //Cantidad aleatoria
        cantidad = 1 + rand() % MaxProductos;
        lista[i].Cantidad = cantidad;
        //Reservar y asignar memoria para tipo de producto aleatorio del 0 al 4
        aux = rand() % 5;
        cantidad = strlen(TiposProductos[aux]) + 1;
        lista[i].TipoProducto = (char*) malloc(sizeof(char)*cantidad);
        strcpy(lista[i].TipoProducto, TiposProductos[aux]);
        //Asignar un precio float por unidad entre 10 a 100
        cantidad = 10 + rand() % 100-10 +1;
        aux = 0;
            //Si el precio no es el maximo, entonces agregamos decimales
            if (cantidad != 100)
            {
                aux = rand() % 1000;
            }
            //
        lista[i].PrecioUnitario = (float)aux/1000 + cantidad;
        //
    }
    //
}
void cargarCliente(Cliente* lista, int tama){
    //Recive una lista de clientes y crea y/o carga sus atributos
    char Buff[100];
    int cantidad;
    int IDProducto = -1;
    for (int i = 0; i < tama; i++)
    {
        //ID ciclo iterativo
        lista[i].ClienteID = i;
        //Cantidad de productos aleatoria
        cantidad = 1 + rand() % 5;
        lista[i].CantidadProductosAPedir = cantidad;
        //Crear y cargar lista de productos segun su cantidad
        lista[i].Productos = (Producto*) malloc(sizeof(Producto)* cantidad);
        cargarProducto(lista[i].Productos, cantidad, IDProducto);
        IDProducto += cantidad;
        //Ingreso nombre de cliente
        printf("\nIngrese el nombre del %d° cliente:\n", i+1);
        fflush(stdin);
            //Si overflow entonces cierra todo
            if (!fgets(Buff, sizeof(Buff),stdin)){
                exit(1);
            };
            //
        lista[i].NombreCliente = (char*) malloc(sizeof(char)*strlen(Buff)+1);
        strcpy(lista[i].NombreCliente, Buff);
        //
    }
    //
}
Cliente* crearCliente(int cantidad){
    //Reserva de memoria para la lista de clientes
    Cliente* lista = (Cliente*) malloc(sizeof(Cliente)* cantidad);
    return lista;
}
float costoTotalDeUnProducto(Producto prod){
    return prod.Cantidad * prod.PrecioUnitario;
}