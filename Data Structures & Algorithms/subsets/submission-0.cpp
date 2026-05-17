class Solution {
public:
    vector<vector<int>> res;
    void f(int i,vector<int> &a,vector<int> &n){
        if(i==n.size()){
            res.push_back(a);
            return;
        }
        a.push_back(n[i]);
        f(i+1,a,n);
        a.pop_back();
        f(i+1,a,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int> a;
        f(i,a,nums);
        return res;
    }
};
