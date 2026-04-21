class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st=""
        r=0
        for c in s:
            if c in st:
                st=st[st.index(c)+1:]
            st+=c
            r=max(r,len(st))
        return r