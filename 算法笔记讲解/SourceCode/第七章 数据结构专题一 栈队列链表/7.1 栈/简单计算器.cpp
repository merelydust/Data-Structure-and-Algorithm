#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <map>
using namespace std;

struct node {
    double num;
    char op;
    bool flag; // true表示操作数 false表示操作符
};

string str;
stack<node> s; // 操作栈
queue<node> q; // 后缀表达式序列
map<char, int> opRank; // 标记操作符优先级

void change() { // 将中缀表达式变成后缀表达式
    node tmp;
    for (int i = 0; i < str.length();) {
        if (isdigit(str[i])) {
            tmp.flag = true;
            tmp.num = str[i++] - '0';
            while (i < str.length() && isdigit(str[i])) tmp.num = tmp.num * 10 + str[i++] - '0';
            q.push(tmp);
        }
        else {
            tmp.flag = false;
            tmp.op = str[i];
            while (!s.empty() && opRank[tmp.op] <= opRank[s.top().op]) {
                q.push(s.top()); s.pop();
            }
            s.push(tmp);
            ++i;
        }
    }
    while (!s.empty()) {
        q.push(s.top()); s.pop();
    }
}

double cal() {
    double tmp1, tmp2; // 每个操作符有需要两个操作数
    node cur, tmp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag) s.push(cur);
        else {
            tmp2 = s.top().num; s.pop();
            tmp1 = s.top().num; s.pop();
            tmp.flag = true; // 临时记录操作数
            switch (cur.op) {
                case '+': tmp.num = tmp1 + tmp2;
                    break;
                case '-': tmp.num = tmp1 - tmp2;
                    break;
                case '*': tmp.num = tmp1 * tmp2;
                    break;
                case '/': tmp.num = tmp1 / tmp2;
                    break;
            }
            s.push(tmp);
        }
    }
    return s.top().num;
}

int main() {
    opRank['+'] = opRank['-'] = 1;
    opRank['*'] = opRank['/'] = 2;
    while (getline(cin, str) && str != "0") {
        for (auto it = str.end(); it != str.begin(); --it) {
            if (*it == ' ') str.erase(it); // 去除表达式中的空格
        }
        while (!s.empty()) s.pop();
        change();
        printf("%.2lf\n", cal());
    }
    return 0;
}
