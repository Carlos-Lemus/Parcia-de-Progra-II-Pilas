//Programa hecho por Carlos Alfonso Lemus Rodezno

//programa que toma y muestra los datos de los estudieantes, utilizando pilas

#include <iostream> //libreria estandar de c++, necesaria para usar sus funciones y elementeos
#include <windows.h> //libreria necesaria para utilizar sus funciones y elementes
#include <iomanip> //libreria necesaria para el manejo de los puntos decimales
#include <stdio.h> //libreria necesaria para utilizar sus funciones y elementes

using namespace std;    //Espacio de nombre a usar el estandar, no ayuda a abreviar el codigo

struct CA_Nodo //estructura nodo, esta sera los nodos de la pila
{   //Declaracion devariables a tuilizar
    string L_due;
    int L_dia;
    int L_mes;
    int L_anio;
    string L_acti;
    float L_nota;

    CA_Nodo *sig;
};

class CA_student // clase estudiante
{
    private:

        //Delcaracion de variables a utilizar;
        float L_prom = 0.00;
        float L_max = 0.00;
        float L_min = 0.00;
        float L_cont = 0.00;
        bool L_verificar;

    public:

        //metodos o funciones a utilizar

        CA_student();
        ~CA_student();

        //funcion que agrega un nodo a la pila
        void C_agregar(CA_Nodo *&CA_pila, string L_du, int L_d, int L_m, int L_an, string act, float L_not);

        //funcion que elimina un nodo de la pila
        void C_eliminar(CA_Nodo *&CA_pila);

        //funcion que muestra los datos de la pila
        void C_listar(CA_Nodo *CA_pila);

        //funcion que busca un examen en la pila
        void C_buscar(CA_Nodo *CA_pila, string L_du);

        //funcion que muestra los datos de los estudiantes
        void C_datos(CA_Nodo *CA_pila);

};

//declaracion de funciones
void C_menu(); //funcion que sera el menu del programa
bool C_vacio(CA_Nodo *pila); //funcion que comprueba que la pila esta o no varia
void C_ErrorDato(); //funcion para evitar errores de entradas

int main()
{
    C_menu(); //funcion que sera el menu del programa

    system("pause");
    return 0;
}

