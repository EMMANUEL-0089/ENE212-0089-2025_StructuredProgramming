#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Variable declaration
    int radius;
    double pi = 3.142;
    double area;

    //Capture input from user
    printf("What is the radius of the sphere:");
    scanf("%d", &radius);
    area = 4 * pi * radius * radius;
    printf("Area : %f", area);

    return 0;
}
