#include <cstdio>
#include <algorithm>
using namespace std;

int ranks[1000000][4] = {0}; // 空间换时间 高效索引 按优先级存储 ranka rankc rankm ranke
int subjectindex;
char subject[4] = {'A', 'C', 'M', 'E'};

struct stu {
    int id, grade[4]; // 也按优先级存储
};

bool cmp(stu a, stu b) { // 按不同的学科排序
    return a.grade[subjectindex] > b.grade[subjectindex];
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    stu students[n];
    for (int i = 0; i < n; ++i) {
        int total = 0;
        scanf("%d", &students[i].id);
        for (int j = 1; j < 4; ++j) {
            scanf("%d", &students[i].grade[j]); total += students[i].grade[j];
        }
        students[i].grade[0] = total; // 大家平均数的分母都是4 取分子就行了
    }
    
    for (subjectindex = 0; subjectindex < 4; ++subjectindex) { // 填写四个ranks
        sort(students, students+n, cmp);
        int rank = 1, premark = students[0].grade[subjectindex];
        for (int j = 0; j < n; ++j) {
            if (students[j].grade[subjectindex] != premark) {
                rank = j + 1; // j从0开始索引 所以这里要加一
                premark = students[j].grade[subjectindex];
            }
            ranks[students[j].id][subjectindex] = rank;
        }
    }
    
    for (int i = 0; i < m; ++i) { // 查询
        int tmp; scanf("%d", &tmp);
        if (!ranks[tmp][0]) printf("N/A\n"); // 如果总分是0说明这个考生不存在
        else {
            int minindex = 0;
            for (int j = 0; j < 4; ++j) {
                if (ranks[tmp][j] < ranks[tmp][minindex]) minindex = j;
            }
            printf("%d %c\n", ranks[tmp][minindex], subject[minindex]);
        }
    }
    return 0;
}
