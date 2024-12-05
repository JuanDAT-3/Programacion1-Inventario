#include <stdio.h>
#include <string.h>
#include "inventario.h"

// Programa de Inventario de 25 objetos

//Main

int main(){
    
    int indice, opcion;
    
    while (1) {
        
        //Menú de opciones
        printf("\n    MENU INVENTARIO   \n");
        printf("1. Mostrar Inventario\n");
        printf("2. Agregar item\n");
        printf("3. Eliminar item\n");
        printf("4. Modificar item\n");
        printf("5. Salir\n");
        
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();
        
        //Ejecución
        switch(opcion){
            case 1:
                Mostrar();
                break;
            
            case 2:
                if(num_items >= item_maximo){
                    printf("Inventario lleno.");
                }
                else{
                    Agregar();
                }
                break;
                
            case 3:
                Mostrar();
                
                //Validación de indice
                do{
                    printf("Ingresa el ID del item a eliminar:\n");
                    scanf("%d", &indice);
                    getchar();
                    
                    if(indice < 0 || indice >= num_items){
                        printf("Indice inválido, Número entre 0 y %d\n",num_items-1);
                    }
                    else{
                        break;
                    }
                }while(1);
                //
               
                Eliminar(indice);
                break;
                
            case 4:
                Mostrar();
                
                //Validación de indice
                
                if(num_items == 0){
                    printf("Inventario Vacio\n");
                    break;
                }
                else{
                    do{
                        printf("Ingresa el ID del item a Modificar:\n");
                        scanf("%d", &indice);
                        getchar();
                        
                        if(indice < 0 || indice >= num_items){
                            printf("Indice inválido, Número entre 0 y %d\n",num_items-1);
                        }
                        else{
                            break;
                        }
                    } while(1);
                }//
                
                Modificar(indice);
                break;
                
            case 5:
                printf("Programa Terminado.");
                return 0;
                
            default:
                printf("Opción Invalida\n");
            
        }
    }
    return 0;
}
