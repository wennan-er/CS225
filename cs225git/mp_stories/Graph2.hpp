#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <iostream>
#include <utility>
/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */


  // using bfs

 template <class V, class E>
 std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
   // TODO: Part 3
   std::list<std::string> path;
   std::queue<std::string> q;
   std::unordered_map<std::string, bool> sptSet;
   std::unordered_map<std::string, int> dist;
   std::unordered_map<std::string, std::string> pred;

   for(auto it = vertexMap.begin(); it != vertexMap.end(); it++){
     std::string v = it->first;
     dist.insert({v,INT_MAX});
     sptSet.insert({v,false});
     pred.insert({v,v});

   }
   //initialize start vertex
   dist[start] = 0;
   q.push(start);
   sptSet[start] = true;
  //mark pred
   while(!q.empty()){
     std::string curr = q.front();
     q.pop();

    const std::list<E_byRef> list = incidentEdges(curr);
    for(Edge e : list){
      if (e.source().key()== curr && sptSet[e.dest().key()] == false){
        sptSet[e.dest().key()] = true;
        dist[e.dest().key()] = dist[curr]+1;
        pred[e.dest().key()] = curr;
        q.push(e.dest().key());

      }
      else if(e.dest().key() == curr && sptSet[e.source().key()] == false){
        sptSet[e.source().key()] = true;
        dist[e.source().key()] = dist[curr]+1;
        pred[e.source().key()] = curr;
        q.push(e.source().key());
      }
    }
   }
  //get shortest path
  string curr_ = end;
  while(curr_!=start){
    path.insert(path.begin(),curr_);
    curr_ = pred[curr_];

  }
  path.insert(path.begin(),start);
   return path;
}
/*
  //using priority_queue
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;
  std::unordered_map<std::string, bool> sptSet;
  std::unordered_map<std::string, int> dist;
  std::unordered_map<std::string, std::string> pred;
  std::vector<std::pair<std::string,int>> heap_elem;
  for(auto it = vertexMap.begin(); it != vertexMap.end(); it++){
    std::string v = it->first;
    dist.insert({v,INT_MAX});
    sptSet.insert({v,false});
    pred.insert({v,v});
    heap_elem.push_back(make_pair(v,INT_MAX));
  }

  dist[start] = 0;

  auto cmp = [](const std::pair<std::string,int> &a, const std::pair<std::string,int> &b)
          { return a.second < b.second; };

  std::priority_queue <std::pair<std::string,int>, std::vector<std::pair<std::string,int>>, decltype(cmp)> heap(cmp);

  for(std::pair<std::string,int>& p : heap_elem){
    heap.push(p);
  }
  string curr;

  for(unsigned int count = 0; count < numVertices(); count++){
    curr = heap.top().first;
    heap.pop();
    const std::list<E_byRef> list = incidentEdges(curr);
    sptSet[curr] = true;
    for(Edge e : list){
      if(e.source().key()==curr && sptSet[e.dest().key()] == false){
        if (dist[curr]+1 < dist[e.dest().key()]){
          dist[e.dest().key()] = dist[curr]+1;
          for(std::pair<string,int> &it : heap_elem){
            if(it.first == e.dest().key()){it.second = dist[curr]+1;}
          }
          pred[e.dest().key()] = curr;

        }

      }
      if(e.dest().key()==curr && sptSet[e.source().key()] == false){
        if (dist[curr]+1 < dist[e.source().key()]){
          dist[e.source().key()] = dist[curr]+1;
          for(std::pair<string,int> &it : heap_elem){
            if(it.first == e.source().key()){it.second = dist[curr]+1;}
          }
          pred[e.source().key()] = curr;
        }
    }
  }
  }
  string curr_ = end;
  while(curr_!=start){
    path.insert(path.begin(),curr_);
    curr_ = pred[curr_];

  }

  return path;
}
*/
