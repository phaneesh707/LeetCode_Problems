class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        l=[0]*pow(2,k)
        for i in range(0,len(s)-k+1):
            l[int(s[i:i+k],2)]=1
        
        # l.sort();
        # print(l)
        for i in l:
            if(i==0):
                return 0
        return 1
        
        
        