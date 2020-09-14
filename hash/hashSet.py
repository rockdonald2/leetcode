class MyHashSet:
    def hashFunction(self, key):
        # multiplicative hashing
        # key is the key we need to hash
        # 999983 is a random prime number
        # we need to calculate the mod of this multiplication by 2^w
        # for w we can choose any number that is strictly bigger than m
        # m = 15, is the length in bits of the output
        # this will decide how many individual buckets we will have
        # because our program will have no more than 10000 operations overall, we can
        # simply have any 2^m > 10000
        return ((key * 999983) % (1 << 20)) >> 5
        # this whole formula will return a hash value between {0 and 2^15 - 1}


    def __init__(self):
        """
        Initialize your data structure here.
        """
        # a convenient formula for calculating 2^n is 1 << n
        self._st = [[] for _ in range(1 << 15)]


    def add(self, key: int) -> None:
        index = self.hashFunction(key)
        if not key in self._st[index]:
            self._st[index].append(key)


    def remove(self, key: int) -> None:
        index = self.hashFunction(key)
        if key in self._st[index]:
            self._st[index].remove(key)


    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        index = self.hashFunction(key)
        return key in self._st[index]


hs = MyHashSet()
hs.add(1)
hs.add(2)
hs.contains(1)
hs.contains(2)
hs.contains(3)
hs.add(2)
hs.remove(2)
hs.contains(2)