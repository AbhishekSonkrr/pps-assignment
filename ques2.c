

#include <stdio.h>

// Calculates and prints the sum of squares of the digits of 'num'.
// Returns the sum as an integer.
int sumOfSquares(int num) {
    int sum = 0;
    int digits[10], count = 0;

    // Extract digits (in reverse order)
    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    // Print the calculation in readable format
    printf("(");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d^2", digits[i]);
        if (i > 0) printf(" + ");
        sum += digits[i] * digits[i];
    }
    printf(") = %d\n", sum);
    return sum;
}

int main() {
    int n = 17; // Starting number
    int k = 5;  // Number of repetitions

    printf("Start: %d\n", n);
    for (int step = 1; step <= k; step++) {
        n = sumOfSquares(n);
    }
    printf("Final result after %d steps: %d\n", k, n); // Should print 89
    return 0;
}