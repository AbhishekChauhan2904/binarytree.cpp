#include <bits/stdc++.h>
using namespace std;
#include "binarytreenode.h"
binarytreenode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"enter data"<<endl;
	cin>>rootdata;
	if(rootdata == -1){
		return NULL;
	}
	binarytreenode<int>* root=new binarytreenode<int>(rootdata);
queue<binarytreenode<int>*> pendingnodes;
pendingnodes.push(root);
while(pendingnodes.size()  != 0){
	binarytreenode<int>* front=pendingnodes.front();
	pendingnodes.pop();
	int leftchilddata;
	cout<<"enter left child of "<<front->data<<endl;
	cin>>leftchilddata;
	if(leftchilddata !=  -1){
		binarytreenode<int>* child=new binarytreenode<int>(leftchilddata);
		front->left=child;
		pendingnodes.push(child);
	}
	int rightchilddata;
	cout<<"enter right child of "<<front->data<<endl;
	cin>>rightchilddata;
	if(rightchilddata != -1){
		binarytreenode<int>* child=new binarytreenode<int>(rightchilddata);
		front->right=child;
		pendingnodes.push(child);
	}
}
return root;
}
void printtree(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
		binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left){
         pendingnodes.push(front->left);
         cout<<"L:"<<front->left->data;
		}
		else{
			cout<<"L:-1";
		}
		cout<<",";
		if(front->right){
			pendingnodes.push(front->right);
			   cout<<"R:"<<front->right->data<<endl;
		}
		else{
			cout<<"R:-1"<<endl;
		}
		
		
	}
}
int main(){
	binarytreenode<int>* root=takeinputlevelwise();
	printtree(root);
	return 0;
}