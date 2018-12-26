#include <iostream> // 涉及到字符串 用iostream更方便
#include <string>
using namespace std;

int main() {
    string word[80]; int cnt = 0;
    while (cin >> word[cnt]) cnt++; // 保存所有读入的单词
    for (int i = cnt-1; i >= 0; i--) {
        cout << word[i];
        if (i) cout << ' ';
        else cout << endl; // i=0时说明是最后一个单词 不输出空格
    }
    return 0;
}
