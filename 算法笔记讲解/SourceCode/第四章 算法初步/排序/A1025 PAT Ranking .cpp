/***
 n个考场 接下来n块
 k 每个考场人数 接下来k行
 考生ID（13位）分数
 
 输出
 考生总数 按总排名从小到大输出 排名相同按ID字典序排名
 考生ID 总排名 考场号 考场排名
 ***/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
    string id; int place, score, rank[2]; // rank[0]-考场排名 rank[1]总排名
};

bool cmp(stu a, stu b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

void giveRank(vector<stu>& v, int now) { // now指示现在是考场排名还是总排名
    if (v.empty()) return;
    int r = 1, preScore = v[0].score;
    for (int i = 1; i <= v.size(); ++i) {
        if (v[i-1].score != preScore) {
            r = i; preScore = v[i-1].score;
        }
        v[i-1].rank[now] = r;
    }
}

int main() {
    int n, k; scanf("%d", &n);
    vector<stu> students; stu student;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k); vector<stu> tmp;
        for (int j = 0; j < k; ++j) {
            cin >> student.id >> student.score; student.place = i;
            tmp.push_back(student);
        }
        sort(tmp.begin(), tmp.end(), cmp); giveRank(tmp, 0);
        students.insert(students.end(), tmp.begin(), tmp.end());
    }
    sort(students.begin(), students.end(), cmp); giveRank(students, 1);
    cout << students.size() << endl;
    for (int i = 0; i < students.size(); ++i) {
        printf("%s %d %d %d\n", students[i].id.c_str(), students[i].rank[1], students[i].place, students[i].rank[0]);
    }
    return 0;
}
