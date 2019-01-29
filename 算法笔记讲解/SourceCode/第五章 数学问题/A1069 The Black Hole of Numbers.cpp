#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    string s; cin >> s;
    do {
        while (s.length() < 4) s = "0" + s; // 不足四位补的0也是要纳入计算的 不只是输出格式
        sort(s.begin(), s.end(), less<char>()); int a = stoi(s); // a数字升序
        sort(s.begin(), s.end(), greater<char>()); int b = stoi(s); // b数字降序
        int c = b - a;
        printf("%04d - %04d = %04d\n", b, a, c);
        s = to_string(c); // 更新a
    }while (s != "6174" && s != "0");
    return 0;
}
