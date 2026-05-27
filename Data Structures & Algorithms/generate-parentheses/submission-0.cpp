class Solution {
public:
    vector<string> res;
    void f(int n,string &a,int o,int c){
        if(a.size()==n*2){
            res.push_back(a);
            return;
        }
        if(o<n){
            a.push_back('(');
            f(n,a,o+1,c);
            a.pop_back();
        }
        if(c<o) {
            a.push_back(')');
            f(n,a,o,c+1);
            a.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string a;
        f(n,a,0,0);
        return res;
    }
};
