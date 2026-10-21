#include<stdio.h>
#define LEN 1000005
int a[LEN] = {0};
int b[LEN] = {0};
int main() {
    int n = 0, m = 0, t = 0;
    scanf("%d %d %d", &n, &m, &t);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    getchar();
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    int min = b[0];
    for (int i = 1; i < m; i++) {
        if (b[i] < min){min = b[i];}
    }
    if (min + a[0] > t) {
        printf("-1\n");
        return 0;
    }
    int min2 = t - min - a[0];
    for (int j = 0; j < m; j ++) {
        int target = t - b[j];
        if (target < 0){continue;}
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] > target) {
                high = mid;
            }else {
                low = mid + 1;
            }
        }
        if (low > 0) {
            int ok = t - a[low - 1] - b[j];
            if (ok < min2) {
                min2 = ok;
            }
        }
    }
    printf("%d\n", min2);
    return 0;
}
