#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> adjacencyMatrix; //2 dimensional array
    int numVertices;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // undirected
    }

    void removeEdge(int u, int v) {
        adjacencyMatrix[u][v] = 0;
        adjacencyMatrix[v][u] = 0;
    }

    bool isAdjacent(int u, int v) {
        return adjacencyMatrix[u][v] == 1;
    }

    void printMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphMatrix graph(4);

    graph.addEdge(0, 1); //0->1
    graph.addEdge(2, 3); //2->3

    graph.addEdge(1, 2); //1->2

    graph.printMatrix();
    

    cout << "0 and 1 adjacent? " << (graph.isAdjacent(0, 1) ? "yes" : "no") << endl; // should return true
}