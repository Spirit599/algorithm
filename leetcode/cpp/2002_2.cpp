class Solution:
    def maxProduct(self, s: str) -> int:
        def check(mask):
            tmp = []
            idx = 0
            while mask:
                if mask & 1: tmp.append(s[idx])
                idx += 1
                mask >>= 1
            return len(tmp) if tmp == tmp[::-1] else 0
            
        n = len(s)
        valid = [0] * (1 << n)
        for mask in range(1, 1 << n):
            valid[mask] = check(mask)
        ans = 0
        for mask in range(1, 1 << n):
            subject = mask
            while subject:
                ans = max(ans, valid[subject] * valid[mask ^ subject])
                subject = (subject - 1) & mask
        return ans
                