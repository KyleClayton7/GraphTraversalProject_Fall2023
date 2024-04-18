#include "bellman-ford.cpp"

using namespace std;

int minKey(int key[], bool mstSet[], int V) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

void prim(ifstream &infile, ofstream &outfile) {
  int src, dest, weight, V;
  string type;

  infile >> type >> V;

  int graph[V][V];

  while (infile >> src >> dest >> weight) {
    graph[src - 1][dest - 1] = weight;
    graph[dest - 1][src - 1] = weight;
  }

  int parent[V];

  int key[V];

  bool mstSet[V];

  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  key[0] = 0;

  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {

    int u = minKey(key, mstSet, V);

    mstSet[u] = true;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
    }
  }

  outfile << "Edge \tWeight\n";
  for (int i = 1; i < V; i++)
    outfile << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
