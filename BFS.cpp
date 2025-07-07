    #include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

void BFS(int startNode, const vector<list<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    
    // Marcar el nodo inicial como visitado y encolarlo
    visited[startNode] = true;
    q.push(startNode);
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // Procesar el nodo (aquí solo lo imprimimos)
        
        // Recorrer todos los nodos adyacentes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Ejemplo: Grafo no dirigido con 5 nodos (0-4)
    const int numNodes = 5;
    vector<list<int>> adjList(numNodes);
    
    // Añadir aristas
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
    
    cout << "Recorrido BFS empezando desde el nodo 0:\n";
    BFS(0, adjList, visited);
    
    return 0;
}