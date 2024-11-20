// Capitan's file
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include <chrono>

#include "Algorithm.h"
#include "Graph.h"

using namespace std;

Connections load(string path) {
    Connections connections;
    ifstream fin;
    fin.open(path);
    int count_connections;
    fin >> count_connections;
    while (count_connections--) {
        Edge edge;
        fin >> edge;
        connections.insert(edge);
    }
    fin.close();
    return connections;
}

void Run(string method_name, vector<int>(* method)(vector<vector<double>>, int, int),
    int startNode, int endNode, string path) {

    Connections connections = load(path);

    Graph graph = Graph(connections.edges, connections.nodes);
    vector<vector<double>> adj_weight = graph.get_adj_weight();
    startNode = graph.GetIndex(startNode);
    endNode = graph.GetIndex(endNode);

    cout << endl << "Running the algorithm: " << method_name << endl;
    auto start = chrono::system_clock::now();
    vector<int> result = (*method)(adj_weight, startNode, endNode);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << "Algorithm " << method_name << (result.size() ? " completed successfully." : " didn't find the way") << endl;
    cout << "Time: " << time << " mcs" << endl << endl;

    cout << "Found Way: " << endl;
    for (auto node : result) {
        cout << graph.GetNode(node) << " -> ";
    }
    cout << "end" << endl;
    cout << "Len: " << graph.lenghtShortestPath(result) << endl;


}

int main() {

    int a1 = 1;
    int b1 = 20;
    int a2 = 1;
    int b2 = 6;
    
    cout << "--------------method Deikstra--------------" << endl;
    Run("method Deikstra graph 1", metodDeikstra, a2, b2, "Graph/graph1.txt");
    Run("method Deikstra graph 2", metodDeikstra, a1, b1, "Graph/graph8.txt");
    Run("method Deikstra graph 3", metodDeikstra, a1, b1, "Graph/graphCC.txt");
    Run("method Deikstra graph 4", metodDeikstra, a1, b1, "Graph/graphIC.txt");
    Run("method Deikstra graph 5", metodDeikstra, a1, b1, "Graph/graphC2.txt");

    cout << endl << "--------------method BFS--------------" << endl;
    Run("method BFS graph 1", BFS, a2, b2, "Graph/graph1.txt");
    Run("method BFS graph 2", BFS, a1, b1, "Graph/graph8.txt");
    Run("method BFS graph 3", BFS, a1, b1, "Graph/graphCC.txt");
    Run("method BFS graph 4", BFS, a1, b1, "Graph/graphIC.txt");
    Run("method BFS graph 5", BFS, a1, b1, "Graph/graphC2.txt");

    cout << endl << "--------------method DFS--------------" << endl;
    Run("method DFS graph 1", DFS, a2, b2, "Graph/graph1.txt");
    Run("method DFS graph 2", DFS, a1, b1, "Graph/graph8.txt");
    Run("method DFS graph 3", DFS, a1, b1, "Graph/graphCC.txt");
    Run("method DFS graph 4", DFS, a1, b1, "Graph/graphIC.txt");
    Run("method DFS graph 5", DFS, a1, b1, "Graph/graphC2.txt");

    cout << "--------------method FloydWarshall--------------" << endl;
    Run("method FloydWarshall graph 1", FloydWarshall, a2, b2, "Graph/graph1.txt");
    Run("method FloydWarshall graph 2", FloydWarshall, a1, b1, "Graph/graph8.txt");
    Run("method FloydWarshall graph 3", FloydWarshall, a1, b1, "Graph/graphCC.txt");
    Run("method FloydWarshall graph 4", FloydWarshall, a1, b1, "Graph/graphIC.txt");
    Run("method FloydWarshall graph 5", FloydWarshall, a1, b1, "Graph/graphC2.txt");


    return 0;

}