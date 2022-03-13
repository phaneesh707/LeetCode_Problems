class Solution {
public:
    bool isValid(string s) {
        char ch;
        bool flag;
        stack<char> st;
        if(s.length()%2)
            return false;
        for(auto it=s.begin();it!=s.end();it++){
            if(*it=='(' || *it=='{' || *it=='[')
                st.push(*it);
            else if(!st.empty()){
                
                if(st.top()=='(' && *it==')' || st.top()=='[' && *it==']' || st.top()=='{' && *it=='}')
                    st.pop();
                else
                    return false;
                
            
            }else{
                return false;
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
        
    }
};