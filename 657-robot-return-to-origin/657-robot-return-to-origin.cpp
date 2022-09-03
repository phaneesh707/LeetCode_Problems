class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> m;
        for(auto it:moves)
            m[it]++;
        return (m['U']-m['D']==0 && m['R']-m['L'] == 0);
    }
};