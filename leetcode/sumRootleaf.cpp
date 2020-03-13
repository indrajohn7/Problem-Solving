/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int inorder1(TreeNode* root, vector<int>* v) {
        int lheight, rheight;
        //static int val = root->val;
        
        if (root != NULL) {
            if (root->left == NULL && root->right == NULL)
                v->push_back(root->val);
            lheight = inorder1(root->left, v);
            rheight = inorder1(root->right, v);
            return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
        } else {
            
            return 0;
        }
    }
    
    void inorder(TreeNode** root, vector<int>* vec) 
{ 
    stack<TreeNode*> s; 
    TreeNode* curr = *root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr);
            if (curr->left)
                curr->left->val = curr->val * 10 + curr->left->val;
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
      //  cout << curr->val << " "; 
      //  if (curr->left == curr->right == NULL)
            vec->push_back(curr->val);
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        if (curr->right)
            curr->right->val = curr->val * 10 + curr->right->val;
        curr = curr->right; 
  
    } /* end of while */
} 
    
void get_leaf_node_path(TreeNode* root, vector<int>* v)
{
    
}
    
    int sumRootToLeaf(TreeNode* root) {
        vector<int> vec, vec2;
       // vec.push_back(-1);
        inorder(&root, &vec);
       int depth = inorder1(root, &vec2);
 
        int sum = 0;
        for (int i = 0; i < vec2.size(); i++) {
            int res, count;
            res = count = 0;
            
           // if ((vec[i] - pow(10, depth - 1)) >= 0) {  
                cout << vec2[i] << " ";
                while(vec2[i]){
                    int nemo = vec2[i] % 10;
                    vec2[i] /= 10;
                // cout << vec[i] << " ";
                    
                    res += nemo * pow(2, count);
                    count++;
                }
                sum += res;
           // }
           // cout << endl;
        }
        
        
        return sum;
    }
};
