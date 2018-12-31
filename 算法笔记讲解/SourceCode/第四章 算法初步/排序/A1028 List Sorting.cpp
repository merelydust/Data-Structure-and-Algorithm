#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct stu {
    string inf[3]; // id name grade
}students[maxn];

int c;
bool cmp(stu a, stu b) {
    if (a.inf[c] != b.inf[c]) return a.inf[c] < b.inf[c];
    else return a.inf[0] < b.inf[0];
}

int main() {
    int n; scanf("%d %d", &n, &c); --c;
    char str[10] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%s", str); students[i].inf[j] = str;
        };
    }
    sort(students, students+n, cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%s", students[i].inf[j].c_str());
            if (j != 2) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
