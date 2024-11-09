#include <stdio.h>

int main() {
    int n, i;
    int sum = 0, avr;

    printf("Enter the sizes: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    avr = sum / n;
    printf("Average = %d\n", avr);

    return 0;
}

