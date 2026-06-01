class Solution {
public:
    bool isPalindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    vector<vector<string>> res;
    void generate(string s,int start,vector<string> path){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int e=start;e<s.size();e++){
            string p=s.substr(start,e-start+1);
            if(isPalindrome(p)){
                path.push_back(p);
                generate(s,e+1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        generate(s,0,path);
        return res;
    }
};
