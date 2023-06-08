#include<iostream>
using namespace std;
 
#define INF 9999999
#define V 6
 
int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                   {3, 0, 2, 1, 10, 0},
                   {0, 2, 0, 3, 0, 5},
                   {0, 1, 3, 0, 5, 0},
                   {0, 10, 0, 5, 0, 4},
                   {1, 0, 5, 0, 4, 0}};
                   
void printMST(int parent[]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
 
void primMST() {
    int parent[V];
    int key[V];
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = false;
 
    key[0] = 0;
    parent[0] = -1;
 
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
 
        for(int i=0;i<V;i++)
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
 
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent);
}
 
int main() {
    primMST();
 
    return 0;
}
