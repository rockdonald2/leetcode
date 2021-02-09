class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        if not list1 or not list2:
            return []

        _st = {}

        for r in list1:
            if r in list2:
                _st[r] = (list1.index(r), list2.index(r))

        min = []
        for r in _st.keys():
            if not min or sum(_st[min[0]]) > sum(_st[r]):
                min = [r]
            elif sum(_st[min[0]]) == sum(_st[r]):
                min.append(r)

        return min