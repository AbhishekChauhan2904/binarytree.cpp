#include<bits/stdc++.h>
using namespace std;
#include "binarytreenode.h"
binarytreenode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	binarytreenode<int>* root= new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cin>>leftchilddata;
		if(leftchilddata!=-1){
			binarytreenode<int>* child=new binarytreenode<int>(leftchilddata);
			front->left=child;
			pendingnodes.push(child);
		}
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>* child=new binarytreenode<int>(rightchilddata);
			front->right=child;
			pendingnodes.push(child);
		}
	}
	return root;
}
void inorder(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	inorder(root->left) ;
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	binarytreenode<int>* root=takeinputlevelwise();
	inorder(root);
	delete root;
	return 0;
}