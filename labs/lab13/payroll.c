/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab09
* Date: Novemeber 19, 2021
* Description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {

    char name[100];      // employee's name - last, first
    char title;          // title 'B' or 'M'
    double hours_worked; // total number of hours worked
    double payrate;      // pay rate per hour
    double payment;      // total payment for the pay period – you will compute

} Employee;

double ComputePayment(char title, double hours_worked, double payrate);

int main() 
{
    int n, i = 0;
    double totalPayments = 0, average = 0, max, min;
    FILE *f_payroll, *f_paid;

    f_payroll = fopen("payroll.txt", "r");
    f_paid = fopen("paid.txt", "w");

    fscanf(f_payroll, "%d", &n); //Read the total number of records
    printf("The number of empolyees is %d\n", n);

    Employee *prt = (Employee*) malloc(n * sizeof(Employee)); //Allocate the memory

    for(i = 0; i < n; i++) 
    {
        fgets(prt[i].name, 100, f_payroll);
        fscanf(f_payroll, "%s", prt[i].name);
        fscanf(f_payroll, " %c", &prt[i].title);
        fscanf(f_payroll, "%lf", &prt[i].hours_worked);
        fscanf(f_payroll, "%lf", &prt[i].payrate);
        prt[i].payment = ComputePayment(prt[i].title, prt[i].hours_worked, prt[i].payrate);
    }
    // if(prt[i].hours_worked > 80) {
    //     overtime = prt[i].hours_worked - 80;
    //     payment = 80 * prt[i].payrate;

    //     if(prt[i].title == 'B') {
    //         overtime_pay = 1.5 * prt[i].payrate * overtime;
    //         prt[i].payment = payment + overtime_pay;

    //     } else {
    //         overtime_pay = 1.8 * prt[i].payrate * overtime;
    //         prt[i].payment = payment + overtime_pay;
    // }
    // }
    // else {
    //     prt[i].payment = prt[i].hours_worked * prt[i].payrate; // Compute the total payment for each employee
    //     }

    // total_payroll = total_payment + prt[i].payment;
    // average = total_payroll/n;
    // }
    
    /*!!!!!!!how to add slashes to a block of code: command + / !!!!!!!*/

    max = prt[0].payment;
    min = prt[0].payment;
    
    for(i = 0; i < n; i++) {
        if(prt[i].payment > max) {
            max = prt[i].payment;
        }
        if(prt[i].payment < max) {
            min = prt[i].payment;
        }
    }
    average = totalPayments/n;

    fprintf(f_paid, "Total: $%.2lf\n", totalPayments);
    fprintf(f_paid, "Average: $%.2lf\n", average);
    fprintf(f_paid, "Maximum: $%.2lf\n", max);
    fprintf(f_paid, "Minimum: $%.2lf\n", min);

    fclose(f_payroll);
    fclose(f_paid);
    free(prt);

    return 0;
}

double ComputePayment(char title, double hours_worked, double payrate) 
{
    double payment, over = 0, rateOver, overtime;

    rateOver = (title == 'B') ? 1.5 : 1.8;

    if(hours_worked > 80) {
        over = hours_worked - 80;
        hours_worked = 80;
    }
    payment = hours_worked * payrate;
    overtime = rateOver * payrate * over;

    return payment + overtime;
}