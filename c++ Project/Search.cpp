// #include <iostream>
// #include <vector>
// #include <string>
// #include <filesystem>

// using std::cout; using std::cin;
// using std::endl; using std::string;
// using std::filesystem::directory_iterator;

// int main() {
//     string path = "/";

//     for (const auto & file : directory_iterator(path))
//         cout << file.path() << endl;

//     return EXIT_SUCCESS;
// }

// #include<iostream>
// #include<dirent.h>
// using namespace std;

// struct FolderFile
// {
//     char name[100];
// };
//     FolderFile file[1000];
// int main()
// {
//     struct dirent *d;
//     DIR *dr;
//     dr = opendir(".");

//     char tempFile[261];

//     int i = 0;

//     if(dr!=NULL)
//     {

//         while((d=readdir(dr))!=NULL){
//             if( strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0 && strcmp(d->d_name, ".vscode") != 0 ){
//                 // cout<<d->d_name<<endl;
//                 strcat_s(tempFile,d->d_name);
//                 strcat_s(tempFile,"\n");
//                 cout<<tempFile;
//                 strcpy(file[i].name,tempFile);
//                 i++;
//             }
//         }
//         closedir(dr);
//     }
//     else
//         cout<<"\nError Occurred!";
//     cout<<endl;
//     int j  = i;
//     i=0;

//     cout<<i<<" "<<j<<endl;

//     while (i<j)
//     {
//         cout<<file[i].name<<endl;
//         i++;
//     }
    
//     return 0;
// }

#include<iostream>
#include<dirent.h>

struct FolderFile
{
    char* name[100];
};

using namespace std;

FolderFile fileName[1000];
int numberFile = 0;

void listFile()
{
    
    DIR *pDIR;
    struct dirent *entry;


    char  directoryName[261];
    strcpy_s(directoryName,"ImageLibrary/");
    
    if( pDIR=opendir(directoryName) )
    {
        while(entry = readdir(pDIR))
        {
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
            {
                if (strcmp(entry->d_name,"Thumbs.db")!=0)
                {
                
                    char tempFile[260];
                    strcpy_s(tempFile,"ImageLibrary/");
                    strcat_s(tempFile,entry->d_name);

                     strcpy(fileName[numberFile].name,tempFile);
                    
                     //This will print the output to test the result.
                     //Until now, it works well and prints out the right result    
                    cout<< fileName[numberFile].name << "\n";
                    
                    numberFile= numberFile + 1;        
                }
            
            }
            

        }

                closedir(pDIR);
    }
}