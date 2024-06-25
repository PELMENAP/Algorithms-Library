#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stralgo.h"


char* ManakerPreprocessing(const char* s) {
    int n = strlen(s);
    if (n == 0) return "^$";
    char* ret = (char*)malloc((2 * n + 3) * sizeof(char));
    ret[0] = '^';
    for (int i = 0; i < n; i++)
    {
        ret[2 * i + 1] = '#';
        ret[2 * i + 2] = s[i];
    }
    ret[2 * n + 1] = '#';
    ret[2 * n + 2] = '$';
    ret[2 * n + 3] = '\0';
    return ret;
}

char* longestPalindrome(const char* str)
{
    char* T = ManakerPreprocessing(str);
    int n = strlen(T);
    int* P = (int*)malloc(n * sizeof(int));
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int mirr = 2 * C - i;
        if (R > i) P[i] = (R - i < P[mirr]) ? R - i : P[mirr];
        else P[i] = 0;
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;
        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, str + start, maxLen);
    result[maxLen] = '\0';
    free(T);
    free(P);
    return result;
}

char* longestIncreasingSubstring(const char* s)
{
    int n = strlen(s);
    if (n == 0) return "";
    int maxLength = 1;
    int currentLength = 1;
    int startIndex = 0;
    int maxStartIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] > s[i - 1]) currentLength++;
        else
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                maxStartIndex = startIndex;
            }
            startIndex = i;
            currentLength = 1;
        }
    }

    if (currentLength > maxLength)
    {
        maxLength = currentLength;
        maxStartIndex = startIndex;
    }
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + maxStartIndex, maxLength);
    result[maxLength] = '\0';
    return result;
}

char* findLCS(char* X, char* Y)
{
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }
    int index = L[m][n];
    char* lcs = (char *)malloc((index+1)*sizeof(char));
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1]) i--;
        else j--;

    }
    return lcs;
}

char* findLongestCommonSubstring(char* X, char* Y)
{
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];
    int maxLength = 0;
    int endIndex = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            L[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > maxLength)
                {
                    maxLength = L[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    if (maxLength > 0)
    {
        char* lcs = (char*)malloc((maxLength + 1) * sizeof(char));
        strncpy(lcs, &X[endIndex - maxLength + 1], maxLength);
        lcs[maxLength] = '\0';
        return lcs;
    }
    else return NULL;
}

void computeLPSArray(const char* substr, int M, int* lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (substr[i] == substr[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0) length = lps[length - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int find(const char* text, const char* substr)
{
    int N = strlen(text);
    int M = strlen(substr);
    int* lps = (int*)malloc(M * sizeof(int));
    computeLPSArray(substr, M, lps);
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (substr[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            free(lps);
            return i - j;
        }
        else if (i < N && substr[j] != text[i])
        {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    free(lps);
    return -1;
}
