/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node {
    //unsigned long long val;
    string val;
    Node* left;
    Node* right;
    Node(string x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int inorder1(Node* root, vector<string>* v) {
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
    
    void inorder(Node** root, vector<string>* vec) 
{ 
    stack<Node*> s; 
    Node* curr = *root; 
  
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
            if (curr->left) {
                curr->left->val = curr->val + curr->left->val;
                //curr->left->val = curr->val * 10 + curr->left->val;
            }
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
        if (curr->right) {
            curr->right->val = curr->val + curr->right->val;
            //curr->right->val = curr->val * 10 + curr->right->val;
        }
        curr = curr->right; 
  
    } /* end of while */
} 
    
void preorder(Node** t1, TreeNode* t2)
{
    if (t2 != NULL) {
        if (*t1 == NULL) {
            string s = to_string(t2->val);
            (*t1) = new Node(s);
        } /*else {
           (*t1)->val += t2->val;
        }*/
        preorder(&(*t1)->left, t2->left);
        preorder(&(*t1)->right, t2->right);
    } else
        return;
}
    


    int sumRootToLeaf(TreeNode* root) {
        //vector<string> vs;
        struct Node* node;
        preorder(&node, root);
        vector<string> vec, vec2;
       // vec.push_back(-1);
        inorder(&node, &vec);
       int depth = inorder1(node, &vec2);
 
        unsigned long long sum = 0;
        for (int i = 0; i < vec2.size(); i++) {
            unsigned long long res, count;
            res = count = 0;
            
           // if ((vec[i] - pow(10, depth - 1)) >= 0) {  
                cout << vec2[i] << " ";
               // unsigned long long num = stoi(vec2[i]);
                for(string :: reverse_iterator it = vec2[i].rbegin(); it != vec2[i].rend(); ++it){
                    //unsigned long long nemo = num % 10;
                    // num /= 10;
                // cout << vec[i] << " ";
                    char c = *it;
                    int nemo = c - '0';
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
