//Programa hecho por Carlos Alfonso Lemus Rodezno

//programa que proceso los datos de un lote de autos prestados

#include <iostream> //libreria estandar de c++, necesaria para usar sus funciones y elementeos
#include <windows.h> //libreria necesaria para utilizar sus funciones y elementes
#include <iomanip> //libreria necesaria para el manejo de los puntos decimales
#include <stdio.h> //libreria necesaria para utilizar sus funciones y elementes

using namespace std;    //Espacio de nombre a usar el estandar, no ayuda a abreviar el codigo

struct CA_Nodo //estructura nodo, esta sera los nodos de la pila
{   //Declaracion devariables a tuilizar
    int L_cod;
    string L_vehiculo;
    float L_horas;
    float L_costo;

    CA_Nodo *sig;
};

class CA_student // clase estudiante
{
    private:

        //Delcaracion de variables a utilizar;
        float L_prom = 0.00;
        float L_cont = 0.00;
        bool L_verificar;

    public:

        //metodos o funciones a utilizar

        CA_student();
        ~CA_student();

        //funcion que agrega un nodo a la pila
        void C_agregar(CA_Nodo *&CA_pila, int L_cod, string L_vehiculo,float L_horas, float L_costo);

        //funcion que elimina un nodo de la pila
        void C_eliminar(CA_Nodo *&CA_pila);

        //funcion que muestra los datos de la pila
        void C_listar(CA_Nodo *CA_pila);

        //funcion que busca un examen en la pila
        void C_buscar(CA_Nodo *CA_pila, int L_cod);

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

    int L_cod;
    string L_vehiculo;
    float L_horas;
    float L_costo;

    system("color 2D"); //funcion que le da color al fondo y texto de la consola

