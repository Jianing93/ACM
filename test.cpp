#include<iostream>
#include<vector>

using namespace std;

struct Edge {
  int u, v;
};

vector<Edge> e;

int main() {
  Edge edge;
  edge.u = 1;
  edge.v = 2;
  e.push_back(edge);

  Edge &e2 = e[0];
  e2.u = 10;
  
  cout << e[0].u << " " << e2.u << endl;
  return 0;
}
