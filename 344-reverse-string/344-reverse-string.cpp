class Solution {
public:
    void reverseString(vector<char>& s) {
        auto start=s.begin();
        auto last=s.end();
        last--;
        if(s.size()%2!=0){
            while(start!=last){
                char ch = *start;
                *start= *last;
                *last = ch;
               ++start;
                --last;
            }
        }else{
            if(s.size()==2){
                char h = s[0];
                s[0]=s[1];
                s[1]=h;
            }else{
            
            while(start!=last){
                char ch = *start;
                *start= *last;
                *last = ch;
                ++start;
                --last;
                if((start+1)==last)
                    break;
                }
                char ch = *start;
                *start= *last;
                *last = ch;
            }
        }
        }
    };
