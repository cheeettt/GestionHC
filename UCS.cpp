#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

// Estructura para representar un nodo y su costo acumulado
struct Node {
    int id;
    int cost;
    
    // Sobrecarga del operador para la priority_queue
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void uniformCostSearch(int start, int goal, const vector<vector<pair<int, int>>>& graph) {
    priority_queue<Node, vector<Node>, greater<Node>> frontier; // Cola de prioridad (min-heap)
    unordered_map<int, int> cost_so_far; // Registra el mejor costo conocido para cada nodo
    
    frontier.push({start, 0});
    cost_so_far[start] = 0;
    
    while (!frontier.empty()) {
        Node current = frontier.top();
        frontier.pop();
        
        if (current.id == goal) {
            cout << "Costo mínimo para llegar al objetivo: " << current.cost << endl;
            return;
        }
        
        for (const auto& neighbor : graph[current.id]) {
            int next = neighbor.first;
            int new_cost = current.cost + neighbor.second;
            
            // Si no hemos visitado 'next' o encontramos un camino más barato
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                frontier.push({next, new_cost});
            }
        }
    }
    
    cout << "No se encontró un camino al nodo objetivo." << endl;
}

int main() {
    // Ejemplo: Grafo ponderado no dirigido (nodo, peso)
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 3}},       // Nodo 0
        {{0, 2}, {3, 4}},        // Nodo 1
        {{0, 3}, {3, 1}},        // Nodo 2
        {{1, 4}, {2, 1}}         // Nodo 3
    };
    
    int start_node = 0;
    int goal_node = 3;
    
    cout << "Búsqueda de Costo Uniforme (de " << start_node << " a " << goal_node << "):" << endl;
    uniformCostSearch(start_node, goal_node, graph);
    
    return 0;
}