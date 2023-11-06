//Class: CMSC226 CRN 21504
//Program : Project 2.1
//Instructor: Ping-Wei Tsai
//Summary of Description : A basic menu for inventory
//Due Date : 09.25.2023
//Integrity Pledge : I pledge that I have completed the programming assignment independently.
//I have not copied the code from a student or any source.
//Student name : Jacob Hauptman
#include "Combined.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
void invMenu() {
	char option;
	while (true) {
		cout << setw(50) << "Serendipity Booksellers\n";
		cout << setw(48) << "Inventory Database\n\n";
		cout << setw(43) << "- Look up a book\n";
		cout << setw(39) << "- Add a book\n";
		cout << setw(49) << "- Edit a book's record\n";
		cout << setw(42) << "- Delete a book\n";
		cout << setw(53) << "- Return to the main menu\n\n";
		cout << setw(47) << "Enter your choice: "; cin >> option;
	/*	if (option < '1' || option > '5') {
			cout << setw(69) << "Please enter a number in the range 1 - 5\n";
			continue;
		}*/
		switch (option) {
		case '1':
			cout << setw(47) << "You selected item 1\n";
			lookUpBook();
			break;
		case '2':
			cout << setw(47) << "You selected item 2\n";
			addBook();
			break;
		case '3':
			cout << setw(47) << "You selected item 3\n";
			editBook();
			break;
		case '4':
			cout << setw(47) << "You selected item 4\n";
			deleteBook();
			break;
		case '5':
			cout << setw(47) << "You selected item 5\n";
			MainMenu();
			break;
		default:
			cout << setw(69) << "Please enter a number in the range 1 - 5\n";
			continue;
		}
		cout << "\n";
	}
}

void lookUpBook() {
	cout << "You selected Look Up Book\n";
	string searchSubstring;
	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, searchSubstring);
	displayWithIndexes(searchBookBySubstring(searchSubstring));
}


void addBook() {
	cout << "You selected Add Book\n";
	double input;
	cin.ignore();
	for (int i = 0; i < 20; i++) {
		if (bookTitle[i][0] == '\0') {
			cout << "Book title: ";
			cin.getline(bookTitle[i], 51);
			strUpper(bookTitle[i]);

			cout << "ISBN #: ";
			cin.getline(isbn[i], 14);
			strUpper(isbn[i]);

			cout << "Author's name: ";
			cin.getline(author[i], 31);
			strUpper(author[i]);

			cout << "Publisher's name: ";
			cin.getline(publisher[i], 31);
			strUpper(publisher[i]);

			cout << "Date: ";
			cin.getline(dateAdded[i], 11);

			cout << "Quantity of book: ";
			cin >> input;
			qtyOnHand[i] = (int)input;

			cout << "Wholesale cost: ";
			cin >> input;
			wholesale[i] = input;

			cout << "Retail cost: ";
			cin >> input;
			retail[i] = input;
			break;
		}
	}
	cout << "Inventory full..." << endl;
}



void editBook() {
	cout << "You selected Edit Book\n";
	string search;
	int bookNumber = 100;
	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, search);
	vector<int> indexes = searchBookBySubstring(search);
	bool onlyOption = false;
	displayWithIndexes(indexes);
	if (indexes.size() > 1) {
		while (bookNumber > indexes.size()) {
			cout << "\n\n\nWhich book did you want to edit? #"; cin >> bookNumber;
			if (bookNumber > indexes.size()) {
				cout << "Please enter a valid book number\n";
			}
		}
	}
	if (indexes.size() == 1) {
		onlyOption = true;
		bookNumber = 1;
	}
	if (!onlyOption) {
		cout << "\n\n\n<BOOK SELECTED FOR EDITING>"
			<< "\nBook Title: " << bookTitle[indexes[bookNumber - 1]]
			<< "\nISBN #: " << isbn[indexes[bookNumber - 1]]
			<< "\nAuthor's name: " << author[indexes[bookNumber - 1]]
			<< "\nPublisher's name: " << publisher[indexes[bookNumber - 1]]
			<< "\nDate: " << dateAdded[indexes[bookNumber - 1]]
			<< "\nQuantity of book: " << qtyOnHand[indexes[bookNumber - 1]]
			<< "\nWholesale cost: " << wholesale[indexes[bookNumber - 1]]
			<< "\nRetail cost: " << retail[indexes[bookNumber - 1]]
			<< "\n\nWhat would you like to edit?";
	}
	while (true) {
		int option = 0;
		cout << "\n1. Book title"
			<< "\n2. ISBN"
			<< "\n3. Author's name"
			<< "\n4. Publisher's name"
			<< "\n5. Date added"
			<< "\n6. Quantity of books"
			<< "\n7. Wholesale cost"
			<< "\n8. Retail cost\n";
		cin >> option;
		cin.ignore();
		switch (option) {
		case 1:
			cout << "Enter the updated book title: ";
			cin.getline(bookTitle[indexes[bookNumber - 1]], 51);
			strUpper(bookTitle[indexes[bookNumber - 1]]);
			break;
		case 2:
			cout << "Enter the updated ISBN: #";
			cin >> isbn[indexes[bookNumber - 1]];
			break;
		case 3:
			cout << "Enter the updated author: ";
			cin.getline(author[indexes[bookNumber - 1]], 31);
			strUpper(author[indexes[bookNumber - 1]]);
			break;
		case 4:
			cout << "Enter the updated publisher: "; 
			cin.getline(publisher[indexes[bookNumber - 1]], 31);
			strUpper(publisher[indexes[bookNumber - 1]]);
			break;
		case 5:
			cout << "Enter the updated date added: "; cin.ignore(); cin.getline(dateAdded[indexes[bookNumber - 1]], 11);
			break;
		case 6:
			cout << "Enter the updated quantity of books: "; cin >> qtyOnHand[indexes[bookNumber - 1]];
			break;
		case 7:
			cout << "Enter the updated wholesale cost: "; cin >> wholesale[indexes[bookNumber - 1]];
			break;
		case 8:
			cout << "Enter the updated retail cost: "; cin >> retail[indexes[bookNumber - 1]];
			break;
		default:
			cout << "Invalid input, please try again\n";
			continue;
		}
		char choice = 'N';
		cout << "Would you like to edit anything else in this book? (Y/N)\n"; cin >> choice;
		if (choice == 'N' || choice == 'n') {
			break;
		}
	}
}


