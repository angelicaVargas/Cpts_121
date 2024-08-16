/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab5 Task1
* Date: September 24, 2021
* Description: This program finds the distance between two
* points (longitude and latitude) on the Earth's surface.
*/

#include <stdio.h>
#include <math.h>

double dmsToRadians(double dms[3])
{
    double degree, radians;

    degree = dms[0] + (dms[1]/60) + (dms[2]/3600);
    radians = (degree * M_PI) / 180;

    return radians;
}

void polarToCartesian(double latitude[3], double longitude[3], double position[3])
{
    double theta = dmsToRadians(latitude);
    double phi = dmsToRadians(longitude);

    position[0] = cos(theta) * cos(phi);
    position[1] = cos(theta) * sin(phi);
    position[2] = sin(theta);
}

double arcLength(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
    double arc_length;
    double position0[3];
    double position1[3];

    polarToCartesian(latitude0, longitude0, position0);
    polarToCartesian(latitude1, longitude1, position1);
    
    arc_length = acos(position0[0]*position1[0] + position0[1]*position1[1] + position0[2]*position1[2]);

    return arc_length;
}

double crowFly(double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
    double distance;
    double length_arc;

    length_arc = arcLength(latitude0, longitude0, latitude1, longitude1);
    distance = length_arc * 6378;

    return distance;
}

int main(void)
{
    double latitude0[3], longitude0[3];
    double latitude1[3], longitude1[3];

    printf("From latitude (d m s): ");
    scanf("%lf %lf %lf", &latitude0[0], &latitude0[1], &latitude0[2]);
    printf("From longitude (d m s): ");
    scanf("%lf %lf %lf", &longitude0[0], &longitude0[1], &longitude0[2]);

    printf("From latitude (d m s): ");
    scanf("%lf %lf %lf", &latitude1[0], &latitude1[1], &latitude1[2]);
    printf("From longitude (d m s): ");
    scanf("%lf %lf %lf", &longitude1[0], &longitude1[1], &longitude1[2]);

    printf("Distance: %.1lf km\n", crowFly(latitude0, longitude0, latitude1, longitude1));

    return 0;
}