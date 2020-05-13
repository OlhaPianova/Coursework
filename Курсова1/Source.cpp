#include"Distance_Learning.h"
#include<iostream>
#include<string>
using namespace std;
#define CLEAR system ("cls");
bool *login;

int main() {
	initAdmins();
	initStudents();
	initLesson();
	initTest();
	initMarks();
	int Entrance = 0;
	int action = 0;
	int categoryItem = 0;
	int *countStudents;
	do {
		cout << "\n\n\t\t\tDistance Learning " << endl;

		cout << "\n\n\n\n\t\t\t1 - Student " << endl;
		cout << "\n\n\t\t\t2 - Admin " << endl;
		cout<< "\n\n\t\t\t0 - Exit" << endl;
		cin >> Entrance;
		switch (Entrance) {
		case 1: {
			CLEAR
			cout << "\n\n\n\n\t\t\t1 - LOG IN \n\n\t\t\t2 - GET REGISTERED \n\n\t\t\t0 - Back " << endl;
			int ent = 0;
			cin >> ent;
			switch (ent) {
			case 1: {
				CLEAR
				initStudents();
				login_student();
				
					do {
						cout << "\nSelect category:_ " << endl;
						main_menu();
						cin >> action;
						switch (action) {
						case 1: {
							do {
								CLEAR
									cout << "\t\t\tEnglish" << endl;
								cout << "Choose action: " << endl;
								cout << "\n1. Theory or homework" << endl;
								cout << "2. Back to main menu" << endl;
								cin >> categoryItem;
								switch (categoryItem) {
								case 1: {
									CLEAR
										int item = 0;
									do {
										lessonMenu();
										cin >> item;
										if (item == 1) {
											showEnglishTheory();
										}
										else if (item == 2) {
											showEnglishHomework();
										}
									} while (item != 3);
								}break;
								case 2: {
									break;
								}
								}
							} while (categoryItem != 2);
						}break;
						case 2: {
							CLEAR
								do {
									cout << "\t\t\tMath" << endl;
									cout << "Choose action: " << endl;
									work_menu();
									cin >> categoryItem;
									switch (categoryItem) {
									case 1: {
										CLEAR
											int item = 0;
										do {
											lessonMenu();
											cin >> item;
											if (item == 1) {
												showMathsTheory();
											}
											else if (item == 2) {
												showMathsHomework();
											}
										} while (item != 3);
									}break;
									case 2: {
										CLEAR
											int item = 0;
										do {
											testMenu();
											cin >> item;
											switch (item) {
											case 1: {
												showMathsTrainingTests();
												cout << "Do you want to pass one of the tests? 'y' or 'n':_" << endl;
												string ansvPassTest = "";
												cin >> ansvPassTest;
												if (ansvPassTest == "y") {
													passTest();
													
												}
												else {
													break;
												}
											}break;
											case 2: {
												showMathsControlTests();
												cout << "Do you want to pass one of the tests? 'y' or 'n':_" << endl;
												string ansvPassTest = "";
												cin >> ansvPassTest;
												if (ansvPassTest == "y") {
													passTest();
													
												}
												else {
													break;
												}
											}break;
											case 3: {
												break;
											}
											}
										} while (item != 3);
									}break;
									case 3: {
										break;
									}break;
									}
								} while (categoryItem != 3);
						}break;
						case 3: {
							CLEAR
								do {
									cout << "\t\t\tUkrainian language" << endl;
									cout << "Choose action: " << endl;
									cout << "\n1. Theory or homework" << endl;
									cout << "2. Back to main menu" << endl;
									cin >> categoryItem;
									switch (categoryItem) {
									case 1: {
										CLEAR
											int item = 0;
										do {
											lessonMenu();
											cin >> item;
											if (item == 1) {
												showUkrainianlanguageTheory();
											}
											else if (item == 2) {
												showUkrainianlanguageHomework();
											}
										} while (item != 3);
									}break;
									case 2: {
										break;
									}
									}
								} while (categoryItem != 2);
						}break;
						case 4: {
							CLEAR
								cout << "\t\t\tI am exploring the world" << endl;
							do {
								cout << "Choose action: " << endl;
								work_menu();
								cin >> categoryItem;
								switch (categoryItem) {
								case 1: {
									CLEAR
										int item = 0;
									do {
										lessonMenu();
										cin >> item;
										if (item == 1) {
											showExploring_worldTheory();
										}
										else if (item == 2) {
											showExploring_worldHomework();
										}
									} while (item != 3);
								}break;
								case 2: {
									CLEAR
										int item = 0;
									do {
										testMenu();
										cin >> item;
										switch (item) {
										case 1: {
											showExploring_worldTrainingTests();
											cout << "Do you want to pass one of the tests? 'y' or 'n':_" << endl;
											string ansvPassTest = "";
											cin >> ansvPassTest;
											if (ansvPassTest == "y") {
												passTest();
												
											}
											else {
												break;
											}
										}break;
										case 2: {
											showExploring_worldControlTests();
											cout << "Do you want to pass one of the tests? 'y' or 'n':_" << endl;
											string ansvPassTest = "";
											cin >> ansvPassTest;
											if (ansvPassTest == "y") {
												passTest();
												
											}
											else {
												break;
											}
										}break;
										case 3: {
											break;
										}
										}
									} while (item != 3);
								}break;
								case 3: {
									break;
								}
								}
							} while (categoryItem != 3);
						}break;
						case 5: {
							CLEAR
								//My marks
								cout << "\n\t\t\tYour success: " << endl;
							showMarks();
						}break;
						case 6: {
							CLEAR
								editStudent();
						}break;
						case 7: {
							CLEAR
								cout << "\n\n\t\t\tGoodbye!" << endl;
							break;
						}
						}
					} while (action != 7);
				
			}break;
			case 2: {
				Add_Student();
				initStudents();
			}break;
			case 0: {
				break;
			}
		  }
		}break;
		case 2: {
			CLEAR
			int ansverLogAdmin = 0;
			do {
				cout << "\n\n\n\n\t\t\t1. Log in" << endl;
				cout << "\n\t\t\t2. Registration" << endl;
				cout << "\n\t\t\t0. Back" << endl;

				cin >> ansverLogAdmin;
				switch (ansverLogAdmin) {
				case 1: {
					CLEAR
					initAdmins();
					//login_Admin();
					
					do {
						adminMenu();
						cout << "Select action: " ;
						cin >> action;
						switch (action) {
						case 1: {
							showStudent();
						}break;
						case 2: {
							search_by_surname();
						}break;
						case 3: {
							addMark();
							initMarks();
						}break;
						case 4: {
							CLEAR
							string ansvAddLesson = "";
							cout << "\n\n\tDo you want to add new thery or homework? 'y' or 'n':_";
							cin >> ansvAddLesson;
							if (ansvAddLesson == "y") {
								addNewLesson();
							}
							else {
								break;
							}
						}break;
						case 5: {
							CLEAR
								string ansvAddTest = "";
							cout << "\n\n\tDo you want to add new test? 'y' or 'n':_";
							cin >> ansvAddTest;
							if (ansvAddTest == "y") {
								addTest();
							}
							else {
								break;
							}
						}break;
						case 6: {
							break;
						}

						}
					} while (action != 6);
				}break;
				case 2: {
					addAdmin();
				}break;
				case 0: {
					break;
				}
				}
			} while (ansverLogAdmin != 0);
		}break;
		
		case 0: {
			CLEAR
			cout << "\n\n\n\t\t\tGoodbye!\n\n\n" << endl;
			break;
		}
	  }	
	} while (Entrance !=0);
				

	system ("pause");
		return 0;
}
											                                                  