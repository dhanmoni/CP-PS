/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class TemplateGraph {

  private:
    int V;
    unordered_map<T, list<pair<T, int>>> adjList;
    void dfsUtil(T start, unordered_map<T, bool> &visited) {
      if(!visited[start]){
        visited[start] = true;
        cout << start << " ";
        for(auto node: adjList[start]) {
          dfsUtil(node.first, visited);
        }
      }
    }
  public:
    TemplateGraph(int v): V(v) {}

    void addEdge(T from, T to,bool isBiDir, int weight) {
      adjList[from].push_back(make_pair(to, weight));
      if(isBiDir) {
        adjList[to].push_back(make_pair(from, weight));
      }
    }

    void printGraph() {
      for(auto m: adjList) {
        T key = m.first;
        list<pair<T, int>> list_pairs = m.second;
        cout << key << "-> ";
        for(auto lp: list_pairs) {
          cout << "(" << lp.first << ", " << lp.second << ")" << " ";
        }
        cout << "\t";
      }
    }
    void bfs(T start) {
      queue<T> q;
      unordered_map<T, bool> visited;
      q.push(start);
      visited[start] = true;
      while(!q.empty()) {

        T top = q.front();
        cout << top << " ";
        q.pop();
        for(auto node: adjList[top]){
          T f = node.first;
          if(visited[f] == false){
            q.push(f);
            visited[f] = true;
          }
        }
      }
    }

    void dfs(T start) {
      unordered_map<T, bool> visited;
      dfsUtil(start, visited);
    }

    bool containsCycleUtil(T start, unordered_map<T, bool> &visited, T parent) {
      visited[start] = true;
      for(auto node: adjList[start]) {
        if(!visited[node.first]){
          bool isTrue = containsCycleUtil(node.first, visited, start);
          if(isTrue) {
            return true;
          }
        } else if(node.first != parent) {
          return true;
        }
      }
      return false;
    }

    bool containsCycle(T start) {
      unordered_map<T, bool> visited;
      return containsCycleUtil(start, visited, start);
    }

};


int main() {
  
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
  TemplateGraph<int> g2(9);
  g2.addEdge(1, 2, true, 40);
   g2.addEdge(1, 4, true, 30);
  g2.addEdge(2, 3, true, 20);
  g2.addEdge(2, 5, true, 10);
  g2.addEdge(4, 5, true, 50);
  g2.addEdge(3, 8, true, 50);
  g2.addEdge(3, 7, true, 50);
  g2.addEdge(7, 9, true, 50);
  g2.printGraph();
  cout <<endl;
  // g2.bfs(1);
  if(g2.containsCycle(1)){
    cout << "Graph contains cycle";
  } else {
    cout << "Graph doesnot contain cycle";
  }
  return 0;
}