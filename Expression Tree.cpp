/*
Author: Parag Ghorpade

PROBLEM STATEMENT:
For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using postorder traversal(recursive).
*/


#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

class ino
{


	public:

 	 char data;
	 ino *left ,*right;
	 ino *root=NULL;
	 ino* New(ino* temp)

{
 temp=new ino;
 temp->right=NULL;
 temp->left=NULL;
 return temp;
}


 	void create()
	{
	 	char b[20];
         	int count=0;
         	ino *l,*r,*ro;
		cout<<"Enter the inorder expression: ";
        	cin>>b;
         	stack<ino*> s;
         		for(int i=0;b[i]!='\0';i++)
         		{
        			 ino* temp=New(temp);
         			 temp->data=b[i];
                                 s.push(temp);
         	     		 count++;
				
				if(count==3)
				{
 				 r=s.top();
				 s.pop();
				 ro=s.top();
				 s.pop();
				 l=s.top();
				 s.pop();

				 ro=insert(ro,l,r);
				 s.push(ro);
				 count=1;
				}
			}
	}


	ino* insert(ino *ro,ino *l,ino *r)
	{
		ro->left=l;
		ro->right=r;
		root=ro;
		return ro;
	}


	void preorder(ino *root)
	{
		if(root!=NULL)
			{
				cout<<root->data;
				preorder(root->left);
				preorder(root->right);
			}
	}

	
	void inorder(ino *root)
	{
		if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data;
				inorder(root->right);
			}
	}


	void postorder(ino *root)
	{
		if(root!=NULL)
			{
				postorder(root->left);
				postorder(root->right);
				cout<<root->data; 
			}
	}

};


int main()
{
	ino obj;
	int ch;
	do
	{
		cout<<"\n\n\n========================================\n";
		cout<<"\n*************EXPRESSION TREE*************\n";
		cout<<"\n1.CREATE\n2.POSTORDER\n3.PREORDER\n4.EXIT\n";
		cout<<"\nENTER YOUR CHOICE: ";  
		cout<<"\n========================================\n";
		cin>>ch;

		switch(ch)
		{

		case 1: obj.create();
			break;

		case 2: cout<<"POSTORDER TRAVERSAL OF EXPRESSION  ";
		        obj.inorder(obj.root);
		        cout<<" IS :";
                        obj.postorder(obj.root);
		        break;

		case 3: cout<<"PREORDER TRAVERSAL OF EXPRESSION ";
			obj.inorder(obj.root);
			cout<<" IS :";
			obj.preorder(obj.root);
			break;

		case 4:cout<<"EXIT";
		       break;
		}

	}while(ch!=4);

	return 0;
}

