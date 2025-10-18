/*___________________________________________________________________________________________________________________________
Polite numbers: integers expressible as a sum of two or more consecutive positive integers; politeness is the count of such representations.
politeFunc(n) prints each representation on a new line or "I am RUDE!" if none (e.g., powers of 2).

Name:Abhishek Sonkar (2025ca005)

_____________________________________________________________________________________________________________________________*/

#include <stdio.h>

// Function: politeFunc
// Purpose: Prints all ways n can be written as a sum of consecutive positive integers.
// If n is impolite (cannot be written as such), prints "I am RUDE!"
// Example: For n=10, output is:
//   1+2+3+4
//   2+3+5
// For n=8 (a power of 2), output is:
//   I am RUDE!

// Prints all ways n can be written as a sum of consecutive positive integers.
// If n is impolite, prints "I am RUDE!"
void politeFunc(int n) 
{
    int found = 0; // Tracks if at least one representation is found

    // Try all possible lengths of consecutive numbers (at least 2)
    for (int length = 2; length < n; length++) 
    {
        // The sum of 'length' consecutive numbers starting from x is:
        // n = x + (x+1) + ... + (x+length-1) = length*x + length*(length-1)/2
        // Rearranged: x = (n - length*(length-1)/2) / length
        
        int temp = n - length * (length - 1) / 2;
        if (temp <= 0) break; // No valid starting number x for this length
        if (temp % length == 0) 
        {
            int x = temp / length; // Starting number of the sequence
            found = 1;
            // Print the sequence x, x+1, ..., x+length-1 with plus signs
            for (int i = 0; i < length; i++) 
            {
                printf("%d", x + i);
                if (i < length - 1) printf("+");
            }
            printf("\n");
        }
    }
    // If no representation found, print the rude message
    if (!found) {
        printf("I am RUDE!\n");
    }
}


// Main function: gets user input and calls politeFunc
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    politeFunc(n);
    return 0;
}
