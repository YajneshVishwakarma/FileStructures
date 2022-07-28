#include <fstream>
#include <iostream>
#include <string.h> 
using namespace std;
void writeList()
{
 fstream f1, f2;
 int m;
 char name[10];
 f1.open("file1.txt", ios::out);
 f2.open("file2.txt", ios::out);
 cout << "Enter number of names for file1 : " << endl;
 cin >> m;
 for (int i = 0; i < m; i++)
 {
 cin >> name;
 f1 << name;
 f1 << "\n";
 }
 cout << "Enter number of names for file2 : " << endl;
 cin >> m;
 for (int j = 0; j < m; j++)
 {
 cin >> name;
 f2 << name;
 f2 << "\n";
 } 
  f1.close();
 f2.close();
}
int main()
{
 char list1[10][10], list2[10][10];
 fstream f1, f2, f3;
 int i = 0, j = 0, m = 0, n = 0;
 writeList();
 f1.open("file1.txt", ios::in);
 f2.open("file2.txt", ios::in);
 f3.open("common.txt", ios::out);
 while (!f1.eof())
 {
 f1.getline(list1[i], 10, '\n');
 i++;
 m++;
 }
 while (!f2.eof())
 {
 f2.getline(list2[j], 10, '\n');
 j++;
 n++;
 } 
   i = 0;
 j = 0;
 while (i < m && j < n)
 {
 if (strcmp(list1[i], list2[j]) == 0)
 {
 cout << "The common name is : " << list1[i] << endl;
 f3 << list1[i];
 i++;
 j++;
 }
 else if (strcmp(list1[i], list2[j]) < 0) // returns negative if
not equal
 i++;
 else
 j++;
 }
 f1.close();
 f2.close();
 f3.close();
 return 0;
}
