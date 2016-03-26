#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>

#define inf 0x3f3f3f3f
#define MAXN 20
#define MAXT 1440

using namespace std;

int p[MAXN + 2];
int t[MAXT + 2];
int d[MAXN + 2];
int cost[MAXN+2][MAXN+2];
int n, T;

int best_point = 0;
vector<int> best_sol;

int dist_to_end(const vector<int>& graph, int source) {
    int dist[MAXN + 2] = {};
    unordered_set<int> visited;
    
    struct Node {
        int n;
        int cost;
        bool operator>(const Node& o) {
            return cost > o.cost;
        }
    };
    
    struct NodeGreater {
        bool operator()(Node& a, Node& b){ return a.cost > b.cost;}
    };
    priority_queue<Node, vector<Node>, NodeGreater> q;


    dist[source] = 0;
    for (int e : graph) {
        if (e != source) {
            dist[e] = inf;
        }
        Node initial{e, dist[e]};
        q.push(initial);
    }

    while (!q.empty()) {
        int node = q.top().n;
        q.pop();
        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);
        for (int e : graph) {
            if (visited.find(e) != visited.end()) continue;
            int alt = dist[node] + cost[node][e] + t[e];
            if (alt < dist[e]) {
                dist[e] = alt;
                Node better{e, alt};
                q.push(better);
            }
        }
    }
    return dist[n+1];
}

void bt(unordered_set<int> used, int location, int time, int point) {
    if (location == n + 1) {
        if (point > best_point) {
            vector<int> sorted (used.begin(), used.end());
            sort(sorted.begin(), sorted.end());
            best_point = point;
            best_sol = sorted;
        }
        return;
    }

    vector<int> graph;
    for (int i = 0; i < n; i++) {
        if (used.find(i) == used.end()) graph.push_back(i);
    }
    graph.push_back(location);
    graph.push_back(n+1);

    if (time + dist_to_end(graph, location) > T) return;
    
    for (int i = 0; i <= n + 1; i++) {
        if (used.find(i) != used.end()) continue;
        int nt = time + cost[location][i] + t[i];
        if (nt > T || (d[i] > -1 && nt > d[i])) continue;
        int np = point + p[i];
        used.insert(i);
        bt(used, i, nt, np);
        used.erase(i);
    }
}

int main() {

    cin >> n >> T;
    for (int i =0; i< n; i++)
        cin >> p[i] >> t[i] >> d[i];
    
    
    for (int i =0; i< n+2; i++)
        for (int j =0; j< n+2; j++)
            cin >> cost[i][j];

    d[n] = -1;
    t[n] = 0;
    p[n] = 0;
    d[n+1] = -1;
    p[n+1] = 0;
    t[n+1] = 0;

    unordered_set<int> initial;
    initial.insert(n);
    bt(initial, n, 0, 0);

    cout << best_point << endl;
    if (best_point > 0) {
        for (int i = 0; i < best_sol.size() - 2; i++) {
            cout << best_sol.at(i) + 1;
            if (i != best_sol.size() - 1) cout << ' ';
        }
    }
    cout << endl;
}
