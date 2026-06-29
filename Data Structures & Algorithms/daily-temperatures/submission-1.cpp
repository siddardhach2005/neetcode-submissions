class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> r(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                int x=s.top();
                s.pop();
                r[x]=i-x;
            }
            s.push(i);
        }
        return r;
    }
};
