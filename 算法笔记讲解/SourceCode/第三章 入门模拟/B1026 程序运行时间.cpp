#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double c1, c2; scanf("%lf %lf", &c1, &c2);
    int seconds = (c2-c1+50) / 100; // +50是为了四舍五入 如果小数位>=50 则+50后整数位+1
    int hour = seconds / 3600;
    seconds %= 3600;
    int minute = seconds / 60;
    seconds %= 60;
    printf("%02d:%02d:%02d\n", hour, minute, seconds);
    return 0;
}
