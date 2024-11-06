// Capitan's file
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include <chrono>

#include "Graph.h"

using namespace std;

#define RUN(x, show_sort) {                \
    Run(#x, x, data, show_sort);           \
}


//template<typename FindWayMethod>
//void Run(FindWayMethod findway_method) {
//    cout << "Running the algorithm: " << method_name << endl;
//
//    auto start = chrono::high_resolution_clock::now();
//    
//    findway_method_method();
//    auto stop = chrono::system_clock::now();
//    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
//
//    cout << "Algorithm " << method_name << (is_sorted ? " completed successfully." : " completed with an error.") << endl;
//    cout << "Time: " << time << " mcs" << endl << endl;
//
//}


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

    Graph graph = Graph(connections.edges, connections.nodes);
    vector<int> result = graph.metodDeikstra(1, 6);

    for (auto node : result) {
        cout << node << " -> ";
    }
    cout << "end" << endl;
    cout << "Len: " << graph.lenghtShortestPath(result) << endl;
    return 0;

}