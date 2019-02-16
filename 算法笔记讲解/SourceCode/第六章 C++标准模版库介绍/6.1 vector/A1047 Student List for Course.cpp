#include <cstdio>
#include <vector>
#include <string>
#include <algorithm> // 用set会超时 改成每次都sort可以AC
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<string> arr[2510];
    char name[10] = {0}; int num, index;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", name, &num);
        while (num--) {
            scanf("%d", &index);
            arr[index].push_back(name);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, (int)arr[i].size());
        if (arr[i].empty()) continue;
        sort(arr[i].begin(), arr[i].end());
        for (int j = 0, len = (int)arr[i].size(); j < len; ++j) printf("%s\n", arr[i][j].c_str());
    }
    return 0;
}
