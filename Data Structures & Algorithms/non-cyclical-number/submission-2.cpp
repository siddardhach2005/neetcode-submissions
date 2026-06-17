class Solution {
   public:
    int sos(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_set<int> vis;
        while (vis.find(n) == vis.end() && n != 1) {
            vis.insert(n);
            n = sos(n);
        }
        return n == 1;
    }
};
