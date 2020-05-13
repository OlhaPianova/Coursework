#include "Distance_Learning.h"
#include<iostream>
#include <fstream>
#include <Windows.h>

using namespace std;
#define CLEAR system("cls");
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


Info* arrStudents;
Admin* arrAdmins;
task* arrLessons;
Test* arrTests;
MarkInfo* arrMarks;

int countStudents = 0;
int ID = 1;
int countAdmins = 0;
int countLessons = 0;
int countTests = 0;
int countMarks = 0;
int howManyMarks = 0;

const int countQuestions = 6;
const string studentsfile = "students.txt";
const string adminsfile = "admins.txt";
const string lessonsfile = "lessons.txt";
const string homeworkfile = "homeworks.txt";
const string testNamefile = "tests.txt";
const string marksfile = "marks.txt";

void adminMenu(){
	cout << "\n\n\n\n\n\t\t\t1. Show all students" << endl;
	cout << "\t\t\t2. Search by surname" << endl;
	cout << "\t\t\t3. Add mark for student" << endl;
	cout << "\t\t\t4. Add new theory or homework" << endl;
	cout << "\t\t\t5. Add new training or control test" << endl;
	cout << "\n\t\t\t6. Back " << endl;

}

void main_menu(){
	cout << "1) English" << endl;
	cout << "2) Math" << endl;
	cout << "3) Ukrainian language" << endl;
	cout << "4) I am exploring the world" << endl;
	cout << "5) Marks" << endl;
	cout << "6) Edit edit info about yourself" << endl;
	cout << "7) Exit" << endl;
}

void work_menu() {
	cout << "\n1. Theory or homework" << endl;
	cout << "2. Training or control test" << endl;
	cout << "3. Back to main menu" << endl;
}
void lessonMenu() {
	cout << "\n\n1. Show theory" << endl;
	cout << "2. Show homework" << endl;
	cout << "3. Back" << endl;
	cout << "Select item:_" << endl;
}
void testMenu() {
	cout << "\n\n1. Training test" << endl;
	cout << "2. Control test" << endl;
	cout << "3. Back" << endl;
	cout << "Select item:_" << endl;
}

