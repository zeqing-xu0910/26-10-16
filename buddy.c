#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define LEN 10005
int buddy[LEN] = {0};
int name[LEN] = {0};
char op[LEN];
int up(int a) {
    int sum = 0;
    int b = a;
    bool power = true;
    while (a != 1) {
        if (a % 2 != 0){power = false;}
        a /= 2;
    }
    while (b != 1) {
        b /= 2;
        sum ++;
    }
    if (power){return pow(2, sum);}
    else{return pow(2, sum + 1);}

}
int main() {
    int n = 0;
    int q = 0;
    int dot = 1; //空间节点数
    scanf("%d %d", &n, &q);
    getchar();
    buddy[0] = pow(2, n);
    for (int round = 0; round < q; round ++) {
        scanf(" %c", &op[round]);
        if (op[round] == 'A') {
            int m = 0;
            int id = 0;
            scanf("%d %d", &id, &m);
            m = up(m);
            bool found = false;
            for (int i = dot - 1; i >= 0; i --) {
                if (buddy[i] == m && name[i] == 0) {
                    name[i] = id;
                    found = true;
                    break;
                }
            }
            if (!found) {
                int idx = -1;
                for (int i = dot - 1; i >= 0; i --) {
                    if (buddy[i] > m && name[i] == 0) {
                        idx = i;
                        break;
                    }
                }
                while (buddy[idx] > m) {
                    for (int j = dot - 1; j > idx; j --) {
                        buddy[j + 1] = buddy[j];
                        name[j + 1] = name[j];
                    }
                    buddy[idx] /= 2;
                    buddy[idx + 1] = buddy[idx];
                    name[idx + 1] = 0;
                    dot ++;
                    idx ++;
                }
                name[idx] = id;
            }
        }
        if (op[round] == 'Q') {
            printf("%d\n", dot);
            for (int i = dot - 1; i >= 0; i --) {
                printf("%d ", name[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
