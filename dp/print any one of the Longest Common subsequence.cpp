// we use LC subsequence's tabulation code to print one of the multiple answers. We cannot print multiple ans using this method if they exist:


#include <iostream>
#include <vector>
using namespace std;

void LCS_Tab(const string& s, const string& t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = m;
    int len_of_lcs = dp[n][m];
    string lcs(len_of_lcs, ' ');  // Initialize with a length of len_of_lcs

    int index = len_of_lcs - 1;

    // Backtrack to find the LCS
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs[index] = s[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << lcs;
}

int main() {
    string s = "abcde";
    string t = "bdgek";
    LCS_Tab(s, t);
    return 0;
}
