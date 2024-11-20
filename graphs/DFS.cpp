#include "Graph.h"
#include <queue>

using namespace std;

// ������� DFS ��� ������ ���� � �����
bool DFS_Recursive(vector<vector<double>> adjMatrix, int start, int end, vector<bool>& visited, vector<int>& path) {
    visited[start] = true;
    /*path.push_back(nodes.at(start));*/
    path.push_back(start);

    if (start == end) {
        return true;
    }

    // �������� �� ���� �������
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[start][i] > 0 && !visited[i]) {
            if (DFS_Recursive(adjMatrix, i, end, visited, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

// �������� ������� ��� ������ DFS
vector<int> DFS(vector<vector<double>> adjMatrix, int start, int end) {
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> path;
    //start = GetIndex(start);
    //end = GetIndex(end);

    if (DFS_Recursive(adjMatrix, start, end, visited, path)) {
        return path;
    }
    else {
        return {};
    }
}