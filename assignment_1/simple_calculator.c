#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
double add(double a,double b){return a + b;}
double subtract(double a, double b){return a - b;}
double multiply(double a, double b){return a * b;}
double divide(double a, double b){return a / b;}

void print_menu(void){

    printf("\nChoose an operation\n");
    printf("+ : addition\n");
    printf("- : subtraction\n");
    printf("/ : division\n");
    printf("* : multiplication\n");
    printf("q : Quit\n");

    }
int main (void)
{   printf("\tSIMPLE CALCULATOR\n");
    print_menu();
    double a , b, result;
    char op;
    bool running = true;
while(running){
    printf("Enter operation: ");
    if (scanf(" %c", &op) != 1) {
        printf("Invalid operator!\n");
        return 1;
    }

    if (op == 'q' || op == 'Q' ){
        running = false;
        printf("Goooodbyeeee\n");
            break;
    }

    printf("Enter first number: ");
    if (scanf("%lf", &a) != 1){
        printf("Invalid operator!\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &b) != 1){
        printf("Invalid operator!\n");
        return 1;
    }

    switch(op)
    {   case'+' : result = add(a,b);
                break;
        case'-' : result = subtract(a,b);
                break;
        case'/' : result = divide(a,b);
                break;
        case'*' : result = multiply(a,b);
                if(b == 0)
                    {
                    printf("Error:Division by zero!\n");
                    return 1;
                    }
        default: printf("Unknown operator %c", op);
                return 1;
    }
    printf("result : %.2f", result);
    printf("\n");
    }
    return 0;

}


