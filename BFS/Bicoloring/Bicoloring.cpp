#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int l;
        cin >> l;

        vector<vector<int>> graph(n);
        vector<int> color(n, -1); // -1 = uncolored

        // Read edges
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        bool isBicolor = true;

        // BFS start from node 0
        color[0] = 0;
        q.push(0);

        while (!q.empty() && isBicolor) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) {
                    // Give opposite color
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    isBicolor = false;
                    break;
                }
            }
        }

        if (isBicolor)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
