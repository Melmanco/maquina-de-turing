#include <iostream>
#include<vector>
#include<map>
using namespace std;

typedef typename std::map<char,string*>::value_type map_val;

struct nodo
{
    struct nodo* l;
    char info;
    struct nodo* r;
};

void transicion(nodo** nodo_actual, char info_nueva, char movimiento)
{
    (*nodo_actual)->info = info_nueva;
    if (movimiento == 'l') (*nodo_actual)->r;
    else (*nodo_actual)->r;
}

void insertar_cola(struct nodo** cabeza, struct nodo** cola, char info_nueva)
{
    struct nodo* nodo_nuevo = new nodo;
    nodo_nuevo->info = info_nueva;
    nodo_nuevo->r = NULL;

    if (*cola == NULL)
    {
        nodo_nuevo->l = NULL;
        *cabeza = nodo_nuevo;
        *cola = nodo_nuevo;
        return;
    }

    (*cola)->r = nodo_nuevo;
    nodo_nuevo->l = *cola;
    *cola = nodo_nuevo;

    return;
}

void imprimir_lista(struct nodo* cabeza)
{
    struct nodo* actual = cabeza;
    int i = 1;
    while (actual != NULL && actual->r != NULL)
    {
        cout << actual->info << " -> ";
        actual = actual->r;
    }
    cout << actual->info << endl;
}

int main()
{
    char nuevo;
    struct nodo* cabeza = NULL;
    struct nodo* cola = NULL;
    string estado_inicial;
    vector<string> estados_finales;
    string estado;
    bool entrada_finales = false;
    map<string, map<char,string*>> transiciones;
    string estado_entrada;
    char simbolo_entrada;
    string estado_llegada;
    char simbolo_llegada;
    char direccion;
    bool entrada_transiciones = false;
    bool entrada_simbolos;
    

    //estado inicial
    cin >> estado_inicial;

    //estados finales
    do
    {
        cin >> estado;
        estados_finales.push_back(estado);
    }while(entrada_finales);

    //transiciones
    do
    {
        cin >> estado_entrada;
        cin >> simbolo_entrada;
        cin >> estado_llegada;
        cin >> simbolo_llegada;
        cin >> direccion;

        string lista_llegada[3] = {estado_llegada, string(1,simbolo_llegada), string(1,direccion)};

        transiciones[estado_entrada].insert(map_val(simbolo_entrada, lista_llegada));

    } while (entrada_transiciones);
    

    //palabra de entrada
    do
    {
        cin >> nuevo;
        insertar_cola(&cabeza, &cola, nuevo);
        imprimir_lista(cabeza);
    }while(entrada_simbolos);

    //analizar palabra
    //funcion que procesa un simbolo, en el primer simbolo
    //almacenar estado actual, simbolo actual y seguir procesando la palabra
    //al final del proceso de cada simbolo, analizar si el estado de llegada es final
    //si se encuentra un simbolo que no existe en el estado actual, se rechaza la palabra

}