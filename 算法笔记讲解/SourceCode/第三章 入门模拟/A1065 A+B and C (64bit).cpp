#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long d = a + b;
        printf("Case #%d: ", i);
        if (a < 0 && b < 0 && d >= 0) {
            printf("false\n");
            continue;
        }
        if ((a > 0 && b > 0 && d <= 0) || (a+b > c)) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
