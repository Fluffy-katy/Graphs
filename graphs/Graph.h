#pragma once
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <fstream>



class Edge
{
    friend std::ifstream& operator >> (std::ifstream& file, Edge& edge);
public:
    Edge() {};
    Edge(int from, int to, int edge) : from(from), to(to), edge(edge) {};
    int from, to, edge, weight;
};


class Connections {
public:
    std::unordered_map<int, Edge> edges;
    std::set<int> nodes;
    void insert(Edge& edge);
};



class Graph
{
public:
    Graph(const std::unordered_map<int, Edge>& edges, const std::set<int>& nodes);
    std::vector<std::vector<double>> get_adj_weight();
    double lenghtShortestPath(std::vector<int>&);

    std::vector<int> metodDeikstra(std::vector<std::vector<double>> adj_weight, int StartNode, int EndNode);

    std::vector<int> FloydWarshall(std::vector<std::vector<double>> adjMatrix, int start, int end);
    
    std::vector<int> BFS(std::vector<std::vector<double>> adj_matrix, int sourse, int sink);
    std::vector<int> DFS(std::vector<std::vector<double>> adjMatrix, int start, int end);
    bool DFS_Recursive(std::vector<std::vector<double>> adjMatrix,
        int start, int end, std::vector<bool>& visited, std::vector<int>& path);

private:
    int GetIndex(int node) const;
    std::map<int, int> nodes;
    std::unordered_map<int, Edge> edges;
    std::vector<std::vector<double>> adj_weight;
    int SizeGraph;
};