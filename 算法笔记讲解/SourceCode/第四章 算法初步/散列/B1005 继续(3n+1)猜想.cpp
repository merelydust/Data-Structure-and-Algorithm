#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int num, cnt = 0, hashtable[110] = {0};
    set<int, greater<int> > st;
    while (n--) {
        scanf("%d", &num); st.insert(num);
        do {
            num = num % 2 ? (3*num+1)/2 : num/2;
            if (num > 100) continue; // 可能会产生大于100的值
            hashtable[num] = 1;
        } while (num != 1);
    }
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (!hashtable[*it]) ++cnt; // 记录共有几个关键数
    }
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (!hashtable[*it]) {
            printf("%d", *it); --cnt;
            if (cnt) printf(" ");
        }
    }
    return 0;
}
