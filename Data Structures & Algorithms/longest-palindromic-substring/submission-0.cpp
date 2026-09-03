class Solution {
public:
    pair<int,int> pal(string &s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return {l+1,r-l-1};
    }
    string longestPalindrome(string s) {
        int len=1;
        int st=0;
        for(int i=0;i<s.size();i++){
            auto odd=pal(s,i,i);
            auto even=pal(s,i,i+1);
            if(odd.second>len){
                st=odd.first;
                len=odd.second;
            }
            if(even.second>len){
                st=even.first;
                len=even.second;
            }
        }
        return s.substr(st,len);
    }
};