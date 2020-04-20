#pragma once
#include<string>
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
struct Questions
{
	string question;
	string answer;
};

struct Test
{
	string testName;
	Questions* description;
	int questionNumb;

};
struct task {
	string theme;
	int paragraphNumb;
	int pageNumb;
	int exercise;

};
struct Category {
	string categoryName;
	int countLessons;
	task* theory;
	task* homework;
	Test* trainingTest;
	Test* controlTest;
};

void main_menu();
void category_menu();

void login_Admin();
void insertAdmins(Admin admin);
void initAdmins();
void addAdmin();

void login_student();
void insertStudents(Info stud);
void initStudents();
void Add_Student();

void addNewLesson();
