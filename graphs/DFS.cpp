#include "Graph.h"
#include <stack>
#include <vector>

using namespace std;

// Основная функция для вызова DFS 
vector<int> DFS(vector<vector<double>> adjMatrix, int start, int end) {
    //создаем вектор, его размер - кол-во вершин в графе (для посещ. вершин)
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> path; //вектор для вершин, которые будут входить в наш путь
    stack<int> s; // вершины, которые мы хотим посетить

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

