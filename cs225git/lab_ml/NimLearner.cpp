/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>

using namespace std;
/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true) {
    /* Your code goes here! */
    startingVertex_ = "p1-"+to_string(startingTokens);
    vector<Vertex> vertices;
    for (int i = int(startingTokens);i>=0; i--)
    {
        string p1 = "p1-"+to_string(i);
        string p2 = "p2-"+to_string(i);
        g_.insertVertex(p1);
        g_.insertVertex(p2);
        vertices.push_back(p1);
        vertices.push_back(p2);
    }
    for (unsigned i = 0; i < 2*startingTokens; i+=2){
      int j = int(startingTokens)-i/2;
      g_.insertEdge(vertices[i],vertices[i+3]);
      g_.setEdgeWeight(vertices[i],vertices[i+3], 0);
      g_.setEdgeLabel(vertices[i], vertices[i+3], "p1-"+to_string(j-1));

      g_.insertEdge(vertices[i+1],vertices[i+2]);
      g_.setEdgeLabel(vertices[i+1], vertices[i+2], "p2-"+to_string(j-1));
      g_.setEdgeWeight(vertices[i+1],vertices[i+2], 0);

      if (i+5<= 2*startingTokens+1 ){
      g_.insertEdge(vertices[i+1],vertices[i+4]);
      g_.setEdgeWeight(vertices[i+1],vertices[i+4], 0);
      g_.setEdgeLabel(vertices[i+1], vertices[i+4], "p2-"+to_string(j-2));

      g_.insertEdge(vertices[i],vertices[i+5]);
      g_.setEdgeWeight(vertices[i],vertices[i+5], 0);
      g_.setEdgeLabel(vertices[i], vertices[i+5], "p1-"+to_string(j-2));
    }
  }
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
 /* Your code goes here! */
 Vertex old_state = startingVertex_;
 Vertex new_state;

 while (!g_.getAdjacent(old_state).empty()){

    vector<Vertex> vec = g_.getAdjacent(old_state);
    if (vec.size() == 1){
      new_state = vec[0];
      Edge edge = g_.getEdge(old_state, new_state);
      path.push_back(edge);
      old_state = new_state;
    }
    else{
      int random_number = rand()%2;
      new_state = vec[random_number];
      Edge edge = g_.getEdge(old_state, new_state);
      path.push_back(edge);
      old_state = new_state;
    }
}
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */

 //determine p1 or p2 win and update their weight
 int upWeight_p1;
 int upWeight_p2;
 if (path.back().dest == "p1-0"){//p2 took the last token : p2 win
   upWeight_p1 = -1;
   upWeight_p2 = 1;
 }
 else{
   upWeight_p1 = 1;
   upWeight_p2 = -1;
 }
 for (int i = 0; i < int(path.size()); i++){
   if (i%2 == 0){
     Edge edge = path[i];
     int oriWeight = g_.getEdgeWeight(edge.source, edge.dest);
     g_.setEdgeWeight(edge.source, edge.dest, oriWeight+upWeight_p1);
   }else{
     Edge edge = path[i];
     int oriWeight = g_.getEdgeWeight(edge.source, edge.dest);
     g_.setEdgeWeight(edge.source, edge.dest, oriWeight+upWeight_p2);
   }
 }
}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
