#include <stdio.h>
#include "myFunctions.c"
#include <string.h>

int main(){

    bool again = false;
    bool proceed = true;
    char input; 
    char sign;
    double numA, numB;
    
    // Do loop that repeats if the user wants to make another calculation.
    // 'y' = again = true || 'n' = again = false.
    do {
        // grabs op from user and assigns it to var sign.
        sign = opPrompt();
        // grabs numbers to calculate from user. 
        numPrompt(&numA, &numB, sign);
        // calculates the given operation and numbers.
        calculate(&numA, &numB, sign);

        // do loop that repeats until user gives inputs 'y' or 'n'.
        do {
            printf("\nWould you like to make another calculation?"); 
            printf("\nYes(y) / No(n): ");
            scanf(" %c", &input);

            if (input == 'y' || input == 'Y') {
                again = true;
                break;
            } 

            else if (input != 'n' && input != 'N') {
                proceed = false;
                printf("\nPlease input using (Y) or (N).\n");
            }

            else {
                printf("\nThank you for using Chong's Calculator!\n");
                again = false;
                break;
            }
        } while (!proceed);

    } while (again);

    return 0;
}