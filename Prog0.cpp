#include<fstream>
#include<iostream>

using namespace std;

int main()
{
    fstream file;
    char ch, input[10];

    cout<<"Enter the file name\n";
    cin>>input;

    file.open(input,ios::in);
    file.unsetf(ios::skipws);

    while(1)
    {
        file>>ch;

        if (file.fail())
        {
            break;
        }
        
        cout<<ch;
    }
}