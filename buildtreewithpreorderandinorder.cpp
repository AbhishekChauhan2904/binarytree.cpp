#include<bits/stdc++.h>
using namespace std;
#include "binarytreenode.h"
binarytreenode<int>* gettree(int *pre,int * in,int preS,int preE,int inS,int inE){
	if(inS>inE){
		return NULL;
			}
		int rootindex=-1;
		for(int i=inS;i<=inE;i++){
			if(in[i]==pre[preS]){
				rootindex=i;
				break;
			}
		}
		int rootData=pre[preS];
		int lpreS=preS+1;
		int llns=inS;
		int line=rootindex-1;
		int lpreE=line-llns+lpreS;
		int rpres=lpreE+1;
		int rpree=preE;
		int rins=rootindex+1;
		int rine=inE;
		binarytreenode<int>* root=new binarytreenode<int>(rootData);
		root->left=gettree(pre,in,lpreS,lpreE,llns,line);
		root->right=gettree(pre,in,rpres,rpree,rins,rine);
		return root;
	
}
binarytreenode<int>* buildtree(int * preorder,int prelength,int* inorder,int inlength){
	int s1,e1,s2,e2;
	s1=0;s2=0;e1=prelength-1;e2=inlength-1;
	return gettree(preorder,inorder,s1,e1,s2,e2);
}
void printtree(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printtree(root->left);
	printtree(root->right);
}
int main(){
	int n;
	cin>>n;
	int preorder[n],inorder[n];
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	for(int i=0;i<n;i++){
		cin>>inorder[i];
	}

cout<<endl;
int prelength=n;
int inlength=n;
binarytreenode<int>* root=buildtree(preorder,prelength,inorder,inlength);
printtree(root);
	return 0;
}