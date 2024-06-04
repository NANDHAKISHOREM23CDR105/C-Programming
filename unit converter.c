#include <stdio.h>

int main() {
    double kilometers, miles;

    printf("Enter distance in kilometers: ");
    scanf("%lf", &kilometers);

    miles = kilometers * 0.621371;

    printf("Distance in miles: %.2lf\n", miles);

    return 0;
}
