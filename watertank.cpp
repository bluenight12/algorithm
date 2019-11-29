#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
struct Edge {
    int x, y, h;
};
struct State {
    int x, y, sx, sy, h;
    bool operator<(const struct State& rhs) const { return h > rhs.h; }
};
vector<Edge> edges[1005][1005];
int height[1005][1005];
bool visit[1005][1005];
int main() {
    int N, M, H;
    scanf("%d%d%d", &N, &M, &H);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            height[i][j] = H;
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) { /* (i,j) ~ (i+1, j) */
            int v;
            scanf("%d", &v);
            if (~v) {
                edges[i][j].push_back({i + 1, j, v});
                edges[i + 1][j].push_back({i, j, v});
            }
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 0; i <= M; i++) { /* (j, i) ~ (j, i+1) */
            int v;
            scanf("%d", &v);
            if (~v) {
                edges[j][i].push_back({j, i + 1, v});
                edges[j][i + 1].push_back({j, i, v});
            }
        }
    }
    priority_queue<State> pq;
    for (int i = 0; i <= M + 1; i++) {
        int x = 0;
        int y = i;
        visit[x][y] = true;
        for (auto next : edges[x][y]) {
            pq.push({next.x, next.y, x, y, next.h});
        }
    }
    for (int i = 0; i <= M + 1; i++) {
        int x = N + 1;
        int y = i;
        visit[x][y] = true;
        for (auto next : edges[x][y]) {
            pq.push({next.x, next.y, x, y, next.h});
        }
    }
    for (int i = 1; i <= N; i++) {
        int x = i;
        int y = 0;
        visit[x][y] = true;
        for (auto next : edges[x][y]) {
            pq.push({next.x, next.y, x, y, next.h});
        }
    }
    for (int i = 1; i <= N; i++) {
        int x = i;
        int y = M + 1;
        visit[x][y] = true;
        for (auto next : edges[x][y]) {
            pq.push({next.x, next.y, x, y, next.h});
        }
    }
    while (pq.size()) {
        auto state = pq.top();
        pq.pop();
        int x = state.x;
        int y = state.y;
        int sx = state.sx;
        int sy = state.sy;
        int h = state.h;
        if (visit[x][y] == false) {
            visit[x][y] = true;
            height[x][y] = min(height[x][y], max(h, height[sx][sy]));
            for (auto eg : edges[x][y]) {
                if (visit[eg.x][eg.y] == false) {
                    pq.push({eg.x, eg.y, x, y, eg.h});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += height[i][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}

출처 : https:  //eine.tistory.com/entry/2018년-한국정보올림피아드KOI-초등부-문제-풀이 [아인스트라세의 소프트웨어 블로그]