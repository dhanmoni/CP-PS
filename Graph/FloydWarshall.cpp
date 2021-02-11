/*
PROBLEM STATEMENT:

URL:


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
#include<climits>

#define N 4
#define I INT_MAX

using namespace std;

class TemplateGraph {
  public:
    void floydWarshall(int adjMat[N][N], int start, int end){

      //Intialize path and distance matrix;
      int dist[N][N], path[N][N];

      //add values to path matrix
      for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
          dist[i][j] = adjMat[i][j];
          if(adjMat[i][j] != I && i != j){
            path[i][j] = i;
          } else {
            path[i][j] = -1;
          }
        }
      }
      
      for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
          for(int j = 0; j < N; ++j){
            if(dist[i][k] == I || dist[k][j] == I) {
              continue;
            }
            if(dist[i][j] > dist[i][k] + dist[k][j]){
              dist[i][j] = dist[i][k] + dist[k][j];
              path[i][j] = path[k][j];
            }
          }
        }
      }

      for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
          cout << dist[i][j] << " ";
        }
        cout << "\t";
      }
      cout << endl;
      for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
          cout << path[i][j] << " ";
        }
        cout << "\t";
      }

      //Look for negative cycle( if dist[i][i] < 0 then -ve cycle exists);

      for(int i = 0; i < N; ++i){
        if(dist[i][i] < 0) {
          cout << "negative cycle exists!";
        }
      }

      printPath(dist,path, start,end);

    }

    void printPath(int dist[N][N], int path[N][N], int start, int end){
      stack<int> s;
      cout << path[1][2];
      cout <<endl;
      cout << "Shortest path between " << start << " and " << end << " -> " << dist[start][end] << " -> " << endl;
      s.push(end);
      // cout << end << endl;
      while(true){
        end = path[start][end];
        // cout << end << endl;
        if(end == -1) return;
        s.push(end);
        if(end == start) break;
      }
      while(!s.empty()){
        int top = s.top();
        cout << top << " ";
        s.pop();
      }
    }
};

int main() {
  int adjMatrix[N][N] =
    {
        { 0, 3, 6, 15 },
        { I, 0, -2, I },
        { I, I, 0, 2 },
        { 1, I, I, 0 }
    };
  TemplateGraph g;
  g.floydWarshall(adjMatrix, 0,2);
  return 0;
}