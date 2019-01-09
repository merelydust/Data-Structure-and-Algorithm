// 有三个诡异的超时点
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct record {
    string owner;
    int dd, hh, mm, status; // status0代表online 1代表offline
};

bool cmp(record a, record b) {
    if (a.dd != b.dd) return a.dd < b.dd;
    else if (a.hh < b. hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}

int tolls[24];
void cal(vector<record>& v) {
    double total = 0;
    for (int i = 1; i < v.size(); i += 2) {
        printf("%02d:%02d:%02d %02d:%02d:%02d ", v[i-1].dd, v[i-1].hh, v[i-1].mm, v[i].dd, v[i].hh, v[i].mm);
        int time = 0; double cost = 0;
        while (v[i-1].dd != v[i].dd || v[i-1].hh != v[i].hh || v[i-1].mm != v[i].mm) {
            ++v[i-1].mm; ++time; cost += tolls[v[i-1].hh];
            if (v[i-1].mm == 60) { // 小时进位
                ++v[i-1].hh; v[i-1].mm = 0;
            }
            if (v[i-1].hh == 24) { // 天数进位
                ++v[i-1].dd; v[i-1].hh = 0;
            }
        }
        printf("%d $%.2f\n", time, cost / 100.0);
        total += cost;
    }
    printf("Total amount: $%.2f\n", total / 100.0);
}

int main() {
    for (int i = 0; i < 24; ++i) scanf("%d", &tolls[i]);
    int n, month = 0; scanf("%d", &n);
    map<string, vector<record> > mp; record tmp; char str1[30] = {0}, str2[30] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d:%d %s", str1, &month, &tmp.dd, &tmp.hh, &tmp.mm, str2);
        tmp.owner = str1; tmp.status = !strcmp(str2, "on-line") ? 0 : 1;
        mp[tmp.owner].push_back(tmp);
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<record> valid; sort(it->second.begin(), it->second.end(), cmp);
        for (int i = 1; i < it->second.size(); ++i) {
            if (!it->second[i-1].status && it->second[i].status) {
                valid.push_back(it->second[i-1]); valid.push_back(it->second[i]);
            }
        }
        if (valid.empty()) continue;
        printf("%s %02d\n", valid[0].owner.c_str(), month);
        cal(valid);
    }
    return 0;
}
