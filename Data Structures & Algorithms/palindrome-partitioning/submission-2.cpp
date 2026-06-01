class Solution {
public:
    vector<vector<string>> res;
    vector<vector<bool>> dp;

    void backtrack(string& s, int start,
                   vector<string>& path) {

        if(start == s.size()) {
            res.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); end++) {

            if(dp[start][end]) {

                path.push_back(
                    s.substr(start, end - start + 1)
                );

                backtrack(s, end + 1, path);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        dp.assign(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j] &&
                   (j - i <= 2 || dp[i+1][j-1])) {

                    dp[i][j] = true;
                }
            }
        }

        vector<string> path;
        backtrack(s, 0, path);

        return res;
    }
};