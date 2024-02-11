The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
  Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

  class Solution {
public:
void mapping(string s,vector<pair<char,int>> &v){
    int size=s.size();

    for(int i=0;i<size;i++){
     char ch=s[i];
     int cnt=0;
     int j=i;
    while( j<size && s[j]==ch ){
        cnt++;
        j++;
    }
    v.push_back({ch,cnt});
    i=j-1;

    }
}

// string helper(vector<pair<char,int>> v){
//     string ans="";
//     for(auto i:v){
//         ans+=i.first;
//         ans+=to_string(i.second);
//     }

//     return ans;
// }
    string countAndSay(int n) {
        if(n==1)
        return "1";

        string temp="1";
        for(int i=2;i<=n;i++){
            vector<pair<char,int>> v;
            mapping(temp,v);
            temp="";
            for(auto pair:v)
            temp+=to_string(pair.second)+pair.first;
        }
        return temp;
    }
};
