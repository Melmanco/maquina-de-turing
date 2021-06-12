#include <iostream>
using namespace std;

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

    do
    {
        cin >> nuevo;
        insertar_cola(&cabeza, &cola, nuevo);
        imprimir_lista(cabeza);
    }while(nuevo >= 'a' && nuevo <= 'z');
}