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

/*
# **Cómo Modificar el Algoritmo BFS para Diferentes Propósitos**

El BFS (Breadth-First Search) es un algoritmo versátil que puedes adaptar para múltiples aplicaciones. Aquí te muestro cómo modificarlo según necesidades específicas:

## **1. BFS Estándar (Recorrido Simple)**
```cpp
void BFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // Procesamiento básico

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

## **2. BFS para Encontrar el Camino Más Corto (No Ponderado)**
```cpp
vector<int> shortestPathBFS(int start, int target, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(), -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == target) break; // Encontramos el objetivo

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u; // Registramos el padre
                q.push(v);
            }
        }
    }

    // Reconstruir el camino
    vector<int> path;
    for (int at = target; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}
```

## **3. BFS para Grafos con Pesos (Usando Cola de Prioridad)**
```cpp
void weightedBFS(int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(adj.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        if (current_dist > dist[u]) continue; // Ya encontramos un camino mejor

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
```

## **4. BFS para Componentes Conexas**
```cpp
int countConnectedComponents(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    int count = 0;

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            count++;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return count;
}
```

## **5. BFS para Detección de Ciclos**
```cpp
bool hasCycleBFS(vector<vector<int>>& adj) {
    vector<int> parent(adj.size(), -1);
    vector<bool> visited(adj.size(), false);

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        return true; // Ciclo detectado
                    }
                }
            }
        }
    }
    return false;
}
```

## **6. BFS Niveles (Para Aplicaciones como Word Ladder)**
```cpp
int bfsLevels(int start, int target, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<pair<int, int>> q; // {nodo, nivel}
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [u, level] = q.front();
        q.pop();

        if (u == target) return level;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, level + 1});
            }
        }
    }
    return -1; // No alcanzable
}
```

## **¿Qué Modificación Necesitas?**
- **Para grafos dirigidos**: Simplemente ajusta la lista de adyacencia.
- **Para múltiples fuentes**: Inicializa la cola con todos los nodos fuente.
- **Para evitar procesamiento redundante**: Usa un `unordered_set` en lugar de `vector<bool>` si los nodos son strings o no consecutivos.

¿Necesitas alguna de estas versiones adaptada a un problema específico? ¡Dímelo! 🚀
*/
