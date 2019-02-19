/***
 思路：
 用队列模拟 每轮取group次(队列前ng个人做比较) 建组不够ng就提前break
 每轮被淘汰的人名次=晋级组数+1
 每小组优胜者推入队列
 ***/
#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int w, rank;
};

int main() {
    int np, ng; scanf("%d %d", &np, &ng);
    node arr[1010];
    for (int i = 0; i < np; ++i) scanf("%d", &arr[i].w);
    queue<int> Q; int index;
    for (int i =  0; i < np; ++i) {
        scanf("%d", &index); Q.push(index);
    }
    int now = np, group = 0; // 当前剩余人数 当前组数
    while (Q.size() > 1) {
        group = now / ng;
        if (now % ng) ++group;
        for (int i = 0; i < group; ++i) {
            int maxId = Q.front();
            for (int j = 0; j < ng; ++j) {
                if (i * ng + j == now) break;
                if (arr[Q.front()].w > arr[maxId].w) maxId = Q.front();
                arr[Q.front()].rank = group + 1;
                Q.pop();
            }
            Q.push(maxId);
        }
        now = group;
    }
    arr[Q.front()].rank = 1;
    for (int i = 0; i < np; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i].rank);
    }
    return 0;
}
