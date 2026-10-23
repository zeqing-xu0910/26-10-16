#include<stdio.h>
#define LEN 20
static char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

void trans3(int n) {
    //先统计位数
    if (n < 0) {n = -n;}
    int temp = n;
    int digit = 0;
    while (temp != 0) {
        temp /= 10;
        digit ++;
    }
    switch (digit) {
        case 1: printf("%s ", ones[n]);break;
        case 2:
            if (n == 0){break;}
            if (n >= 1 && n <= 19) {
                printf("%s ", ones[n]);
                break;
            }
            if (n >= 21 && n % 10 != 0){
                    printf("%s-%s ", tens[n / 10], ones[n % 10]);
            }else if (n % 10 == 0){
                printf("%s ", tens[n / 10]);
            }
            break;
        case 3:
            printf("%s hundred ", ones[n / 100]);
            n %= 100;
            if (n == 0){break;}
            if (n != 0){printf("and ");}
            if (n / 10 < 2 && n != 0) {
                printf("%s ", ones[n]);
            }else {
                if (n % 10 != 0) {
                    printf("%s-%s ", tens[n / 10], ones[n % 10]);
                }else {
                    printf("%s ", tens[n / 10]);
                }
            }
            break;
    }
}


int main(){
    int x = 0;
    int count = 0;
    scanf("%d", &x);
    int digit[20] = {0};

    long long n = x;
    if (n < 0) {
        printf("minus ");
    }
    if (n == 0) {
        printf("zero");
        return 0;
    }

    while (n != 0) {
        digit[count] = n % 1000;
        n /= 1000;
        count ++;
    }

    for (int i = count - 1; i >= 0; i --){
        if (digit[i] == 0){continue;}
        switch (i) {
            case 3:
                trans3(digit[i]);
                printf("billion ");
                break;
            case 2:
                trans3(digit[i]);
                printf("million ");
                break;
            case 1:
                trans3(digit[i]);
                printf("thousand ");
                break;
            case 0:
                trans3(digit[i]);
                break;
        }
    }
    return 0;

}
