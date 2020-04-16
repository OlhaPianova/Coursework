#include "Distance_Learning.h"
#include<iostream>
#include <fstream>

using namespace std;
Info* arrStudents;
Admin* arrAdmins;
int countStudents = 0;
int countAdmins = 0;

const string studentsfile = "students.txt";

void login(){
	string login = "";
	string password = "";
	do {
		cout << "enter your login:" << endl;
		cin >> login;
		cout << "enter your password:" << endl;
		cin >> password;
	} while (arrStudents[countStudents].login != login&&arrStudents[countStudents].password != password);
}

void addAdmin(){
	Admin newAdmin;
	cout << "Enter name: " << endl;
	cin >> newAdmin.AdminName;
	cout << "Enter surname: " << endl;
	cin >> newAdmin.AdminSurname;
	cout << "Enter your login: " << endl;
	cin >> newAdmin.LoginAdmin;
	cout << "Enter your password: " << endl;
	cin >> newAdmin.PasswordAdmin;
	Admin* temp = new Admin[countAdmins + 1];
	for (int i = 0; i < countAdmins; i++)
	{
		temp[i] = arrAdmins[i];
	}
	temp[countAdmins] = newAdmin;
	countAdmins++;
	arrAdmins = new Admin[countAdmins];
	for (int i = 0; i < countAdmins; i++)
	{
		arrAdmins[i] = temp[i];
	}
	delete[]temp;
}
void login_Admin(){
	string login = "";
	string password = "";
	do {
		cout << "enter your login:" << endl;
		cin >> login;
		cout << "enter your password:" << endl;
		cin >> password;
	} while (arrAdmins[countAdmins].LoginAdmin!= login&&arrAdmins[countAdmins].PasswordAdmin != password);
}

void insertStudents(Info stud){
	Info* temp = new Info[countStudents + 1];
	for (int i = 0; i < countStudents; i++)
	{
		temp[i] = arrStudents[i];
	}
	temp[countStudents] = stud;
	countStudents++;
	arrStudents = new Info[countStudents];
	for (int i = 0; i < countStudents; i++)
	{
		arrStudents[i] = temp[i];
	}
	delete[]temp;
}
void Add_Student(){
	ofstream fout;
	fout.open(studentsfile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

	Info newStudent;
	newStudent.ID= countStudents;

	cout << "Enter name: " << endl;
	cin >> newStudent.name;
	cout << "Enter surname: " << endl;
	cin >> newStudent.surname;
	cout << "Enter your email: " << endl;
	cin >> newStudent.email;
	cout << "Enter your login: " << endl;
	cin >> newStudent.login;
	cout << "Enter your password: " << endl;
	cin >> newStudent.password;
	
	countStudents++;

	insertStudents(newStudent);

	fout << newStudent.name << endl;
	fout << newStudent.surname << endl;
	fout << newStudent.email << endl;
	fout << newStudent.login << endl;
	fout << newStudent.password<< endl;

	fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

	void init()
	{
		ifstream fin;
		fin.open(studentsfile);
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			while (!fin.eof())
			{
				Info temp;
				fin.ignore();
				getline(fin, temp.name);
				if (temp.name != "") {
					fin >> temp.surname;
					fin >> temp.email;
					fin >> temp.login;
					fin >> temp.password;

					insertStudents(temp);
				}
				else {
					break;
				}

			}
		}
		else {
			cout << "Error: Application can't open data file!" << endl;
		}
	}
