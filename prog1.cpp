#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

class prog1
{
    private: char a[10][20], input[10],output[10];
    public: void std_io();
    public: void file_io();
    public: void file_io2();
};

void prog1::std_io()
{
    int n;
    string s1;

    cout<<"Enter the no of names\n";
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cout<<"Enter the name\n";
        cin>>a[i];
    }

    for(int i = 0; i<n; i++)
    {
        s1 = a[i];
        reverse(s1.begin(),s1.end());
        cout<<s1<<"\n";
    }

}

void prog1::file_io()
{
    string str;
    cout<<"Enter the File name\n";
    cin>>input;

    fstream file;

    file.open(input,ios::in);
    file.unsetf(ios::skipws);

    while(1)
    {
        getline(file,str);
        reverse(str.begin(),str.end());
        cout<<str<<"\n";

        if (file.fail())
        {
            break;
        }
    }
};

void prog1::file_io2()
{
    fstream fp1,fp2;
    string str;

    cout<<"Enter the input filename\n";
    cin>>input;
    cout<<"Enter the output filename\n";
    cin>>output;

    fp1.open(input,ios::in);
    fp2.open(output,ios::out);

    while(1)
    {
        if(fp1.fail())
        {
            break;
        }
        getline(fp1,str);
        reverse(str.begin(),str.end());
        fp2<<str;
    }

};

int main()
{
    prog1 x;
    int ch;
    do
    {
        
    cout<<"Enter your choice:\n1)Reverse the input text.\n2)Reverse the text from a file.\n3)Reverse the text from one file and store it in another.\n(0 to break)\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
        x.std_io();
        break;
    case 2:
        x.file_io();
        break;
    case 3:
        x.file_io2();
        break; 
    case 0:
        break;       
    default:
        cout<<"Invalid Choice!!!\n";
        break;
    }
    } while (ch!=0);
    
}