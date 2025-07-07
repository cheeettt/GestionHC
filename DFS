#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(int currentNode, const vector<list<int>>& adjList, vector<bool>& visited) {
    // Marcar el nodo actual como visitado y procesarlo
    visited[currentNode] = true;
    cout << currentNode << " ";  // Puedes reemplazar esto con tu lógica

    // Recorrer todos los nodos adyacentes
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);  // Llamada recursiva
        }
    }
}

int main() {
    // Ejemplo: Grafo no dirigido con 5 nodos (0-4)
    const int numNodes = 5;
    vector<list<int>> adjList(numNodes);

    // Añadir aristas (mismo grafo que en el BFS para comparar)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[4].push_back(2);

    vector<bool> visited(numNodes, false);

    cout << "Recorrido DFS empezando desde el nodo 0:\n";
    DFS(0, adjList, visited);

    return 0;
}