class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
             return False
        rev = int(str(x)[::-1])
        if rev == x:
            return True
        else :
            return False
        