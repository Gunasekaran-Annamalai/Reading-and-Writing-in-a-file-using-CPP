#include<iostream>
#include<fstream>
using namespace std;

class GetData {
public:
    int id;
    char name[15];
    char department[10];
    int marks[5];

    void GetDetails() {
        cout << "\n------ENTER-STUDENT-DETAILS------\n" << endl;
        cout << "Enter student \'ID\' : ";
        cin >> id;
        cout << "Enter student \'NAME\' : ";
        cin >> name;
        cout << "Enter student \'DEPARTMENT\' : ";
        cin >> department;
        cout << "Enter student marks : "<<endl;
        cout << "C mark : ";
        cin >> marks[0];
        cout << "C++ mark : ";
        cin >> marks[1];
        cout << "Java mark : ";
        cin >> marks[2];
        cout << "Python mark : ";
        cin >> marks[3];
        cout << "Go Lang mark : ";
        cin >> marks[4];
        cout <<"\n------------------------------------------------\n" << endl;
    }
};

class FileInsert:public GetData {
public:
    void FileWrite() {
        ofstream WriteFile;
        WriteFile.open("xyz.txt");
        WriteFile << "\n[............... STUDENT DATABASE FILE ...............]\n" <<endl;
        WriteFile.close();
    }
    void FileAppend() {
        fstream AppendFile;
        AppendFile.open("xyz.txt",ios :: app);
        if(AppendFile.fail()) cout << "Error in opening the file." << endl;
        else {
            AppendFile << "ID : " << id << endl;
            AppendFile << "Name : " << name <<endl;
            AppendFile << "Department : " << department <<endl;
            AppendFile << "C : " << marks[0] <<endl;
            AppendFile << "C++ : " << marks[1] <<endl;
            AppendFile << "Java : " << marks[2] <<endl;
            AppendFile << "Python : " << marks[3] <<endl;
            AppendFile << "GoLang : " << marks[4] <<endl;
            AppendFile <<"\n------------------------------------------------\n" << endl;
        }
        AppendFile.close();
        }
};

class FileDisplay:public  FileInsert{
public:
    void FileRead() {
        char read[100];
        ifstream ReadFile;
        ReadFile.open("xyz.txt");
        while(!ReadFile.eof()) {
            ReadFile.getline(read, 100);
            cout << read << endl;
        }
        ReadFile.close();
    }
};

int main() {
    int number_of_students;
    cout << "Kindly enter the number students in your class : ";
    cin >> number_of_students;
    FileDisplay x;
    x.FileWrite();
    FileInsert f[3];
    for(int i=0; i<number_of_students; i++) {
        f[i].GetDetails();
        f[i].FileAppend();
    }
    x.FileRead();
}
