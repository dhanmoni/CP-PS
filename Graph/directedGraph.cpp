/*
PROBLEM STATEMENT:
Implement directed graph
URL:


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

class DirectedGraph
{
private:
  void dfsRec(int start, vector<bool> &visited)
  {
    if (!visited[start])
    {
      visited[start] = true;
      cout << start << " ";
    }
    for (auto it = adjList[start].begin(); it != adjList[start].end(); ++it)
    {
      if (!visited[*it])
      {
        dfsRec(*it, visited);
      }
    }
  }

  void topologicalSort(int v, vector<bool> visited, stack<int> &Stack)
  {
    visited[v] = true; //mark current node as visited
    //Recur for all the vertices adjacent to this vertex.
    for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i)
      if (!visited[*i])
        topologicalSort(*i, visited, Stack);
    Stack.push(v);
  }

public:
  map<int, vector<int>> adjList;
  int V;
  DirectedGraph(int v) : V(v) {}
  void addEdge(int to, int from)
  {
    adjList[to].push_back(from);
  }
  void printGraph()
  {
    map<int, vector<int>>::iterator it;

    for (it = adjList.begin(); it != adjList.end(); ++it)
    {
      cout << it->first << "-> ";
      for (int i = 0; i < it->second.size(); ++i)
      {
        cout << it->second[i] << " ";
      }
      cout << "\t";
    }
    cout << endl;
  }

  void dfs(int start)
  {
    vector<bool> visited(V, false);
    dfsRec(start, visited);
  }

  //not working...
  void topSort()
  {
    stack<int> s;
    vector<bool> visited(V, false);

    //Mark all the vertices which are not visited.
    for (int i = 0; i < V; i++)
      visited[i] = false;
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        //Call the function topologicalSort().
        topologicalSort(i, visited, s);
    while (s.empty() == false)
    {
      cout << s.top() << " "; //print the element
      s.pop();
    }
  }
};

int main()
{
  DirectedGraph g(5);
  g.addEdge(1, 3);
  g.addEdge(3, 7);
  g.addEdge(3, 5);
  g.addEdge(5, 8);
  g.addEdge(5, 7);
  g.printGraph();
  g.dfs(1);
  cout << endl;
  g.topSort();
  return 0;
}