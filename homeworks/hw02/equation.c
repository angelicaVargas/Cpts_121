#include <stdio.h>
#include <math.h>

#define PI 3.141593
#define G 6.67*(10^(-11))

int main()
{
    int a;
    char letter, plaintext_character, encoded_character;
    double force, mass, acceleration;
    double volume_cylinder, radius, height;
    double mass1, mass2, distance;
    double vout, r2, r1, vin;
    double x1, x2, y1, y2;
    double y, z, x;

do {
    printf("Select an equation by typing one of the following charcters: \n");
    printf("N: Newton's Second Law\nV: Volume of a cylinder\nC: Character encoding\nG: Gravity\nR: Resistive divider\nD: Distance between two points\nE: General equation\n");
    scanf(" %c", &letter);

    if (letter == 'N')
    {
        printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
        scanf("%lf %lf", &mass, &acceleration);

        force = mass * acceleration;
        printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n", force, mass, acceleration);
    }
    else if (letter == 'V')
    {
        printf("Enter a radius and height (both floating-point values) for use in a volume of a cylinder equation: ");
        scanf("%lf %lf", &radius, &height);

        volume_cylinder = PI * radius * radius * height;
        printf("Volume of a cylinder: volume_cylinder = PI * radius * radius * height = %lf\n", volume_cylinder);

    }
    else if (letter == 'C')
    {
        printf("Enter a character (a - z): ");
        scanf(" %c", &plaintext_character);

        encoded_character = (plaintext_character - 'a') + 'A';
        printf("%c\n", encoded_character);
    }
    else if (letter == 'G')
    {
        printf("Enter the value for mass1, mass2 and distance (all floating-point values): ");
        scanf("%lf %lf %lf", &mass1, &mass2, &distance);

        force = G * mass1 * mass2 / (distance * distance);
        printf("Gravity: force = G * mass1 * mass2 / (distance * distance) = %lf\n", force);
    }
    else if (letter == 'R')
    {
        printf("Enter the values for r1, r2 and vin (all floating-point values): ");
        scanf("%lf %lf %lf", &r1, &r2, &vin);

        vout = r2 / (r1 + r2) * vin;
        printf("Resistive divider: vout = r2 / (r1 + r2) * vin = %lf\n", vout);
    }
    else if (letter == 'D')
    {
        printf("Enter the values for x1, x2, y1 and y2 (all floating-point values): ");
        scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

        distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        printf("Distance between two points: sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) = %lf\n", distance);
    }
    else if (letter == 'E')
    {
        printf("Enter the values to a (integer), x (float number), and z (float number): ");
        scanf("%d %lf %lf", &a, &x, &z);

        y = ((float) 89 / 27) - z * x + a / (a % 2);
        printf("General equation: y = (89 / 27) - z * x + a / (a %% 2) = %lf\n", y);
    }
    else
    {
        printf("Error... ");
    }
        printf("Do you want to continue? ('C': continue, 'S': stop): \n");
        scanf(" %c", &letter);
    }

    while (letter == 'C');

    return 0;
}
