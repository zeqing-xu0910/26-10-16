#include<stdio.h>
#include<stdbool.h>
#define LEN 605
unsigned char map[LEN][LEN][LEN] = {0};
int dr[6][3] = {
    {1, 0, 0}, {-1, 0, 0},
    {0, 1, 0}, {0, -1, 0},
    {0, 0, 1}, {0, 0, -1}
};
int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int t = 1; t <= n; t ++) {
                scanf(" %c", &map[i][j][t]);
            }
        }
    }
    int wrong = 0;
    int rel_wrong = 0;
    int ifplus = 0;
    bool valid = true;
    int bad[36][3] = {0};
    int cnm[3] = {0};
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int t = 1; t <= n; t ++) {
                bool rel = false;
                if (   map[i + 1][j][t] == '?'
                    || map[i - 1][j][t] == '?'
                    || map[i][j + 1][t] == '?'
                    || map[i][j - 1][t] == '?'
                    || map[i][j][t + 1] == '?'
                    || map[i][j][t - 1] == '?') {
                    rel = true;
                    }
                if (map[i][j][t] == '?') {
                    cnm[0] = i;
                    cnm[1] = j;
                    cnm[2] = t;
                    continue;
                }else if (map[i][j][t] == '*') {
                    continue;
                }else if (!rel){
                    int count = 0;
                    for (int s = 0; s < 6; s ++) {
                        int a = i + dr[s][0];
                        int b = j + dr[s][1];
                        int c = t + dr[s][2];
                        if (map[a][b][c] == '*') {
                            count ++;
                        }
                    }
                    if (count != map[i][j][t] - '0') {
                        bad[wrong][0] = i;
                        bad[wrong][1] = j;
                        bad[wrong][2] = t;
                        wrong ++;
                        valid = false;
                    }
                }else {
                    int count  = 0;
                    for (int s = 0; s < 6; s ++) {
                        int a = i + dr[s][0];
                        int b = j + dr[s][1];
                        int c = t + dr[s][2];
                        if (map[a][b][c] == '*') {
                            count ++;
                        }
                    }
                    if (count != map[i][j][t] - '0') {
                        rel_wrong ++;
                    }
                    if (count == map[i][j][t] - '0' - 1) {
                        ifplus ++;
                    }
                    if (count != map[i][j][t] - '0' - 1){
                        bad[wrong][0] = i;
                        bad[wrong][1] = j;
                        bad[wrong][2] = t;
                        wrong ++;
                        }
                }
            }
        }
    }
    bool no = (valid && rel_wrong == 0);//？不是雷
    bool yes = (valid && wrong == 0);//？是雷

    if (no) {
        int count = 0;
        for (int s = 0; s < 6; s ++) {
            int a = cnm[0] + dr[s][0];
            int b = cnm[1] + dr[s][1];
            int c = cnm[2] + dr[s][2];
            if (map[a][b][c] == '*') {
                count ++;
            }
        }
        printf("valid\n%d\n", count);
    }else if (yes) {
        printf("valid\n*\n");
    }else {
        printf("invalid\n");
        for (int i = 0; i < wrong; i ++) {
            printf("%d %d %d\n", bad[i][0], bad[i][1], bad[i][2]);
        }
    }
    return 0;
}
