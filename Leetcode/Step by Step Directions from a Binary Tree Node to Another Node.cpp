// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, 
// and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 
//   Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:


// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

## SOLUTION:-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* findLCA(TreeNode* root,int n1,int n2){
    if(root==NULL)
    return NULL ;
    if(root->val==n1 || root->val==n2)
    return root;

    TreeNode* leftAns=findLCA(root->left,n1,n2);
    TreeNode* rightAns=findLCA(root->right,n1,n2);
    if(leftAns!=NULL && rightAns!=NULL)
    return root;
    else if(leftAns==NULL && rightAns!=NULL)
    return rightAns;
    else if(leftAns!=NULL && rightAns==NULL)
    return leftAns;
    else
    return NULL;
}

bool pathfromLCA(TreeNode*LCA,int x,string &s){
    if(LCA==NULL)
    return false;
    if(LCA->val==x)
    return true;

    s.push_back('L');
    if(pathfromLCA(LCA->left,x,s))
    return true;
    s.pop_back();
    s.push_back('R');
    if(pathfromLCA(LCA->right,x,s))
    return true;
    s.pop_back();
return false;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA=findLCA(root,startValue,destValue);
        string s;
        pathfromLCA(LCA,startValue,s);
        string t;
        pathfromLCA(LCA,destValue,t);

        for(auto &i:s){
            i='U';
        }

        string result=s+t;
        return result;  
    }
};
