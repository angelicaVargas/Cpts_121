/*Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Homework 04
* Date: October 1, 2021
* Description: This program evaluates equations (using functions).
* The user inputs a letter to solve a specific equation. Once the
* equation is solved, the program asks if they want to continue or stop.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141593

double calculate_newtons_2nd_law(double mass, double acceleration) 
{
    return mass * acceleration; 
}

double calculate_volume_cylinder(double radius, double height)
{
    return PI * radius * radius * height;
}

char perform_character_encoding(char plaintext_character)
{
    return (plaintext_character - 'a') + 'A';
}

double calculate_gravity_force(double mass1, double mass2, double distance)
{
    const double G = 6.67*(10^(-11));
    return G * mass1 * mass2 / (distance * distance);
}

double calculate_resistive_divider(double r1, double r2, double vin)
{
    return r2 / (r1 + r2) * vin;
}

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calculate_general_equation(int a, double x, double z)
{
    return ((float) 89 / 27) - z * x + a / (a % 2);
}

int main()
{
    int a;
    char letter, plaintext_character;
    double mass, acceleration;
    double radius, height;
    double mass1, mass2, distance;
    double r2, r1, vin;
    double x1, x2, y1, y2;
    double x, z;

do {
    printf("Select an equation by typing one of the following charcters: \n");
    printf("N: Newton's Second Law\n");
    printf("V: Volume of a cylinder\n");
    printf("C: Character encoding\n");
    printf("G: Gravity\n");
    printf("R: Resistive divider\n");
    printf("D: Distance between two points\n");
    printf("E: General equation\n");
    scanf(" %c", &letter);

    switch(letter) {
    
    case 'N': {        
        printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
        scanf("%lf %lf", &mass, &acceleration);
        printf("Newton's Second Law: force = mass * acceleration = %.3lf\n", calculate_newtons_2nd_law(mass, acceleration));
        break;
    }
    case 'V': {
        printf("Enter a radius and height (both floating-point values) for use in a volume of a cylinder equation: ");
        scanf("%lf %lf", &radius, &height);
        printf("Volume of a cylinder: volume_cylinder = PI * radius * radius * height = %.3lf\n", calculate_volume_cylinder(radius, height));
        break;
    }
    case 'C': {
        printf("Enter a character (a - z): ");
        scanf(" %c", &plaintext_character);
        printf("%c\n", perform_character_encoding(plaintext_character));
        break;
    }
    case 'G': {
        printf("Enter the value for mass1, mass2 and distance (all floating-point values): ");
        scanf("%lf %lf %lf", &mass1, &mass2, &distance);
        printf("Gravity: force = G * mass1 * mass2 / (distance * distance) = %.3lf\n", calculate_gravity_force(mass1, mass2, distance));
        break;
    }
    case 'R': {
        printf("Enter the values for r1, r2 and vin (all floating-point values): ");
        scanf("%lf %lf %lf", &r1, &r2, &vin);
        printf("Resistive divider: vout = r2 / (r1 + r2) * vin = %.3lf\n", calculate_resistive_divider(r1, r2, vin));
        break;
    }
    case 'D': {
        printf("Enter the values for x1, x2, y1 and y2 (all floating-point values): ");
        scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
        printf("Distance between two points: sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) = %.3lf\n", calculate_distance_between_2pts(x1, x2, y1, y2));
        break;
    }
    case 'E': {
        printf("Enter the values to a (integer), x (float number), and z (float number): ");
        scanf("%d %lf %lf", &a, &x, &z);
        printf("General equation: y = (89 / 27) - z * x + a / (a %% 2) = %.3lf\n", calculate_general_equation(a, x, z));
        break;
    }
    default: {
        printf("Error...\n");
        break;
    }
    }
    printf("Do you want to continue? ('C': continue, 'S': stop): \n");
    scanf(" %c", &letter);
    }
    while (letter == 'C');

    return 0;
}
