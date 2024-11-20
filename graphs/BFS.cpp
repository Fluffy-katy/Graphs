#include "Graph.h"
#include <queue>

using namespace std;

vector<int> BFS(vector<vector<double>> adj_matrix, int sourse, int sink)
{
    if (sourse > adj_matrix.size() || sink > adj_matrix.size()) return vector<int>();
    vector<int> prew;
    prew.resize(adj_matrix.size());

    //sourse = GetIndex(sourse);
    //sink = GetIndex(sink);

    prew[sourse] = -1;

    vector<bool> visited;
    visited.resize(adj_matrix.size());
    visited[sourse] = true;

    queue<int> q;
    q.push(sourse);


    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        for (int node = 0; node < adj_matrix.size(); node++)
        {
            int weight = adj_matrix[cur_node][node];
            if (weight != 0 && !visited[node])
            {
                visited[node] = true;
                q.push(node);
                prew[node] = cur_node;
            }
        }
    }

    vector<int> path;
    //path.push_back(nodes.at(sink));
    path.push_back(sink);
    while (prew[sink] != -1) {
        sink = prew[sink];
        /*path.push_back(nodes.at(sink)); */
        path.push_back(sink);
    }
    reverse(path.begin(), path.end());
    return path;
}