void insertAdmins(Admin admin){
	Admin* Temp = new Admin[countAdmins + 1];
	for (int i = 0; i < countAdmins; i++)
	{
		Temp[i] = arrAdmins[i];
	}
	Temp[countAdmins] = admin;
	countAdmins++;
	arrAdmins = new Admin[countAdmins];
	for (int i = 0; i < countAdmins; i++)
	{
		arrAdmins[i] = Temp[i];
	}
	delete[]Temp;
}
void initAdmins(){
	ifstream fin;
	fin.open(adminsfile);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Admin getAdmin;
			fin.ignore();
			fin >>getAdmin.AdminName;

			if (getAdmin.AdminName != "") {
				fin >> getAdmin.AdminSurname;
				fin >> getAdmin.LoginAdmin;
				fin >> getAdmin.PasswordAdmin;
			
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
		CLEAR;
		Admin newAdmin;
		cout << "Enter name: " << endl;
		cin>> newAdmin.AdminName;
		cout << "Enter surname: " << endl;
		cin>> newAdmin.AdminSurname;
		cout << "Enter your login: " << endl;
		cin>> newAdmin.LoginAdmin;
		cout << "Enter your password: " << endl;
		cin>> newAdmin.PasswordAdmin;
		
			fout << newAdmin.AdminName << endl;
			fout << newAdmin.AdminSurname << endl;
			fout << newAdmin.LoginAdmin << endl;
			fout << newAdmin.PasswordAdmin << endl;
			insertAdmins(newAdmin);
			countAdmins++;
			fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

void search_by_surname()
{
	string search_surname;
	cout << "Enter surname of the student for search: ";
	cin >> search_surname;
	for (int i = 0; i < countStudents; i++)
	{
		if (arrStudents[i].surname==search_surname) {
			cout << arrStudents[i].studID <<" ";
			cout << arrStudents[i].surname << endl;
			cout << arrStudents[i].name << endl;
			cout << arrStudents[i].email << endl;
		
		}
	}
}

void insertMarks(MarkInfo mark) {
	MarkInfo* temp = new MarkInfo[countMarks + 1];
	for (int i = 0; i < countMarks; i++)
	{
		temp[i] = arrMarks[i];
	}
	temp[countMarks] = mark;
	countMarks++;
	arrMarks = new MarkInfo[countMarks];
	for (int i = 0; i < countMarks; i++)
	{
		arrMarks[i] = temp[i];
	}
	delete[]temp;
}
void addMark() {
	CLEAR
	ofstream fout;
	fout.open(marksfile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		MarkInfo newMark;
		
		cout << "Enter count mark what you want to add: " << endl;
		cin >> howManyMarks;
		newMark.marks = new Mark[howManyMarks];

		for (int i = 0; i < howManyMarks; i++)
		{
			cout << "Enter student ID to whom you want to add a mark: ";
			cin >> newMark.ID;
			cout << "Enter from which school subject this mark (Maht, English, Ukrainion, Exploring): " << endl;
			cin >> newMark.marks[i].subject;
			cout << "Enter type for this mark (thematic or control): " << endl;
			cin >> newMark.marks[i].typeMark;
			cout << "Enter mark: ";
			cin >> newMark.marks[i].mark;
		}
		for (int i = 0; i < howManyMarks; i++)
		{
		fout << newMark.ID << endl;
		fout << newMark.marks[i].subject << endl;
		fout << newMark.marks[i].typeMark << endl;
		fout << newMark.marks[i].mark << endl;
		}
		insertMarks(newMark);
		countMarks++;
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
	fout.close();

}
void initMarks() {
	ifstream fin;
	fin.open(marksfile);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			MarkInfo getMark;
			if (countMarks!=0) {
				for (int i = 0; i < countMarks; i++) {
					fin >> getMark.ID;
					fin >> getMark.marks[i].subject;
					fin >> getMark.marks[i].typeMark;
					fin >> getMark.marks[i].mark;
				}
			}
			else {
				break;
			}
			insertMarks(getMark);
		}
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
	fin.close();
}
void showMarks() {
	
	int id = 0;
	cout << "Enter your students ID: ";
	cin >> id;
	
	
}

void login_student() {
	string templogin = "";
	string temppassword = "";
	bool login = false;

		cout << "\n\n\n\n\n\t\t\tEnter login: ";
		cin >> templogin;
		cout << "\n\n\n\n\n\t\t\tEnter password: ";
		cin >> temppassword;
		for (int i = 0; i < countStudents; i++)
		{
			if (arrStudents[i].login == templogin && arrStudents[i].password == temppassword ){
				login == true;
			}
			else{
				login == false;
			}
		}
		if (login == true) {
			cout << "Access allowed!" << endl;
		}
		else if (login == false) {
			cout << "Error: wrong password or login!" << endl;

		}

	
}
void passwordStudent() {
	string pasw = "";
	cout << "\n\n\n\n\n\t\t\tPassword: ";
	cin >> pasw;
	bool foundStudentPasw = false;

	for (int i = 0; i < countStudents; i++) {
		if (arrStudents[i].password == pasw) {
			foundStudentPasw = true;
			break;
		}
	}
	if (foundStudentPasw == false) {
		cout << endl;
		cout << "\nWrong password!" << endl;

	}
	else if (foundStudentPasw == true) {
		cout << endl;
		cout << "Welcome!" << endl;
		cout << endl;
	}
}
void insertStudents(Info stud){
	Info* tempStud = new Info[countStudents + 1];
	for (int i = 0; i < countStudents; i++){
		tempStud[i] = arrStudents[i];
	}
	tempStud[countStudents] = stud;
	countStudents++;
	ID++;
	arrStudents = new Info[countStudents];
	for (int i = 0; i < countStudents; i++)
	{
		arrStudents[i] = tempStud[i];
	}
	delete[]tempStud;
}
void Add_Student(){
	ofstream fout;
	fout.open(studentsfile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		CLEAR;
		Info newStudent;
		newStudent.studID = ID;
		cout << "Enter name: " << endl;
		cin >> newStudent.name;
		cout << "Enter surname: " << endl;
		cin >> newStudent.surname;
		cout << "Enter email: " << endl;
		cin >> newStudent.email; 
		cout << "Enter your login: " << endl;
		cin >> newStudent.login;
		cout << "Enter your password: " << endl;
		cin >> newStudent.password;

		fout << newStudent.studID << endl;
		fout << newStudent.name << endl;
		fout << newStudent.surname << endl;
		fout << newStudent.email << endl;
		fout << newStudent.login << endl;
		fout << newStudent.password << endl;
		insertStudents(newStudent);
		ID++;
		countStudents++;
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
	fout.close();

}
void initStudents(){
	ifstream fin;
	fin.open(studentsfile);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Info getStudent;
			fin.ignore();
			fin >> getStudent.studID;
			fin >> getStudent.name;
			if (getStudent.name != "") {
				fin >> getStudent.surname;
				fin >> getStudent.email;
				fin >> getStudent.login;
				fin >> getStudent.password;
			}
			else {
				break;
			}
			insertStudents(getStudent);
		}
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}
void showStudent(){
	for (int i = 0; i < countStudents; i++)
		 {
		cout <<"ID: "<< arrStudents[i].studID << ". " << arrStudents[i].name <<" "<< arrStudents[i].surname<< endl;
		}
	cout << endl;
}
void editStudent(){
	for (int i = 0; i < countStudents; i++)
	{
		cout << "ID: " << arrStudents[i].studID << ". " << arrStudents[i].name << " " << arrStudents[i].surname << endl;
	}
	cout << endl;
	cout << "Select students number do you want to edit :_ " << endl;
	int studentsNumb = 0;
	cin >> studentsNumb;

	ofstream fout;
	fout.open(studentsfile);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		Info* temp = new Info[countStudents];
		for (int i = 0; i < countStudents; i++)
		{
			temp[i] = arrStudents[i];
		}

		cout << "Enter new details for this student:" << endl;
		cout << "Name: " << endl;
		temp[studentsNumb - 1].name == "";
		cin >> temp[studentsNumb - 1].name;
		cout << "Surname: " << endl;
		temp[studentsNumb - 1].surname == "";
		cin >> temp[studentsNumb - 1].surname;
		cout << "Email: " << endl;
		temp[studentsNumb - 1].email == "";
		cin >> temp[studentsNumb - 1].email;
		for (int i = 0; i < countStudents; i++) {
			fout << temp[i].name << endl;
			fout << temp[i].surname << endl;
			fout << temp[i].email << endl;
		}

		for (int i = 0; i < countStudents; i++)
		{
			arrStudents[i] = temp[i];
		}
		delete[]temp;
		fout.close();
	}
	else {
		cout << "Application can't open data file!" << endl;
	}
}

void insertLesson(task lesson) {
	task* temp = new task[countLessons + 1];
	for (int i = 0; i < countLessons; i++)
	{
		temp[i] = arrLessons[i];
	}
	temp[countLessons] = lesson;
	countLessons++;
	arrLessons = new task[countLessons];
	for (int i = 0; i < countLessons; i++)
	{
		arrLessons[i] = temp[i];
	}
	delete[]temp;
}
void initLesson() {
	ifstream fin;
	fin.open(lessonsfile);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			task getLesson;
			fin >> getLesson.CategoryName;
			if (getLesson.CategoryName != "") {
				    fin >> getLesson.taskType;
					fin >> getLesson.theme;
					fin >> getLesson.paragraphNumb;
					fin >> getLesson.pageNumb;
					fin >> getLesson.exercise;
			}
			else {
				break;
			}
			insertLesson(getLesson);
		}
	}
	else {
		cout << "Error: Application can't open file \"lessons.txt\"!" << endl;
	}
}
void addNewLesson(){

	ofstream fout;
	fout.open(lessonsfile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		
		task newLesson;
		cout << "Enter categorys name: " << endl;
		cout<<"English\nMath\nUkrainian\nExploring" << endl;
		cin >> newLesson.CategoryName;
		cout << "Enter type of task: " << endl;
		cout << "(theory or homework)" << endl;
		cin >> newLesson.taskType;
		cout << "Enter theme for this lesson:_ " << endl;
		cin >> newLesson.theme;
		cout << "Enter the paragraph number:_ " << endl;
		cin >> newLesson.paragraphNumb;
		cout << "Enter page in the book:_" << endl;
		cin >> newLesson.pageNumb;
		cout << "Enter exercise:_" << endl;
		cin >> newLesson.exercise;

		
		fout << newLesson.CategoryName << endl;
		fout << newLesson.taskType<< endl;
		fout << newLesson.theme << endl;
		fout << newLesson.paragraphNumb << endl;
		fout << newLesson.pageNumb << endl;
		fout << newLesson.exercise << endl;

		insertLesson(newLesson);
		countLessons++;
		fout.close();
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
}


void showMathsTheory(){
	CLEAR
	cout << "\n\t\tAll Maths theory: " << endl;
	for (int i = 0; i < countLessons; i++){
		if (arrLessons[i].CategoryName=="Math"&&arrLessons[i].taskType=="theory") {
			cout <<i+1<<". "<< "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showEnglishTheory() {
	CLEAR
	cout << "\n\t\tAll English theory: " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "English"&&arrLessons[i].taskType == "theory") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showUkrainianlanguageTheory(){
	CLEAR
	cout << "\n\t\tAll \"Ukrainian language\" theory: " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "Ukrainian"&&arrLessons[i].taskType == "theory") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showExploring_worldTheory(){
	CLEAR
	cout << "\n\t\tAll \"I am exploring the world\" theory: " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "Exploring"&&arrLessons[i].taskType == "theory") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}

void showMathsHomework(){
	CLEAR;
	cout << "\n\t\tAll \"Math\" homework " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "Math"&&arrLessons[i].taskType == "homework") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showEnglishHomework(){
	CLEAR;
	cout << "\n\t\tAll \"English\" homework " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "English"&&arrLessons[i].taskType=="homework") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showUkrainianlanguageHomework(){
	CLEAR;
	cout << "\n\t\tAll \"Ukrainian language\" homework " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName == "Ukrainian"&&arrLessons[i].taskType=="homework") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}
void showExploring_worldHomework(){
	CLEAR;
	cout << "\n\t\tAll \"I am exploring the world\" homework " << endl;
	for (int i = 0; i < countLessons; i++) {
		if (arrLessons[i].CategoryName=="Exploring"&&arrLessons[i].taskType == "homework") {
			cout << i + 1 << ". " << "Theme: " << arrLessons[i].theme << endl;
			cout << "Paragraph: " << arrLessons[i].paragraphNumb << endl;
			cout << "Page: " << arrLessons[i].pageNumb << endl;
			cout << "Exercise: " << arrLessons[i].exercise << endl;
			cout << endl;
		}
	}
	cout << endl;
}

void initTest() {
	ifstream fin;
	fin.open(testNamefile);
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof()) {
			Test getTest;
			fin >> getTest.categoryName;
			if (getTest.categoryName != "") {
				fin >> getTest.testName;
				fin >> getTest.tipe;
				for (int i = 0; i < countQuestions; i++) {
					fin >> getTest.description[i].question;
					fin >> getTest.description[i].rightAnswer;
					for (int j = 0; j < 4; j++) {
						fin >> getTest.description[i].fourOption[j];
					}
				}
			}
			else {
				break;
			}
			insertTest(getTest);
		}
	}
	else {
		cout << "Error: file not open!" << endl;
	}
	fin.close();
}
void insertTest(Test test) {
	Test* temp = new Test[countTests + 1];
	for (int i = 0; i < countTests; i++) {
		temp[i] = arrTests[i];
	}
	temp[countTests] = test;
	countTests++;
	arrTests = new Test[countTests];
	for (int i = 0; i < countTests; i++) {
		arrTests[i] = temp[i];
	}
	delete[] temp;
}
void addTest() {
	ofstream fout;
	fout.open(testNamefile, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Test newTest;
		cout << "\nEnter categorys name (Math or Exploring): " << endl;
		cin >> newTest.categoryName;
		cout << "Enter name for test: " << endl;
		cin >> newTest.testName;
		cout << "Enter the test tipe (training or control): " << endl;
		cin >> newTest.tipe;
		for (int i = 0; i < countQuestions; i++) {
			cout << "Enter " << i + 1 << " question for this test: " << endl;
			cin >> newTest.description[i].question;
			cout << "Enter right answer for this question: " << endl;
			cin >> newTest.description[i].rightAnswer;
			cout << "Enter four answer options: " << endl;
			for (int j = 0; j < 4; j++) {
				cout << "Enter " << j + 1 << " answer option: " << endl;
				cin >> newTest.description[i].fourOption[j];
			}
		}
		fout << newTest.categoryName << endl;
		fout << newTest.testName<< endl;
		fout << newTest.tipe << endl;
		for (int i = 0; i <countQuestions; i++) {
			fout << newTest.description[i].question << endl;
			fout << newTest.description[i].rightAnswer << endl;
			for(int j = 0; j < 4; j++){
				fout << newTest.description[i].fourOption[j]<< endl;
			}
		}
		insertTest(newTest);
		countTests++;
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
	fout.close();
}
void passTest() {
	cout << "\tEnter the test number you want to pass: " << endl;
	int numberTest = 0;
	string ansv = "";
	int bal = 0;
	int rightAnsver = 0;
	cin >> numberTest;
	numberTest--;
	cout << "\n\n\t\t\t" << arrTests[numberTest].categoryName << endl;
	cout << "\n\t\You pass " << arrTests[numberTest].tipe << " test: " << arrTests[numberTest].testName << endl;
	for (int i = 0; i < countQuestions; i++) {
		cout << i + 1 << ". " << arrTests[numberTest].description[i].question << endl;
		cout << "Choose one from the options: " << endl;
		for (int j = 0; j < 4;j++) {
			cout<<" "<<arrTests[numberTest].description[i].fourOption[j]<<" ";
		}
		cout << "\nEnter your answer: ";
		cin >> ansv;
		if (arrTests[numberTest].description[i].rightAnswer == ansv) {
			SetConsoleTextAttribute(color, FOREGROUND_GREEN);
			cout << "RIGHT ANSVER - YOU GET 2 BALS)" << endl;
			SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			bal += 2;
			rightAnsver++;
		}
		else {
			SetConsoleTextAttribute(color, FOREGROUND_RED);
			cout << "INCORRECT" << endl;
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
	}
	SetConsoleTextAttribute(color, FOREGROUND_GREEN);
	cout << "\n\n\n\t\tYou answered " << rightAnsver << " questions correctly " << endl;
	cout << "\nYOUR EARNING BALSS: " << bal << endl;
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	
		ofstream fout;
		fout.open(marksfile, fstream::app);
		bool isOpen = fout.is_open();
		if (isOpen == true) {
			MarkInfo newMark;
			newMark.marks = new Mark[1];
			
				cout << "Enter your student ID: ";
				cin >> newMark.ID;
				for (int i = 0; i < countTests; i++) {
					if (arrTests[i].categoryName=="Math") {
						newMark.marks[howManyMarks].subject = "Math";
					}
					else if (arrTests[i].categoryName == "Eploring") {
						newMark.marks[howManyMarks].subject = "Exploring";
					}
					if (arrTests[i].tipe=="training") {
						newMark.marks[howManyMarks].typeMark = "training";
					}
					else if (arrTests[i].tipe =="control") {
						newMark.marks[howManyMarks].typeMark = "control";
					}
					newMark.marks[howManyMarks].mark=bal;

				}
				fout << newMark.ID << endl;
				fout << newMark.marks[howManyMarks].subject << endl;
				fout << newMark.marks[howManyMarks].typeMark << endl;
				fout << newMark.marks[howManyMarks].mark << endl;
				insertMarks(newMark);
				countMarks++;	
			}
		    else {
			cout << "Error: file not opened!" << endl;
		    }
		    fout.close();
}

void showMathsTrainingTests() {
	CLEAR;
	cout << "\t\tALL MATH TRAINING TESTS: " << endl;
	for (int i = 0; i < countTests; i++) {
		if (arrTests[i].categoryName=="Math"&&arrTests[i].tipe=="training") {
			cout << i + 1 << ". " << arrTests[i].testName << endl;
		}
	}
	cout << endl;
}
void showMathsControlTests() {
	CLEAR;
	cout << "\t\tALL MATH CONTROL TESTS: " << endl;
	for (int i = 0; i < countTests; i++) {
		if (arrTests[i].categoryName == "Math"&&arrTests[i].tipe == "control") {
			cout << i + 1 << ". " << arrTests[i].testName << endl;
		}
	}
	cout << endl;
}
void showExploring_worldTrainingTests() {
	CLEAR;
	cout << "\t\tTRAINING TESTS \"IEXPLORING THE WORLD\": " << endl;
	for (int i = 0; i < countTests; i++) {
		if (arrTests[i].categoryName == "Exploring"&&arrTests[i].tipe == "training") {
			cout << i + 1 << ". " << arrTests[i].testName << endl;
		}
	}
	cout << endl;
}
void showExploring_worldControlTests() {
	CLEAR;
	cout << "\t\tCONTROL TESTS \"IEXPLORING THE WORLD\": " << endl;
	for (int i = 0; i < countTests; i++) {
		if (arrTests[i].categoryName == "Exploring"&&arrTests[i].tipe == "control") {
			cout << i + 1 << ". " << arrTests[i].testName << endl;
		}
	}
	cout << endl;
}