#include<iostream>
#include <limits.h> 
#include <stdio.h> 
  
const int Ver=5;      //maximum number of vertex in graph

using namespace std;
  
//function that find the min distance from the source to the vertex
int MinDist(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_ind; 
  
    for (int v = 0; v < Ver; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_ind = v; 
  
    return min_ind; 
} 
  
// Print the distance
void print(int dist[]) 
{ 
    printf("Vertex \t Distance from Source\n"); 
    for (int i = 0; i < Ver; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// dijkstra algorithm function that implement single source algorithm
void dijkstra(int graph[Ver][Ver], int src) 
{ 
    int dist[Ver]; 
    bool sptSet[Ver]; 
    
    for (int i = 0; i < Ver; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    dist[src] = 0; 
  
    for (int count = 0; count < Ver - 1; count++) { 
        int u = MinDist(dist, sptSet); 
          sptSet[u] = true; 
          for (int v = 0; v < Ver; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    print(dist); 
} 
  
int main() 
{ 
    int graph[Ver][Ver];

    for(int i=0; i<Ver;i++)
    {
        for(int j=0;j<Ver;j++)
        {
            cout<<"Enter element at the position ["<<i<<", "<<j<<"] : ";
            cin>>graph[i][j];
        }
    } 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 