#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// getting list of valid ops
const char validOps[] = {'+', '-', '*', '/'};
const int size = sizeof(validOps) / sizeof(validOps[0]);

// prompts user for their desired operation and checks list of valid operations
// to check if their input is valid. Also checks to see if input is correct. 
char opPrompt() {
    char opSign;
    char correct;
    bool incorrect = false; 
    bool match = false;

    // loops until user clarifies operation is correct. 
    while (!match) {
        printf("\nPlease input the sign of the operation you would like to use.");
        printf("\nFor ex: To use subtraction, input the \"-\" character.");
        printf("\n\nDesired operation: ");
        scanf(" %c", &opSign);

        for (int i = 0; i < size; i++) {
            if (opSign == validOps[i]) {
                match = true;
                break;
            }
        }

        if (!match) {
            printf("\nNot a valid operation.\n");
        } 
        else {
            
            do {
                printf("\nThe operation you enetered is %c.", opSign);
                printf("\nIs this correct?"); 
                printf("\nYes(y) / No(n): ");
                scanf(" %c", &correct);
                if (correct == 'y' || correct == 'Y') {
                    break;
                } 

                else if (correct != 'n' && correct != 'N') {
                    incorrect = true;
                    printf("\nPlease input using (Y) or (N).\n");
                }

                else {
                    match = false;
                    break;
                }
            } while (incorrect);

        }
    }
    return opSign;
}

// Prompts user for desired numbers and clarifies if the numbers
// are correct. 
void numPrompt(double *numA, double *numB, char opSign) {
    char correct;
    bool incorrect = true;
    bool proceed = true;

    while (incorrect) {
        printf("\nPlease input the values for A and B.");
        printf("\nFor ex: A %c B.", opSign);
        printf("\nValue for A: ");
        scanf(" %lf",   numA); 
        printf("Value for B: ");
        scanf(" %lf", numB); 

        do {
            printf("\n A = %.2lf and B = %.2lf.\n", *numA, *numB);
            printf("\nIs this the desired values?"); 
            printf("\nYes(y) / No(n): ");
            scanf(" %c", &correct);

            if (correct == 'y' || correct == 'Y') {
                incorrect = false;
                break;
            }

            else if (correct != 'n' && correct != 'N') {
                proceed = false;
                printf("\nPlease input using (Y) or (N).\n");
            }

            else {
                incorrect = true;
                break; 
            }
        } while (!proceed);
    }
}

// Functions for caculating. 
double add(double x, double y) {
    double sum = x + y;
    return sum;
}

double sub(double x, double y) {
    double diff = x - y;
    return diff;
}

double mul(double x, double y) {
    double prod = x * y;
    return prod;
}

double div(double x, double y){
    double quo = x / y;
    return quo;
}

// Calculates based on what operation the user inputs. 
void calculate(double *numA, double *numB, char opSign) {
    double answer; 

    switch (opSign) {
        case '+': 
            answer = add(*numA, *numB);
            printf("\n%.2lf + %.2lf = %.2lf\n", *numA, *numB, answer);
            break;
        case '-':
            answer = sub(*numA, *numB);
            printf("\n%.2lf - %.2lf = %.2lf\n", *numA, *numB, answer);
            break;
        case '*':
            answer = mul(*numA, *numB);
            printf("\n%.2lf * %.2lf = %.2lf\n", *numA, *numB, answer);
            break;
        case '/':
            if(*numB == 0) {
                printf("\n%.2lf cannot be divided by %.2lf\n", *numA, *numB);
                break;
            }

            else {
            answer = div(*numA, *numB);
            printf("\n%.2lf / %.2lf = %.2lf\n", *numA, *numB, answer);
            break;
            }
    }
}

