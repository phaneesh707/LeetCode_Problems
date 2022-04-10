class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        sol=[]
        for i in ops:
            if(i=="C"):
                sol.pop(-1)
            elif(i=="D"):
                sol.append(2*sol[-1])
            elif(i=="+"):
                sol.append(sol[-1]+sol[-2])
            else:
                sol.append(int(i))
            
        return sum(sol)
                
                
        