class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //a stack to store the index and the bracket 
        vector<pair<int,char>> st;
        int count=0;
        //storing all the invalid brackets and its index
        for(auto it=s.begin();it!=s.end();it++){
            if(*it=='('){
                st.push_back(make_pair(count,*it));
            }
            else if(*it==')' && !st.empty() && (*(st.end()-1)).second =='('){
               st.pop_back();
            } 
            else if(*it==')'){
                st.push_back(make_pair(count,*it)); 
            }
            count++;
        }
        if(st.empty())
            return s;
        else if(s.length()==st.size())
            return "";
        else{
            //removing the brackets 
            count=0;
            for(auto it = st.begin();it!=st.end();it++){
                s.erase(s.begin()+(*it).first-count);
                count++;
            }
            
            
        }
        
    
    
    
     return s;
    }

       
    
    
    
    
    
    
    
    
    
};