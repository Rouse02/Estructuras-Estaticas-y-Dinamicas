#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "strings.h"
#include "time.h"

#define DIM 30
#define CantidadDatosPila 100

/*Estructuras*/
typedef struct {
char nombreYapellido[DIM];
char genero;
int edad;
}Persona;

typedef struct {
int datos[CantidadDatosPila];
int posicionTope; //Posición de nuevo tope, lugar en donde se almacenará el nuevo valor. Actua como validos
}stPila;

typedef struct {
int matricula;
char nombreYapellido[DIM];
}Alumno;

typedef struct {
int codigoMateria;
char nombreMateria[DIM];
}Materia ;

typedef struct {
int matricula;
int codigoMateria;
int nota;
}Nota;

/*Prototipado*/
void menu();
void consignas();

void ejercicio1();
int cargarPersonasHasta(Persona personas[DIM]);
Persona cargarPersona();
int contabilizarRegistrosPorGenero(Persona *ptrPersonas, int cantidadRegistros, char genero);
Persona *copiaDePersonasPorGeneroDinamico(Persona *ptrPersonas, int cantidadPorGenero, int cantidadRegistros, char genero);

void ejercicio2();
void intercambiar(Persona *a, Persona *b);
void ordenarPorSeleccion(Persona *personas, int n);

void ejercicio3();
void inicializarPila(stPila *pila);
void apilar(stPila *pila);
int pedirDato();
void mostrar(stPila *pila);
void leer(stPila *pila);
int pilaVacia(stPila *pila);
void tope(stPila *pila);
void desapilar(stPila *pila);

void ejercicio4();
void ordenarPila(stPila *pila);
void intercalarDatosOrdenadosEnPila(stPila *ptr1, stPila *ptr2, stPila *ptr3);

void ejercicio5();
void insertarDatoOrdenadoEnVector(int vector[], int validos, int dato);

void ejercicio6();
void ordenamientoXinsercion(int vector[], int validos);

void ejercicio7();
int eliminarElementoVector(int vector[], int validos, int dato);

void ejercicio8();
int cargarAlumnoHasta(Alumno alumnos[]);
Alumno cargarAlumno();
void cargarArregloMateria(Materia materias[]);
void mostrarArregloDeMaterias(Materia materias[]);

void ordenamientoXseleccionArray(int vector[], int validos);
void posMenor(int *a, int *b);
/*--------------------------------------------------------------------------------------------------------*/
int main(){
srand(time(NULL));
menu();

}
/*--------------------------------------------------------------------------------------------------------*/
//Funciones

