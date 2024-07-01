#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char peliculas[20][4][40] = {0};
    double precio[3] = {7, 3.5, 3};
    char clientes[5][2][40] = {0};
    int reserva[10][4] = {-1};

    // Nombres de los archivos
    const char* archivoPeliculas = "peliculas.txt";
    const char* archivoClientes = "clientes.txt";
    const char* archivoReservas = "reservas.txt";

    // Cargar datos desde archivos
    cargarPeliculasDesdeArchivo(peliculas, archivoPeliculas);
    cargarClientesDesdeArchivo(clientes, archivoClientes);
    cargarReservasDesdeArchivo(reserva, archivoReservas);

    int opcion1 = 0, opcion2 = 0, opcion3 = 0;
    do {
        printf("Escoja una opcion:\n1.Ingresar Cliente\n2.Ver Peliculas\n3.Buscar Pelicula\n4.Comprar Ticket\n5.Ver Compras\n>>");
        scanf("%d", &opcion2);
        switch (opcion2) {
            case 1:
                ingresarCliente(clientes);
                guardarClientesEnArchivo(clientes, archivoClientes);
                break;
            case 2:
                listarPeliculas(peliculas);
                guardarPeliculasEnArchivo(peliculas, archivoPeliculas);
                break;
            case 3:
                printf("1.Por nombre\n2.Por Genero\n>>");
                scanf("%d", &opcion3);
                switch (opcion3) {
                    case 1:
                        buscarporNombre(peliculas);
                        break;
                    case 2:
                        buscarporGenero(peliculas);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                comprarTicket(peliculas, precio, clientes, reserva);
                guardarReservasEnArchivo(reserva, archivoReservas);
                break;
            case 5:
                verCompras(peliculas, precio, clientes, reserva);
                break;
            default:
                break;
        }
        printf("Desea escoger una nueva opcion: 1.Si/2.No\n>>");
        scanf("%d", &opcion1);
    } while (opcion1 == 1);

    // Guardar datos en archivos
    guardarPeliculasEnArchivo(peliculas, archivoPeliculas);
    guardarClientesEnArchivo(clientes, archivoClientes);
    guardarReservasEnArchivo(reserva, archivoReservas);

    // Llamada a la función para calcular el costo total
    calcularCostoTotal(precio, reserva);

    return 0;
}
