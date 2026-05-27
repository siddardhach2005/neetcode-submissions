class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int> &nums,vector<int> &a,vector<int> &v){
        if(a.size()==nums.size()){
            res.push_back(a);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!v[i]){
                a.push_back(nums[i]);
                v[i]=1;
                f(nums,a,v);
                a.pop_back();
                v[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        vector<int> a;
        f(nums,a,v);
        return res;
    }
};
