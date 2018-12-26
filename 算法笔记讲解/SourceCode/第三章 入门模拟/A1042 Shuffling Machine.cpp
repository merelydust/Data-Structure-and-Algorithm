#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 60;

int main() {
    int k; scanf("%d", &k);
    int order[maxn], givenOrder[maxn], newOrder[maxn]; string cards[maxn], card;
    for (int i = 1; i <= 54; ++i) {
        scanf("%d", &givenOrder[i]); order[i] = i;
    }
    for (int i = 1; i <= 54; ++i) {
        int num = i % 13; if (num % 13 == 0) num += 13;
        if (i < 14) card = "S" + to_string(num);
        else if (i < 27) card = "H" + to_string(num);
        else if (i < 40) card = "C" + to_string(num);
        else if (i < 53) card = "D" + to_string(num);
        else card = "J" + to_string(i % 13);
        cards[i] = card;
    }
    while (k--) {
        for (int i = 1; i <= 54; ++i) newOrder[givenOrder[i]] = order[i]; // 新位置 = givenOrder让order去的位置
        memcpy(order, newOrder, sizeof(order)); // 更新初始顺序
    }
    for (int i = 1; i <= 54; ++i) {
        cout << cards[order[i]];
        if (i != 54) cout << " ";
        else cout << endl;
    }
    return 0;
}
