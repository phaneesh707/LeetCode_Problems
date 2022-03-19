class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l=[]
        l.extend(nums)
        sol=[]
        l.sort()
        i=0
        j=len(l)-1
        while(i<j):
            if(l[i]+l[j]==target):
                sol.append(l[i])
                sol.append(l[j])
                break
            elif(l[i]+l[j]>target):
                j-=1
            else:
                i+=1
        
        solu=[]
        for k in range(len(nums)):
            if(nums[k]==sol[0] or nums[k]==sol[1]):
                solu.append(k)
        return solu