void C_menu() //funcion que sera el menu del programa
{
    //Declaracion de variables a tuilizar
    CA_student *CA_obj = new CA_student(); //reserva espacion en la memoria
    CA_Nodo *CA_pila = NULL; //declaracion de la pila

    int L_opcion;
    char L_seguir;

    char L_due[8];
    int L_dia;
    int L_mes;
    int L_anio;
    char L_acti[20];
    float L_nota;

    system("color 5A"); //funcion que le da color al fondo y texto de la consola

    do { //ciclo que permite la ejecucion del programa mientras el usario no haigo elejido la opcion de salir

        do { //ciclo que evita entradas de datos erroneos

            system("cls"); //funcion que borra texto de la pantalla

            cout << "\n\n\n\n\t\t\t\t\t\t\t\tMenu" << endl;
            cout << "\t\t\t\t\t\t\t***============***\n\n";
            cout << "\t\t\t\t\t\t\t1.Agregar examen" << endl;
            cout << "\t\t\t\t\t\t\t2.Eliminar examen" << endl;
            cout << "\t\t\t\t\t\t\t3.Listar examenes" << endl;
            cout << "\t\t\t\t\t\t\t4.Buscar Examen" << endl;
            cout << "\t\t\t\t\t\t\t5.Datos de alumnos" << endl;
            cout << "\t\t\t\t\t\t\t6.Salir" << endl;

            fflush(stdin); //funcion que limpia el buffer
            cout << "\n\n\t\t\t\t\t\t\tIngrese una opcion: ";
            cin >> L_opcion;
            C_ErrorDato(); //funcion para evitar errores de entradas


        } while (L_opcion < 1 || L_opcion > 6 || L_opcion == cin.fail());

        switch(L_opcion)
        {
            case 1:

                  do { //ciclo para evitar entradas de edatos eeroneos

                    do { //ciclo para evitar entradas de edatos eeroneos

                        system("cls"); //funcion que borra texto de la pantalla

                        cout << "\n\n\n\n\t\t\t\t\t\tIngrese el examen" << endl;
                        cout << " \t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^";

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\n\n\t\t\t\t\t\t\tIngrese Due: ";
                        cin >> L_due;
                        C_ErrorDato(); //funcion para evitar errores de entradas;

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el dia: ";
                        cin >> L_dia;
                        C_ErrorDato(); //funcion para evitar errores de entradas;

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el mes: ";
                        cin >>  L_mes;
                        C_ErrorDato(); //funcion para evitar errores de entradas

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el anio: ";
                        cin >> L_anio;
                        C_ErrorDato(); //funcion para evitar errores de entradas

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese la actividad: ";
                        cin >> L_acti;
                        C_ErrorDato(); //funcion para evitar errores de entradas

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese la nota: ";
                        cin >> L_nota;
                        C_ErrorDato(); //funcion para evitar errores de entradas


                    } while (L_dia == cin.fail() || L_mes == cin.fail() || L_anio == cin.fail() || L_nota == cin.fail() || L_nota < 1 || L_nota > 10);

                    fflush(stdin); //funcion que limpia el buffer
                    cout << "\n\n\t\t\t\t\t\t\tDesea agregar otro examen (y/n): ";
                    cin >> L_seguir;
                    C_ErrorDato(); //funcion para evitar errores de entradas


                    if(L_seguir == 'y' || L_seguir == 'Y' || L_seguir == 'n' || L_seguir == 'N')
                    {
                        CA_obj->C_agregar(CA_pila, string(L_due), L_dia, L_mes, L_anio, string(L_acti), L_nota); //metodo que ingresa datos a la pila

                    }

                  } while((L_seguir == 'y' || L_seguir == 'Y') || (L_seguir != 'y' && L_seguir != 'Y' && L_seguir != 'n' && L_seguir != 'N'));

                system("pause");

                break;

            case 2:

                system("cls"); //funcion que borra texto de la pantalla

                if(C_vacio(CA_pila)) //condicion que verifica si la pila esta vacia
                {
                    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
                }

                else {

                    do { //ciclo para evitar entradas de edatos eeroneos

                        system("cls"); //funcion que borra texto de la pantalla

                        cout << "\n\n\n\n\t\t\t\t\t\tElimina el examen" << endl;
                        cout << " \t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^";

                        CA_obj->C_eliminar(CA_pila); //metodo que elimina el ultimo nodo de la pila

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\n\n\t\t\t\t\t\tDesea eliminar otro examen (y/n): ";
                        cin >> L_seguir;
                        C_ErrorDato(); //funcion para evitar errores de entradas

                      } while(CA_pila != NULL && ((L_seguir == 'y' || L_seguir == 'Y') || (L_seguir != 'y' && L_seguir != 'Y' && L_seguir != 'n' && L_seguir != 'N')));
                }

                system("pause");

                break;

            case 3:

                system("cls"); //funcion que borra texto de la pantalla

                if(C_vacio(CA_pila)) //condicion que verifica si la pila esta vacia
                {
                    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
                }

                else {
                    system("cls"); //funcion que borra texto de la pantalla

                    cout << "\n\n\n\n\t\t\t\t\t\tListado de examenes" << endl;
                    cout << " \t\t\t\t\t\t***********************" << endl;

                    CA_obj->C_listar(CA_pila); //metodo que muestra los nodos y los datos que contienen
                }

                cout << "\n\n";

                system("pause");

                break;

            case 4:

                    system("cls"); //funcion que borra texto de la pantalla

                    if(C_vacio(CA_pila)) //condicion que verifica si la pila esta vacia
                    {
                        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
                    }

                    else {
                        do { //ciclo para evitar entradas de edatos eeroneos

                            system("cls"); //funcion que borra texto de la pantalla

                            cout << "\n\n\n\n\t\t\t\t\t\tBuscar el examen" << endl;
                            cout << " \t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~";

                            fflush(stdin); //funcion que limpia el buffer
                            cout << "\n\n\t\t\t\t\t\t\tIngrese Due: ";
                            cin >> L_due;
                            C_ErrorDato(); //funcion para evitar errores de entradas


                            cout << "\n\n";

                            CA_obj->C_buscar(CA_pila, string(L_due)); //metodo que elimina el ultimo de la pila


                            fflush(stdin); //funcion que limpia el buffer
                            cout << "\n\n\t\t\t\t\t\tDesea buscar otro examen (y/n): ";
                            cin >> L_seguir;
                            C_ErrorDato(); //funcion para evitar errores de entradas

                        } while((L_seguir == 'y' || L_seguir == 'Y') || (L_seguir != 'y' && L_seguir != 'Y' && L_seguir != 'n' && L_seguir != 'N'));
                    }

                    system("pause");

                    break;
            case 5:

                system("cls"); //funcion que borra texto de la pantalla

                if(C_vacio(CA_pila)) //condicion que verifica si la pila esta vacia
                {
                    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tNo hay registros\n\n" << endl;
                }

                else {
                    system("cls"); //funcion que borra texto de la pantalla

                    cout << "\n\n\n\n\t\t\t\t\t\tDatos de examenes" << endl;
                    cout << " \t\t\t\t\t\t""""""""""""""""""""""" << endl;

                    CA_obj->C_datos(CA_pila); //metodo que muestra datos de los examenes
                }

                system("pause");

                break;

            case 6:

                system("cls"); //funcion que borra texto de la pantalla

                cout << "\n\n\n\n\t\t\t\t\t\tGracias por usar el programa\n\n\n" << endl;

                system("pause");

                break;

        }

    } while (L_opcion == 1 || L_opcion == 2 || L_opcion == 3 || L_opcion == 4 || L_opcion == 5);

    delete CA_obj; //se libera la memoria
}



CA_student::CA_student()
{

}

CA_student::~CA_student()
{

}

//funcion que agrega un nodo a la pila
void CA_student::C_agregar(CA_Nodo *&CA_pila, string L_du, int L_d, int L_m, int L_an, string L_act, float L_not)
{

    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    //condicion para verificar si es la primera vez que se ingresa un nodo a la pila
    if(CA_reco != NULL) //mientras reco se diferente de null se hara se ejecutra el siguente bloque
    {

        while(CA_reco != NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
        {
            /* si hay un due en un nodo igual al que se esta ingresando entonces verificar sera false
             por lo que no se almacenaran los datos ingresados en la pila */

            if(L_du == CA_reco->L_due)
            {
                L_verificar = false;

                //se imrimirA un mensaje señalando que ya esta ese esamen en la pila
                cout << "\n\n\t\t\t\t\t\tYa existe este examen en la pila" << endl;
                cout << "\t\t\t\t\t\tPor lo tanto no se ingresara" << endl;
            }

            /* si no hay un due en un nodo igual al que se esta ingresando entonces verificar sera true
             por lo que se almacenaran los datos ingresados en la pila */
            else
            {
                L_verificar = true;
            }

            CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes

        }
    }

    if(CA_pila == NULL) {

        L_verificar = true;
    }

    if(L_verificar) //si veficar es true entonces se ingresara aqui
    {

        CA_Nodo *CA_nuevo = new CA_Nodo();   /* Reservara y segmentara un espacio de memoria para el puntero nuevo del
                                                tipo CA_Nodo que servira para almacenar los datos en el nodo */

        //Se alamcenan los datos que ingresan en el nodo
        CA_nuevo->L_due = L_du;
        CA_nuevo->L_dia = L_d;
        CA_nuevo->L_mes = L_m;
        CA_nuevo->L_anio = L_an;
        CA_nuevo->L_acti = L_act.c_str();
        CA_nuevo->L_nota = L_not;


        CA_nuevo->sig = CA_pila; /* luego el nodo recien creado apuntara a pila, al nodo anterior al nodo que se creo, si es que habia uno
                            sino apuntara a null */

        CA_pila = CA_nuevo; //luego pila tendra la direccion del ultimo nodo almacenado

        L_prom += CA_nuevo->L_nota; //Acumuladara las notas ingresadas

        L_cont++; //contador para saber el numero de elementos en la pila

    }
}

//funcion que elimina un nodo de la pila
void CA_student::C_eliminar(CA_Nodo *&CA_pila)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    if(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente bloque
    {

        CA_pila = CA_pila->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes


        L_prom -= CA_reco->L_nota; //Acumuladara las notas ingresadas


        delete CA_reco; //Se eliminara el ultimo nodo de la pila el cual born contiene su direccion

        L_cont--; //contador para saber el numero de elementos en la pila

        cout << "\n\n\t\t\t\t\t\tSe ha eliminado el ultimo examen";
    }
}

//funcion que muestra los datos de la pila
void CA_student::C_listar(CA_Nodo *CA_pila)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    while(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
    {
        //se imrimira los datos de los nodos de la pila
        cout << "\n\n\t\t\t\t\tDUE: " << CA_reco->L_due << endl;
        cout << "\t\t\t\t\tFecha: " << CA_reco->L_dia << "/" << CA_reco->L_mes << "/" << CA_reco->L_anio << endl;
        cout << "\t\t\t\t\tActividad: " << CA_reco->L_acti << endl;
        cout << "\t\t\t\t\tNota: " << fixed << setprecision(2) << CA_reco->L_nota << endl;


        CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes

    }
}

//funcion que busca un examen en la pila
void CA_student::C_buscar(CA_Nodo *CA_pila, string L_du)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    bool L_mensaje = true; //Varaible que servira para imprimir un mensaje

    while(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
    {
        //Si el due ingresado es igual a uno de los due ingresados entonces se ejecutara este bloque
        if(L_du == CA_reco->L_due)
        {
            //se imrimirA el dato del nodo encontrado
            cout << "\t\t\t\t\t\t\tDUE: " << CA_reco->L_due << endl;
            cout << "\t\t\t\t\t\t\tFecha: " << CA_reco->L_dia << "/" << CA_reco->L_mes << "/" << CA_reco->L_anio << endl;
            cout << "\t\t\t\t\t\t\tActividad: " << CA_reco->L_acti << endl;
            cout << "\t\t\t\t\t\t\tNota: " << fixed << setprecision(2) << CA_reco->L_nota << endl;

            L_mensaje = false; //si se ecnoctro el examen buscado entonces L_mensaje sera false
        }


        CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes

    }

    //Si L_mensaje es true significa que no se encontro el examen buscado por lo que imprimira un mensaje
    if (L_mensaje)
        {
             cout << "\n\n\t\t\t\t\t\t\tNo existe ese examen" << endl;
        }
}

//funcion que muestra los datos de los estudiantes
void CA_student::C_datos(CA_Nodo *CA_pila)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    L_min = CA_pila->L_nota; //L_min tiene el valor la ultima nota ingresada asi L_min puede evaluar con las demas notas

    //ciclo que se utilizara para determinar la mayor y menor nota
    while(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
    {
        //condicion que evalua la nota mayor de cada nodo con cada iteracion
        if(CA_reco->L_nota > L_max) //si la nota es mauor que L_max entonces se ingresara a este bloque
        {
            L_max = CA_reco->L_nota; //L_max almacenara la nota mas alta
        }

        //condicion que evalua la nota menor de cada nodo con cada iteracion
        if(CA_reco->L_nota < L_min)
        {
            L_min = CA_reco->L_nota; //L_min almacenara la nota menor
        }

        CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes
    }

    //se imprimen la nota promedio, la nota mayor y la nota minima
    cout << "\n\n\t\t\t\t\tEl numero de notas promedio es: " << fixed << setprecision(2) << L_prom / L_cont << endl;
    cout << "\n\n\t\t\t\t\tLa nota mayor es: " << fixed << setprecision(2) << L_max << endl;
    cout << "\n\n\t\t\t\t\tLa nota menor es: " << fixed << setprecision(2) << L_min << endl;
}

bool C_vacio(CA_Nodo *pila) //funcion que comprueba que la pila esta o no varia
{
    return (pila == NULL)? true : false;
}


void C_ErrorDato() //funcion para evitar errores de entradas
{

    //condicion que verifica si hubo un ingreso de dato erroneo
    if(cin.fail())
    {
        cout << "\n\n\t\t\t\t\tSe ha introducido un dato erroneo vuelva a ingrearlo\n\n" << endl;

        system("pause");
    }

    while(cin.fail()) //ciclo que evita el error de entradas
    {
        cin.clear(); //limpia el buffer

        cin.ignore(1000, '\n'); //ignora los primeros 1000 elements ingresados

    }
}