void menu() {
    char eleccion = 's';
    int ejercicio;

    consignas();

    do {
    printf("\nIngrese el Numero de ejercicio a dirigirse --> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");


    switch(ejercicio) {

    case 1:
        ejercicio1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio3();
        break;

    case 4:
        ejercicio4();
        break;

    case 5:
        ejercicio5();
        break;

    case 6:
        ejercicio6();
        break;

    case 7:
       ejercicio7();
        break;

    case 8:
        ejercicio8();
        break;

    default:
        printf("Has ingresado un numero incorrecto, vuelve a intentarlo \n\n");
        break;
        }

        printf("\nPulse 's' para ingresar a otro ejercicio --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's');
}

void consignas() {
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("1)Dada la Estructura de Persona:  \n\n");
    printf("        a)Crear un arreglo estatico de 30 elementos de esta estructura y cargarlo mediante una funcion.\n");
    printf("        b)Hacer una funcion que cuente la cantidad de un genero determinado.\n");
    printf("        c)Hacer una funcion que copie los datos de todos los registros de un genero determinado del arreglo anterior en otro arreglo del tamanio justo. Usar malloc dentro de la funcion y retornarlo o usar dos parametros de tipo arreglo y crear el arreglo dinamico antes de la invocacion.\n\n");
    printf("2)Codificar el algoritmo de ordenamiento por seleccion, sobre la estructura anterior teniendo en cuenta la edad como criterio de ordenacion \n\n");
    printf("3)Simular el uso de una pila de enteros a partir de la estructura. Implementar las siguientes funciones:\n\n");
    printf("        void apilar(Pila * p, int valor);\n");
    printf("        int desapilar(Pila * p);\n");
    printf("        int tope(Pila * p); \n");
    printf("        int pilavacia(Pila * p);\n");
    printf("        void mostrar(Pila * p);\n");
    printf("        void leer (Pila * p);\n");
    printf("        void inicPila(Pila * p);\n\n");
    printf("4)Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados, generar una tercer pila que contenga los datos de las dos anteriores intercalados, de forma tal que queden ordenados.\n\n");
    printf("5)Funcion insertar orden en un arreglo\n\n");
    printf("6)Algoritmo de ordenamiento por insercion\n\n");
    printf("7)Funcion eliminar un elemento de un arreglo.(ver por desplazamiento si es ordenado)\n\n");
    printf("8)Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5 materias diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen final de cada materia.\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

//Ejercicios

void ejercicio1() {
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 1 \n\n");

    Persona personas[DIM];
    char genero;

    int cantidadRegistros = cargarPersonasHasta(personas);
    printf("Has cargado en sistema %i registro/s \n\n", cantidadRegistros);

    Persona *ptrPersonas = &personas;

    printf("Ingrese el genero que desea contabilizar (M/F/O) --> ");
    fflush(stdin);
    scanf("%c", &genero);
    printf("\n");

    int cantidadPersonasPorGenero = contabilizarRegistrosPorGenero(ptrPersonas, cantidadRegistros, genero);
    printf("Se contabilizaron %i personas del genero %c \n", cantidadPersonasPorGenero, genero);

    Persona *copiaPersonasPorGenero = copiaDePersonasPorGeneroDinamico(ptrPersonas, cantidadPersonasPorGenero, cantidadRegistros, genero);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void ejercicio2() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 2 \n\n");

    Persona people[DIM];

    int cantidadRegistros = cargarPersonasHasta(people);
    printf("Has cargado en sistema %i registro/s \n\n", cantidadRegistros);

    Persona *ptrPersonas = &people;

    int tamanio = sizeof(ptrPersonas) / sizeof(ptrPersonas[0]); //Tamanio del arreglo de personas

    ordenarPorSeleccion(ptrPersonas, tamanio);

    printf("\nPersonas ordenadas por edad:\n");

    for (int i = 0; i < cantidadRegistros; i++) {
        printf("Nombre y Apellido: %s \n", ptrPersonas[i].nombreYapellido);
        printf("Edad: %i \n", ptrPersonas[i].edad);
        printf("Genero: %c \n", ptrPersonas[i].genero);
        printf("\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------\n");

}

void intercambiar(Persona *a, Persona *b) {

    Persona temporal = *a;
    *a = *b;
    *b = temporal;
}

void ordenarPorSeleccion(Persona *personas, int n) {

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (personas[j].edad < personas[minIndex].edad) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            intercambiar(&personas[i], &personas[minIndex]);
        }
    }
}

void ejercicio3() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 3 \n \n");

    stPila pila;
    stPila *ptrPila = &pila; //Declaración del Puntero a la Estructura de Tipo Pila

    inicializarPila(ptrPila);

    apilar(ptrPila);

    mostrar(ptrPila);

    leer(ptrPila);

    mostrar(ptrPila);

    tope(ptrPila);

    int verificacion = pilaVacia(ptrPila);

    if(verificacion == 1) printf("\nLa Pila esta vacia \n");

    else printf("\nLa Pila no esta vacia \n");

    desapilar(ptrPila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void desapilar(stPila *pila) {

    pila->datos[pila->posicionTope] = - 1;

    pila->posicionTope--;

    printf("\nDato desapilado con exito \n");
}

void tope(stPila *pila) {

    printf("\nTope --> %i\n", pila->datos[pila->posicionTope]);
}

void inicializarPila(stPila *pila) {

    pila->posicionTope = - 1; //Inicializamos la Posición del tope en -1, para indicar que la Pila está vacía

    for(int i = 0; i < CantidadDatosPila; i++) pila->datos[i] = 0; //Inicializamos todos los valores dela Pila en 0

    //Debug
    //for(int i = 0; coint < CantidadDatosPila; i++) printf("Index Nro %i|%i| \n",i, pila->datos[cont]);
}

void apilar(stPila *pila) {

    if(pila->posicionTope < 99) {//Verificamos que la pila no este llena

    pila->posicionTope ++; //Incremento en uno ya que previamente lo inicializamos en -1
    pila->datos[pila->posicionTope] = pedirDato(); //En el arreglo, apilamos en la posición de "PosicionTope", estamos utilizando los miembros de manera simultanea

    }else printf("La Pila esta llena \n");
}

int pedirDato() {

    int dato;
    printf("Ingrese un dato a Apilar --> ");
    fflush(stdin);
    scanf("%i", &dato);
    printf("\n");

    return dato;
}

void mostrar(stPila *pila) {

    printf("TOPE\n");
    for(int i = pila->posicionTope; i >= 0; i--) printf("|%d|\n", pila->datos[i]); //Utilizo i como variables Auxiliar así no se mueve el bloque de memoria y pierde la referencia
    printf("BASE\n");
}

void leer(stPila *pila) {

    int dato;
    printf("\nIngrese un dato a Apilar --> ");
    fflush(stdin);
    scanf("%i", &dato);
    printf("\n");

    pila->posicionTope++;
    pila->datos[pila->posicionTope] = dato;
}

int pilaVacia(stPila *pila) {

    if(pila->posicionTope == -1) return 1;

    else return 0;
}

void ejercicio4() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 4 \n\n");

    int validosPila;
    stPila pila1;

    stPila *ptrPila1 = &pila1;
    inicializarPila(ptrPila1); //Declaración e inicializacion de Pila1

    stPila pila2;
    stPila *ptrPila2 = &pila2;
    inicializarPila(ptrPila2);//Declaración e inicializacion de Pila2

    stPila pila3;
    stPila *ptrPila3 = &pila3;

    /*Cargamos Pila1----------------------------------------------------------------------------------*/
    printf("Ingrese la cantidad de datos a cargar en Pila1 --> ");
    fflush(stdin);
    scanf("%i", &validosPila);
    printf("\n");
    for(int i = 0; i < validosPila; i++) apilar(ptrPila1);
    /*Cargamos Pila2----------------------------------------------------------------------------------*/
    printf("Ingrese la cantidad de datos a cargar en Pila2 --> ");
    fflush(stdin);
    scanf("%i", &validosPila);
    printf("\n");
    for(int i = 0; i < validosPila; i++) apilar(ptrPila2);
     /*------------------------------------------------------------------------------------------------*/
    printf("Pila1: \n");
    mostrar(ptrPila1);
    printf("\n");                   //Mostrando ambas Pilas cargadas
    printf("Pila2: \n");
    mostrar(ptrPila2);
    printf("\n");

    printf("Ordenando Pila1\n");
    ordenarPila(ptrPila1);
                                    //Ordenando pilas
    printf("Ordenando Pila2\n");
    ordenarPila(ptrPila2);

    intercalarDatosOrdenadosEnPila(ptrPila1, ptrPila2, ptrPila3);
    ordenarPila(ptrPila3);
    printf("\nMostrando Pila 3 \n");
    mostrar(ptrPila3);
    printf("\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void intercalarDatosOrdenadosEnPila(stPila *ptr1, stPila *ptr2, stPila *ptr3) {
    inicializarPila(ptr3);

    while(pilaVacia(ptr1) == 0 && pilaVacia(ptr2)  == 0) { //Verifico que las pilas no estén vacias

        if(ptr1->datos[ptr1->posicionTope] < ptr2->datos[ptr2->posicionTope]) {
            ptr3->posicionTope++;
            ptr3->datos[ptr3->posicionTope] = ptr1->datos[ptr1->posicionTope];
            ptr1->posicionTope--;
        }
        else {
            ptr3->posicionTope++;
            ptr3->datos[ptr3->posicionTope] = ptr2->datos[ptr2->posicionTope];
            ptr2->posicionTope--;
        }
    }

    while(pilaVacia(ptr1) == 0) { //Verificamos si quedaron datos en Pila 1

        if((pilaVacia(ptr1) == 0)) {//Verificamos nuevamente, ya que si no hay un dato, almacenará 0
        ptr3->posicionTope++;
        ptr3->datos[ptr3->posicionTope] = ptr1->datos[ptr1->posicionTope];
        ptr1->posicionTope--;
        }
    }

    while(pilaVacia(ptr2) == 0) { //Verificamos si quedaron datos en Pila 2

        if((pilaVacia(ptr2) == 0)) { //Verificamos nuevamente, ya que si no hay un dato, almacenará 0
        ptr3->posicionTope++;
        ptr3->datos[ptr3->posicionTope] =  ptr2->datos[ptr2->posicionTope];
        ptr2->posicionTope--;
        }
    }
}
void ordenarPila(stPila *pila) {

    int n = pila->posicionTope + 1;// Obtener la cantidad de elementos en la pila

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (pila->datos[j] < pila->datos[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) { // Intercambiar elementos de la pila usando punteros
            int temp = pila->datos[i];
            pila->datos[i] = pila->datos[minIndex];
            pila->datos[minIndex] = temp;
        }
    }
}

void ejercicio5() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 5\n\n");

    srand(time(NULL));
    int vector[DIM];
    int validos;

    printf("Ingrese la cantidad de datos a cargar de manera aleatoria en el Vector --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");


    for(int i = 0; i < validos; i++) vector[i] = rand()% 100 + 1;

    printf("Mostrando Vector cargado y ordenado --> ");
    ordenamientoXseleccionArray(vector, validos);
    for(int i = 0; i < validos; i++) printf("I:%i |%i| ",i, vector[i]);
    printf("\n\n");

    int dato;
    printf("Ingrese un dato --> ");
    fflush(stdin);
    scanf("%i", &dato);
    printf("\n");

    insertarDatoOrdenadoEnVector(vector, validos, dato);
    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void insertarDatoOrdenadoEnVector(int vector[], int validos, int dato) {

    int indexAux;

    for(int i = 0; i < validos; i++) {
        if(vector[i] < dato) indexAux = i + 1; //Guardo el index donde tiene que colocarse el dato a insertar
    }
    validos++; //Incremento el tamaño de mis validos

    for (int i = validos - 1; i > indexAux; i--) vector[i] = vector[i - 1]; //Desplazamos los elementos hacia la Der

    vector[indexAux] = dato; //Piso el dato que se encuentra en el indice de Aux

    for(int i = 0; i < validos; i++) printf("|%i| ", vector[i]);
}
void ejercicio6() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 6 \n\n");

    srand(time(NULL));
    int vector[DIM];
    int validos;

    printf("Ingrese la cantidad de datos a cargar de manera aleatoria en el Vector --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    for(int i = 0; i < validos; i++) vector[i] = rand()% 100 + 1;

    ordenamientoXinsercion(vector, validos);
    printf("Mostrando Vector cargado y ordenado --> ");
    for(int i = 0; i < validos; i++) printf("|%i|", vector[i]);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void ejercicio7() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 7 \n\n");


    srand(time(NULL));
    int vector[DIM];
    int validos;
    int dato;

    printf("Ingrese la cantidad de datos a cargar de manera aleatoria en el Vector --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    for(int i = 0; i < validos; i++) vector[i] = rand()% 100 + 1;

    printf("Mostrando Vector cargado --> ");
    for(int i = 0; i < validos; i++) printf("|%i| ", vector[i]);
    printf("\n\n");

    printf("Ingrese el numero a eliminar del arrelgo --> ");
    fflush(stdin);
    scanf("%i", &dato);
    printf("\n");

    validos = eliminarElementoVector(vector, validos, dato);
    for(int i = 0; i < validos; i++) printf("|%i| ", vector[i]);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int eliminarElementoVector(int vector[], int validos, int dato) {

    int posicionDelElementoAEliminar;

    for(int i = 0; i < validos; i++) {

        if(vector[i] == dato) posicionDelElementoAEliminar = i;
    }
    //printf("Posicion del elemento a eliminar %i", posicionDelElementoAEliminar);

    for(int i = posicionDelElementoAEliminar ; i < validos - 1; i++) {

        vector[i] = vector[i + 1];
    }
}


void ejercicio8() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 8 \n\n");

    Alumno alumnos[20]; // para almacenar los datos de los 20 alumnos.
    Materia materias[5]; // para almacenar los códigos y nombres de las 5 materias.
    Nota calificaciones[100]; // para almacenar todas las notas de los alumnos
    char eleccion = 's';
    int resultado;

    cargarArregloMateria(materias);
    cargarAlumnoHasta(alumnos);

    printf("Pulse 's' para cargar una nota en sistema --> ");
    fflush(stdin);
    scanf("%c", &eleccion);
    printf("\n");

    if(eleccion == 's') {

        resultado = agregarNota(calificaciones, alumnos, materias);
        resultado = agregarNota(calificaciones, alumnos, materias);
        resultado = agregarNota(calificaciones, alumnos, materias);
    }




    printf("\n--------------------------------------------------------------------------------------------------\n");
}
/*INICIO FUNCIONES EJERCICIO 8*/

//void mostrarAlumno(Nota calificaciones[], Alumno alumnos[], Materia materias[]) {
//
//
//
//
//}


int agregarNota(Nota calificaciones[], Alumno alumnos[], Materia materias[]) {

    int numMatricula, codigo, numNota;
    int flag;
    int cont = 0;
    int encontrado = 0;
     int notaIngresada = 0;

    //Matricula alumno
    do {
        printf("Ingrese la matricula del alumno: ");
        scanf("%d", &numMatricula);
        printf("\n");

        encontrado = 0; // Reiniciar el estado de búsqueda en cada iteración

        for (int i = 0; i < 5; i++) {
            if (alumnos[i].matricula == numMatricula) {
                encontrado = 1; // Marcar como encontrado si la matrícula coincide
                break; // Salir del bucle for, ya se encontró una coincidencia
            }
        }

        if (encontrado) {
            flag = 1; // Establecer flag en 1 si se encontró una coincidencia
        } else {
            printf("No se encontró la matrícula del alumno. Vuelva a intentarlo.\n");
        }

    } while (flag != 1);

    //Codigo materia
    do {
        printf("Ingrese el codigo de la materia: ");
        scanf("%d", &codigo);
        printf("\n");

        int encontrado = 0; // Variable para seguir el estado de búsqueda

        for (int i = 0; i < 5; i++) {
            if (materias[i].codigoMateria == codigo) {
                encontrado = 1; // Marcar como encontrado si el código coincide
                break; // Salir del bucle for, ya se encontró una coincidencia
            }
        }

        if (encontrado) {
            flag = 1; // Establecer flag en 1 si se encontró una coincidencia
        } else {
            printf("No se encontro el código de materia. Vuelva a intentarlo.\n");
            break; // Salir del bucle do-while si no se encontró el código de materia
        }

    } while (flag != 1);

    //Nota alumno
    if (!notaIngresada) { // Verificar si la nota no ha sido ingresada aún
        do {
            printf("Ingrese la nota del alumno: ");
            scanf("%d", &numNota);
            printf("\n");

            if (numNota >= 0 && numNota <= 10) {
                flag = 1;
            } else {
                printf("Nota inválida. Vuelva a intentarlo.\n");
                flag = 0;
            }

        } while (flag != 1);
    }

    calificaciones[cont].matricula = numMatricula;
    calificaciones[cont].codigoMateria = codigo;
    calificaciones[cont].nota = numNota;
    notaIngresada = 1;

    printf("\n Nota: %i \n Matricula: %i \n Codigo Materia: %i\n", calificaciones[cont].nota, calificaciones[cont].matricula, calificaciones[cont].codigoMateria);

}
int cargarAlumnoHasta(Alumno alumnos[]) {

    int i = 0;
    char eleccion = 's';

    do {
        alumnos[i] = cargarAlumno();

        printf("Pulse 's' para registrarse como Alumno --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

        i++;

    }while(eleccion == 's' && i < 20);

    return i;
}

Alumno cargarAlumno() {

    int flag = 1;
    int matriculaAlumno, matriculaValida;
    Alumno newAlumno;

    printf("Ingrese su nombre y apellido ---> ");
    fflush(stdin);
    gets(newAlumno.nombreYapellido);
    printf("\n");

        do {
            printf("Ingrese su Matricula  ---> ");
            fflush(stdin);
            scanf("%i", &matriculaAlumno);
            matriculaValida = matriculaAlumno;
            if(flag != 1) {
                printf("\nNo se ingreso un numero para indicar la Matricula. Vuelva a intentarlo\n\n");
                flag = 0;
            }
        }while(flag != 1);

        if(flag == 1) {
            newAlumno.matricula = matriculaValida;
        }
        printf("\n");
        //Fin verificación

        return newAlumno;
}
void cargarArregloMateria(Materia materias[]) {

    materias[0].codigoMateria = 555;
    strcpy(materias[0].nombreMateria, "Programacion ");

    materias[1].codigoMateria = 111;
    strcpy(materias[1].nombreMateria, "Estadistica");

    materias[2].codigoMateria = 222;
    strcpy(materias[2].nombreMateria, "Laboratorio ");

    materias[3].codigoMateria = 333;
    strcpy(materias[3].nombreMateria, "Arquitectura y SO ");

    materias[4].codigoMateria = 444;
    strcpy(materias[4].nombreMateria, "Metodologia de la Investigacion");
}

void mostrarArregloDeMaterias(Materia materias[]) {

    for(int i = 0; i < 5; i++)
    printf("%s  %i \n", materias[i].nombreMateria, materias[i].codigoMateria);
}

/*FIN FUNCIONES EJERCICIO 8*/
Persona *copiaDePersonasPorGeneroDinamico(Persona *ptrPersonas, int cantidadPorGenero, int cantidadRegistros, char genero) {

    int i = 0;

    Persona *ptrCopiaPorGenero = (Persona *) malloc(cantidadPorGenero * sizeof(Persona));

        while(i < cantidadRegistros) {

        if(ptrPersonas[i].genero == genero){

            strcpy(ptrCopiaPorGenero[i].nombreYapellido, ptrPersonas[i].nombreYapellido);
            ptrCopiaPorGenero[i].genero = ptrPersonas[i].genero;
            ptrCopiaPorGenero[i].edad = ptrPersonas[i].edad;
            }
        i++;
        }
    for(int i = 0; i < cantidadPorGenero; i++) {
        printf("Nombre y Apellido: %s \n", ptrCopiaPorGenero[i].nombreYapellido);
        printf("Genero: %c\n", ptrCopiaPorGenero[i].genero);
        printf("Edad: %i \n", ptrCopiaPorGenero[i].edad);
    }

    return ptrCopiaPorGenero;
}

int contabilizarRegistrosPorGenero(Persona *ptrPersonas, int cantidadRegistros, char genero) {

    int i = 0;
    int contadorDeGenero = 0;

    while(i < cantidadRegistros) {

        if(ptrPersonas[i].genero == genero) contadorDeGenero++;

        i++;
    }
    return contadorDeGenero;
}

int cargarPersonasHasta(Persona personas[DIM]) {

    int i = 0;
    char eleccion = 's';

    do {
        personas[i] = cargarPersona();

        printf("Pulse 's' para cargar un Registro de Persona --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

        i++;
    }while(eleccion == 's' && i < DIM);

    return i;
}

Persona cargarPersona() {

    int flag = 1;
    int edadPersona, edadValida;
    char generoPersona;
    Persona newPerson;

    printf("Ingrese su nombre y apellido ---> ");
    fflush(stdin);
    gets(newPerson.nombreYapellido);
    printf("\n");

    //Verificación del genero
        do {

        printf("Ingrese su sexo (M/F/O) ---> ");
        fflush(stdin);
        scanf("%c", &generoPersona);

        if(generoPersona == 'f' || generoPersona == 'F') {
            newPerson.genero = generoPersona;
            flag = 1;
        }
        else if(generoPersona == 'm' || generoPersona == 'M'){
            newPerson.genero = generoPersona;
            flag = 1;
        }
        else if(generoPersona == 'o' || generoPersona == 'O') {
            newPerson.genero = generoPersona;
            flag = 1;
        }
        else {
            printf("\nGenero invalido. Vuelva a intentarlo");
            flag = 0;
        }
        }while(flag == 0);
        printf("\n");
        //Fin verificación del Genero

        //Verificación de la Edad
        do {
            printf("Ingrese su edad  ---> ");
            fflush(stdin);
            scanf("%i", &edadPersona);
            edadValida = edadPersona;

            if(flag != 1) {
                printf("\nNo se ingreso un numero para indicar la Edad. Vuelva a intentarlo\n\n");
                flag = 0;
            }

        }while(flag != 1);

        if(flag == 1) {
            newPerson.edad = edadValida;
        }
        printf("\n");
        //Fin verificación

        return newPerson;
}


// Función de ordenamiento por selección
void posMenor(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ordenamientoXseleccionArray(int vector[], int validos) {
    for (int i = 0; i < validos - 1; i++) {
        int minIndex = i;

        // Encuentra el índice del elemento mínimo en el resto del arreglo
        for (int j = i + 1; j < validos; j++) {
            if (vector[j] < vector[minIndex]) {
                minIndex = j;
            }
        }

        // Intercambia el elemento mínimo con el elemento en la posición actual
        if (minIndex != i) {
            posMenor(&vector[i], &vector[minIndex]);
        }
    }
}

//Función ordenamiento por inserción
void ordenamientoXinsercion(int vector[], int validos) {

    for (int i = 1; i < validos; i++) {
        int elementoVector = vector[i];
        int j = i - 1;

    // Mover elementos mayores que key a una posición adelante

        while (j >= 0 && vector[j] > elementoVector) {
            vector[j + 1] = vector[j];
            j--;
        }
    vector[j + 1] = elementoVector;
    }
}
