#include <bits/stdc++.h>
using namespace std;

#define sz 200005

int par[sz];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int find_set(int node) {
    if (par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

int k() {
    vector<pair<int, pair<int, int>>> ans;
    int c, u, v, tot = 0, x, y;
    while (!pq.empty()) {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        x = find_set(u);
        y = find_set(v);
        if (x != y) {
            ans.push_back({c, {u, v}});
            par[x] = y;
            tot += c;
        }
        pq.pop();
    }
    for (const auto& connection : ans) {
        cout << "Stations: " << connection.second.first << " and " << connection.second.second << endl;
    }
    return tot;
}

int main() {
    int node, edge, x, y, z;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;
    for (int i = 0; i <= node; i++)
        par[i] = i;
    cout << "Enter edges (from_node to_node cost): ";
    for (int i = 0; i < edge; i++) {
        cin >> x >> y >> z;
        pq.push({z, {x, y}});
    }
    cout << "Minimum cost of connecting all substations: " << k() << endl;

    return 0;
}
