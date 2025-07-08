#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
  try
  {
    string fileName;
    int startVertex;

    cout << "Enter input file name: ";
    cin >> fileName;

    cout << "Enter starting vertex (0-based): ";
    cin >> startVertex;

    Graph graph;

    if (!graph.loadFromFile(fileName))
    {
      cerr << "Failed to load graph from file.\n";
      return 1;
    }

    vector<int> reachable = graph.bfs(startVertex);

    cout << "Reachable vertices: ";
    for (int v : reachable)
    {
      cout << v << " ";
    }

    cout << endl;
  }
  catch (const exception& e)
  {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
