#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <cstring>

using namespace std;

#define MVERT 500

struct {
    int used, max;
} edges[MVERT][MVERT];

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;

    while (m--) {
        int from, to, cap;
        cin >> from >> to >> cap;
        edges[from][to].max = cap;
    }

    while (true) {
        list<int> queue;
        queue.push_front(s);
        bool visited[MVERT] = {0};
        struct { int pre_node, edge_cost;} prv[MVERT];
        while (!queue.empty()) {
            int c = queue.back();
            queue.pop_back();
            if (visited[c]) continue;
            visited[c] = true;
            for (int i = 0; i < MVERT; i++) {
                if (!visited[i] && edges[c][i].used < edges[c][i].max) {
                    queue.push_front(i);
                    prv[i].pre_node = c;
                    prv[i].edge_cost = edges[c][i].max - edges[c][i].used;
                }
            }
        }
        if (!visited[t]) break;
        int df = 0x3f3f3f3f;
        int i = t;
        while (i != s) {
            df = min(df, prv[i].edge_cost);
            i = prv[i].pre_node;
        }

        i = t;
        while (i != s) {
            edges[prv[i].pre_node][i].used += df;
            edges[i][prv[i].pre_node].used -= df;
            i = prv[i].pre_node;
        }
    }
    int maxflow = 0;
    for (int i = 0; i < MVERT; i++) {
        if (edges[i][t].used > 0) maxflow += edges[i][t].used;
    }
    int solution_edge_count = 0;
    for (int i = 0; i < MVERT; i++)
        for (int j = 0; j < MVERT; j++)
            if (edges[i][j].used > 0) solution_edge_count++;
    cout << n << ' ' << maxflow << ' ' << solution_edge_count << endl;

    for (int i = 0; i < MVERT; i++)
        for (int j = 0; j < MVERT; j++)
            if (edges[i][j].used > 0) {
                cout << i << ' ' << j << ' ' << edges[i][j].used << endl;
            }
}
