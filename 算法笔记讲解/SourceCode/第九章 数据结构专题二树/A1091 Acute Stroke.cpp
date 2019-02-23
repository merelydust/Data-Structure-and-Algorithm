#include <cstdio>
#include <queue>
using namespace std;

int m, n, l, t, vol = 0;

struct node {
    int x, y, z, flag;
    node() {
        flag = 0;
    }
};
int matrix[1300][130][60] = {0};
bool inq[1290][130][61] = {false};
int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false; // 越界
    if (!matrix[x][y][z] || inq[x][y][z]) return false; // 非法
    return true;
}

int bfs(int x, int y, int z) {
    node Node; Node.x = x; Node.y = y; Node.z = z;
    queue<node> Q;
    Q.push(Node); inq[Node.x][Node.y][Node.z] = true;
    int cnt = 1;
    while (!Q.empty()) {
        node fro = Q.front();
        Q.pop();
        for (int i = 0; i < 6; ++i) {
            int newX = fro.x + X[i], newY = fro.y + Y[i], newZ = fro.z + Z[i];
            if (judge(newX, newY, newZ)) {
                node newNode; newNode.x = newX; newNode.y = newY; newNode.z = newZ;
                Q.push(newNode); inq[newX][newY][newZ] = true; ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int k = 0; k < l; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }
    for (int k = 0; k < l; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j][k] && !inq[i][j][k]) {
                    int cnt = bfs(i, j, k);
                    if (cnt >= t) vol += cnt;
                }
            }
        }
    }
    printf("%d\n", vol);
    return 0;
}
