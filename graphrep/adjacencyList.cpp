#include <iostream>
#include <vector>
using namespace std;

class GraphList {
private:
    vector<vector<int>> adjacencyList;
    int numVertices;

public:
    GraphList(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // undirected
    }

    void removeEdge(int u, int v) {
        // remove v from u's list
        for (int i = 0; i < adjacencyList[u].size(); i++) {
            if (adjacencyList[u][i] == v) {
                adjacencyList[u].erase(adjacencyList[u].begin() + i);
                break;
            }
        }

        // remove u from v's list
        for (int i = 0; i < adjacencyList[v].size(); i++) {
            if (adjacencyList[v][i] == u) {
                adjacencyList[v].erase(adjacencyList[v].begin() + i);
                break;
            }
        }
    }

    bool isAdjacent(int u, int v) {
        for (int neighbor : adjacencyList[u]) {
            if (neighbor == v) return true;
        }
        return false;
    }

    void printList() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphList graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.printList();

    cout << "0 and 1 adjacent? " << graph.isAdjacent(0,1) << endl;
}