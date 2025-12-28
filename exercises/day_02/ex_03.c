//
// Created by tuan-nguyen on 28/12/2025.
//
#include <stdio.h>

const double PI = 3.141592654;
double calculate_area(double radius);
double calculate_circumference(double radius);

int main()
{
    double circle_radius;
    printf("Enter circle radius: ");
    scanf("%lf", &circle_radius);
    printf("Area of circle: %f\n", calculate_area(circle_radius));
    printf("Circumference of circle: %f\n", calculate_circumference(circle_radius));
    return 0;
}

double calculate_area(const double radius)
{
    return PI * radius * radius;
}

double calculate_circumference(const double radius)
{
    return 2 * PI * radius;
}