void deleteBook() {
	cout << "You selected Delete Book\n";
	string search;
	int bookNumber = 0;
	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, search);
	vector<int> indexes = searchBookBySubstring(search);

	if (indexes.empty()) {
		cout << "No matching book titles found." << endl;
		return;
	}

	cout << "Matching books found:" << endl;
	displayWithIndexes(indexes);

	if (indexes.size() == 1) {
		bookNumber = 1;
	}
	else {
		while (bookNumber < 1 || bookNumber > indexes.size()) {
			cout << "\nEnter the number of the book you want to delete: ";
			cin >> bookNumber;
			if (bookNumber < 1 || bookNumber > indexes.size()) {
				cout << "Please enter a valid book number.\n";
			}
		}
	}

	char option;
	cout << "\nPlease confirm, would you like to delete this book? (Y/N): ";
	cin >> option;

	if (option == 'Y' || option == 'y') {
		int indexToDelete = indexes[bookNumber - 1];
		for (int i = indexToDelete; i < MAX_BOOKS - 1; i++) {
			strcpy(bookTitle[i], bookTitle[i + 1]);
			strcpy(isbn[i], isbn[i + 1]);
			strcpy(author[i], author[i + 1]);
			strcpy(publisher[i], publisher[i + 1]);
			strcpy(dateAdded[i], dateAdded[i + 1]);
			qtyOnHand[i] = qtyOnHand[i + 1];
			wholesale[i] = wholesale[i + 1];
			retail[i] = retail[i + 1];
		}
		int lastIndex = MAX_BOOKS - 1;
		strcpy(bookTitle[lastIndex], "");
		strcpy(isbn[lastIndex], "");
		strcpy(author[lastIndex], "");
		strcpy(publisher[lastIndex], "");
		strcpy(dateAdded[lastIndex], "");
		qtyOnHand[lastIndex] = 0;
		wholesale[lastIndex] = 0.0;
		retail[lastIndex] = 0.0;
		cout << "Book deleted successfully.\n";
	}
}


void strUpper(char *input) {
	for (int i = 0; i < (int)strlen(input); i++) {
		input[i] = toupper(input[i]);
	}
}

vector<int> searchBookBySubstring(const string& searchSubstring) {
	vector<int> indexes;
	char searchSubstringCStr[51];
	strncpy(searchSubstringCStr, searchSubstring.c_str(), sizeof(searchSubstringCStr));
	searchSubstringCStr[sizeof(searchSubstringCStr) - 1] = '\0';
	strUpper(searchSubstringCStr);
	bool found = false;
	for (int i = 0; i < 20; i++) {
		if (strstr(bookTitle[i], searchSubstringCStr)) {
			indexes.push_back(i);
			found = true;
		}
	}

	if (!found) {
		cout << "No matching book titles found." << endl;
	}
	return indexes;
}


void displayWithIndexes(vector<int> indexs) {
	
	for (int i = 0; i < indexs.size(); i++) {
		cout << "\n\nBook " << i + 1
	<< "\n==================================\n"
	<< "\n\nBook Title: " << bookTitle[indexs[i]]
	<< "\nISBN #: " << isbn[indexs[i]]
	<< "\nAuthor's name: " << author[indexs[i]]
	<< "\nPublisher's name: " << publisher[indexs[i]]
	<< "\nDate: " << dateAdded[indexs[i]]
	<< "\nQuantity of book: #" << qtyOnHand[indexs[i]]
	<< "\nWholesale cost: $" << wholesale[indexs[i]]
	<< "\nRetail cost: $" << retail[indexs[i]];
	}


}
