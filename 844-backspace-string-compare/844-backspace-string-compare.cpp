class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        auto a = s.begin();
        auto b = t.begin();
        while(a!=s.end()){
            if(*a!='#')
                st1.push(*a);
            else if(!st1.empty()) st1.pop(); 
            a++;
        }
        
        while(b!=t.end()){
             if(*b!='#')
                st2.push(*b);
            else if(!st2.empty()) st2.pop();
            b++;
        }
        // cout<<st1.top()<<endl;
        cout<<st1.empty()<<st2.empty();
        while(!st1.empty() && !st2.empty()){
            if(st1.top()!=st2.top())
                return false;
            else 
                st1.pop();st2.pop();
        }

        
        
        if(st1.empty() && st2.empty())
            return true;
        else return false;
        
    }
};