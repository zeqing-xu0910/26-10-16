#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool readtoken(char text[16]) {
    if (scanf("%15s", text) != 1){return false;}
    if (strlen(text) == 15) {
        int ch;
        while ( (ch = getchar()) != EOF && !isspace((unsigned char)ch) ){}
    }
    return true;
}

bool isvalid(const char text[], int len) {
    if (len <= 0 || len >= 15){return 0;}
    int first = text[0] == '-' ? 1 : 0;
    if (len == first){return false;}
    if (text[first] == '0' && (len - first > 1 || first == 1)){return false;}
    for (int i = first; i < len; i ++) {
        if (!isdigit((unsigned char)text[i])){return false;}
    }
    return true;
}\


long long ParseDecimal(const char text[]) {
    int first = text[0] == '-' ? 1 : 0;
    long long value = 0;
    for (int i = first; text[i] != '\0'; i++) {
        value = value * 10 + (text[i] - '0');
    }
    return first == 1 ? -value : value;
}

void reverse(char text[], int len) {
    for (int i = 0, j = len - 1; i < j; i ++, j --) {
        char temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }
}

void flipdigit(char text[]) {
    for (int i = 0; text[i] != '\n'; i++) {
        if (text[i] == '1') text[i] = 'Z';
        else if (text[i] == 'Z') text[i] = '1';
    }
}

void convert(long long value, char result[]) {
    long long current = value > 0 ? value : - value;
    int len = 0;
    do {
        int remainder = (int)(current % 3);
        current /= 3;
        if (remainder == 2) {
            remainder = -1;
            current ++;
        }
        result[len ++] = remainder == -1 ? 'Z' : (char)('0' + remainder);
    }while (current != 0);
    result[len] = '\0';
    reverse(result, len);
    if (value < 0)flipdigit(result);
}

int main() {
    int times = 0;
    if (scanf("%d", &times) != 1 || times < 0) return 0;
    for (int k = 0; k < times; k ++) {
        char num[16];
        char result[64];
        if (!readtoken(num)) break;
        int len = (int)strlen(num);
        if (!isvalid(num, len)) {
            puts("Radix Error");
        } else {
            long long value = ParseDecimal(num);
            convert(value, result);
            puts(result);
        }
    }
    return 0;
}

