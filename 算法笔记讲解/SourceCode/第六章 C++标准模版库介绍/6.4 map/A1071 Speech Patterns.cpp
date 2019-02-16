// 单词之间以非alnum为界限
#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string s; getline(cin, s);
    map<string, int> m;
    int index = 0, len = int(s.length());
    while (index < len) {
        if (!isalnum(s[index])) ++index;
        else {
            string word = "";
            while (isalnum(s[index])) word += tolower(s[index++]);
            m[word]++;
        }
    }
    string ans = ""; int cnt = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > cnt) {
            cnt = it->second; ans = it->first;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}
