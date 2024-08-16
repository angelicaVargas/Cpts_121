#ifndef _INCLUDED_GRAPHICS

// these are provided by "grafic"
void color(double r, double g, double b);
void line(double p0[2], double p1[2]);

// these are to be provided by the user (instead of main())
void init(const char **appTitle);
void redraw(void);

#define _INCLUDED_GRAPHICS
#endif
