#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int jia = 0, yi = 0;
    for (int i = 0; i < n; ++i) {
        int jiahan, jiahua, yihan, yihua;
        cin >> jiahan >> jiahua >> yihan >> yihua;
        int s = jiahan + yihan;
        if (s == jiahua && s != yihua) yi++;
        if (s == yihua && s != jiahua) jia++;
    }
    cout << jia << ' ' << yi << endl;
    return 0;
}
