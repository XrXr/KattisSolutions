#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct Edge {
    int weight;
    int dest;
};
struct Vert {
    vector<Edge> edges;
};

long long shortest(vector<Vert> &verts, int s, int t) {
    vector<bool> visited;
    visited.resize(verts.size());
    map<long long, vector<long long>> queue;

    queue[0].push_back(s);
    while (queue.upper_bound(-1) != queue.end()) {
        auto it = queue.upper_bound(-1);
        long long vi = it->second.back();
        long long vc = it->first;
        if (it->second.size() == 1) 
            queue.erase(it);
        else {
            it->second.pop_back();
        }
        if (visited[vi]) continue;
        Vert &v = verts[vi];
        visited[vi] = true;
        if (vi == t) {
            return vc;
        }
        for (auto neighbor : v.edges) {
            if (visited[neighbor.dest]) continue;
            queue[neighbor.weight + vc].push_back(neighbor.dest);
        }
    }
    return -1;
}

int main() {
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    vector<Vert> verts;
    verts.resize(n);
    for (int i = 0; i < m; i++) {
        int to, from, weight;
        cin >> from >> to >> weight;
        Edge toe, frome;
        toe.weight = weight;
        frome.weight = weight;
        toe.dest = from;
        frome.dest = to;
        verts[from].edges.push_back(frome);
        verts[to].edges.push_back(toe);
    }
    long long best = shortest(verts, s, t);
    for (int i = 0; i < f; i++) {
        int to, from;
        cin >> from >> to;
        Edge plane;
        plane.dest = to;
        plane.weight = 0;
        verts[from].edges.push_back(plane);
        best = min(best,shortest(verts,s,t));
        verts[from].edges.pop_back();
    }
    cout << best << endl;
}
