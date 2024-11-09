#include <stdio.h>
 int main() {
    int n, num, rem, ans = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &n);
    num = n;

    while (num != 0) {

        rem = num % 10;

       ans += rem * rem * rem;


       num /= 10;
    }

    if (ans == n)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    return 0;
}