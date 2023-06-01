#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<iomanip>
#define size 6

using namespace std;

void dijkstra(int graph[size][size], int source)
{
    map<int, bool> ignoredVertex;
    map<int, int> timeToCity;

    for(int i = 0; i < size; i++)
    {
        ignoredVertex[i] = false;
        timeToCity[i] = INT_MAX;
    }

    timeToCity[source] = 0;

    for(int count = 0; count < size-1; count++) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < size; v++)
            if (!ignoredVertex[v] && timeToCity[v] <= min)
                min = timeToCity[v], min_index = v;
        int u = min_index;
        ignoredVertex[u] = true;
        for (int v = 0; v < size; v++)
            if (!ignoredVertex[v] && graph[u][v] != 0 && timeToCity[u] != INT_MAX && timeToCity[u] + graph[u][v] < timeToCity[v])
                timeToCity[v] = timeToCity[u] + graph[u][v];
    }
    cout<<"\n\n\n";
    for (int i = 0; i < size; i++){
        if(i != source)
        {
            cout << "Time to City " << i << " from City "<< source <<" is " << timeToCity[i] << endl;
        }
    }

    int totalTime = 0;
    double averageTime = 0.0;
    for(int v = 0; v < size; v++)
    {
        totalTime += timeToCity[v];
    }

    averageTime = (double)totalTime/(size-1);
    cout<<"Average Time to City "<<source<< " is "<< std::fixed << std::setprecision(1) << averageTime << endl;
    cout<<"\n\n\n";
}


int main()
{
    int graph[size][size] = {{0, 10, 0, 0, 15, 5},
                             {10, 0, 10, 30, 0, 0},
                             {0, 10, 0, 12, 5, 0},
                             {0, 30, 12, 0, 0, 20},
                             {15, 0, 5, 0, 0, 0},
                             {5, 0, 0, 20, 0, 0}};

    dijkstra(graph, 0);
    return 0;
}