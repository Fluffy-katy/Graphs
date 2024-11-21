#include "Graph.h"
#include <stack>
#include <vector>

using namespace std;

// �������� ������� ��� ������ DFS 
vector<int> DFS(vector<vector<double>> adjMatrix, int start, int end) {
    //������� ������, ��� ������ - ���-�� ������ � ����� (��� �����. ������)
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> path; //������ ��� ������, ������� ����� ������� � ��� ����
    stack<int> s; // �������, ������� �� ����� ��������

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        path.push_back(u);

        if (u == end) {
            return path;
        }

        for (int v = 0; v < adjMatrix.size(); ++v) {
            if (adjMatrix[u][v] > 0 && !visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }

    return {}; 
}

