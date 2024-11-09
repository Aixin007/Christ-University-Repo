#include <stdio.h>

int main() {
    int n, i, ctr = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n == 0 || n == 1)
        ctr = 1;

    for (i = 2; i <= n / 2; ++i) {
  
        if (n % i == 0) {
            ctr = 1;
            break;
        }
    }

    if (ctr == 0)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}