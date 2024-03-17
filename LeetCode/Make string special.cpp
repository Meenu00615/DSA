#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s){
  vector<string> specials;
  int count = 0, i=0;
  for(int j =0; j<s.length(); j++){
    count += (s[j]=='1')?1:-1;
    if(count==0){
      specials.push_back("1" + makeLargestSpecial(s.substr(i+1, j-i-1))+ "0");
      i=j+1;

    }
  }
  sort(specials.begin(), specials.end(), greater<string>());
  string result;
  for(const string & special : specials){
    result += special;
  }
  return result;
}
int main() {
  string str;
  cin>>str;
  cout<<makeLargestSpecial(str)<<endl;
  return 0;
}