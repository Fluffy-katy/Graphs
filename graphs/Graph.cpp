#include "Graph.h"
#include <queue>

using namespace std;

void Connections::insert(Edge& edge) {
	edges.insert({ edge.edge, edge });
	nodes.insert({ edge.from });
	nodes.insert({ edge.to });
}

ifstream& operator >> (std::ifstream& file, Edge& edge) {
	if (file.is_open()) {
		file >> edge.edge;
		file >> edge.weight;
		file >> edge.from;
		file >> edge.to;
	}
	return file;
}

Graph::Graph(const unordered_map<int, Edge>& edges, const set<int>& nodes) : edges(edges) {
	int count = 0;
	for (int node : nodes) {
		this->nodes.insert({ count, node });
		count++;
	}
	SizeGraph = nodes.size();
	adj_weight.resize(SizeGraph, vector<double>(SizeGraph, 0.0));
	for (auto& [pipe_id, edge] : edges) {
		auto i = GetIndex(edge.from);
		auto j = GetIndex(edge.to);
		adj_weight[i][j] = edge.weight;
	}
}


int Graph::GetIndex(int vertice) const
{
	for (auto& [index, node] : nodes) {
		if (node == vertice) { return index; }
	}
	return INT16_MAX;
}

double Graph::lenghtShortestPath(std::vector<int>& path)
{
	double length = 0.0;
	if (path.size() < 2) { return length; }

	for (size_t i = 0; i < path.size() - 1; ++i) {
		int start = GetIndex(path[i]);
		int end = GetIndex(path[i + 1]);
		length += adj_weight[start][end];
	}
	return length;
}

//std::vector<std::vector<double>> Graph::get_adj_weight() {
//	return adj_weight;
//}
