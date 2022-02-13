#include<bits/stdc++.h>
using namespace std;
#include"binarytreenode.h"
binarytreenode<int>* takeinput(){
	int rootdata;
	cout<<"enter data"<<endl;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	binarytreenode<int>* root=new binarytreenode<int>(rootdata);
	binarytreenode<int>* leftchild=takeinput();
	binarytreenode<int>* rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
void printtree(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL){
    cout<<"L:"<<root->left->data;
	}
	if(root->right!=NULL){
      cout<<"R:"<<root->right->data;
	}
	cout<<endl;
	printtree(root->left);
	printtree(root->right);
}
int main(){
	binarytreenode<int>* root=takeinput();
	printtree(root);
	delete root;
	return 0;
}