#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student
{
private:
    char name[20], sem[10], branch[10], buff[45]; 
public:
    void read()
    {
        cout<<"Enter the Name of the Student\n";
        cin>>name;
        cout<<"Enter the Sem of the Student\n";
        cin>>sem;
        cout<<"Enter the Branch of the Student\n";
        cin>>branch;
        

    }

    void pack(fstream &ofile)
    {
        read();
        strcpy(buff,"");
        strcat(buff,name);
        strcat(buff,"|");
        strcat(buff,sem);
        strcat(buff,"|");
        strcat(buff,branch);
        strcat(buff,"|");
        
        while (strlen(buff) < 45)
        {
            strcat(buff,"!");
        }

        strcat(buff,"\n");

        ofile.write(buff,strlen(buff));
    }
    
    void unpack(fstream &ifile)
    {
        char extra[45];

        while(!ifile.eof())
        {
            ifile.getline(name,20,'|'); 
            ifile.getline(sem,10,'|');
            ifile.getline(branch,20,'|');  
            ifile.getline(extra,45,'\n');

            cout<<name<<" | "<<sem<<" | "<<branch<<" | "<<extra<<endl;

        }
        
    }
    
};

int main()
{
    fstream ofile,ifile;
    string filename;
    Student st;

    cout<<"Enter the filename\n";
    cin>>filename;

    

    

    
    ofile.close();
    


    switch (exp)
    {
    case 1:
        cout<<"Enter the filename\n";
        cin>>filename;
        cout<<"Enter the number of Student you want to enter\n";
        int num;
        cout<<"\n";

        ofile.open(filename,ios::out | ios::app);

        for (int i = 0; i < num; i++)
        {
            cout<<"**********************************************\n";
            st.pack(ofile);
            cout<<"**********************************************\n\n";
        }

        cin>>num;
        break;

    case 2:
        cout<<"Enter the filename\n";
        cin>>filename;

        ifile.open(filename,ios::in);
        st.unpack(ifile);
        break;
        
    default:
        break;
    }
    
    ifile.close();

    return 0;
}

