#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int hashtable[256] = {0};

int main() {
    string broken, given; getline(cin, broken); getline(cin, given); // 一个小坑 第一行可能是空的 所以不能cin
    bool capital = broken.find("+") == string::npos ? true : false;
    for (int i = 0, len = broken.length(); i < len; ++i) hashtable[tolower(broken[i])] = 1;
    for (int i = 0, len = given.length(); i < len; ++i) {
        if (!capital && isupper(given[i])) continue;
        if (!hashtable[tolower(given[i])]) cout << given[i];
    }
    cout << endl;
    return 0;
}
