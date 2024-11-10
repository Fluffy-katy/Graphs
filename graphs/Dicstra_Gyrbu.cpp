#include "Graph.h"
#include <queue>

using namespace std;

vector<int> Graph::metodDeikstra(vector<vector<double>> adj_weight, int StartNode, int EndNode) {
	vector<int> dist(SizeGraph, INT_MAX);
	vector<int> prev(SizeGraph, -1);
	vector<bool> visited(SizeGraph, false);

	StartNode = GetIndex(StartNode);
	EndNode = GetIndex(EndNode);

	dist[StartNode] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, StartNode });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (u == EndNode) { break; }

		visited[u] = true;

		for (int v = 0; v < SizeGraph; ++v) {
			if (!visited[v] && adj_weight[u][v] && dist[u] != INT_MAX &&
				dist[u] + adj_weight[u][v] < dist[v])
			{
				dist[v] = dist[u] + adj_weight[u][v];
				prev[v] = u;
				pq.push({ dist[v], v });
			}
		}
	}

	vector<int> path;
	int current_node = EndNode;
	while (current_node != StartNode) {
		path.push_back(nodes.at(current_node));
		if (prev[current_node] != -1) {
			current_node = prev[current_node];
		}
		else {
			return vector<int>();
		}
	}
	path.push_back(nodes.at(StartNode));
	reverse(path.begin(), path.end());
	return path;
}