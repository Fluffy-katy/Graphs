#pragma once

#include <vector>

std::vector<int> FloydWarshall(std::vector<std::vector<double>> adjMatrix, int start, int end);

std::vector<int> BFS(std::vector<std::vector<double>> adj_matrix, int sourse, int sink);
