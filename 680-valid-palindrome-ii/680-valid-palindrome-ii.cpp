class Solution {
public:
    bool isPal(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        string left = s;
        string right = s;
        while(i<=j){
            if(s[i]!=s[j]){
                left.erase(left.begin()+i);
                right.erase(right.begin()+j);
                
                break;
            }
            i++;j--;
        }
        cout<<left<<right;
        return (isPal(left)||isPal(right));
        
    }
};