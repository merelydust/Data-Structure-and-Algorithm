#include <iostream>
using namespace std;

int main() {
    int jiawin = 0, yiwin = 0, same = 0;
    int jia[3] = {0};
    int yi[3] = {0};
    int n;
    cin >> n;
    while (n--) {
        char g1, g2;
        cin >> g1 >> g2;
        if (g1 == 'B' && g2 == 'C') {
            jiawin++;
            jia[0]++;
        }
        else if (g1 == 'C' && g2 == 'J') {
            jiawin++;
            jia[1]++;
        }
        else if (g1 == 'J' && g2 == 'B') {
            jiawin++;
            jia[2]++;
        }
        else if (g2 == 'B' && g1 == 'C') {
            yiwin++;
            yi[0]++;
        }
        else if (g2 == 'C' && g1 == 'J') {
            yiwin++;
            yi[1]++;
        }
        else if (g2 == 'J' && g1 == 'B') {
            yiwin++;
            yi[2]++;
        }
        else same++;
    }
    cout << jiawin << ' ' << same << ' ' << yiwin << endl;
    cout << yiwin << ' '<< same << ' ' << jiawin  << endl;
    int maxjia = jia[0] >= jia[1] ? 0 : 1; // 注意是>= 优先选择字典序小的
    maxjia = jia[maxjia] >= jia[2] ? maxjia : 2;
    int maxyi = yi[0] >= yi[1] ? 0 : 1;
    maxyi = yi[maxyi] >= yi[2] ? maxyi : 2;
    char ges[3] = {'B', 'C', 'J',};
    cout << ges[maxjia] << ' ' << ges[maxyi];
    return 0;
}
