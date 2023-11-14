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
		if (books[i].getTitle() == "\0") {
			cout << "Book title: ";
			char tempTitle[51];
			cin.getline(tempTitle, 51);
			strUpper(tempTitle);
			books[i].setTitle(tempTitle);

			cout << "ISBN #: ";
			char tempIsbn[14];
			cin.getline(tempIsbn, 14);
			strUpper(tempIsbn);
			books[i].setISBN(tempIsbn);

			cout << "Author's name: ";
			char tempAuthor[31];
			cin.getline(tempAuthor, 31);
			strUpper(tempAuthor);
			books[i].setAuthor(tempAuthor);

			cout << "Publisher's name: ";
			char tempPublisher[31];
			cin.getline(tempPublisher, 31);
			strUpper(tempPublisher);
			books[i].setPub(tempPublisher);

			cout << "Date: ";
			char tempDate[11];
			cin.getline(tempDate, 11);
			books[i].setDateAdded(tempDate);

			cout << "Quantity of book: ";
			cin >> input;
			books[i].setQty(input);

			cout << "Wholesale cost: ";
			cin >> input;
			books[i].setWholesale(input);

			cout << "Retail cost: ";
			cin >> input;
			books[i].setRetail(input);
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
			<< "\nBook Title: " << books[indexes[bookNumber - 1]].getTitle() //bookTitle[indexes[bookNumber - 1]]
			<< "\nISBN #: " << books[indexes[bookNumber - 1]].getISBN() // isbn[indexes[bookNumber - 1]]
			<< "\nAuthor's name: " << books[indexes[bookNumber - 1]].getAuthor() //author[indexes[bookNumber - 1]]
			<< "\nPublisher's name: " << books[indexes[bookNumber - 1]].getPub() //publisher[indexes[bookNumber - 1]]
			<< "\nDate: " << books[indexes[bookNumber - 1]].getDateAdded() //dateAdded[indexes[bookNumber - 1]]
			<< "\nQuantity of book: " << books[indexes[bookNumber - 1]].getQty() // qtyOnHand[indexes[bookNumber - 1]]
			<< "\nWholesale cost: " << books[indexes[bookNumber - 1]].getWholesale() //wholesale[indexes[bookNumber - 1]]
			<< "\nRetail cost: " << books[indexes[bookNumber - 1]].getRetail() //retail[indexes[bookNumber - 1]]
			<< "\n\nWhat would you like to edit?";
	}
	string tempIsbn;
	char tempTitle[51];
	char tempAuthor[31];
	char tempPub[31];
	char tempDate[11];
	int tempQty;
	double tempRetail;
	double tempWholesale;

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
			cin.getline(tempTitle, 51);
			strUpper(tempTitle);
			books[indexes[bookNumber - 1]].setTitle(tempTitle);
			break;
		case 2:
			cout << "Enter the updated ISBN: #";
			cin >> tempIsbn;
			books[indexes[bookNumber - 1]].setISBN(tempIsbn);
			break;
		case 3:
			cout << "Enter the updated author: ";
			cin.getline(tempAuthor, 31);
			strUpper(tempAuthor);
			books[indexes[bookNumber - 1]].setAuthor(tempAuthor);
			break;
		case 4:
			cout << "Enter the updated publisher: ";
			cin.getline(tempPub, 31);
			strUpper(tempPub);
			books[indexes[bookNumber - 1]].setPub(tempPub);
			break;
		case 5:
			cout << "Enter the updated date added: "; cin.ignore(); cin.getline(tempDate, 11);
			books[indexes[bookNumber - 1]].setDateAdded(tempDate);
			break;
		case 6:
			cout << "Enter the updated quantity of books: "; cin >> tempQty;
			books[indexes[bookNumber - 1]].setQty(tempQty);
			break;
		case 7:
			cout << "Enter the updated wholesale cost: "; cin >> tempWholesale;
			books[indexes[bookNumber - 1]].setWholesale(tempWholesale);
			break;
		case 8:
			cout << "Enter the updated retail cost: "; cin >> tempRetail;
			books[indexes[bookNumber - 1]].setRetail(tempRetail);
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
			books[i].setTitle(books[i + 1].getTitle());
			//strcpy(isbn[i], isbn[i + 1]);
			books[i].setISBN(books[1 + i].getISBN());
		//	strcpy(author[i], author[i + 1]);
			books[i].setAuthor(books[i + 1].getISBN());
		//	strcpy(publisher[i], publisher[i + 1]);
			books[i].setPub(books[i + 1].getPub());
			//strcpy(dateAdded[i], dateAdded[i + 1]);
			books[i].setDateAdded(books[i + 1].getDateAdded());
			books[i].setQty(books[1 + i].getQty());
			books[i].setWholesale(books[i + 1].getWholesale());
			books[i].setRetail(books[i + 1].getRetail());
			//qtyOnHand[i] = qtyOnHand[i + 1];
			//wholesale[i] = wholesale[i + 1];
			//retail[i] = retail[i + 1];
		}
		int lastIndex = MAX_BOOKS - 1;
		//strcpy(bookTitle[lastIndex], "");
		books[lastIndex].setTitle("");
	//	strcpy(isbn[lastIndex], "");
		books[lastIndex].setISBN("");
		//strcpy(author[lastIndex], "");
		books[lastIndex].setAuthor("");
		//strcpy(publisher[lastIndex], "");
		books[lastIndex].setPub("");
		//strcpy(dateAdded[lastIndex], "");
		books[lastIndex].setDateAdded("");
		books[lastIndex].setQty(0);
		books[lastIndex].setWholesale(0);
		books[lastIndex].setRetail(0);
		//qtyOnHand[lastIndex] = 0;
		//wholesale[lastIndex] = 0.0;
		//retail[lastIndex] = 0.0;
		cout << "Book deleted successfully.\n";
	}
}



void strUpper(char* input) {
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
		if (strstr(books[i].getTitle().c_str(), searchSubstringCStr)) {
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
			<< "\n\nBook Title: " << books[indexs[i]].getTitle() // bookTitle[indexs[i]]
			<< "\nISBN #: " << books[indexs[i]].getISBN() //isbn[indexs[i]]
			<< "\nAuthor's name: " << books[indexs[i]].getAuthor() //author[indexs[i]]
			<< "\nPublisher's name: " << books[indexs[i]].getPub() //publisher[indexs[i]]
			<< "\nDate: " << books[indexs[i]].getDateAdded() //dateAdded[indexs[i]]
			<< "\nQuantity of book: #" << books[indexs[i]].getQty() //qtyOnHand[indexs[i]]
			<< "\nWholesale cost: $" << books[indexs[i]].getWholesale() //wholesale[indexs[i]]
			<< "\nRetail cost: $" << books[indexs[i]].getRetail(); //retail[indexs[i]];
	}


}
