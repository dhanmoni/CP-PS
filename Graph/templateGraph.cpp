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
#include <climits>
#include <stack>
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
    vector<int> vec;
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

    void dijkstras(T start, T end) {
      unordered_map<T, int> dist;
      priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
      unordered_map<T, T> parent;
      stack<T> res;
      for(auto vtx: adjList) {
        T key = vtx.first;
        dist[key] = INT_MAX;
      }
      pq.push(make_pair(start, 0));
      dist[start] = 0;
      parent[start] = 0;
      while(!pq.empty()){
        T top = pq.top().first;
        pq.pop();
        for(auto nbr: adjList[top]){
          T node = nbr.first;
          int wt = nbr.second;
          int newWt = dist[top] + wt;
          if(newWt < dist[node]) {
            dist[node] = newWt;
            pq.push(make_pair(node, dist[node]));
            parent[node] = top;
          }
        }
      }
      T curr = end;
      while(curr != 0) {
        res.push(curr);
        curr = parent[curr];
      }
      cout << "shortest distance length = "<< dist[end] << " and path = ";
      while(!res.empty()){
        T node = res.top();
        res.pop();
        cout << node << " ";
      }
      
    }

};


int main() {

    TemplateGraph<char> g(9);
  g.addEdge('A', 'B', true, 2);
  g.addEdge('A', 'C', true, 5);
  g.addEdge('B', 'D', true, 7);
  g.addEdge('C', 'D', true, 2);
  g.addEdge('C', 'E', true, 3);
  g.addEdge('E', 'F', true, 4);
  g.addEdge('E', 'H', true, 3);
  g.addEdge('F', 'G', true, 1);
  g.addEdge('D', 'F', true, 1);
  g.printGraph();
  g.dijkstras('A', 'F');
  
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
  // g2.addEdge(1, 2, false, 40);
  //  g2.addEdge(4, 1, false, 30);
  // g2.addEdge(2, 3, false, 20);
  // g2.addEdge(2, 5, false, 10);
  // g2.addEdge(4, 5, false, 50);
  // g2.addEdge(3, 8, false, 50);
  // g2.addEdge(3, 7, false, 50);
  // g2.addEdge(7, 9, false, 50);
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