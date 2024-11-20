#pragma once

#include <vector>

std::vector<int> metodDeikstra(std::vector<std::vector<double>> adj_weight, int StartNode, int EndNode);

std::vector<int> FloydWarshall(std::vector<std::vector<double>> adjMatrix, int start, int end);

std::vector<int> BFS(std::vector<std::vector<double>> adj_matrix, int sourse, int sink);

bool DFS_Recursive(std::vector<std::vector<double>> adjMatrix,
    int start, int end, std::vector<bool>& visited, std::vector<int>& path);
