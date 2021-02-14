/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

class Graph {
  class Edge {
    public:
    int end, start, cost;
    Edge(int start, int end, int cost) {
      this->end = end;
      this->start = start;
      this->cost = cost;
    }
  };
  private:
    int V;
    unordered_map<int, vector<Edge>> adjList;
  public:
    Graph(int n){
      this->V = n;
    }
    void addEdge(int start, int end, int cost){
      Edge fromEdge(start, end, cost);
      Edge toEdge(end, start, cost);
      adjList[start].push_back(fromEdge);
      adjList[end].push_back(toEdge);
    }
    void printGraph(){
      for(auto node: adjList){
        for(auto edge: adjList[node.first]){
          cout << node.first << "-> " << edge.end << ", " << edge.cost << "\t";
        }
        cout << endl;
      }
    }

    class myComparator
    {
    public:
        int operator() (const Edge& e1, const Edge& e2)
        {
            return e1.cost > e2.cost;
        }
    };
    void prims(int start){
      priority_queue<Edge, vector<Edge>, myComparator> pq;
      unordered_map<int, int> dist;
      vector<bool> visited(V, false);
      int totalEdge = V - 1;
      int edgeCount = 0;
      for(auto node: adjList){
        dist[node.first] = INT_MAX;
      }
      dist[start] = 0;
      visited[start] = true;
      for(auto edges: adjList[start]){
        Edge newEdge(edges.start, edges.end, edges.cost);
        pq.push(newEdge);
      }
      while(!pq.empty() && edgeCount != totalEdge){
        auto top = pq.top();
        pq.pop();
        if(dist[top.end] > top.cost && visited[top.end] == false){
          cout << top.start << "->" << top.end << "-> ";
          dist[top.end] = top.cost;
          visited[top.end] = true;
          edgeCount++;
          for(auto edges: adjList[top.end]){
            if(visited[edges.end] == false){
              Edge newEdge(edges.start, edges.end, edges.cost);
              pq.push(newEdge);
            }
          }
        }
      }

    }
};

int main() {
  Graph g(7);
  g.addEdge(2,0,0);
  g.addEdge(2,5,6);
  g.addEdge(0,5,7);
  g.addEdge(0,1,9);
  g.addEdge(0,3,5);
  g.addEdge(5,3,2);
  g.addEdge(5,6,1);
  g.addEdge(3,1,-2);
  g.addEdge(3,6,3);
  g.addEdge(1,4,3);
  g.addEdge(1,6,4);
  g.addEdge(6,4,6);
  g.printGraph();
  g.prims(2);
  return 0;
} 