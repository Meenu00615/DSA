class Solution {
public:
    string minRemoveToMakeValid(string s) {
       string tempStack;
       int openCount = 0;
       for(char& c: s) {
           if(c == ')' && openCount ==0) continue;
           if(c == '(') {
              openCount++;
           }else if(c == ')') {
              openCount--;
           }
           tempStack.push_back(c);
       }
    string result;
    openCount = 0;
    while(!tempStack.empty()){
    char c = tempStack.back();
    tempStack.pop_back();

    if(c == '(' && openCount == 0) continue;
    if(c == ')') {
    openCount++;
    }
    else if(c== '(') {
    openCount--;
    }
    result.push_back(c);
    }
    std::reverse(result.begin(), result.end());
    return result;
    }
    };
       
