class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        for i in range(len(s)):
            str = s[-1]+s[:len(s)-1]
            if(str == goal):
                return 1
            s = str
        return 0