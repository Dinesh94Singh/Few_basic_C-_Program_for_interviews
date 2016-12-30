#include<iostream>
#include<string.h>
using namespace std;
char x[10][10];
int m=0;
void permute(char a[],int i,int l)
{
    int j;
    if(i==l)
    {
        cout<<a<<"\n";
        for(int i=0;i<l;i++)
        {
            x[m][i]=a[i];
        }
     m++;
    }
    else
    {
        for(j=i;j<=l-1;j++)
        {
            char temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            
            permute(a,i+1,l);
            
            char temp1=a[i];
            a[i]=a[j];
            a[j]=temp1;
            
        }
    }
}
void display()
{   cout<<"\n in an array \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<x[i][j];
        }
        cout<<"\n";
    }

}

int init=-1;
void checkpos(int l)
{
    char e[]="abcdaba";
    int c=0;
    while(1)
    {
        char d[10];
        for(int p=0;p<l;p++)
        {
            d[p]=e[c+p];
            if(d[p]=='\0')
                return;
        }
        c=c+1;
        /*for(int g=0;g<strlen(d)-1;g++)
            cout<<d[g]<<"\t";*/
           for(int i=0;i<m;i++)
            {   //cout<<i;
               // int r=0;
                int flag=0;
                int k=0;
                int j;
                    for(j=0;j<l;j++)
                    {
                        //cout<<j;
                        //cout<<"COMPARING "<<x[i][j]<<" AND  "<<d[k]<<"\n";
                        //r=x[i][j] ^ d[k] ^ r;
                        if(d[k]==x[i][j])
                        {
                            flag=0;
                        }
                        else
                        {
                            flag=1;
                            break;
                        }
                        k++;
            
                    }
                if(flag==0)
                {
                    //cout<<"AN ANAGRAM \n";
                    cout<<"AT POSTIONS "<<c-1<<endl;
                }
                else
                {
                    //cout<<"fuck u \n";
                   // init++;
                }
        }
    }
}
int main()
{
    char a[10];
    cout<<"enter \n";
    cin>>a;
    int l=strlen(a);
    permute(a,0,l);
    display();
    cout<<"\n";
    checkpos(l);
}

