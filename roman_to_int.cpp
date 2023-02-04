#include<map>
#include<iostream>
#include<string>
class Solution {
public:

    int getIndivalRomanToInt(char ch){
        std::map<char, int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        std::map<char,int>::iterator it = map.begin();
        while(it != map.end()){
            if (it->first == ch){
                return it->second;
            }
            it++;
        }
        return -1;
    }

   
    int romanToInt(std::string s) {
        int totalVal = 0;
        int i = 0;
            if(s.length()>1){
        for( i=0;i<=s.length()-2;i++){
            if(getIndivalRomanToInt(s[i]) >= getIndivalRomanToInt(s[i+1]))
                totalVal += getIndivalRomanToInt(s[i]);
            else
                totalVal -= getIndivalRomanToInt(s[i]);
        }
        }
                totalVal += getIndivalRomanToInt(s[i]);
        return totalVal;
    }
};

int main(){
    Solution s1 ;
    std::cout<<s1.romanToInt("D");
    return 0;
}
