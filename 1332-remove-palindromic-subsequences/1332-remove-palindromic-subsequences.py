class Solution(object):
    def removePalindromeSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        i=0
        j = len(s)-1;
        while(i<j):
            if(s[i]!=s[j]):
                return 2;
            i+=1
            j-=1
        
    
        return 1;