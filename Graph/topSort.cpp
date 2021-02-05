#include<iostream>
#include <list>
#include <stack>
using namespace std;
class G {
   int n;
   list<int> *adj;
   //declaration of functions
   void topologicalSort(int v, bool visited[], stack<int> &Stack);
   public:
   G(int n); //constructor
   void addEd(int v, int w);
   void topoSort();
};
G::G(int n) {
   this->n = n;
   adj = new list<int> [n];
}
void G::addEd(int v, int w)  { // add the edges to the graph.
   adj[v].push_back(w); //add w to v’s list
}
void G::topologicalSort(int v, bool visited[], stack<int> &Stack) {
   visited[v] = true; //mark current node as visited
   list<int>::iterator i;
   //Recur for all the vertices adjacent to this vertex.
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
         topologicalSort(*i, visited, Stack);
         Stack.push(v);
}
void G::topoSort() {
   stack<int> Stack;
   bool *visited = new bool[n];
   //Mark all the vertices which are not visited.
   for (int i = 0; i < n; i++)
      visited[i] = false;
      for (int i = 0; i < n; i++)
         if (visited[i] == false)
            //Call the function topologicalSort().
            topologicalSort(i, visited, Stack);
         while (Stack.empty() == false) {
            cout << Stack.top() << " "; //print the element
            Stack.pop();
         }
}
int main() {
   G g(6);
   g.addEd(4, 2);
   g.addEd(5, 1);
   g.addEd(4, 0);
   g.addEd(3, 1);
   g.addEd(1, 3);
   g.addEd(3, 2);
   cout << " Topological Sort of the given graph \n";
   g.topoSort();
   return 0;
}