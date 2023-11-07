#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
Entrada: No necesita
Salida: Genera un "tipo de dato AB"
Proceso: Crea un "AB" usando la estructura dinámica.
*/
struct nodo{
char info;
struct nodo *izq;
struct nodo *der;
};
typedef struct nodo tNodo;
typedef tNodo *AB;
int i = 0;
/*
Entrada: Requiere algún valor tipo char.
Salida: Retorna un 'nodo' creado con sus caracteristicas respectivas(apunte a nodos hijos izq y der o NULL además de su info.).
Proceso: La función recibe un valor tipo char para poder crearlo como un nodo y agregaarlo a nuestro Arbol Binario.
*/
AB creaNodo(char valor)
{
  AB aux; // Se crea un nodo tipo AB que se llenará dentro del primer if.
  aux = (AB)malloc(sizeof(tNodo)); //Se reserva el espacio para hacer el nodo.
  if (aux != NULL){
    aux->info = valor;
    aux->izq = NULL;
    aux->der = NULL;
  }
  else{
    printf("Sin memoria");
    exit(1);
  }
  return aux;
}
/*
Entrada: No requiere recibir ningún otro dato para su funcionamiento, solo ser llamada.
Salida: Entrega el arbol creado (creaAB).
Proceso: Crea los nodos del arbol binario.
*/
AB creaAB()
{
    AB T;
    T = creaNodo('#');
    T->izq = creaNodo('E');
    T->der = creaNodo('T');
    T->izq->izq = creaNodo('I');
    T->izq->der = creaNodo('A');
    T->der->izq = creaNodo('N');
    T->der->der = creaNodo('M');
    T->izq->izq->izq = creaNodo('S');
    T->izq->izq->der = creaNodo('U');
    T->izq->der->izq = creaNodo('R');
    T->izq->der->der = creaNodo('W');
    T->der->izq->izq = creaNodo('D');
    T->der->izq->der = creaNodo('K');
    T->der->der->izq = creaNodo('G');
    T->der->der->der = creaNodo('O');
    T->izq->izq->izq->izq = creaNodo('H');
    T->izq->izq->izq->der = creaNodo('V');
    T->izq->izq->der->izq = creaNodo('F');
    T->izq->izq->der->der = creaNodo('#');
    T->izq->der->izq->izq = creaNodo('L');
    T->izq->der->izq->der = creaNodo('#');
    T->izq->der->der->izq = creaNodo('P');
    T->izq->der->der->der = creaNodo('J');
    T->der->izq->izq->izq = creaNodo('B');
    T->der->izq->izq->der = creaNodo('X');
    T->der->izq->der->izq = creaNodo('C');
    T->der->izq->der->der = creaNodo('Y');
    T->der->der->izq->izq = creaNodo('Z');
    T->der->der->izq->der = creaNodo('Q');
    T->der->der->der->izq = creaNodo('#');
    T->der->der->der->der = creaNodo('#');
    T->izq->izq->izq->izq->izq = creaNodo('5');
    T->izq->izq->izq->izq->der = creaNodo('4');
    T->izq->izq->izq->der->der = creaNodo('3');
    T->izq->izq->der->der->izq = creaNodo('#');
    T->izq->izq->der->der->der = creaNodo('2');
    T->izq->der->izq->izq->izq = creaNodo('&');
    T->izq->der->izq->izq->der = creaNodo('#');
    T->izq->der->izq->der->izq = creaNodo('+');
    T->izq->der->der->izq->der = creaNodo('#');
    T->izq->der->der->der->der = creaNodo('1');
    T->der->izq->izq->izq->izq = creaNodo('6');
    T->der->izq->izq->izq->der = creaNodo('=');
    T->der->izq->izq->der->izq = creaNodo('/');
    T->der->izq->der->izq->der = creaNodo('#');
    T->der->izq->der->der->izq = creaNodo('(');
    T->der->der->izq->izq->izq = creaNodo('7');
    T->der->der->izq->izq->der = creaNodo('#');
    T->der->der->izq->der->der = creaNodo(165);// Ñ
    T->der->der->der->izq->izq = creaNodo('8');
    T->der->der->der->der->izq = creaNodo('9');
    T->der->der->der->der->der = creaNodo('0');
    T->izq->izq->der->der->izq->izq = creaNodo('?');
    T->izq->izq->der->der->izq->der = creaNodo('_');
    T->izq->der->izq->izq->der->izq = creaNodo('"');
    T->izq->der->izq->der->izq->der = creaNodo('.');
    T->izq->der->der->izq->der->izq = creaNodo('@');
    T->izq->der->der->der->der->izq = creaNodo(39); // '
    T->der->izq->izq->izq->izq->der = creaNodo('-');
    T->der->izq->der->izq->der->izq = creaNodo(';');
    T->der->izq->der->izq->der->der = creaNodo('!');
    T->der->izq->der->der->izq->der = creaNodo(')');
    T->der->der->izq->izq->der->der = creaNodo(',');
    T->der->der->der->izq->izq->izq = creaNodo(':');
    return T;
}
/*
Entrada: Requiere un arbol y un valor que se desea buscar.
Salida: Te entrega un valor booleano en caso de que se encuentre (true) o no (false) el valor requerido.
Proceso: Busca algun valor solicitado en todo el arbol.
*/
bool buscaElemento(AB T, char n)
{
  if(T == NULL){
    return false;
  }
  if(T->info == n){
    return  true;
  }
  return buscaElemento(T->izq, n) || buscaElemento(T->der, n); // Realiza el mismo proceso repetidas veces hasta obtener un solo valor bool.
}
/*
Entrada: Requiere un valor y el nombre de un archivo.
Salida: Devuelve un tipo Bool; True o False.
Proceso: Abrir y agregarle la 'letra' al archivo.
*/
void escribeArch(char letra, char nombre_a[30])
{
  FILE *archivo;
  archivo = fopen(nombre_a, "a+"); //Abrimos el archivo para poder agregarle nuevos valores sin borrar su contenido.
  fputc(letra, archivo); // Aquí le agregamos un valor nuevo dentro del archivo.
  fclose(archivo);
  return;
}
/*
Entrada: Requiere un arbol, una linea de codigo morse y otra del nombre del archivo de texto
Salida: No presenta salida dado que es una función tipo void.
Proceso: Toma el codigo morse y lo convierte en texto español y lo guarda en el archivo de texto.
*/
void morseaLetra(AB T, char linea[4000], char nombre_a[30]) // Traducir morse a letra
{
  AB aux; // Se genera una variable auxiliar tipo AB.
  int i = 0; // Variable que nos ayudará a recorrer el contenido de "linea".
  aux = T; // Asignamos que aux le "pida prestado" a todo el Ab de T.
  while(linea[i] != '\0') // Ciclo que recorre todo el codigo morse hasta su final.
  {
    if(linea[i] == '.')
    {
      aux = aux->izq;
    }
    if(linea[i] == '-')
     {
      aux = aux->der;
    }
    if((linea[i] == ' ') || (linea[i+1] == '\0'))
    {
        if(aux->info != '#')
        {
            escribeArch(aux->info, nombre_a); // Manda la letra econtrada en el camino que se hace en las lineas anteriores.
        }
        aux = T;
    }
    if((linea[i] == ' ') && (linea[i+1] == ' '))
    {
        escribeArch(' ', nombre_a);
    }
    i++;
  }
  return;
}
/*
Entrada: Requiere un arbol, una linea de texto español y otra del archivo de texto.
Salida:No presenta salida dado que es una función tipo void.
Proceso: Guarda el recorrido para encontrar la letra.
*/
void espanolAmorse(AB T, char letra, char nombre_a[30])
{
    if(T->info == letra){
        escribeArch(' ', nombre_a);
        return;
    }
    if(letra == ' '){
        escribeArch('  ',nombre_a);
    }
    if (buscaElemento(T->izq,letra)==true){
        escribeArch('.', nombre_a);
        return espanolAmorse(T->izq,letra,nombre_a);
    }
    if(buscaElemento(T->der,letra)==true){
        escribeArch('-', nombre_a);
        return espanolAmorse(T->der,letra,nombre_a);
    }
}
/*
Entrada: Requiere de un arbol y de la opción elegida por el usuario.
Salida: No tiene salida dado que es tipo Void. Pero lo que realiza es leer el archivo y otras funciones como traducir a morse o a español.
Proceso: Guarda el parrafo que se encuentra dentro de un archivo de texto y lo tracude a morse o a español.
*/
void leeArchivo(AB T, char opcion[1])
{
  FILE *archivo;
  char nombre_a[30]; // Se guarda el nombre del archivo.
  char linea[4000]; // Se guarda el contenido del archivo.
  int largo; // Largo de "linea"
  int l; // Largo del "nombre_a" para borrar el salto de línea.
  printf("Ingrese el nombre del archivo: ");
  gets(nombre_a);
  l = strlen(nombre_a);
  nombre_a[l] = '\0';
  archivo = fopen(nombre_a, "r+");
  if (archivo == NULL){
    printf("\nArchivo no encontrado, este programa se va a cerrar.");
    exit(1);
  }
  else{
    fgets(linea, 4000, archivo); // Se guarda el parrafo completo en LINEA
    largo = strlen(linea);
    linea[largo] = '\0'; // Se le asigna el "final de linea"
    fputc('\n', archivo);
    fclose(archivo);
    if(opcion[0] == '1')
    {
        while(i<strlen(linea))
        {
            espanolAmorse(T,linea[i],nombre_a);
            i++;
        }
        printf("Codificacion realizada. \n");
    }
    if(opcion[0] == '2')
    {
      morseaLetra(T, linea, nombre_a);
      printf("Codificacion realizada. \n");
    }
  }
}
/*
Entrada: Requiere de un AB para su correcto funcionamiento.
Salida: No presenta salida dado que es un "void". Pero nos muestra las opciones que se requieren en el programa.
Proceso: Esta función logra mostrar al usuario las opciones que se requieren en el programa además de que se vaya limpiando la pantalla.
*/
void menu(AB T)
{
  char opcion[1]; // Variable para guardar la opción del usuario.
  int l; // Variable para calcular el largo de la opcion y borrar el salto de línea.
  while(opcion[0] != '3')
  {
    printf("1. Lenguaje natural a Codigo morse. \n2. Codigo morse a Lenguaje natural. \n3. Salir. \nIngresa una opcion: ");
    gets(opcion);
    l = strlen(opcion);
    opcion[l-1] = '\0';
    if(opcion[0] == '1')
      leeArchivo(T, opcion);
    if(opcion[0] == '2')
      leeArchivo(T, opcion);
    printf("\n");
    system("pause"); // Esta opción pausa la pantalla.
    system("cls"); // Esta opción limpia la pantalla.
  }
  return;
}
/*
Entrada: Recibe datos del usuario y reacciona a ello.
Salida: Presenta la tipica salida de una función Main. Esta se encarga de que las funciones se valla ejecutando.
Proceso: Es la función principal; realizará la llamada de las funciones necesarias para que el programa funcione.
*/
int main()
{
  AB T = NULL; // Se crea un arbol con contenido NULL
  T = creaAB();
  menu(T);
  printf("\n\n");
  return 0;
}
