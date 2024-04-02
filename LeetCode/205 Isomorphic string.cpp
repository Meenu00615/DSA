class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mappingS[256] = {0};
        int mappingT[256] = {0};
        int length = s.size();
        for(int i = 0; i<lengtha; ++i){
            char charS = s[i];
            char charT = t[i];
            if(mappingS[charS]!=mappingT[charT]){
                 return false;
            }
            mappingS[charS] = mappingT[charT] = i+1;
        }
        return true;
    }
};
