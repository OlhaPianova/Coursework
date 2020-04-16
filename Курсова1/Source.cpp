#include"Distance_Learning.h"
#include<iostream>
#include<string>
using namespace std;
#define CLEAR system("ctl");
int main() {
	Info* arrStudents;
	
	int Entrance = 0;
	int action = 0;
	int categoryItem = 0;
	int *countStudents;
	do {
		cout << "\n\n\t\t\tPlease select:" << endl;
		cout << "\n\t\t\t1 - LOG IN \n\n\t\t\t2 - GET REGISTERED " << endl;
		cout << "3 - login as admin " << endl;
		cin >> Entrance;
		switch (Entrance) {
		case 1: {
			login();
			do {
				CLEAR;
				cout << "1) English" << endl;
				cout << "2) Mathematics" << endl;
				cout << "3) Art" << endl;
				cout << "4) Ukrainian language" << endl;
				cout << "5) I am exploring the world" << endl;
				cout << "6) My marks" << endl;
				cout << "7) Exit" << endl;
				cout << "\nSelect action:_ " << endl;
				cin >> action;
				switch (action) {
				case 1: {
					while (categoryItem != 5) {
						cout << "\t\t\tEnglish" << endl;
						cout << "\n1. Theory" << endl;
						cout << "2. Homework" << endl;
						cout << "3. Training test" << endl;
						cout << "4. Control test" << endl;
						cout << "5. back to main menu" << endl;

						cout << "Enter category item: " << endl;
						cin >> categoryItem;
						switch (categoryItem) {
						case 1: {
							//Theory
						}break;
						case 2: {
							//Homework
						}break;
						case 3: {
							//Training test
						}break;
						case 4: {
							//Control test
						}break;
						case 5: {
							break;
						}

						}
					}
				}break;
				case 2: {
				//Mathematics
				}break;
				case 3: {
				//Art
				}break;
				case 4: {
				//Ukrainian language
				}break;
				case 5: {
				//I am exploring the world
				}break;
				case 6: {
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
		case 3: {
			login_Admin();
		}break;
		case 4: {
			cout << "Goodbye!" << endl;
			break;
		}
	}
		
	} while (Entrance!=4);
				
		
	
	





	system("pause");
		return 0;
}
											                                                  