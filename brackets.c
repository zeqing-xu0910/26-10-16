#include<stdio.h>
#include<string.h>
#define SIZE 10005
char stack[SIZE];
char input[SIZE];
int main() {
    int t = 0;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i ++) {
        int top = 0;
        scanf("%s", input);
        int len = strlen(input);
        for (int j = 0; j < len; j ++) {
            if (   input[j] == '('
                || input[j] == '{'
                || input[j] == '[') {
                stack[top] = input[j];
                top ++;
            }
            if (input[j] == ')'
                || input[j] == '}'
                || input[j] == ']') {
                if (top == 0) {
                    printf("False");
                    goto done;
                }else {
                    if (!(input[j] == ')' && stack[top - 1] == '('
                        || input[j] == '}' && stack[top - 1] == '{'
                        || input[j] == ']' && stack[top -1] == '[') ){
                        printf("False");
                        goto done;
                    }else {
                        stack[top - 1] = '\0';
                        top --;
                    }
                }
            }
        }
        if (top == 0) {
            printf("True");
            goto done;
        }else {
            printf("False");
            goto done;
        }
        done:
        stack[0] = '\0';
        printf("\n");
    }
    return 0;
}
