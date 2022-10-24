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
};

void leftView(Node *root, int level, vector<int> &ans){
	if(!root) return;
	if(ans.size() == level) ans.push_back(root->data);
	leftView(root->left, level+1, ans);
	leftView(root->right, level+1, ans);
}

void rightView(Node *root, int level, vector<int> &ans1){
	if(!root) return;
	if(ans1.size() == level) ans1.push_back(root->data);
	rightView(root->right, level+1, ans1);
	rightView(root->left, level+1, ans1);
}

void printTree(vector<int> &ans){
	for(auto it: ans) cout << it << " ";
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
 
	vector<int> ans, ans1;
	leftView(root, 0, ans);
	printTree(ans);
	cout << "\n";
	
	rightView(root, 0, ans1);
	printTree(ans1);
	
	return 0;
}
/* Complexity: TC - O(N), SC - O(H)
 * 
		10
	 2		3
   7   8  12  15
			 14
			
 LeftView : 10 2 7 14
 RightView: 10 3 15 14
*/
