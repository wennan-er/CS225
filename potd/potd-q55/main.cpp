#include <cstdio>
#include <vector>
#include "adjacency_list.cpp"
#include "adjacency_list.h"

using namespace std;

int main() {
    // Construct graph
    Graph* g = createVertices(3);
    addEdge(g, 0, 1);
    addEdge(g, 1, 0);
    addEdge(g, 2, 1);

    // Print the edges
    printGraph(g);

    cout << "Edge from 0 to 1 exists (expected output is 1): " << containsEdge(g, 0, 1) << endl;
    cout << "Edge from 1 to 0 exists (expected output is 1): " << containsEdge(g, 1, 0) << endl;
    cout << "Edge from 2 to 0 exists (expected output is 0): " << containsEdge(g, 2, 0) << endl;

    Graph* g2 = createVertices(3);
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 0);

    // Print the edges
    printGraph(g2);

    cout << "Edge from 0 to 1 exists (expected output is 1): " << containsEdge(g2, 0, 1) << endl;
    cout << "Edge from 1 to 2 exists (expected output is 1): " << containsEdge(g2, 1, 2) << endl;
    cout << "Edge from 2 to 0 exists (expected output is 0): " << containsEdge(g2, 2, 0) << endl;
}
