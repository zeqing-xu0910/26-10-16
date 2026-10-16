#include<stdio.h>
#include<string.h>
#define LEN 1005
int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    getchar();
    char dir[LEN] = {0};
    scanf("%s", dir);
    int len = strlen(dir);
    int x1 = 0, x2 = a, y1 = 0, y2 = b, z = c;
    for (int i = 0; i < len; i++) {
        if (dir[i] == 'W') {
            int temp = z;
            z = (x2 - x1) > 0? (x2 - x1): (x1 - x2);
            x2 = x1;
            x1 -= temp;
        }else if (dir[i] == 'S') {
            int temp = z;
            z = (x2 - x1) > 0? (x2 - x1): (x1 - x2);
            x1 = x2;
            x2 += temp;
        }else if (dir[i] == 'A') {
            int temp = z;
            z = (y2 - y1) > 0? (y2 - y1): (y1 - y2);
            y2 = y1;
            y1 -= temp;
        }else if (dir[i] == 'D') {
            int temp = z;
            z = (y2 - y1) > 0? (y2 - y1): (y1 - y2);
            y1 = y2;
            y2 += temp;
        }
    }
    printf("%d %d %d %d", x1, x2, y1, y2);
    return 0;
}
