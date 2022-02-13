#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
void printtree(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL){
    cout<<"L"<<root->left->data;
	}
	if(root->right!=NULL){
      cout<<"R"<<root->right->data;
	}
	cout<<endl;
	printtree(root->left);
	printtree(root->right);
}
int main(){
	binarytreenode<int>* root=new binarytreenode<int>(1);
	binarytreenode<int>* node1=new binarytreenode<int>(2);
	binarytreenode<int>* node2=new binarytreenode<int>(3);
	root->left=node1;
	root->right=node2;
	printtree(root);
	delete root;
	return 0;
}