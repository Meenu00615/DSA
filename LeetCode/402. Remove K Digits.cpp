class Solution {
public: 
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        if(k==n) return "0";
        for(int i =0; i<n; i++){
            while(ans.size()>0 &&k>0 && ans.back()>num[i]){
                ans.pop_back();
                k--;
            }
            if(ans.size()>0 || num[i]!='0'){
                ans.push_back(num[i]);
            }
        } 
        while(k>0 && ans.size()>0){
            k--;
            ans.pop_back();
        }
        return ans=="" ? "0" : ans;
    }

};
