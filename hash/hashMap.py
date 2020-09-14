class MyHashMap:
    def hashFunction(self, key):
        return ((key * 999983) % (1 << 15)) >> 5


    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._st = [[] for _ in range(1 << 15)]


    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        index = self.hashFunction(key)
        bucket = self._st[index]

        if self.get(key) == -1:
            bucket.append([key, value])
        else:
            for pair in bucket:
                if pair[0] == key:
                    pair[1] = value


    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        index = self.hashFunction(key)
        bucket = self._st[index]

        for pair in bucket:
            if pair[0] == key:
                return pair[1]

        return -1


    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        index = self.hashFunction(key)
        bucket = self._st[index]
        pair = [key, self.get(key)]

        if pair[1] != -1:
            bucket.remove(pair)


hashMap = MyHashMap()
hashMap.put(1, 1)
hashMap.put(2, 2)
hashMap.get(1)
hashMap.get(3)
hashMap.put(2, 1)
hashMap.get(2)
hashMap.remove(2)
hashMap.get(2)