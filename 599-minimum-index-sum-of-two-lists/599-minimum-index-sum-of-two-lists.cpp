class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> temp;
        for(int i=0;i<list1.size();i++)
            temp[list1[i]] = i;
        vector<string> str; 
        int min = INT_MAX;
        for(int i=0;i<list2.size();i++){
            auto it = temp.find(list2[i]);
            if(it!=temp.end() && it->second+i<=min){
                if(it->second+i!=min && !str.empty()){
                    while(!str.empty())
                        str.pop_back();
                }
                    
                min = it->second+i;
                str.push_back(list2[i]);
            }
        }
        
        return str;
    }
};