    do { //ciclo que permite la ejecucion del programa mientras el usario no haigo elejido la opcion de salir

        do { //ciclo que evita entradas de datos erroneos

            system("cls"); //funcion que borra texto de la pantalla

            cout << "\n\n\n\n\t\t\t\t\t\t\t\tMenu" << endl;
            cout << "\t\t\t\t\t\t\t***============***\n\n";
            cout << "\t\t\t\t\t\t\t1.Agregar un aunto" << endl;
            cout << "\t\t\t\t\t\t\t2.Eliminar un aunto" << endl;
            cout << "\t\t\t\t\t\t\t3.Listar auntos" << endl;
            cout << "\t\t\t\t\t\t\t4.Buscar aunto" << endl;
            cout << "\t\t\t\t\t\t\t5.Datos del lote de autos" << endl;
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

                        cout << "\n\n\n\n\t\t\t\t\t\tIngrese el auto" << endl;
                        cout << " \t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^";

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\n\n\t\t\t\t\t\t\tIngrese el codigo: ";
                        cin >> L_cod;
                        C_ErrorDato(); //funcion para evitar errores de entradas;

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el tipo de vehiculo: ";
                        cin >> L_vehiculo;
                        C_ErrorDato(); //funcion para evitar errores de entradas;

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el total de horas prestado: ";
                        cin >>  L_horas;
                        C_ErrorDato(); //funcion para evitar errores de entradas

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\t\t\t\t\t\t\tIngrese el costo por hora: $ ";
                        cin >> L_costo;
                        C_ErrorDato(); //funcion para evitar errores de entradas


                    } while (L_cod == cin.fail() || L_horas == cin.fail() || L_costo == cin.fail());

                    fflush(stdin); //funcion que limpia el buffer
                    cout << "\n\n\t\t\t\t\t\t\tDesea agregar otro auto (y/n): ";
                    cin >> L_seguir;
                    C_ErrorDato(); //funcion para evitar errores de entradas


                    if(L_seguir == 'y' || L_seguir == 'Y' || L_seguir == 'n' || L_seguir == 'N')
                    {
                        CA_obj->C_agregar(CA_pila,L_cod, L_vehiculo, L_horas, L_costo); //metodo que ingresa datos a la pila

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

                        cout << "\n\n\n\n\t\t\t\t\t\tElimina un auto" << endl;
                        cout << " \t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^";

                        CA_obj->C_eliminar(CA_pila); //metodo que elimina el ultimo nodo de la pila

                        fflush(stdin); //funcion que limpia el buffer
                        cout << "\n\n\t\t\t\t\t\tDesea eliminar otro auto (y/n): ";
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

                    cout << "\n\n\n\n\t\t\t\t\t\tListado de autos en el lote" << endl;
                    cout << " \t\t\t\t\t\t*****************************" << endl;

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

                            do { //ciclo para evitar entradas de edatos eeroneos

                                system("cls"); //funcion que borra texto de la pantalla

                                cout << "\n\n\n\n\t\t\t\t\t\tBuscar un auto" << endl;
                                cout << " \t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~";

                                fflush(stdin); //funcion que limpia el buffer
                                cout << "\n\n\t\t\t\t\t\t\tIngrese el Codigo: ";
                                cin >> L_cod;
                                C_ErrorDato(); //funcion para evitar errores de entradas

                            } while (L_cod == cin.fail());

                            cout << "\n\n";

                            CA_obj->C_buscar(CA_pila, L_cod); //metodo que elimina el ultimo de la pila


                            fflush(stdin); //funcion que limpia el buffer
                            cout << "\n\n\t\t\t\t\t\tDesea buscar otro auto (y/n): ";
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

                    cout << "\n\n\n\n\t\t\t\t\t\tDatos del lote de autos" << endl;
                    cout << " \t\t\t\t\t\t""""""""""""""""""""""""" << endl;

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
void CA_student::C_agregar(CA_Nodo *&CA_pila, int L_cod, string L_vehiculo, float L_horas, float L_costo)
{

    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    //condicion para verificar si es la primera vez que se ingresa un nodo a la pila
    if(CA_reco != NULL) //mientras reco se diferente de null se hara se ejecutra el siguente bloque
    {

        while(CA_reco != NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
        {
            /* si hay un due en un nodo igual al que se esta ingresando entonces verificar sera false
             por lo que no se almacenaran los datos ingresados en la pila */

            if(L_cod == CA_reco->L_cod)
            {
                L_verificar = false;

                //se imrimirA un mensaje señalando que ya esta ese esamen en la pila
                cout << "\n\n\t\t\t\t\t\tYa existe este auto en la pila" << endl;
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
        CA_nuevo->L_cod = L_cod;
        CA_nuevo->L_vehiculo = L_vehiculo;
        CA_nuevo->L_horas = L_horas;
        CA_nuevo->L_costo = L_costo;


        CA_nuevo->sig = CA_pila; /* luego el nodo recien creado apuntara a pila, al nodo anterior al nodo que se creo, si es que habia uno
                            sino apuntara a null */

        CA_pila = CA_nuevo; //luego pila tendra la direccion del ultimo nodo almacenado

        L_prom += CA_nuevo->L_costo; //Acumuladara las notas ingresadas

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


        L_prom -= CA_reco->L_costo; //Acumuladara las notas ingresadas


        delete CA_reco; //Se eliminara el ultimo nodo de la pila el cual born contiene su direccion

        L_cont--; //contador para saber el numero de elementos en la pila

        cout << "\n\n\t\t\t\t\t\tSe ha eliminado el ultimo auto en la pila";
    }
}

//funcion que muestra los datos de la pila
void CA_student::C_listar(CA_Nodo *CA_pila)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    while(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
    {
        //se imrimira los datos de los nodos de la pila
        cout << "\n\n\t\t\t\t\tCodigo: " << CA_reco->L_cod << endl;
        cout << "\t\t\t\t\tTipo de Vehiculo: " << CA_reco->L_vehiculo << endl;
        cout << "\t\t\t\t\tHoras: " << fixed << setprecision(2) << CA_reco->L_horas << " H " << endl;
        cout << "\t\t\t\t\tCosto por hora: $ " << fixed << setprecision(2) << CA_reco->L_costo << endl;


        CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes

    }
}

//funcion que busca un examen en la pila
void CA_student::C_buscar(CA_Nodo *CA_pila, int L_cod)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    bool L_mensaje = true; //Varaible que servira para imprimir un mensaje

    while(CA_reco!=NULL) //mientras reco se diferente de null se hara se ejecutra el siguente ciclo
    {
        //Si el due ingresado es igual a uno de los due ingresados entonces se ejecutara este bloque
        if(L_cod == CA_reco->L_cod)
        {
            //se imrimira los datos de los nodos de la pila
            cout << "\n\n\t\t\t\t\tCodigo: " << CA_reco->L_cod << endl;
            cout << "\t\t\t\t\tTipo de Vehiculo: " << CA_reco->L_vehiculo << endl;
            cout << "\t\t\t\t\tHoras: " << fixed << setprecision(2) << CA_reco->L_horas << " H " << endl;
            cout << "\t\t\t\t\tCosto por hora: $ " << fixed << setprecision(2) << CA_reco->L_costo << endl;

            L_mensaje = false; //si se ecnoctro el examen buscado entonces L_mensaje sera false
        }


        CA_reco = CA_reco->sig; //CA_reco se movera del ultimo nodo de la pila al nodo que esta antes

    }

    //Si L_mensaje es true significa que no se encontro el examen buscado por lo que imprimira un mensaje
    if (L_mensaje)
        {
             cout << "\n\n\t\t\t\t\t\t\tNo existe ese auto" << endl;
        }
}

//funcion que muestra los datos de los estudiantes
void CA_student::C_datos(CA_Nodo *CA_pila)
{
    CA_Nodo *CA_reco = CA_pila; //CA_reco almacenara la direccion del ultimno elemento de la pila

    //se imprimen la nota promedio, la nota mayor y la nota minima
    cout << "\n\n\t\t\t\t\tTotal de autos prestamos: " << fixed << setprecision(0) << L_cont << endl;
    cout << "\n\n\t\t\t\t\tPromedio de ingresos por prestamos: " << fixed << setprecision(2) << L_prom / L_cont << endl;

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



