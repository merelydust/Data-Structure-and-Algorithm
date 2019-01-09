#include <cstdio>
using namespace std;

int main() {
    int arr[10] = {0}; for (int i = 0; i < 10; ++i) scanf("%d", &arr[i]);
    for (int i = 1; i < 10; ++i) {
        if (arr[i]) {
            printf("%d", i); --arr[i]; break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        while (arr[i]--) printf("%d", i);
    }
    return 0;
}
