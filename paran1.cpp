#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
	char s[10],x[10],j=0;
	int top=-1;
void push(char ch)
{
	top=top+1;
	x[top]=ch;
//	cout<<"pushed"<<x[top];
}
char pop()
{
	char ch=x[top];
	top=top-1;
	//cout<<"\n popped"<<ch;
	return ch;
}
void check(char a[10],int l)
{
	for(int i=0;i<=l;i++)
	{
		if(a[i]==')' || a[i]=='}' || a[i]==']')
			{
				char b=pop();
				if(b=='(')
				{
					if(a[i]!=')')
					 {
					 	cout<<"not (";
					 	return;
					 }
				}
				if(b=='{')
				{
					if(a[i]!='}')
					 {
					 	cout<<"not {";
					 	return;
					 }
				}
				if(b=='[')
				{
					if(a[i]!=']')
					 {
					 	cout<<"not [";
					 	return;
					 }
				}
			}
		else
		 push(a[i]);
	}
	cout<<"matched";
	
}
int main()
{
	cout<<"enter expression \n";
	cin>>s;
	int l=strlen(s);
	check(s,l);
}
