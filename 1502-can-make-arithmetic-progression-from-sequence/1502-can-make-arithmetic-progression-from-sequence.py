class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        m = min(arr)
        gap = (max(arr) - m) / (len(arr) - 1)
        if gap == 0: return True
        i = 0
        while i < len(arr):
            if arr[i] == m + i * gap:
                i += 1
            else:
                dis = arr[i] - m
                if dis % gap != 0: return False
                pos = int(dis / gap)
                if arr[pos] == arr[i]: return False
                arr[pos], arr[i] = arr[i], arr[pos]
        return True