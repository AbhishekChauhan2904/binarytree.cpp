#include<bits/stdc++.h>
using namespace std;
#include "binarytreenode.h"
binarytreenode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
     return NULL;
	}
	binarytreenode<int>* root=new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0){
	binarytreenode<int>* front=pendingnodes.front();
	pendingnodes.pop();
    int leftchilddata;
    cin>>leftchilddata;
    if(leftchilddata!=-1){
    	binarytreenode<int>* child= new binarytreenode<int>(leftchilddata);
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

bool findnode(binarytreenode<int>* root, int x) {
if(root->data==x){
	return true;
}
bool ans=false;
if(root->left){
	bool leftans=findnode(root->left,x);
	if(leftans){
		ans=leftans;
	}
}
if(root->right){
	bool rightans=findnode(root->right,x);
	if(rightans){
		ans=rightans;
	}
}
return ans;
}
int main(){
binarytreenode<int>* root=takeinputlevelwise();
int x;
cin>>x;
bool ans=findnode(root,x);
if(ans==0){
	cout<<"false"<<endl;
}
else{
	cout<<"true"<<endl;
}
delete root;
	return 0;
}