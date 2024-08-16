#include <stdio.h>
#include <math.h> /* for M_PI, sin(), and cos() */
#include "grafic.h"

void init(const char **appTitle_pp)
{
    *appTitle_pp = "\"grafic\" square demo";
}

void middle(double p0[], double p1[], double s, double r[2])
{
    r[0] = p0[0] * (1 - s) + s * p1[0];
    r[1] = p0[1] * (1 - s) + s * p1[1];
}

void triangleDraw(double p0[], double p1[], double p2[])
{
    line(p0, p1);
    line(p1, p2);
    line(p2, p0);
}

void fractalTriangle(double p0[], double p1[], double p2[], int i)
{
    double auxp0[2], auxp1[2], auxp2[2];
    if (i > 7)
    {
        printf("Stop");
    } else {
        triangleDraw(p0, p1, p2);
        middle(p0, p1, .5, auxp0);
        middle(p1, p2, .5, auxp1);
        middle(p2, p0, .5, auxp2);

        fractalTriangle(p0, auxp0, auxp2, i+1);
        fractalTriangle(auxp0, p1, auxp1, i+1);
        fractalTriangle(auxp2, auxp1, p2, i+1);
    }
}

void redraw(void)
{
    double p0[2], p1[2], p2[2];
    p0[0] = -0.5;
    p0[1] = 0;
    p1[0] = 0;
    p1[1] = 1;
    p2[0] = 0.5;
    p2[1] = 0;
    fractalTriangle(p0, p1, p2, 0);
}

