#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    int vertices;
    vector<int> adj[100];
    bool visited[100];
public:
    Graph(int v){
        vertices = v;
        for (int i = 0; i < 100; i++)
            visited[i] = false;
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void resetVisited(){
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }
    void DFS(int start){
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < adj[start].size(); i++)   {
            int next = adj[start][i];
            if (!visited[next])
                DFS(next);
        }
    }
    void BFS(int start){
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()){
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int i = 0; i < adj[current].size(); i++){
                int next = adj[current][i];
                if (!visited[next])              {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
};
int main(){
    int vertices, edges;
    cout << "Enter number of buildings (vertices): ";
    cin >> vertices;
    Graph g(vertices);
    cout << "Enter number of roads (edges): ";
    cin >> edges;
    cout << "Enter connected buildings:" << endl;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int start;
    cout << "Enter starting building: ";
    cin >> start;
    cout << "\nDFS Traversal: ";
    g.DFS(start);
    g.resetVisited();
    cout << "\nBFS Traversal: ";
    g.BFS(start);
    cout << endl;
    return 0;
}