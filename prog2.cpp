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

        bool search()
        {
            int flag = 0;
            char filename[20];
            cout<<"Enter the filename\n";
            cin>>filename;

            fstream file;
            file.open(filename,ios::in);

            char key[100];
            cout<<"Enter the keyword\n";
            cin>>key;
            char extra[45];

            while(!file.eof())
            {
                file.getline(name,20,'|'); 
                file.getline(sem,10,'|');
                file.getline(branch,20,'|');
                file.getline(extra,45,'\n');

                if (strcmp(key,name) == 0)
                {
                    cout<<name<<" | "<<sem<<" | "<<branch<<" | "<<extra<<endl;
                    flag  = 1;
                }
            }
            if (flag == 1)
            {
                return true;
            }
            
            return false;
        }

        void modify()
        {
            char filename[20];
            cout<<"Enter the filename\n";
            cin>>filename;

            fstream file;
            file.open(filename,ios::in);


            char key[100];
            cout<<"Enter the keyword to change\n";
            cin>>key;
            char extra[45];

            while(!file.eof())
            {
                file.getline(name,20,'|'); 
                file.getline(sem,10,'|');
                file.getline(branch,20,'|');
                file.getline(extra,45,'\n');

                if (strcmp(key,name) == 0)
                {
                    cout<<name<<" | "<<sem<<" | "<<branch<<" | "<<extra<<endl;
                    return;
                }
            }

        }
    
};

int main()
{
    fstream ofile,ifile;
    string filename;
    Student st;
    int exp;

    do
    {
        
        cout<<"Enter your choice\n1.Pack Student Object\n2.Unpack Student Object\n3.Search a Keyword\n4.Modify the data\n0 to Exit\n";
        cin>>exp;

        if (exp == 0)
        {
            cout<<"\n**********************************************\n";
            cout<<"Exiting the program\n";
            cout<<"**********************************************\n";
            break;
        }
        
            switch (exp)
        {
        case 1:
            cout<<"Enter the filename\n";
            cin>>filename;
            cout<<"Enter the number of Student you want to enter\n";
            int num;
            cin>>num;
            cout<<"\n";

            ofile.open(filename,ios::out | ios::app);

            for (int i = 0; i < num; i++)
            {
                cout<<"\n**********************************************\n";
                st.pack(ofile);
                cout<<"**********************************************\n\n";
            }

            ofile.close();
            break;

        case 2:
            cout<<"Enter the filename\n";
            cin>>filename;

            ifile.open(filename,ios::in);
            st.unpack(ifile);
            break;
            ifile.close();


         case 3:

            
            if (st.search())
            {
                cout<<"**********************************************\n";
                cout<<"Keyword found!!\n";
                cout<<"**********************************************\n\n";
            }
            else
            {
                cout<<"**********************************************\n";
                cout<<"Keyword not found!!\n";
                cout<<"**********************************************\n\n";
            }
            
            break;
            ifile.close();

        case 4:

            st.modify();
            break;

        default:
                cout<<"Invalid choice";
            break;
        }
    }while(1);
    
   
    return 0;
}
