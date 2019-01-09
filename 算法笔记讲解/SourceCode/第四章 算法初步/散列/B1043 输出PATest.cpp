#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s1, s2 = "PATest"; getline(cin, s1);
    map<char, int> mp; for (int i = 0, len = s1.length(); i < len; ++i) ++mp[s1[i]]; // 记录每个字符出现次数
    bool end = false;
    while (!end) {
        end = true;
        for (int i = 0; i < 6; ++i) {
            if (mp[s2[i]]) {
                cout << s2[i]; --mp[s2[i]]; end = false;
            }
        }
    }
    return 0;
}
