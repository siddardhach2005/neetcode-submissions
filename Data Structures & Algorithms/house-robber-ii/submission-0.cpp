class Solution {
   public:
    int hr(vector<int>& nums) {
        int t = 0;
        int o = 0;
        int c;
        for (int i = 0; i < nums.size(); i++) {
            c = max(o, t + nums[i]);
            t = o;
            o = c;
        }
        return o;
    }
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (l == 1) return nums[0];
        vector<int> a1(nums.begin(), nums.end() - 1);
        vector<int> a2(nums.begin() + 1, nums.end());
        int c1 = hr(a1);
        int c2 = hr(a2);
        return max(c1, c2);
    }
};
