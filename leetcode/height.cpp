#include<bits/stdc++.h>

using namespace std;
#define TRUE 1
#define FALSE 0

class btreenode{
        public:
        btreenode* lchild;
        int data;
        btreenode* rchild;
};

void insert(btreenode** tr,int num)
{
        if(*tr==NULL)
        {
                *tr=new btreenode;
                (*tr)->lchild=NULL;
                (*tr)->rchild=NULL;
                (*tr)->data=num;
                return;
        }
        else{
			if(((*tr)->data) < num)
				insert(&(*tr)->rchild,num);
			else
				insert(&(*tr)->lchild,num);

        }
}

void search(btreenode** bt,int num,btreenode** par,btreenode**x,int *found)
{
        struct btreenode* q;
        q=*bt;
        *found=FALSE;
        *par=NULL;
        while(q!=NULL){
                if(q->data==num){
                        *found=TRUE;
                        *x=q;
                        return;
                }
                if(q->data>num){
                        *par=q;
                        q=q->lchild;
                }
                else{
                        *par=q;
                        q=q->rchild;
                }
        }
}


void bdelete(btreenode** bt, int num)
{
        int *found;
        btreenode *parent,*x,*xsucc,*temp;
        if(*bt==NULL)
        {
                cout<<"Tree is Empty:\n";
                return;
        }
        parent=x=NULL;
		btreenode **par,**x1;
		temp=x;
		par=&parent;
		x1=&x;
        search(bt,num,par,x1,found);
		*bt=temp;
        if(*found==FALSE)
        {
                cout<<"Data not found in BTREE:\n";
                return;
        }
		parent=*par;
		x=*x1;
        if((x)->lchild!=NULL && (x)->rchild!=NULL){
                parent=x;
                xsucc=(x)->rchild;
                while(xsucc->lchild!=NULL){
                        parent=xsucc;
                        xsucc=xsucc->lchild;
                }
                (x)->data=xsucc->data;
                (x)=xsucc;
				delete(xsucc);
        }
        else if((x)->lchild==NULL && (x)->rchild!=NULL){
                if((parent)->rchild==(x))
                        (parent)->rchild=(x)->rchild;
                else
                        (parent)->lchild=(x)->rchild;
                delete(x);
                return;
        }
        else if((x)->lchild!=NULL && (x)->rchild==NULL){
                if((parent)->rchild==(x))
                        (parent)->rchild=(x)->lchild;
                else
                        (parent)->lchild=(x)->lchild;
                delete(x);
                return;
        }
        else if((x)->lchild==NULL && (x)->rchild==NULL){
                if((parent)->rchild==x)
                        (parent)->rchild=NULL;
                else
                        (parent)->lchild=NULL;
                delete(x);
                return;
        }
}


void inorder(btreenode* bt)
{
        if(bt!=NULL){
                inorder(bt->lchild);
                cout<<bt->data<<"\t";
                inorder(bt->rchild);
        }
        else
			return;
}

void preorder(btreenode* bt)
{
        if(bt!=NULL){
                cout<<bt->data<<"\t";
                preorder(bt->lchild);
                preorder(bt->rchild);
        }
        else
			return;
}

void postorder(btreenode* bt)
{
        if(bt!=NULL){
                postorder(bt->lchild);
                postorder(bt->rchild);
                cout<<bt->data<<"\t";
        }       
		else
			return;
}

int max_height(btreenode* bt)
{
	if(bt==NULL)
		return 0;

	else{
		int lheight=max_height(bt->lchild);
		int rheight=max_height(bt->rchild);

		if(lheight > rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}


void print_level_tree(btreenode* bt,int h)
{
	if(bt==NULL)
		return;
	
	if(h==1)
		cout<<bt->data<<"\t";
	else{
		print_level_tree(bt->lchild,h-1);
		print_level_tree(bt->rchild,h-1);
	}
	
}

int main()
{
        btreenode *bt,**bt_h;
        int req,i=1,num,ch,height;
        bt=NULL;
		bt_h=&bt;
        fflush(stdin);
        while(1)
        {
                cout<<" \nBINARY TREE OPERATIONS:\n"<<" 1. INSERTION:\n 2. DELETION:\n 3. TRAVERSAL:\n 4.Height Print:\n";
                cout<<"\nEnter the choice of operation:\n";
                cin>>ch;
                switch(ch)
                {
                        case 1: cout<<"\nEnter the value of the tree node to be inserted:\t";
                                        cin>>num;
                                        insert(bt_h,num);
                                        break;
                        case 2: cout<<"\nEnter the value of the tree node to be deleted:\t";
                                        cin>>num;
                                        bdelete(bt_h,num);
                                        break;
                        case 3: cout<<"\n1.INORDER TRAVERSAL:\n 2. PREORDER TRAVERSAL:\n 3.POSTORDER TRAVERSAL:\n ENTER your choice :";
                                        cin>>num;
                                        if(num==1)
                                                        inorder(bt);
                                        else if(num==2)
                                                        preorder(bt);
                                        else if(num==3)
                                                        postorder(bt);
                                        break;
						case 4: cout<<"Height Traversal Print of the Tree:\n";
								height=max_height(bt);
								for(int i=1;i<=height;i++){
									cout<<i<<":: ";
									print_level_tree(bt,i);
									cout<<endl;
								}
								break;
                        default:
							break;
                }
        }
        return 0;
}

int inorder(TreeNode* root, vector<int>* v) {
        int lheight, rheight;
        
        if (root != NULL) {
            v->push_back(root->val);
            lheight = inorder(root->left, v);
            rheight = inorder(root->right, v);
            return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
        } else
            return 0;    
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<int> vec;
        int depth = inorder(root, &vec);
        typedef vector<int> v;
        vector<v> vvec;
        v temp;
        temp.push_back(vec[0]);
        int sum = 0;
        for (int i = 0; i < depth; i++)
            sum += pow(2, i);
        
        for (int i = 0; i < (pow(2, depth - 1)); i++)
            vvec.push_back(temp);
        
       // for (int i = 0; i < depth; i++) {
        int level, start;
        level = 1;
        start = 1;
       // cout << depth <<endl;
       // for (int i = 0; i < vec.size(); i++)
       //     cout << vec[i] << endl;
       // }
        
        for (int i = 1; i < depth; i++) {
            int count = 0;
            int idx = i;
            while (count < pow(2, i)) {
                count++;
                if (count <= pow(2, i) / 2) {
                    for (int k = 0; k < vvec.size() / 2; k++)
                        vvec[k].push_back(vec[idx]);
                        if (i == depth -1)
                            idx++;
                    idx++;
                } else {
                    idx = pow(2, depth - 1) + i - 1;
                    for (int k = vvec.size() / 2; k < vvec.size(); k++)
                        vvec[k].push_back(vec[idx]);
                        if (i == depth - 1)
                            idx++;
                    idx++;
                }
            }
        }
        
        for (int i = 0; i < vvec.size(); i++) {
            for (int j = 0; j < vvec[i].size(); j++) {
                cout << vvec[i][j] << " ";
            }
            cout << endl;
        }
        
        return 0;
    }

