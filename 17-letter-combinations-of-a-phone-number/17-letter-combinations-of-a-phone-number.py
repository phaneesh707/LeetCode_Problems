class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        alpha =["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        n=len(digits)
        res = []

        def permut(st,buffer,index):
            if(len(buffer)==n):
                ss=""
                res.append(ss.join(buffer))
                
                
            elif(index<len(st)):
                buffer.append(st[index])
                permut(st,buffer,index+1)
                buffer.pop(len(buffer)-1)
                permut(st,buffer,index+1)
        
        new = []
        for i in digits:
            new.append(alpha[int(i)-2])
        hell = ""
        if(n==0):
            pass
        elif(n==1):
            res = list(alpha[int(digits)-2])
        elif(n==2):
            
            for i in new[0]:
                for j in new[1]:
                    hell+=i+j
                    res.append(hell)
                    hell=""
                    
        elif(n==3):
            for i in new[0]:
                for j in new[1]:
                    for k in new[2]:
                        hell+=i+j+k
                        res.append(hell)
                        hell=""
            
        elif(n==4):
            for i in new[0]:
                for j in new[1]:
                    for k in new[2]:
                        for u in new[3]:
                            hell+=i+j+k+u
                            res.append(hell)
                            hell=""
            
                
            
        return res;