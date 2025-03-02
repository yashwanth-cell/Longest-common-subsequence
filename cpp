#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the length of the Longest Common Subsequence
int LCSLength(const std::string &X, const std::string &Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D DP array to store the lengths of LCS
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];  // The length of the LCS is stored in dp[m][n]
}

// Function to print the LCS itself
void printLCS(const std::string &X, const std::string &Y) {
    int m = X.length();
    int n = Y.length();
    
    // Create a DP table for storing the lengths of LCS
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the DP table
    int i = m, j = n;
    std::string lcs = "";
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;  // Add current character to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
}

int main() {
    std::string X = "ABCBDAB";
    std::string Y = "BDCAB";

    std::cout << "Length of LCS: " << LCSLength(X, Y) << std::endl;

    printLCS(X, Y);

    return 0;
}
