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
    int GetIndex(int node) const;
    int GetNode(int index) const;

private:
    std::vector<int> createNodePath(std::vector<int>&);
    std::map<int, int> nodes;
    std::unordered_map<int, Edge> edges;
    std::vector<std::vector<double>> adj_weight;
    int SizeGraph;
};