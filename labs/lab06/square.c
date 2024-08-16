#include <stdio.h>
#include <math.h> /* for M_PI, sin(), and cos() */
#include "grafic.h"

void init(const char **appTitle_pp)
{
    *appTitle_pp = "\"grafic\" square demo";
}

void redraw(void)
{   
    double p0[2], p1[2], p2[2], p3[2];
    p0[0] = -0.5; p0[1] = -0.5;
    p1[0] =  0.5; p1[1] = -0.5;
    p2[0] =  0.5; p2[1] =  0.5;
    p3[0] = -0.5; p3[1] =  0.5;
    line(p0, p1);
    line(p1, p2);
    line(p2, p3);
    line(p3, p0);
}