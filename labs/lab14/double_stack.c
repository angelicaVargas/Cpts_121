#include <stdio.h>
#include <stdlib.h>
#include "double_stack.h"

struct DoubleStack
{
    /*
     * ASSIGNMENT
     *
     * Declare two structure elements:
     *
     * - a pointer `next_p` to the next `struct DoubleStack` in the
     *   list (which is NULL at the end of the list).
     *
     * - a double value `d`
     */
    struct DoubleStack *next_p; //link
    double d;
};

/*
 * ASSIGNMENT
 *
 * Declare a pointer `doubleStackBase_p` as base (aka "top" or “head”) of
 * the `struct DoubleStack` list. 
 * This pointer is the only part of the
 * stack that isn't dynamically allocated. Make it hidden outside of
 * this library (hint: "static"). Initialize it to NULL. (According to
 * C syntax, this last step isn't necessary, but it's a nice reminder
 * to the programmer that it's an empty list.)
 */

static struct DoubleStack *doubleStackBase_p = NULL; //head


static struct DoubleStack *doubleStack_new(double d)
{
     /*
     * ASSIGNMENT
     *
     * Implement the following pseudocode:
     *
     * call malloc() to assign a struct DoubleStack pointer doubleStack_p`
     * to point to a block of heap memory which is the size of a
     * struct DoubleStack.
     * set `doubleStack_p`'s `next_p` pointer to NULL
     * set `doubleStack_p`'s `d` attribute to the `d` argument
     *  of this function
     * return `doubleStack_p`
     */
    struct DoubleStack *doubleStack_p = (struct DoubleStack*) malloc(sizeof(struct DoubleStack));
    doubleStack_p -> next_p = NULL;
    doubleStack_p -> d = d;

    return doubleStack_p;
}

void doubleStack_push(double d)
{
 /*
     * ASSIGNMENT
     *
     * Implement the following pseudocode:
     *
     * call doubleStack_new() with `d` to create a new list element
     *  `doubleStack_p`
       * set `doubleStack_p`'s struct's `next_p` attribute to `doubleStackBase_p`
     * set `doubleStackBase_p` to `doubleStack_p`
     */
    struct DoubleStack* doubleStack_p = doubleStack_new(d);
 
    doubleStack_p -> next_p = doubleStackBase_p;
    doubleStackBase_p = doubleStack_p;


}

int doubleStack_pop(double *val)
{
    if (doubleStackBase_p != NULL)
    {
        (*val) = doubleStackBase_p -> d;
        doubleStackBase_p = doubleStackBase_p -> next_p;
        return 1;
    } 

    return 0;
}

void doubleStack_print(void)
{
    /*
     * ASSIGNMENT
     *
     * Implement the following pseudocode:
     *
     * try to pop the top element off the stack with doubleStack_pop()
     * if successful,
     *     (recursively) call doubleStack_print() to print the rest of
     *      the stack
     *     call printf() to print the `d` attribute of
     *      `doubleStack_p`'s struct on a single line using the "g"
     *      (general) floating point format with a minimum column
     *      width of 20 and (a maximum of) 14 significant digits
     *     call doubleStack_push() to push the top element back on top
     *      of the stack
     *
     * Technically, this prints the stack "upside down", but IMHO that
     * order seems more intuitive to the interactive user.
     */

    int result;
    double d;
    result = doubleStack_pop(&d);
    if (result == 1)
    {
        doubleStack_print();
        printf("%lf\n", d);
        doubleStack_push(d);
    }
}


