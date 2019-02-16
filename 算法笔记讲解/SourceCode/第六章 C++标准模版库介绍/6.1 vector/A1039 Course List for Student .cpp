#include <cstdio> // 用流会超时
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    map<string, set<int> > mp;
    while (k--) {
        int c, cNum; scanf("%d %d", &c, &cNum);
        while (cNum--) {
            char name[10]; scanf("%s", name);
            mp[name].insert(c);
        }
    }
    while (n--) {
        char name[10]; scanf("%s", name);
        printf("%s %d", name, int(mp[name].size()));
        if (mp[name].size()) {
            for (auto it = mp[name].begin(); it != mp[name].end(); ++it) printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}
