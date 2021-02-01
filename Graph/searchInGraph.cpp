/*
PROBLEM STATEMENT:
Implement depth first search in an undirected graph:
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <queue>
using namespace std;


class Graph {
  public:
    map<int, vector<int>> adjList;
    Graph(map<int, vector<int>> &adjList): adjList(adjList) {}
    void dfs(int start, vector<bool> &visited){
      if(!visited[start]) {
        visited[start] = true;
        cout << start << " ";
      }
      for(auto it = adjList[start].begin(); it != adjList[start].end(); ++it ){
        if(!visited[*it]) {
          dfs(*it, visited);
        }
      }
    }
    void DFS(int start, int v){
      vector<bool> visited(v, false);
      dfs(start, visited);
    }

    void bfs(int start, vector<bool> &visited, queue<int> &q){
      while(!q.empty()){
        if(!visited[start]){
          visited[start] = true;
          cout << start << " ";
          q.pop();
          for(auto it = adjList[start].begin(); it != adjList[start].end(); ++it){
            if(!visited[*it]){
              q.push(*it);
            }
          }
          start =q.front();
        } else {
          q.pop();
          start = q.front();
        }
      }
    }

    void BFS(int start, int v) {
      queue<int> q;
      q.push(start);
      vector<bool> visited(v, false);
      bfs(start, visited, q);
    }
};

int main() {

  map<int, vector<int>> adjList;
  adjList = {
    {1, {2,4}},
    {2, {1,3,5}},
    {3, {2, 8,7}},
    {4, {1,5}},
    {5, {2,4}},
    {7, {9,3}},
    {8, {3}},
    {9, {7}}
  };
  Graph g(adjList);
  g.DFS(1, 8);
  g.BFS(1, 8);
  return 0;
}