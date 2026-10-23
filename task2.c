#include <stdio.h>

int sum_of_digits(int n) {
    if (n < 0) {
        return sum_of_digits(-n);
    }
    if (n < 10) {
        return n;
    }
    return n % 10 + sum_of_digits(n / 10);
}

int main(void) {
    int number;
    printf("Введіть ціле число: ");
    scanf("%d", &number);
    printf("Сума цифр числа %d дорівнює: %d\n", number, sum_of_digits(number));
    return 0;
}