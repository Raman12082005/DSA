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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        
        if(root == NULL) return newNode;

        TreeNode* currNode = root;
        while(currNode != NULL){
            if(currNode->val > val){
                if(currNode->left != NULL){
                    currNode = currNode->left;
                }
                else{
                    currNode->left = newNode;
                    break;
                }
            }
            else{
                if(currNode->right != NULL){
                    currNode = currNode->right;
                }
                else{
                    currNode->right = newNode;
                    break;
                }
            }
        }
        return root;
    }
};