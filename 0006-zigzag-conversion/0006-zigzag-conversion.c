#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Base cases: if only 1 row or string length is less than or equal to rows, pattern doesn't change
    if (numRows <= 1 || len <= numRows) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    // Allocate memory to hold string segments for each row
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowLengths = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // Upper bound memory allocation per row
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currentRow = 0;
    int goingDown = 0; // Direction flag (0 = up/up-right, 1 = down)

    for (int i = 0; i < len; i++) {
        // Add current character to its respective row
        rows[currentRow][rowLengths[currentRow]++] = s[i];

        // Reverse direction at the top or bottom row boundary
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }

        // Move to the next row index
        currentRow += goingDown ? 1 : -1;
    }

    // Combine all row strings into the final result string
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowLengths[i]; j++) {
            result[idx++] = rows[i][j];
        }
        free(rows[i]); // Free allocated memory for individual row
    }
    result[idx] = '\0'; // Null-terminate final output

    free(rows);
    free(rowLengths);

    return result;
}