/*codigo de recorrido DFS Y BSF
PROGRAMACION DE UN ARBOL Y SUS RECORRIDOS

Luis Angel
Yoselin
Danna

*/
#include <iostream>
#include <queue>
#include <queue>

using namespace std;

typedef struct nodo
{
    int dato;

    struct nodo *izq, *der;

} *arbolbinario;

int numNodos = 0;

// meotodo para crear nodos en al arbol binario

arbolbinario crearNodo(int a)
{
    arbolbinario nuevoNodo = new (struct nodo);
    nuevoNodo->dato = a;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
} // fin del metodo crear nodo

// metodo para insertar un nodo en el arbol binario

void insertar(arbolbinario &arbol, int a)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(a);
        cout << "\n\t Nodo insertardo en el arbol" << endl
             << endl;
    }
    else if (a < arbol->dato)
        insertar(arbol->izq, a);
    else if (a > arbol->dato)
        insertar(arbol->der, a);
}

arbolbinario eliminar(arbolbinario arbol, int a)
{
    if (arbol == NULL)
        return arbol;

    if (a < arbol->dato)
        arbol->izq = eliminar(arbol->izq, a);
    else if (a > arbol->dato)
        arbol->der = eliminar(arbol->der, a);

    else
    {
        if (arbol->izq == NULL && arbol->der == NULL)
        {
            delete arbol;
            return NULL;
        }
        else if (arbol->izq == NULL)
        {
            arbolbinario temp = arbol->der;
            delete arbol;
            return temp;
        }
        else if (arbol->der == NULL)
        {
            arbolbinario temp = arbol->izq;
            delete arbol;
            return temp;
        }
        arbolbinario sucesor = arbol->der;
        while (sucesor->izq != NULL)
            sucesor = sucesor->izq;
        arbol->dato = sucesor->dato;
        arbol->der = eliminar(arbol->der, sucesor->dato);
    }
    return arbol;
}

void mostrarArbol(arbolbinario arbol, int a)
{
    if (arbol == NULL)
        return;
    mostrarArbol(arbol->der, a + 1);

    for (int i = 0; i < a; i++)
        cout << "   ";
    cout << arbol->dato << endl;
    mostrarArbol(arbol->izq, a + 1);
}

void recorridoBFS(arbolbinario arbol)
{
    if (arbol == NULL)
    {
        cout << "el arbol esta vacio" << endl;
        return;
    }

    queue<arbolbinario> cola;
    cola.push(arbol);
    cout << "Recorrido BFS: ";

    while (!cola.empty())
    {
        arbolbinario actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";
        if (actual->izq != NULL)
            cola.push(actual->izq);
        if (actual->der != NULL)
            cola.push(actual->der);
    }
    cout << endl;
}

void recorridoDFS(arbolbinario arbol)
{
    if (arbol != NULL){
        cout << arbol->dato << " ";
    recorridoDFS(arbol->izq);
    recorridoDFS(arbol->der);
    }
}

bool buscarDFS(arbolbinario arbol, int valor)
{
    if (arbol == NULL)
        return false;
    if (arbol->dato == valor)
    {
        cout << "\n\t valor encontrado:" << valor << endl;
        return true;
    }

    if (buscarDFS(arbol->izq, valor))
        return true;
    if (buscarDFS(arbol->der, valor))
        return true;

    return false;
}

void menu()
{
    system("cls");

    cout << "\t 1.Agregar Nodo\n";
    cout << "\t 2.Mostrar arbol\n";
    cout << "\t 3.Seleccionar recorrido\n";
    cout << "\t 4.Eliminar recorrido\n";
    cout << "\t 5.Buscar dato por DFS \n";
    cout << "\t 6.Salir de la aplicacion\n";
    cout << "\n\t Elige una opcion valida:";
}

void menu2()
{
    cout << "\t 1.Recorrido BFS\n";
    cout << "\t 2.Recorrido DFS\n";
    cout << "\n\t  Elige una opcion valida: ";
}

int main()
{
    arbolbinario arbol = NULL;
    int a, op, op2;
    system("color f0");

    do
    {
        menu();
        cin >> op;
        cout << endl;

        switch (op)
        {
        case 1:
            cout << "ingrese un numero:  ";
            cin >> a;
            insertar(arbol, a);
            break;
        case 2:
            mostrarArbol(arbol, 0);
            break;
        case 3:
            menu2();
            cin >> op2;
            if (arbol != NULL)
            {
                switch (op2)
                {
                case 1:
                    recorridoBFS(arbol);
                    break;
                case 2:
                    recorridoDFS(arbol);
                    break;
                default:
                    cout << "\n\t ingresa una opcion valida: ";
                }
            }
            else
            {
                cout << "\n\t el arbol esta vacio";
            }
            break;

        case 4:
            cout << "Ingresa el valor a eliminar: ";
            cin >> a;
            arbol = eliminar(arbol, a);
            break;
        case 5:
            cout << "ingrese el valor a buscar: ";
            cin >> a;

            if (!buscarDFS(arbol, a))
            {
                cout << "\n\t valor no encontrado en el arbol";
            }
            break;
        case 6:
            exit(0);
        default:
            cout <<"\t ingrese una opcion correcta";
        }
        cout <<"\n\n\n";
        system("pause");
    }while (op != 6);
    
}
