// 把读入数字转化成 0.xx * 10^exp
// 对于大于1的数字 原数字小数点前有几位就是10的几次方 dotPos
// 对于小于1的数字 第一个非零数与小数点之间有几位就是10的负几次方
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n, expA = 0, expB = 0; string a, b;

void solve(string& s, int& exp) {
    while (s[0] == '0') s.erase(0, 1); // 去除多余前导0
    if (s.empty()) {
        s = "0"; exp = 0;
    }
    else if (s[0] == '.') {
        s.erase(0, 1);
        while (s[0] == '0') {
            --exp;
            s.erase(0,1);
        }
        if (s.empty()) {
            s = "0"; exp = 0;
        }
    }
    else {
        int dotPos = int(s.find("."));
        if (dotPos != string::npos) {
            exp = dotPos;
            s.erase(dotPos, 1);
        }
        else exp = s.length();
    }
    s = s.substr(0, n);
    while (s.length() < n) s += "0";
}

int main() {
    cin >> n >> a >> b;
    solve(a, expA); solve(b, expB);
    if (expA == expB && a == b) printf("YES 0.%s*10^%d\n", a.c_str(), expA);
    else printf("NO 0.%s*10^%d 0.%s*10^%d\n", a.c_str(), expA, b.c_str(), expB);
    return 0;
}
