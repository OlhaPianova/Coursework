#pragma once
#include<string>
using namespace std;

struct Mark {
	string  subject;
	string typeMark;
	int mark;
};
struct MarkInfo{
	int ID;
	Mark* marks;
};
struct Info {
	int studID;
	string name;
	string surname;
	string email;
	string login;
	string password;
	
};
struct Admin {
	string AdminName;
	string AdminSurname;
	string LoginAdmin;
	string PasswordAdmin;
};

struct Questions{
	string question;
	string rightAnswer;
	string fourOption[4];
};

struct Test{
	string categoryName;
	string testName;
	string tipe;
	Questions description[6];
	
};
struct task {
	string CategoryName;
	string taskType;
	string theme;
	string paragraphNumb;
	string pageNumb;
	string exercise;
};
void adminMenu();
void main_menu();
void work_menu();
void lessonMenu();
void testMenu();


void insertAdmins(Admin admin);
void initAdmins();
void addAdmin();

void search_by_surname();

void insertMarks(MarkInfo mark);
void addMark();
void initMarks();
void showMarks();

void login_student();
void passwordStudent();
void insertStudents(Info stud);
void initStudents();
void Add_Student();
void showStudent();
void editStudent();

void insertLesson(task lesson);
void initLesson();
void addNewLesson();

void showMathsTheory();
void showEnglishTheory();
void showUkrainianlanguageTheory();
void showExploring_worldTheory();

void showMathsHomework();
void showEnglishHomework();
void showUkrainianlanguageHomework();
void showExploring_worldHomework();

void initTest();
void addTest();
void insertTest(Test test);
void passTest();

void showMathsTrainingTests();
void showMathsControlTests();
void showExploring_worldTrainingTests();
void showExploring_worldControlTests();