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
int heightofbinarytree(binarytreenode<int>* root){
	int ans=0;
	if(root==NULL){
		return ans;
	}
	int ans1=heightofbinarytree(root->left);
	int ans2=heightofbinarytree(root->right);
	if(ans1>=ans2){
		ans=1+ans1;
	}
   else{
   	ans=1+ans2;
   }
return ans;
}
int main(){
	binarytreenode<int>* root=takeinputlevelwise();
	int ans=heightofbinarytree(root);
	cout<<ans<<endl;
	return 0;
}