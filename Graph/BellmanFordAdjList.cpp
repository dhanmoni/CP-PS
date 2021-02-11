/*
PROBLEM STATEMENT:

URL:


*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
#include <climits>
#include <stack>
#include <string>
#include <map>

using namespace std;


template <typename T>
class TemplateGraph {
  class Edge {
    public:
    T to, from;
    int cost;
    Edge(T from, T to, int weight) {
      this->to = to;
      this->from = from;
      this->cost = weight;
    }
  };

  private:
    int V;
    unordered_map<T, list<Edge>> adjList;
    
  public:
    TemplateGraph(int v): V(v) {}
    void addEdge(T from, T to, int weight) {
      Edge ed(from, to, weight);
      adjList[from].push_back(ed);
    }

    void printGraph() {
      for(auto m: adjList) {
        T key = m.first;
        list<Edge> list_pairs = m.second;
        cout << key << "-> ";
        for(auto lp: list_pairs) {
          cout << "(" << lp.from << ", " << lp.to << ", "<< lp.cost << ")" << " ";
        }
        cout << "\t";
      }
    }
    

    void bellmanFord(T start, T end) {
      map<T, int> dist;
      map<T, T> parent;
      stack<T> res;
      for(auto node: adjList){
        // T key = node.first;
        // dist[key] = INT_MAX;
        for(auto edges: adjList[node.first]){
          dist[edges.to] = INT_MAX;
        }
      }
      
      dist[start] = 0;
      // // pq.push(make_pair(start, 0));
      for(int i = 0; i < V - 1; ++i){

        for(auto node: adjList){
          // cout << "itr-> " << node.first << ", " ;
          for(auto edge: adjList[node.first]){
            // cout << edge.from << "->" << edge.to << "+" << edge.cost;
            T to = edge.to;
            T from = edge.from;
            int wt = edge.cost;
            if(dist[from] != INT_MAX && dist[from] + wt < dist[to]){
              // cout <<" less ->" << dist[from] + wt << ","<< dist[to] << "\t";
              dist[to] = dist[from] + wt;
              parent[to] = from;
              // cout << " new val of " << to << " = " << dist[to] << "\t";
            }
          }
        }
      }

      for(auto node: adjList){
        for(auto edge: adjList[node.first]){
            // cout << edge.to << "," << edge.from;
            T to = edge.to;
            T from = edge.from;
            int wt = edge.cost;
            if(dist[from] + wt < dist[to]){
              dist[to] = INT_MIN;
            }
          }
      }
      for(auto node: dist){
        cout << node.first << "-> "<< node.second << "\t";
      }
      cout << endl;
      cout << "Total cost from " << start << " to "<<end << " is = "<< dist[end] << " and path = ";
      T curr = end;
      for(auto node: parent){
        if(parent.find(curr) != parent.end()){
          res.push(curr);
          curr = parent[curr];
        }
      }
      res.push(start);
      while(!res.empty()){
        T top = res.top();
        cout << top << " ";
        res.pop();
      }
    }


};


int main() {
  
  vector<string> vec = {"hello", "world", "Everyone"};
  //C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0
  // TemplateGraph<string> g3(9);
  // g3.addEdge("AB", "BC", true, 2);
  // g3.addEdge("AB", "CD", true, 5);
  // g3.addEdge("BC", "DE", true, 7);
  // g3.addEdge("CD", "DE", true, 2);
  // g3.addEdge("CD", "EF", true, 3);
  // g3.addEdge("EF", "FG", true, 4);
  // g3.addEdge("EF", "HI", true, 3);
  // g3.addEdge("FG", "GH", true, 1);
  // g3.addEdge("DE", "FG", true, 1);
  // // g.printGraph();
  // g3.dijkstras("AB", "FG");
    TemplateGraph<char> g(9);
  g.addEdge('A', 'B', 2);
  g.addEdge('A', 'C', 5);
  g.addEdge('B', 'D', 7);
  g.addEdge('C', 'D', -9);
  g.addEdge('C', 'E', 3);
  g.addEdge('E', 'F', 4);
  g.addEdge('E', 'H', 3);
  g.addEdge('F', 'G', 1);
  g.addEdge('D', 'F', 1);
  g.bellmanFord('A', 'F');
  // g.dijkstras('A', 'F');
  
  // TemplateGraph<char> g(5);
  // g.addEdge('A', 'B', true, 20);
  // g.addEdge('B', 'D', true, 40);
  // g.addEdge('C', 'D', true, 30);
  // g.addEdge('C', 'A', true, 10);
  // g.addEdge('A', 'D', false, 50);
  // // g.addEdge('C', 'F', false, 40);
  // // g.addEdge('D', 'E', false, 10);
  // // g.printGraph();
  // // cout << endl;
  // // g.bfs('A');
  // // g.dfs('A');

  // cout << g.containsCycle('A');
  // TemplateGraph<int> g2(9);
  // g2.addEdge(1, 2, true, 4);
  // g2.addEdge(4, 1, true, 3);
  // g2.addEdge(2, 3, true, 2);
  // g2.addEdge(2, 5, true, 4);
  // g2.addEdge(4, 5, true, 1);
  // g2.addEdge(3, 8, true, 5);
  // g2.addEdge(3, 7, true, 2);
  // g2.addEdge(7, 9, true, 1);
  // g2.dijkstras(1, 5);
  // g2.printGraph();
  // cout <<endl;
  // // g2.bfs(1);
  // if(g2.containsCycle(1)){
  //   cout << "Graph contains cycle";
  // } else {
  //   cout << "Graph doesnot contain cycle";
  // }

  return 0;
}