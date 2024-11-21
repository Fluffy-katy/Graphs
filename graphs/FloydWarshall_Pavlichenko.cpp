#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  

vector<int> FloydWarshall(vector<vector<double>> adjMatrix, int start, int end) 
{
    double n = adjMatrix.size();
    vector<vector<double>> next(n, vector<double>(n, -1)); 


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i != j && adjMatrix[i][j] == 0) 
            {
                adjMatrix[i][j] = INF;  
            }
            else if (adjMatrix[i][j] != INF) 
            {
                next[i][j] = j; 
            }
        }
    }


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMatrix[i][k] != INF && adjMatrix[k][j] != INF && adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    next[i][j] = next[i][k];  
                }
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[i][i] < 0)
        {
            return {};  
        }
    }


    vector<int> path;
    if (adjMatrix[start][end] == INF)
    {
        return path;  
    }
    for (int at = start; at != end; at = next[at][end])
    {
        if (at == -1) {
            return {};  
        }
        path.push_back(at);
    }
    path.push_back(end);  

    return path;
}