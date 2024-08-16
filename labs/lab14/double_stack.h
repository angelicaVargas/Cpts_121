/*
 * This is the external interface of the double_stack library. Note
 * that the stack itself is intentionally not externally visible.
 */
 
extern void doubleStack_push(double d);
/* pushes a double value on the stack */

extern void doubleStack_print(void);
/* prints the stack on stdout, but does not alter it */

extern int doubleStack_pop(double*);

