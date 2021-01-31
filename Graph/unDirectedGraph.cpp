/*
PROBLEM STATEMENT:
Impliment unordered graph and its operations:
URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <set>
using namespace std;


//USING VERTEX AND EDGES AS EDGE LIST----

class Graph {
  public:
  vector<int> v;
  vector<pair<int, int>> e;
  Graph(vector<int> &vertices,vector<pair<int, int>> &edges) : v(vertices), e(edges) {}
  void printVertexnEdges() {
    for(int i = 0; i <v.size(); ++i) {
      cout << v.at(i) << " ";
    }
    cout <<endl;
    for(int j = 0; j <e.size(); ++j) {
      cout << "{"<< e[j].first << "," << e[j].second << "}" << "\t";
    }
    cout <<endl;
  }
};

//USING ADJACENCY LIST----
// 1)
class GraphUsingAL1 {
  public:
    map<int, vector<int>> adjList;
    GraphUsingAL1(map<int, vector<int>> &adjList) : adjList(adjList){}
    void printGraph() {
      map<int, vector<int>>::iterator it;
      for(it = adjList.begin(); it != adjList.end(); ++it) {
        cout << it->first << "-> ";
        for(int j = 0; j < it->second.size(); ++j) {
          cout << it->second[j] << " ";
        }
        cout << "\t";
    }
    cout <<endl;
  }
};

//2) -- using vectex class for storing the vertex and the adjacents---
class Vertex {
  public:
    int key;
    set<int> adj;
    Vertex(int key, set<int> adj): key(key), adj(adj){}
};

class GraphUsingALAndVertexCls {
  public:
    vector<Vertex> adjList;
    GraphUsingALAndVertexCls(vector<Vertex> adjList) : adjList(adjList){}
    void printGraph(){
      for(int i = 0; i < adjList.size(); ++i){
        cout << adjList[i].key << "-> ";
        set<int>::iterator it;
        for(it = adjList[i].adj.begin(); it != adjList[i].adj.end(); ++it){
          cout << *it << " ";
        }
        cout << "\t";
      }
      cout <<endl;
    }
};

class GraphUsingAdjMatrix {
  public:
    vector<vector<int>> matrix;
    GraphUsingAdjMatrix(vector<vector<int>> &matrix) : matrix(matrix) {}
    void printMatrix() {
      for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
          cout << matrix[i][j] << " ";
        }
        cout<<endl;
      }
      cout << endl;
    }
};


int main() {

  //USING VERTEX AND EDGES AS EDGE LIST----

  vector<int> vertices= {1,2,3,4,5};
  vector<pair<int, int>> edges= {{1,2},{1,4}, {2,1}, {2,5}, {2,3}, {3,2}, {4,1}, {4,5}, {5,2}, {5,4}};

  Graph g(vertices, edges);
  g.printVertexnEdges();

  //USING ADJACENCY LIST----
  //METHOD-1:
  map<int, vector<int>> adjList1 = {
    {1, {2,4}},
    {2, {1,3,5}},
    {3, {2}},
    {4, {1,5}},
    {5, {2,4}}
  };
  GraphUsingAL1 g1(adjList1);
  g1.printGraph();

  //METHOD 2-
  vector<Vertex> adjList2 = {Vertex(1, {2,4}), 
  Vertex({2, {1,3,5}}),
  Vertex({3, {2}}),
  Vertex({4, {1,5}}),
  Vertex({5, {2,4}})
  };
  GraphUsingALAndVertexCls g2(adjList2);
  g2.printGraph();

  vector<vector<int>> adjMatrix = {
    {0,1,0,1,0},
    {1,0,1,0,1},
    {0,1,0,0,0},
    {1,0,0,0,1},
    {0,1,0,1,0}
  };
  GraphUsingAdjMatrix g3(adjMatrix);
  g3.printMatrix();

  return 0;
}