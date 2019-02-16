// 对每一种查询方式都建立一个map string-set<int>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;

void query(map<string, set<int> >& mp, string q) {
    if (mp.find(q) == mp.end()) printf("Not Found\n");
    else {
        for (auto it = mp[q].begin(); it != mp[q].end(); ++it) printf("%07d\n", *it);
    }
}

int main() {
    int n; cin >> n;
    map<string, set<int> > title2id, author2id, key2id, publish2id, year2id;
    int id; string tmp;
    while (n--) {
        cin >> id; getchar(); // 吸收换行符
        getline(cin, tmp); title2id[tmp].insert(id);
        getline(cin, tmp); author2id[tmp].insert(id);
        while (cin >> tmp) {
            key2id[tmp].insert(id);
            if (getchar() == '\n') break;
        }
        getline(cin, tmp); publish2id[tmp].insert(id);
        getline(cin, tmp); year2id[tmp].insert(id);
    }
    int m; cin >> m; int tag; string q;
    while (m--) {
        scanf("%d: ", &tag); getline(cin, q);
        cout << tag << ": " << q << endl;
        switch (tag) {
            case 1: query(title2id, q);
                break;
            case 2: query(author2id, q);
                break;
            case 3: query(key2id, q);
                break;
            case 4: query(publish2id, q);
                break;
            case 5: query(year2id, q);
                break;
        }
    }
    return 0;
}

