#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string sa, sb; char da, db; long long a = 0, b = 0;
    cin >> sa >> da >> sb >> db;
    int nDa = int(count(sa.begin(), sa.end(), da));
    if (nDa) {
        string tmpa(nDa, da); a = stoll(tmpa);
    }
    int nDb = int(count(sb.begin(), sb.end(), db));
    if (nDb) {
        string tmpb(nDb, db); b = stoll(tmpb);
    }
    cout << a + b << endl;
    return 0;
}
