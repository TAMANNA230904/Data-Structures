You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=m-1;
        int col_index=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                col_index=mid;
                break;
            }
            else if(target<matrix[mid][0])
            r=mid-1;
            else
            l=mid+1;
        }

       if(col_index==-1)
       return false;

       l=0;
       r=n-1;
       while(l<=r){
       int mid=l+(r-l)/2;
       if(matrix[col_index][mid]==target)
       return true;
       else if(matrix[col_index][mid]>target)
       r=mid-1;
       else
       l=mid+1;
       }
       return false;
    }
};
