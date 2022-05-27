class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        # num = str(n)
        count = 0;
        while(n):
            if(n&1):
                count+=1;
            # print(num)
            n=n>>1
        return count;