class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        if len(s) == 0 and len(t) == 0:
            return True

        _s1 = {}
        _s2 = {}

        i = 0

        while i < len(s):
            if s[i] not in _s1 and t[i] not in _s2:
                _s1[s[i]] = t[i]
                _s2[t[i]] = s[i]
                i += 1
            elif s[i] in _s1 and t[i] in _s2:
                if _s1[s[i]] != t[i] or _s2[t[i]] != s[i]:
                    return False
                else:
                    i += 1
                    continue
            else:
                return False

        return True


sol = Solution()
print(sol.isIsomorphic('aa', 'a'))