#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int m, n, k; scanf("%d %d %d", &m, &n, &k);
    int arr[1010] = {0};
    while (k--) {
        stack<int> s;
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int now = 0;
        for (int i = 1; i <= n && now < n && s.size() < m; ++i) {
            s.push(i);
            while (!s.empty() && s.top() == arr[now] && now < n) {
                s.pop(); ++now;
            }
        }
        if (now < n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
