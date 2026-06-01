class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    void backtrack(string s, int start, vector<string>& path) {

        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            string part = s.substr(start, end - start + 1);

            if (isPalindrome(part)) {

                path.push_back(part);

                backtrack(s, end + 1, path);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> path;

        backtrack(s, 0, path);

        return res;
    }
};