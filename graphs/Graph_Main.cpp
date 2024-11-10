// Capitan's file
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include <chrono>

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

void Run(string method_name, vector<int>(Graph::* method)(vector<vector<double>>, int, int),
    int startNode, int endNode, string path) {

    Connections connections = load(path);

    Graph graph = Graph(connections.edges, connections.nodes);
    vector<vector<double>> adj_weight = graph.get_adj_weight();

    cout << endl << "Running the algorithm: " << method_name << endl;
    auto start = chrono::system_clock::now();
    vector<int> result = (graph.*method)(adj_weight, startNode, endNode);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << "Algorithm " << method_name << (result.size() ? " completed successfully." : " didn't find the way") << endl;
    cout << "Time: " << time << " mcs" << endl << endl;

    cout << "Found Way: " << endl;
    for (auto node : result) {
        cout << node << " -> ";
    }
    cout << "end" << endl;
    cout << "Len: " << graph.lenghtShortestPath(result) << endl;


}

int main() {

    Connections connections;

    ifstream fin;
    fin.open("Graph/graph2.txt");
    int count_connections;
    fin >> count_connections;

    while (count_connections--) {
        Edge edge;
        fin >> edge;
        connections.insert(edge);
    }
    fin.close();



    // Watch Example (how
    cout << "--------------method Deikstra--------------" << endl;

    
    Run("method Deikstra graph 1", &Graph::metodDeikstra, 1, 6, "Graph/graph1.txt");
    Run("method Deikstra graph 3", &Graph::metodDeikstra, 1, 9, "Graph/graph3.txt");
    Run("method Deikstra graph 4", &Graph::metodDeikstra, 1, 7, "Graph/graph4.txt");
    Run("method Deikstra graph 5", &Graph::metodDeikstra, 1, 4, "Graph/graph5.txt");

    /*cout << endl << "--------------method BFS--------------" << endl;
    Run("method BFS graph 1", &Graph::BFS, 1, 6, "Graph/graph1.txt");
    Run("method BFS graph 3", &Graph::BFS, 1, 9, "Graph/graph3.txt");
    Run("method BFS graph 4", &Graph::BFS, 1, 7, "Graph/graph4.txt");
    Run("method BFS graph 5", &Graph::BFS, 1, 4, "Graph/graph5.txt");

    cout << endl << "--------------method DFS--------------" << endl;
    Run("method DFS graph 1", &Graph::DFS, 1, 6, "Graph/graph1.txt");
    Run("method DFS graph 3", &Graph::DFS, 1, 9, "Graph/graph3.txt");
    Run("method DFS graph 4", &Graph::DFS, 1, 7, "Graph/graph4.txt");
    Run("method DFS graph 5", &Graph::DFS, 1, 4, "Graph/graph5.txt");*/

    cout << "--------------method FloydWarshall--------------" << endl;
    Run("method FloydWarshall graph 1", &Graph::FloydWarshall, 1, 6, "Graph/graph1.txt");
    Run("method FloydWarshall graph 3", &Graph::FloydWarshall, 1, 9, "Graph/graph3.txt");
    Run("method FloydWarshall graph 4", &Graph::FloydWarshall, 1, 7, "Graph/graph4.txt");
    Run("method FloydWarshall graph 5", &Graph::FloydWarshall, 1, 4, "Graph/graph5.txt");

    return 0;

}