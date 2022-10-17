#include <iostream>
#include <fstream>
using namespace std;
fstream file, file1;
struct student
{
   string Fname, Lname;
   int roll;
   string house;
   int marks;
} s1;
void add()
{
   cout << "Enter Roll Number:";
   cin >> s1.roll;
   cout << "Enter Student's First Name:";
   cin >> s1.Fname;
   cout << "Enter Student's Last Name:";
   cin >> s1.Lname;
   cout << "Enter House Name:";
   cin >> s1.house;
   cout << "Enter Marks:";
   cin >> s1.marks;
   file.open("student.txt", ios::app | ios::out);
   file << s1.roll << " " << s1.Fname << " " << s1.Lname << " " << s1.house << " " << s1.marks << endl;
   file.close();
}
void modify(int p)
{
   int k = 0;
   file.open("student.txt", ios::in);
   file1.open("StudentRecord.txt", ios::app | ios::out);
   if (!file)
   {
      cout << "Error:Nothing to display!" << endl;
      file.close();
   }
   else
   {
      file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      while (!file.eof())
      {
         if (s1.roll != p)
         {
            file1 << s1.roll << " " << s1.Fname << " " << s1.Lname << " " << s1.house << " " << s1.marks << endl;
         }
         else
         {
            k += 1;
            cout << "Enter Roll Number:";
            cin >> s1.roll;
            cout << "Enter Student's First Name:";
            cin >> s1.Fname;
            cout << "Enter Student's Last Name:";
            cin >> s1.Lname;
            cout << "Enter House Name:";
            cin >> s1.house;
            cout << "Enter Marks:";
            cin >> s1.marks;
            file1 << s1.roll << " " << s1.Fname << " " << s1.Lname << " " << s1.house << " " << s1.marks << endl;
         }
         file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      }
   }
   file1.close();
   file.close();
   remove("student.txt");
   rename("StudentRecord.txt","student.txt");
   if(k==0)
   {
      cout<<"Roll no. not found."<<endl;
   }
   else
   {
      cout<<"Roll No. "<<p<<" student record has been modified."<<endl;
   }
}
void delete_std(int q)
{
   int z = 0;
   file.open("student.txt", ios::in);
   file1.open("StudentRecord.txt", ios::app | ios::out);
   if (!file)
   {
      cout << "Error:Nothing to display!" << endl;
      file.close();
   }
   else
   {
      file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      while (!file.eof())
      {
         if (s1.roll != q)
         {
            file1 << s1.roll << " " << s1.Fname << " " << s1.Lname << " " << s1.house << " " << s1.marks << endl;
         }
         else
         {
            z+=1;
            cout<<"Roll No. "<<q<<" student record has been deleted."<<endl;
         }
         file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      }
   }
   file1.close();
   file.close();
   remove("student.txt");
   rename("StudentRecord.txt","student.txt");
   if(z==0)
   {
      cout<<"Roll no. not found."<<endl;
   }
}
void display()
{
   int j = 1;
   file.open("student.txt", ios::in);
   if (!file)
   {
      cout << "Error:Nothing to display!";
      file.close();
   }
   else
   {
      file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      while (!file.eof())
      {
         cout << "Student No.:" << j++ << endl;
         cout << "Student Roll No.:" << s1.roll << endl;
         cout << "Student First Name:" << s1.Fname << endl;
         cout << "Student Last Name:" << s1.Lname << endl;
         cout << "Student House Name:" << s1.house << endl;
         cout << "Student Marks:" << s1.marks << endl;
         cout << "------------------------------------------------------" << endl;
         file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      }
      if ((j - 1) == 0)
      {
         cout << "No student record found." << endl;
      }
      else
      {
         cout << (j - 1) << " Student record displayed" << endl;
      }
   }
   file.close();
}
void search(int l)
{
   int k = 0;
   file.open("student.txt", ios::in);
   if (!file)
   {
      cout << "Error:Nothing to display!";
      file.close();
   }
   else
   {
      file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      while (!file.eof())
      {
         if (s1.roll == l)
         {
            k += 1;
            cout << "Student Roll No.:" << s1.roll << endl;
            cout << "Student First Name:" << s1.Fname << endl;
            cout << "Student Last Name:" << s1.Lname << endl;
            cout << "Student House Name:" << s1.house << endl;
            cout << "Student Marks:" << s1.marks << endl;
         }
         file >> s1.roll >> s1.Fname >> s1.Lname >> s1.house >> s1.marks;
      }
      if (k == 0)
      {
         cout << "Student Roll Number not matched." << endl;
      }
      else
      {
         cout << "Student Record Displayed." << endl;
      }
   }
   file.close();
}
int main()
{
   system("color 6B"); //add background colour
   /*(0-9 for background colour)
   (a-f for text colour)*/
   int choice;
   char choiceB;
   while (1)
   {
      cout << "1. Add Student Record." << endl;
      cout << "2. Modify Student Record." << endl;
      cout << "3. Delete Student Record. " << endl;
      cout << "4. Display Student Record." << endl;
      cout << "5. Search Student Record." << endl;
      cout << "6. Exit." << endl;
      cout << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1: //(Addition of student record)
      {
         int i = 0;
         choiceB = 'y';
         while (choiceB == 'y')
         {
            add();
            i += 1;
            cout << "Do you want to add another student record(y/n)??";
            cin >> choiceB;
         }
         if (i == 1)
         {
            cout << "1 student record added." << endl;
         }
         else
         {
            cout << i << " student records added." << endl;
         }
         break;
      }
      case 2://(Modify student record)
      {
         int rm;
         cout << "Enter the Roll number you want to modify:";
         cin >> rm;
         modify(rm);
         break;
      }

      case 3://(Delete Student Record)
      {
         int rd;
         cout << "Enter the Roll number you want to delete:";
         cin >> rd;
         delete_std(rd);
         break;
      }
      case 4: //(Display of Student Record)
      {
         display();
         break;
      }
      case 5: //(Search of Student Record)
      {
         int rn;
         cout << "Enter the Roll number of the student you want to search:";
         cin >> rn;
         search(rn);
         break;
      }
      case 6://(Exit)
      {
         exit(0);
      }
      default:
      {
         cout<<"Wrong option.Please Try again."<<endl;
         break;
      }
      }
   }
   return 0;
}
