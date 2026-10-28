#include<stdio.h>
#define LEN 15
int map[LEN][LEN] = {0};
int main() {
    int t = 0, x = 0;
    scanf("%d %d", &t, &x);
    getchar();
    int dr1[4] = {0, 1, -1, -1};// up & down
    int dr2[4] = {1, 1,  0, -1};// left & right
    for (int round = 0; round < t; round ++) {
        int n = 0;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                scanf("%d", &map[i][j]);
            }
        }
        int winner = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int d = 0; d < 4; d ++) {
                    int endrow = i + (x - 1) * dr1[d];
                    int endcol = j + (x - 1) * dr2[d];

                    if (endrow < 0 || endrow >= n || endcol < 0 || endcol >= n) {
                        continue;
                    }
                    int same = 7;
                    for (int k = 0; k < x; k ++) {
                        int row = i + k * dr1[d];
                        int col = j + k * dr2[d];

                        same = same & map[row][col];
                    }
                    winner |= same;
                }
            }
        }
        if (winner == 1 || winner == 2 || winner == 4) {
            printf("%d\n", winner);
        } else {
            printf("draw\n");
        }
    }
    return 0;
}
