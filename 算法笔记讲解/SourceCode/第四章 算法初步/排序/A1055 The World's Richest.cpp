#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;

struct peo {
    string name;
    int age, wealth;
}people[maxn];

bool cmp(peo a, peo b) {
    if (a.wealth != b.wealth) return a.wealth > b.wealth;
    if (a.age != b.age) return a.age < b.age;
    return a.name < b.name;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        char str[10] = {0};
        scanf("%s %d %d", str, &people[i].age, &people[i].wealth);
        people[i].name = str;
    }
    sort(people, people+n, cmp);
    for (int i = 1; i <= k; ++i) {
        printf("Case #%d:\n", i);
        int m, amin, amax; scanf("%d %d %d", &m, &amin, &amax);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (cnt == m) break;
            if (people[j].age >= amin && people[j].age <= amax) {
                printf("%s %d %d\n", people[j].name.c_str(), people[j].age, people[j].wealth);
                ++cnt;
            }
        }
        if (!cnt) printf("None\n");
    }
    return 0;
}
