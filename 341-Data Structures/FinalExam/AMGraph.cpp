#include <iostream>
using namespace std;

class AMGraph {
 public:
  AMGraph(int capacity);
  void addEdge(int a, int b);
  void removeEdge(int a, int b);
  bool getEdge(int a, int b);
  void printGraph();

 private:
  bool** edges;
  int capacity;
};

// THINK CAREFULLY about what this needs to do
// 15 points
AMGraph::AMGraph(int capacity) : capacity(capacity) {
  edges = new bool*[capacity];
  for (int i = 0; i < capacity; i++) {
    edges[i] = new bool[capacity];
    for (int col = 0; col < capacity; col++) {
      edges[i][col] = false;
    }
  }
}

// adds an edge
void AMGraph::addEdge(int a, int b) {
  // from is row to is col
  edges[a][b] = true;
}

// removes and edge
void AMGraph::removeEdge(int a, int b) {
  // edges at a - 1, b- 1
  edges[a][b] = false;
}

// get's edge
bool AMGraph::getEdge(int a, int b) {
  // gets edge
  return edges[a][b];
}

// just for testing purposes
void AMGraph::printGraph() {
  cout << "  01234567" << endl;
  for (int i = 0; i < capacity; i++) {
    cout << i << " ";
    for (int col = 0; col < capacity; col++) {
      if (edges[i][col] == false)
        cout << 0;
      else
        cout << 1;
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  AMGraph graph(8);

  graph.addEdge(5 - 1, 4 - 1);
  graph.addEdge(4 - 1, 5 - 1);

  graph.printGraph();

  if (graph.getEdge(5 - 1, 4 - 1) == true) cout << "5-4 IS an edge" << endl;

  graph.removeEdge(5 - 1, 4 - 1);

  graph.printGraph();

  if (graph.getEdge(5 - 1, 4 - 1) == false)
    cout << "5-4 is NOT an edge" << endl;
}