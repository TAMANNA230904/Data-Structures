You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.



class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int numberof1=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='1')
            numberof1++;
        }
    
    vector<char> str(len,'0');
    
      if(str[len-1]!='1')
      {str[len-1]='1';
      numberof1--;
      }

      
          for(int i=0;i<len-1;i++){
              if(numberof1>0)
              {
              str[i]='1';
              numberof1--;
              }
              
          }
      
    
    string ans="";
    for(int i=0;i<len;i++){
    ans.push_back(str[i]);
    }
    return ans;
    }
};
