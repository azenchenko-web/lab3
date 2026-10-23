#include <stdio.h>
#include <math.h>

void Calculations(int *group, int *variant, double *course) {
    double sum = *group + *variant + *course;
    double product = (double)*group * *variant * *course;
    double result;

    if (*variant % 2 == 0) {
        result = sin(sum);
    } else {
        result = cos(product);
    }

    *group = (int)sum;
    *variant = (int)product;
    *course = result;
}

int main(void) {
    int group = 80;
    int variant = 12;
    double course = 4;

    printf("Початкові значення: група = %d, варіант = %d, курс = %g\n",
           group, variant, course);

    Calculations(&group, &variant, &course);

    printf("Нові значення: група = %d, варіант = %d, курс = %g\n",
           group, variant, course);

    return 0;
}