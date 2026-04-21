class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d=defaultdict(list)
        for s in strs:
            so="".join(sorted(s))
            d[so].append(s)
        return list(d.values())