#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2; getline(cin, s1); getline(cin, s2);
    int hash[128] = {0};
    for (int i = 0, len = s2.length(); i < len; ++i) hash[s2[i]] = 1;
    for (int i = 0, len = s1.length(); i < len; ++i) {
        if (hash[s1[i]]) continue;
        cout << s1[i];
    }
    cout << endl;
    return 0;
}
