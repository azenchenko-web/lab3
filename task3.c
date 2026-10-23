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

void print_array(const char *title, const double *arr, int n) {
    printf("%s: [", title);
    for (int i = 0; i < n; i++) {
        printf("%g", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

int main(void) {
    int group = 80;
    int variant = 12;
    double course = 4;

    int group_orig = group;
    int variant_orig = variant;
    double course_orig = course;

    Calculations(&group, &variant, &course);

    double arr[] = {1, 2, group, variant, course};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array("Масив до змін", arr, n);

    arr[0] = group_orig;
    arr[1] = course_orig;

    for (int i = 0; i < n; i++) {
        arr[i] += variant_orig;
    }

    print_array("Масив після змін", arr, n);

    return 0;
}