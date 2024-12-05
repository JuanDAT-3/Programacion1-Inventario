//Funciones 

#define item_maximo 25 // Maximo de Objetos en el Inventario 
#define item_longi 50 // Longitud maxima que puede contener el nombre del objeto.

//Definir estructura principal
struct Item{
    char nombre[item_longi];
    int cantidad;
    float precio;
};

//Array de Estructuras
struct Item inventario[item_maximo];

//Contador de items
int num_items = 0;


//     Funciones.
//Agregar items
void Agregar(){

    //Creación de item de ingreso
    struct Item nuevo_item;
    
    //Agregación
    //Nombre, Cantidad y Precio.
    printf("Ingrese el nombre del objeto:\n");
    fgets(nuevo_item.nombre, item_longi, stdin);
    nuevo_item.nombre[strcspn(nuevo_item.nombre, "\n")] = '\0';                       
    
    // Validación de cantidad
    do {
        printf("Ingrese la Cantidad: ");
        scanf("%d", &nuevo_item.cantidad);
        getchar();
        
        if(nuevo_item.cantidad <= 0) {
            printf("Error: La cantidad debe ser un número positivo.\n");
        } 
        else {
            break;
        }
    } while(1);
    
    // Validación de precio
    do {
        printf("Ingrese el precio: ");
        scanf("%f", &nuevo_item.precio);
        getchar();
        
        if(nuevo_item.precio <= 0) {
            printf("Error: El precio debe ser un número positivo.\n");
        } else {
            break;
        }
    } while(1);
    
    inventario[num_items] = nuevo_item;
    num_items++;
    
    printf("Item Agregado.\n");
}

//Eliminar Items.
void Eliminar(int indice){
    
    for (int i = indice; i < num_items - 1; i++){
        inventario[i] = inventario[i + 1];
    }
    num_items --;
    printf("Item Eliminado.\n");
}

//Modificar Items.
void Modificar(int indice){

    printf("Item a modificar: %s\n", inventario[indice].nombre);
    printf("Elije modificación: \n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar cantidad\n");
    printf("3. Modificar precio\n");
    
    int opcion;
    scanf("%d",&opcion);
    getchar();
    
    //Casos de modificación
    switch(opcion){
        case 1:
            printf("Ingresa el nuevo nombre: ");
            fgets(inventario[indice].nombre, item_longi, stdin);
            inventario[indice].nombre[strcspn(inventario[indice].nombre, "\n")] = '\0';
            break;
        
        case 2:
            do {
                printf("Ingresa la nueva cantidad: ");
                scanf("%d", &inventario[indice].cantidad);
                getchar();
                if(inventario[indice].cantidad <= 0) {
                    printf("Error: La cantidad debe ser un número positivo.\n");
                } 
                else {
                    break;
                }
            }while(1);
            break;
        
        case 3: 
            do {
                printf("Ingresa el nuevo precio: ");
                scanf("%f", &inventario[indice].precio);
                getchar();
                if(inventario[indice].precio <= 0) {
                    printf("Error: El precio debe ser un número positivo.\n");
                } 
                else {
                    break;
                }
            } while(1);
            break;
            
        default:
            printf("Opción Inválida\n");
            return;
            
    }
    
    printf("Item modificado.\n ");

}

//Mostrar inventario

void Mostrar(){
    //Asegurar Inventario
    if(num_items == 0){
        printf("Inventario Vacío.\n ");
        return;
    }
    
    //
    printf("INVENTARIO. \n");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < num_items; i++){
        printf("ID: %d | %s\n",i ,inventario[i].nombre);
        printf("    Cantidad: %d\n",inventario[i].cantidad);
        printf("    Precio: %.2f\n",inventario[i].precio);
    }
     printf("-----------------------------------------------------");
}