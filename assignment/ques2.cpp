#include <bits/stdc++.h>
using namespace std;

int V;
vector<vector<int>> graph;
vector<int> path;

bool issafe(int vertex, int pos) {
    if(graph[path[pos-1]][vertex] == 0) return false;
    for(int i=0; i<pos; i++) if(path[i] == vertex) return false;
    return true;
}

bool solve(int pos) {
    if(pos == V) {
        return graph[path[pos-1]][path[0]] == 1;
    }
    for(int vertex=1; vertex<V; vertex++) {
        if(issafe(vertex, pos)) {
            path[pos] = vertex;
            if(solve(pos+1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    graph.assign(V, vector<int>(V));
    cout << "Enter adjacency matrix (" << V << "x" << V << "):\n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin >> graph[i][j];
        }
    }

    path.assign(V,-1);
    path[0] = 0;

    if(!solve(1)) {
        cout << "No Hamiltonian Cycle\n";
    } else {
        cout << "Hamiltonian Cycle: ";
        for(int i=0; i<V; i++) cout << path[i] << " ";
        cout << path[0] << "\n";
    }
    return 0;
}
