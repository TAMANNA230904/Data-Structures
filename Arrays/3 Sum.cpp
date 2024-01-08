You are given an array ‘ARR’ containing ‘N’ integers.
Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i and their sum is equal to zero.

  //Brute force Approach
Run three loops to find the 1st 2nd and 3rd element if (sum=0) store them in a vector ,sort the vector to avoid duplicate triplets and insert them in a set.
Now create a list of vector and store every element in the set into the list.
T.C.=O(n^3 log(m)), m= no. of triplets
  S.C.=2*O(m)

//Second Approch 
T.C.=O(n^2 log(k)), k=size of temp set 
 S.C.=2*O(m)
  #include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> temp;
        for(int j=i+1;j<n;j++){
            int x=-(arr[i]+arr[j]);
            if(temp.find(x)!=temp.end()){
                vector<int> v={arr[i],arr[j],x};
                sort(v.begin(),v.end()); 
                st.insert(v); 
            }
            temp.insert(arr[j]);
        }
    }
   vector<vector<int>> ans(st.begin(),st.end()); 
   return ans;
}


#Optimal Approach
T.C.=O(n^2 )+O(nlogn)
  S.C.=O(k),k=no. of triplets

#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum==0){
             vector<int> temp={arr[i],arr[j],arr[k]};
             ans.push_back(temp);
             j++;
             k--;
             while(arr[j]==arr[j-1] && j<k)
             j++;
             while(arr[k]==arr[k+1] && j<k)
             k--;
            }
            else if(sum<0){
             j++;
            }
            else{
             k--;
            }
        }
    }
 
   return ans;
}

