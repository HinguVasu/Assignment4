#include<iostream>
#include <limits.h> 
#include <stdio.h> 
  
const int V=5;      //maximum number of vertex in graph

using namespace std;
  
//function that find the min distance from the source to the vertex
int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// Print the distance
void printSolution(int dist[]) 
{ 
    printf("Vertex \t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// dijkstra algorithm function that implement single source algorithm
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 
    bool sptSet[V]; 
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet); 
          sptSet[u] = true; 
          for (int v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    printSolution(dist); 
} 
  
int main() 
{ 
    int graph[V][V];

    for(int i=0; i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"Enter element at the position ["<<i<<", "<<j<<"] : ";
            cin>>graph[i][j];
        }
    } 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 