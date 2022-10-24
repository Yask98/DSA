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

class Solution{
public:
	int findDiameter(Node *root){
		int diameter = 0;
        height(root, diameter);
        return diameter;
	}
private:
	int height(Node *node, int &diameter) {
		if (!node) return 0;
		int lh = height(node->left, diameter);
		int rh = height(node->right, diameter);
		diameter = max(diameter, lh + rh);
		return 1 + max(lh, rh);
	}
};

int main(){
	Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->left->right->left = newNode(67);
    root->left->right->left->right = newNode(80);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    
    Solution obj;
    int result = obj.findDiameter(root);
    cout << "Diameter of tree is: " << result;
	return 0;
}
/* Complexity: TC - O(N), SC - O(1) + O(H)
				10
		   2		    3
	    7     8  	12      15
		   67   		  14
	          80
Ans: 7
*/
