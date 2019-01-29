#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        map<char, int> mp; bool flag = true;
        int pre = 0, mid = 0, end = 0;
        for (int i = 0, len = s.length(); i < len; ++i) {
            ++mp[s[i]];
            if ((mp['T'] && !mp['P']) || mp['P'] > 1 || mp['T'] > 1) {
                flag = false; break;
            }
            if (s[i] == 'A') {
                if (!mp['P']) ++pre;
                else if (!mp['T']) ++mid;
                else ++end;
            }
        }
        if (flag && mp['P'] && mp['A'] && mp['T'] && mp.size() == 3 && pre * mid == end) cout << "YES" << endl; // 第一次只用用map.size()没有AC 是因为在判断语句里生成了值为0的键
        else cout << "NO" << endl;
    }
    return 0;
}
