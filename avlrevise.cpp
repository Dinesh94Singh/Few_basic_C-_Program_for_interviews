#include<iostream>
using namespace std;
typedef struct node
{
	struct node *left,*right;
	int ht;
}node;
int ht;
node *bt,*p,*q,*avl;
node* singleleftrot(node* p)
{
	node* q;
	q=p->right;
	p->right=q->left;
	q->left=p;
	return q;
}
node* singlerightrot(node* p)
{
	node* q;
	q=p->left;
	p->left=q->right;
	q->right=p;
	return q;
}
node* rightleftrot(node* p)
{
	node* q;
	q=p->right;
	p->right=singlerightrot(p);
	return singleleftrot(p);
}
node* leftrightrot(node* p)
{
	node* q;
	q=p->left;
	p->left=singleleftrot(p);
	return singlerightrot(p);
}

int height1(node* p)
{
	int height=0;
	if(p!=NULL)
	{
		int x=height1(p->left);
		int y=height1(p->right);
		 int max= x>y ? x :y ;
		height=max+1;
	}
	return height;
}
int get_diff(node* p)
{
	int x=height1(p->left);
	int y=height1(p->right);
	 int balfactor=x-y;
	return balfactor;
}
node* balancing(node* p)
{
	int balfactor=get_diff(p);
	if(balfactor==-2)
	{
		if(get_diff(p->right)==-1)
		 p=singleleftrot(p);
		else
		 p=rightleftrot(p);
	}
	else
	if(balfactor==2)
	{
		if(get_diff(p->left)==1)
		 p=singlerightrot(p);
		else
		 p=leftrightrot(p);
	}
	return p;
}
node* insert(node* p,int n)
{
	if(p==NULL)
	{
		p=new node;
		p->ht=n;
		p->left=p->right=NULL;
	}
	else
	 if(n>p->ht)
	 {
	 	p->right=insert(p->right,n);
	 	p=balancing(p);
	 }
	 else
	 {
	 	p->left=insert(p->left,n);
	 	p=balancing(p);
	 }
	 return p;
}
void inorder(node* p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<"  "<<p->ht;
		inorder(p->right);
	}
}
void create()
{
	cout<<"enter ht 0 to exit";
	while(1)
	{
		cin>>ht;
		if(ht==0)
		 break;
		else
		avl=insert(avl,ht);
	}
}

int main()
{
	create();
	inorder(avl);
}
