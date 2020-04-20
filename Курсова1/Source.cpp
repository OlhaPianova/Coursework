#include"Distance_Learning.h"
#include<iostream>
#include<string>
using namespace std;
#define CLEAR system("cls");

int main() {
	initAdmins();
	initStudents();

	Info* arrStudents;
	
	int Entrance = 0;
	int action = 0;
	int categoryItem = 0;
	int *countStudents;
	do {
		cout << "\n\n\t\t\tPlease select:" << endl;
		cout << "\n\t\t\t1 - LOG IN \n\n\t\t\t2 - GET REGISTERED " << endl;
		cout << "\n\n\n\t\t\t0 - login or registration as admin " << endl;
		cin >> Entrance;
		switch (Entrance) {
		case 1: {
			CLEAR;
			login_student();
			do {
				CLEAR;
				main_menu();
				cout << "\nSelect action:_ " << endl;
				cin >> action;
				switch (action) {
				case 1: {
					while (categoryItem != 4) {
						CLEAR;
						cout << "\t\t\tEnglish" << endl;
						category_menu();
						cout << "Enter category item: " << endl;
						cin >> categoryItem;
						switch (categoryItem) {
						case 1: {
							CLEAR;
							//Theory and Homework
						}break;
						case 2: {
							CLEAR;
							//Training test
						}break;
						case 3: {
							CLEAR;
							//Control test
						}break;
						case 4: {
							break;
						}

						}
					}
				}break;
				case 2: {
					CLEAR;
					//Mathematics
				}break;
				case 3: {
					CLEAR;
					//Art
				}break;
				case 4: {
					CLEAR;
					//Ukrainian language
				}break;
				case 5: {
					CLEAR;
					//I am exploring the world
				}break;
				case 6: {
					CLEAR;
					//My marks
				}break;
				case 7: {
					CLEAR;
					cout << "\n\n\t\t\tGoodbye!" << endl;
					break;
				}
				}
			} while (action != 7);
		
		}break;
		case 2: {
			Add_Student();
		}break;
		case 0: {
			CLEAR;
			int ansverLogAdmin = 0;
			cout << "\n\t\t\t1. Log in" << endl;
			cout << "\n\t\t\t2. Registration" << endl;
			cin >> ansverLogAdmin;
			if (ansverLogAdmin==1) {
				login_Admin();
				do {
					CLEAR;
					main_menu();
					cout << "\nSelect action:_ " << endl;
					cin >> action;
					switch (action) {
					case 1: {
						CLEAR;
						cout << "\t\t\tEnglish" << endl;
						category_menu();
					}break;
					case 2: {
						CLEAR;
						cout << "\t\t\tMathematics" << endl;
						category_menu();
					}break;
					case 3: {
						CLEAR;
						cout << "\t\t\tArt" << endl;
						category_menu();
					}break;
					case 4: {
						CLEAR;
						cout << "\t\t\tUkrainian language" << endl;
						category_menu();
					}break;
					case 5: {
						CLEAR;
						cout << "\t\t\tI am exploring the world" << endl;
						category_menu();
					}break;
					case 6: {
						CLEAR;
						cout << "\marks" << endl;
					}break;
					case 7: {
						break;
					}
					}
				} while (action != 7);
			}
			else if (ansverLogAdmin == 2) {
				addAdmin();
			}
			
		}break;
		case 4: {
			CLEAR;
			cout << "Goodbye!" << endl;
			break;
		}
	}
		
	} while (Entrance!=4);
				

	system("pause");
		return 0;
}
											                                                  