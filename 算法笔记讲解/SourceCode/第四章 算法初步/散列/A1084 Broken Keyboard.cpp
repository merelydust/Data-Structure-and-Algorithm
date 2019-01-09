#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int hashtable[128] = {0}; // 数组下标为字符ascii码 一共128位
    string s1, s2; cin >> s1 >> s2;
    int i = 0, j = 0;
    int len1 = s1.length(), len2 = s2.length();
    for (; i < len1; ++i) {
        s1[i] = toupper(s1[i]);
        if (s1[i] != toupper(s2[j])) {
            if (!hashtable[s1[i]]) {
                cout << s1[i]; hashtable[s1[i]] = 1;
            }
        } else ++j;
    }
    cout << endl;
    return 0;
}
