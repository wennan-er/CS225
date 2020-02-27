#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>

/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::numVertices() const {
  // TODO: Part 2
  return vertexMap.size();
  //return 0;
}


/**
* The degree of the vertex. For directed: Sum of in-degree and out-degree
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
  std::list<edgeListIter> List = adjList.at(v.key());
  return List.size();
  //return 0;
}


/**
* Inserts a Vertex into the Graph.
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));
  vertexMap.insert({key,v});
  adjList.insert({key,std::list<edgeListIter>(0)});
  return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2

  //remove vertex
  std::list<E_byRef> List = incidentEdges(key);
  for(E_byRef e : List){
    removeEdge(e.get().source(), e.get().dest());
  }
  vertexMap.erase(key);
  adjList.erase(key);

}


/**
* Inserts an Edge into the Graph.
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2

  E & e = *(new E(v1, v2));
  edgeList.insert(edgeList.begin(), e);
  edgeListIter it= edgeList.begin();
  adjList.at(v1.key()).push_front(it);
  adjList.at(v2.key()).push_front(it);
  return e;


}


/**
* Removes an Edge from the Graph. Consider both the undirected and directed cases.
* min(degree(key1), degree(key2))
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {
  // TODO: Part 2

  for (auto it = edgeList.begin(); it!= edgeList.end(); it++){
    Edge e = *it;
    if(e.source().key()==key1 && e.dest().key()==key2){
      removeEdge(it);
      break;
    }
    if(e.source().key()==key2 && e.dest().key()==key1 && e.directed()){
      removeEdge(it);
      break;
    }
  }

}


/**
* Removes an Edge from the Graph given by the location of the given iterator into the edge list.
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
  /*
  list_name.remove(val):
  This function accepts a single parameter val which refers to the value of elements
  needed to be removed from the list. The remove() function will remove all the elements
  from the list whose value is equal to val.
  */
  Edge e = *it;

  Vertex s = e.source();
  Vertex d = e.dest();
  adjList.at(s.key()).remove(it);
  adjList.at(d.key()).remove(it);
  edgeList.erase(it);

}


/**
* Return the list of incident edges from a given vertex.
* For the directed case, consider all edges that has the vertex as either a source or destination.
* @param key The key of the given vertex
* @return The list edges (by reference) that are adjacent to the given vertex
*/
template <class V, class E>
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;

  for(edgeListIter it : adjList.at(key)){
    edges.push_front(*it);
  }

  return edges;
}


/**
* Return whether the two vertices are adjacent to one another. Consider both the undirected and directed cases.
* When the graph is directed, v1 and v2 are only adjacent if there is an edge from v1 to v2.
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> List1 = incidentEdges(key1);
  for(Edge e : List1){
    if(e.source().key()==key1 && e.dest().key()==key2){
      return true;
    }

  if(e.source().key()==key2 && e.dest().key()==key1 && e.directed())
   {
     return true;
   }
 }
  return false;
}
