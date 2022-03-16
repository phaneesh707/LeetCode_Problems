class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int,char>> st;
        int count=0;
        for(auto it=s.begin();it!=s.end();it++){
            // auto pres = st.end()-1;
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
            int count=0;
            for(auto it = st.begin();it!=st.end();it++){
                // auto pres = s.begin()+(*it).first;
                s.erase(s.begin()+(*it).first-count);
                count++;
                
                // cout<<(*it).first<<*(s.begin());
            }
            
            
        }
        
    
    
    
     return s;
    }

       
    
    
    
    
    
    
    
    
    
};