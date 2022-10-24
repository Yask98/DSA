#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void helper(Node *root, vector<int> &result){
	if(root == NULL) return;
	
	helper(root->left, result);
	result.push_back(root->data);
	helper(root->right, result);
}

vector<int> inorderTraversal(Node *root){
	vector<int> result;
	helper(root, result);
	return result;
}

void helper1(Node *root, vector<int> &ans){
	if(!root) return;
	
	helper1(root->left, ans);
	helper1(root->right, ans);
	ans.push_back(root->data);
}

vector<int> postorderTraversal(Node *root){
	vector<int> result;
	helper1(root, result);
	return result;
}

void helper2(Node *root, vector<int> &ans){
	if(!root) return;
	
	ans.push_back(root->data);
	helper2(root->left, ans);
	helper2(root->right, ans);
}

vector<int> preorderTraversal(Node * root){
	vector<int> result;
	helper2(root, result);
	return result;
}

void printAry(vector<int> &ary){
	for(auto it: ary) cout << it << " ";
}

int main(){
	Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
	vector<int> result = inorderTraversal(root);
	printAry(result);
	cout << "\n";
	
	result = postorderTraversal(root);
	printAry(result);
	cout << "\n";
	
	result = preorderTraversal(root);
	printAry(result);
	cout << "\n";
	
	return 0;
}
/* Complexity: TC - O(N), SC - O(N)
 * 
 * 				10
 *           2		3
 * 		  7    8  12  15
 *                   14
 * 
 * Inourder: 	7 2 8 10 12 3 14 15
 * Postorder: 	7 8 2 12 14 15 3 10
 * Preorder:	10 2 7 8 3 12 15 14
 * 
 * 
Solution: 2
* 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
 */
