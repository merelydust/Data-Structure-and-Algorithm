// 有三个诡异的超时点= =
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct record {
    string owner;
    int dd, hh, mm, time, status; // status0代表online 1代表offline
};

bool cmp(record a, record b) {
    if (a.dd != b.dd) return a.dd < b.dd;
    else if (a.hh < b. hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}

int tolls[24] = {0}, sumTolls[24] = {0};

double calCost(record a) {
    double cost = a.dd * 60 * sumTolls[23] + a.mm * tolls[a.hh];
    cost += !a.hh ? 0 : 60 * sumTolls[a.hh-1];
    return cost;
}

void cal(vector<record>& v) {
    double total = 0;
    for (int i = 1; i < v.size(); i += 2) {
        printf("%02d:%02d:%02d %02d:%02d:%02d ", v[i-1].dd, v[i-1].hh, v[i-1].mm, v[i].dd, v[i].hh, v[i].mm);
        double cost = calCost(v[i]) - calCost(v[i-1]);
        printf("%d $%.2f\n", v[i].time-v[i-1].time, cost / 100.0);
        total += cost;
    }
    printf("Total amount: $%.2f\n", total / 100.0);
}

int main() {
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &tolls[i]);
        if (i) sumTolls[i] = tolls[i] + sumTolls[i-1];
        else sumTolls[i] = tolls[i];
    }
    int n, month = 0; scanf("%d", &n);
     map<string, vector<record> > mp; record tmp; char str1[30] = {0}, str2[30] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d:%d %s", str1, &month, &tmp.dd, &tmp.hh, &tmp.mm, str2);
        tmp.owner = str1; tmp.status = !strcmp(str2, "on-line") ? 0 : 1; tmp.time = tmp.dd*24*60 + tmp.hh*60 + tmp.mm;
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
