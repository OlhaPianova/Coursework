#pragma once
#include<string>
#include<list>
using namespace std;

struct Info {
	int ID;
	string name;
	string surname;
	string email;
	string login;
	string password;
	int* Marks;
	float Seredniy_bal;
};
struct Admin {
	string AdminName;
	string AdminSurname;
	string LoginAdmin;
	string PasswordAdmin;
};
struct Category {
	list<string> theory;
	list<string> homework;
	list<string> trainingTest;
	list<string> controlTest;
};
struct Subjects {
	Category English_language;
	Category Mathematics;
	string Art;
	Category Ukrainian_language;
	Category World;
};
void login();
void login_Admin();
void addAdmin();
void insertStudents(Info stud);
void init();
void Add_Student();

