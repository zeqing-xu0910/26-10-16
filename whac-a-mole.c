//旋转矩阵
//算法：前缀和/二维前缀和

#include <limits.h>
#include<stdio.h>
#define LEN 1300
#define MAX 360020
long long map[LEN][LEN] = {0};
int ansi[MAX] = {0};
int ansj[MAX] = {0};

int main() {
    int n = 0, m = 0, d = 0;
    scanf("%d %d %d", &n, &m, &d);
    getchar();

    int N = m + n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int v = 0;
            scanf("%d", &v);
            map[i + j][i - j + m] = v;
            //存入地图数据 并且直接旋转45°为正方形
        }
    }

    for (int r = 1; r <= N; r ++) {
        for (int c = 1; c <= N; c ++) {
            map[r][c] += map[r][c - 1] + map[r - 1][c] - map[r - 1][c - 1];
        }
    }//把地图数据转换为二位前缀和
    int best = INT_MIN;
    int count = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int sum = 0;
            int row = i + j;
            int col = i - j + m;

            int r1 = row + d;
            int r2 = row - d;
            int c1 = col + d;
            int c2 = col - d;

            if (r1 > N){r1 = N;}
            if (r2 < 1){r2 = 1;}
            if (c1 > N){c1 = N;}
            if (c2 < 1){c2 = 1;}

            sum = map[r1][c1] 
            - map[r2 - 1][c1] 
            - map[r1][c2 -1] 
            + map[r2 - 1][c2 - 1];

            if (sum > best) {
                best = sum;
                count = 0;
                ansi[count] = i;
                ansj[count] = j;
                count ++;
            }else if (sum == best) {
                ansi[count] = i;
                ansj[count] = j;
                count ++;
            }
        }
    }
    printf("%d %d\n", best, count);
    for (int i = 0; i < count; i ++) {
        printf("%d %d\n", ansi[i], ansj[i]);
    }
    return 0;
}
