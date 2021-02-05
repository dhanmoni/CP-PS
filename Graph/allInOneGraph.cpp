/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
  private:
    int V; // number of vertices
    unordered_map<char, list<pair<char, int>>> adj;
  public:
    Graph(int v);
    void addEdge(char from, char to, bool isDir, int weight);
    void printGraph();
};
Graph::Graph(int v) {
    this->V = v;
}

void Graph::addEdge(char from, char to, bool isBiDir, int weight){
  adj[from].push_back(make_pair(to, weight));
  if(isBiDir) {
    adj[to].push_back(make_pair(from, weight));
  }
}
void Graph::printGraph() {
  for(auto l: adj) {
    char vertex = l.first;
    list<pair<char, int>> neighbours = l.second;
    cout << vertex << "-> ";
    for(auto p: neighbours) {
      cout <<"(" << p.first << ", " << p.second << ") ";
    }
    cout << "\t";
  }
}

int main() {

  Graph g(4);
  g.addEdge('A', 'B', true, 20);
  g.addEdge('B', 'D', true, 40);
  g.addEdge('C', 'D', true, 30);
  g.addEdge('C', 'A', true, 10);
  g.addEdge('A', 'D', false, 50);
  g.printGraph();
  
  return 0;
}