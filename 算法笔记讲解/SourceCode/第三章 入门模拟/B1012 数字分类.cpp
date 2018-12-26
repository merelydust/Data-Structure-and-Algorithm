#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp; scanf("%d", &n);
    int a[10] = {0}; bool find[10] = {0}; double a4, sum4 = 0.0; int cnt4 = 0;
    int mark2 = 1;
    while (n--) {
        scanf("%d", &tmp); int mod = tmp % 5;
        if (tmp % 10 == 0) {
            a[1] += tmp; find[1] = true;
        }
        else if (mod == 1) {
            a[2] += mark2 * tmp; mark2 *= -1; find[2] = true;
        }
        else if (mod == 2) {
            ++a[3]; find[3] = true;
        }
        else if (mod == 3) {
            sum4 += 1.0 * tmp; find[4] = true; ++cnt4;
        }
        else if (mod == 4) {
            a[5] = max(a[5], tmp); find[5] = true;
        }
    }
    if (find[4]) a4 = sum4 / cnt4;
    for (int i = 1; i <= 5; ++i) {
        if (i != 1) printf(" ");
        if (!find[i]) printf("N");
        else if (i == 4) printf("%.1f", a4);
        else printf("%d", a[i]);
    } printf("\n");
    return 0;
}
