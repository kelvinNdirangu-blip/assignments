#include <stdio.h>
#include <math.h>

int main()
{
    double radius = 0.0;
    double area = 0.0;
    double surfacearea = 0.0;
    const double PI = 3.14159;
    printf("enter the radius: ");
    if(scanf("%lf", &radius) !=1)

    area = PI*pow(radius, 2);
    surfacearea = 4*PI*pow(radius, 2);
    printf("area: %.2f\n", area);
    printf("surfacearea: %.2f\n",surfacearea);

    return 0;
}
