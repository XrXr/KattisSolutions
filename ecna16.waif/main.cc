#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <cstring>

using namespace std;

#define MVERT 302

struct {
    int used, max;
} edges[MVERT][MVERT];

bool toy_seen[100];

int main() {
    int n,m,p;
    cin >> n >> m >> p;
    const int s = 1+n+m+p;
    const int t = 0;
    // connect children to super sink
    for (int i = 1; i<=n; i++) {
        edges[i][0].max = 1;
    }

    for (int i = 1; i<=n; i++) {
        // connect toys to children
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int l;
            cin >> l;
            // 0 is the super sink, the next n are children followed by toys
            // the index from input start from 1.
            edges[1+n+l-1][i].max = 1;
        }
    }

    for (int i = 0; i<p; i++) {
        // connect categories to toys
        int l,r;
        cin >> l;
        while (l--) {
            int k;
            cin >> k;
            // 0 is the super sink followed by children and toys and categories
            edges[1+n+m+i][1+n+k-1].max = 1;
            toy_seen[k-1] = true;
        }
        cin >> r;
        // super sink to this category
        edges[s][1+n+m+i].max = r;
    }

    for (int i=0;i<m;i++) {
        if (!toy_seen[i]) {
            edges[s][1+n+i].max = 1;
        }
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
    
    int total = 0;
    for (int i=0;i<n;i++) total += edges[1+i][0].used;
    cout << total << endl;
}
