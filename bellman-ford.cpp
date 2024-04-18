#include <bits/stdc++.h>

using namespace std;

void bellman(ifstream &infile, ofstream &outfile) {

  int start, dest, weight, V, src;
  string type1, type2;

  infile >> type1 >> V;
  infile >> type2 >> src;
  src--;

  int graph[V][V];
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      graph[i][j] = 0;
    }
  }

  while (infile >> start >> dest >> weight) {
    graph[start - 1][dest - 1] = weight;
  }

  int dis[V];
  for (int i = 0; i < V; i++)
    dis[i] = INT_MAX;

  dis[src] = 0;

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dis[i] != INT_MAX && dis[i] + graph[i][j] < dis[j] &&
          graph[i][j] != 0)
        dis[j] = dis[i] + graph[i][j];
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      int weight = graph[i][j];
      if (dis[i] != INT_MAX && dis[i] + weight < dis[j])
        outfile << "Graph contains negative weight cycle" << endl;
    }
  }

  outfile << "Vertex Distance from Source" << endl;
  for (int i = 0; i < V; i++)
    outfile << i << "\t\t" << dis[i] << endl;
}
