#include <math.h>
#include<stdio.h>
#include<stdbool.h>
#define LEN 55
#define MAX 1500
char map[LEN][LEN];
bool vis[LEN][LEN] = {0};
int dr1[4] = {1, -1, 0, 0};  //up & down
int dr2[4] = {0, 0, 1, -1}; //right & left

//封装一个函数 实现判断：一个点周围是否存在未走到过的#
bool end(char a[LEN][LEN], bool vis[LEN][LEN], int x, int y, int n, int m);

int main() {
    int n = 0, m = 0, x0 = 0, y0 = 0;
    int pathx[MAX] = {0};
    int pathy[MAX] = {0};
    scanf("%d %d %d %d", &n, &m, &x0, &y0);
    getchar();
    x0 --;
    y0 --;
    vis[x0][y0] = 1;
    for (int i = 0; i < n; i ++) {
            scanf("%s", map[i]);
        }
    int x = x0, y = y0;
    int count = 1;
    pathx[1] = x0;
    pathy[1] = y0;
    while (!end(map, vis, x, y, n, m)) {
        for (int d = 0; d < 4; d ++) {
            int row = x + dr1[d];
            int col = y + dr2[d];
            if (row < 0 || row >= n || col < 0 || col >= m){continue;}
            if (map[row][col] == '#' && vis[row][col] == 0){
                    x = row;
                    y = col;
                    vis[row][col] = 1;
                count ++;
                pathx[count] = x;
                pathy[count] = y;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 1; i <= count; i ++) {
        printf("%d %d\n", pathx[i] + 1, pathy[i] + 1);
    }
}

bool end(char a[LEN][LEN], bool vis[LEN][LEN], int x, int y, int n, int m) {
    for (int d = 0; d < 4; d ++) {
         int row = x + dr1[d];
         int col = y + dr2[d];
         if (row < 0 || row >= n || col < 0 || col >= m){continue;}
         else {
         if (a[row][col] == '#' && vis[row][col] == 0) {
             return false;
         }
         }
            }
    return true;
        }

