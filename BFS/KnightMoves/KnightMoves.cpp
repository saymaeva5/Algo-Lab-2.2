#include <bits/stdc++.h>
using namespace std;

int dr[] = {2,2,-2,-2,1,1,-1,-1};
int dc[] = {1,-1,1,-1,2,-2,2,-2};

int bfs(int sr, int sc, int er, int ec) {
    int dist[8][8];
    memset(dist, -1, sizeof(dist));

    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == er && c == ec) return dist[r][c];

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int main() {
    string a, b;

    while (cin >> a >> b) {
        int sr = a[1] - '1';
        int sc = a[0] - 'a';
        int er = b[1] - '1';
        int ec = b[0] - 'a';

        int moves = bfs(sr, sc, er, ec);

        cout << "To get from " << a << " to " << b
             << " takes " << moves << " knight moves.\n";
    }
}

