#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **res, int *returnSize, char *current, int open, int close, int n, int pos) {
    if (pos == 2 * n) {
        current[pos] = '\0';
        res[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(res, returnSize, current, open + 1, close, n, pos + 1);
    }
    if (close < open) {
        current[pos] = ')';
        backtrack(res, returnSize, current, open, close + 1, n, pos + 1);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;
    int maxSize = 1;
    for (int i = 0; i < n; i++) maxSize *= 2 * i + 1; // rough estimate
    char **res = (char **)malloc(maxSize * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    
    backtrack(res, returnSize, current, 0, 0, n, 0);
    free(current);
    return res;
}

