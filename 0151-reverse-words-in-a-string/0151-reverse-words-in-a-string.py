class Solution:
    def reverseWords(self, s: str) -> str:
        ll = s.split(' ')
        ll.reverse()
        res = []
        for l in ll:
            if l:
                res.append(l)
        return (' '.join(res))