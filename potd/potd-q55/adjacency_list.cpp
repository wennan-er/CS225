#include <iostream>
#include <string>
#include <vector>
#include "adjacency_list.h"
using namespace std;
vector<int> OutgoingEdges;
vector<int> IncomingEdges;

bool containsEdge(Graph const * const g, int src, int dest) {
        // Your code here
        LinkedListNode* src_edge = g->adjLists[src].edges;
        while (src_edge!=NULL){
          if (src_edge->v == dest){
            return true;
        }
        src_edge = src_edge->next;
      }
      return false;

}

void addEdge(Graph* g, int src, int dest) {
        // Your code here
        OutgoingEdges[src]++;
        IncomingEdges[dest]++;
        LinkedListNode* src_edge = g->adjLists[src].edges;
        LinkedListNode* newnode = new LinkedListNode;
        newnode->v = dest;
        newnode->next = NULL;
        if(src_edge == NULL) g->adjLists[src].edges = newnode;
        else {
          while (src_edge->next!=NULL){
          src_edge = src_edge->next;
             }
            src_edge->next = newnode;
        }

}

int numOutgoingEdges(Graph const * const g, int v) {
        // Your code here
        return OutgoingEdges[v];
}


int numIncomingEdges(Graph const * const g, int v) {
        // Your code here
        return IncomingEdges[v];
}

// No need to modify the functions below

Graph* createVertices(int numV) {
        Graph* g = new Graph();
        g->adjLists = new AdjacencyList[numV];
        g->n = numV;

        // Initialize the vertices
        for (int i = 0; i < numV; i += 1) {
                g->adjLists[i].vertex = i;
                g->adjLists[i].edges = NULL;
                OutgoingEdges = vector<int>(numV-1,0);
                IncomingEdges = vector<int>(numV-1,0);
        }

        return g;
}

void printGraph(Graph const * const g) {
    for (int i = 0; i < g->n; i += 1) {
        AdjacencyList adjList = g->adjLists[i];

        int v = adjList.vertex;
        // Vertex
        cout << "Vertex: " << v << endl;

        // Print number of incoming and outgoing edges
        int inc = numIncomingEdges(g, v);
        int out = numOutgoingEdges(g, v);
        cout << "Number of incoming edges: " << inc << endl;
        cout << "Number of outgoing edges: " << out << endl;

        cout << "\n" << endl;
    }
}
