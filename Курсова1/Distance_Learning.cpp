#include "Distance_Learning.h"
#include<iostream>
#include <fstream>
using namespace std;
#define CLEAR system("cls");

Info* arrStudents;
Admin* arrAdmins;
Category* arrLessons;
int countStudents = 0;
int countAdmins = 0;
int countLessons = 0;

const string studentsfile = "students.txt";
const string adminsfile = "admins.txt";
const string lessonsfile = "lessons.txt";

void main_menu(){
	cout << "1) English" << endl;
	cout << "2) Mathematics" << endl;
	cout << "3) Art" << endl;
	cout << "4) Ukrainian language" << endl;
	cout << "5) I am exploring the world" << endl;
	cout << "6) Marks" << endl;
	cout << "7) Exit" << endl;
}
void category_menu(){
	cout << "\n1. Theory and homework" << endl;
	cout << "2. Training test" << endl;
	cout << "3. Control test" << endl;
	cout << "4. back to main menu" << endl;
}

void insertAdmins(Admin admin){
	Admin* temp = new Admin[countAdmins + 1];
	for (int i = 0; i < countAdmins; i++)
	{
		temp[i] = arrAdmins[i];
	}
	temp[countAdmins] = admin;
	countAdmins++;
	arrAdmins = new Admin[countAdmins];
	for (int i = 0; i < countAdmins; i++)
	{
		arrAdmins[i] = temp[i];
	}
	delete[]temp;
}
void initAdmins(){
	ifstream fin;
	fin.open(adminsfile);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Admin temp;
			fin.ignore();
			getline(fin, temp.AdminName);
			if (temp.AdminName != "") {
				fin >> temp.AdminSurname;
				fin >> temp.LoginAdmin;
				fin >> temp.PasswordAdmin;

				insertAdmins(temp);
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
void addAdmin(){
	ofstream fout;
	fout.open(adminsfile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Admin newAdmin;
		CLEAR;
		cout << "Enter name: " << endl;
		cin >> newAdmin.AdminName;
		cout << "Enter surname: " << endl;
		cin >> newAdmin.AdminSurname;
		cout << "Enter your login: " << endl;
		cin >> newAdmin.LoginAdmin;
		cout << "Enter your password: " << endl;
		cin >> newAdmin.PasswordAdmin;
		if (arrAdmins[countAdmins].LoginAdmin == newAdmin.LoginAdmin) {
			cout << "\n\tAn admin with that name has already been created!" << endl;
		}
		else {
			insertAdmins(newAdmin);

			fout << newAdmin.AdminName << endl;
			fout << newAdmin.AdminSurname << endl;
			fout << newAdmin.LoginAdmin << endl;
			fout << newAdmin.PasswordAdmin << endl;
		}
		fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}
void login_Admin(){
	string login = "";
	string password = "";
	CLEAR;
		do {
			CLEAR;
			cout << "enter your login:" << endl;
			cin >> login;
			cout << "enter your password:" << endl;
			cin >> password;
			if (arrAdmins[countAdmins].LoginAdmin != login) {
				CLEAR;
				cout << "\nNo user with this login! Make sure you enter the username correctly" << endl;
			}
			else if (arrAdmins[countAdmins].PasswordAdmin != password) {
				CLEAR;
				cout << "\n\t\tWrong password! Make sure you have entered your password correctly" << endl;
			}
		} while (arrAdmins[countAdmins].LoginAdmin != login&&arrAdmins[countAdmins].PasswordAdmin != password);
}

void login_student() {
	string login = "";
	string password = "";
	do {
		cout << "enter your login:" << endl;
		cin >> login;
		cout << "enter your password:" << endl;
		cin >> password;
		if (arrStudents[countStudents].login != login) {
			cout << "\nNo user with this login! Make sure you enter the username correctly" << endl;
		}
		else if (arrStudents[countStudents].password != password) {
			cout << "\n\t\tWrong password! Make sure you have entered your password correctly" << endl;
		}
	} while (arrStudents[countStudents].login != login&&arrStudents[countStudents].password != password);
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
	if (arrStudents[countStudents].login == newStudent.login) {
		cout << "\n\tThis user has already been created!" << endl;
	}
	else {
		insertStudents(newStudent);

		fout << newStudent.name << endl;
		fout << newStudent.surname << endl;
		fout << newStudent.email << endl;
		fout << newStudent.login << endl;
		fout << newStudent.password << endl;
	}
	

	fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}
void initStudents()
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

void addNewLesson(){
	
	Category newLesson;
	newLesson.countLessons = countLessons;
	ofstream fout;
	fout.open("lessonsfile", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Category* temp = new Category[countLessons + 1];
		for (int i = 0; i < countLessons; i++) {
			temp[i] = arrLessons[i];
		}
		temp[countLessons].countLessons = countLessons;

		cout << "Enter categorys name:_ " << endl;
		cin >> newLesson.categoryName;

		cout << "Enter theme for this lesson:_ " << endl;
		cin >> newLesson.theory[countLessons].theme;
		cout << "Enter the paragraph number:_ " << endl;
		cin >> newLesson.theory[countLessons].paragraphNumb;
		cout << "Enter page in the book:_" << endl;
		cin >> newLesson.theory[countLessons].pageNumb;
		cout << "Enter exercise:_" << endl;
		cin >> newLesson.theory[countLessons].exercise;

		cout << "\n\t\tWrite your homework:_ " << endl;
		cout << "Enter theme for this homework:_ " << endl;
		cin >> newLesson.homework[countLessons].theme;
		cout << "Enter paragraph:_ " << endl;
		cin >> newLesson.homework[countLessons].paragraphNumb;
		cout << "Enter pageNumb:_ " << endl;
		cin >> newLesson.homework[countLessons].pageNumb;
		cout << "Enter exercise:_ " << endl;
		cin >> newLesson.homework[countLessons].exercise;

		fout << temp[countLessons].categoryName << endl;
		fout << temp[countLessons].countLessons << endl;
		fout << temp[countLessons].theory[countLessons].theme << endl;
		fout << temp[countLessons].theory[countLessons].paragraphNumb << endl;
		fout << temp[countLessons].theory[countLessons].pageNumb << endl;
		fout << temp[countLessons].theory[countLessons].exercise << endl;

		fout << temp[countLessons].homework[countLessons].theme << endl;
		fout << temp[countLessons].homework[countLessons].paragraphNumb << endl;
		fout << temp[countLessons].homework[countLessons].pageNumb << endl;
		fout << temp[countLessons].homework[countLessons].exercise << endl;

		countLessons++;
		arrLessons = new Category[countLessons];
		for (int i = 0; i < countLessons; i++) {
			arrLessons[i] = temp[i];
		}
		delete[] temp;
		fout.close();
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
}