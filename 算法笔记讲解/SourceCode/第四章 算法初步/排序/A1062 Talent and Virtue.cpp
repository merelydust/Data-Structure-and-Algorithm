#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
    string id;
    int vir, tal, total;
    int grade; // 考生的等第 sages noblemen...
};

bool cmp(stu a, stu b) {
    if (a.grade != b.grade) return a.grade < b.grade; // 等第优先级最高
    if (a.total != b.total) return a.total > b.total;
    else if (a.vir != b.vir) return a.vir > b.vir;
    return a.id < b.id;
}

int main() {
    int n, l, h; scanf("%d %d %d", &n, &l, &h);
    vector<stu> students; stu tmp; char tmpid[10] = {0};
    while (n--) {
        scanf("%s %d %d", tmpid, &tmp.vir, &tmp.tal); tmp.id = tmpid;
        tmp.total = tmp.vir + tmp.tal;
        if (tmp.vir < l || tmp.tal < l) continue; // 不合格者不计入统计
        if (tmp.vir >= h && tmp.tal >= h) tmp.grade = 1; // 分等第
        else if (tmp.vir >= h) tmp.grade = 2;
        else if (tmp.vir >= tmp.tal) tmp.grade = 3;
        else tmp.grade = 4;
        students.push_back(tmp);
    }
    sort(students.begin(), students.end(), cmp);
    printf("%d\n", students.size());
    for (int i = 0; i < students.size(); ++i) printf("%s %d %d\n", students[i].id.c_str(), students[i].vir, students[i].tal);
    return 0;
}
