class Solution {
public:
    void permut(int voelSize,int index,int start,int& count,int n){
        if(index==n){
            count++;
            return;  
        }
        
        for(int i=start;i<voelSize;i++)
            permut(voelSize,index+1,i,count,n);     
    }
    
    
    int countVowelStrings(int n) {
        int count = 0;
        permut(5,0,0,count,n);
        return count;
    }
};