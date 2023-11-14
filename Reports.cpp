//Class: CMSC226 CRN 21504
//Program : Project 2.1
//Instructor: Ping-Wei Tsai
//Summary of Description : A basic menu for reports of books
//Due Date : 09.25.2023
//Integrity Pledge : I pledge that I have completed the programming assignment independently.
//I have not copied the code from a student or any source.
//Student name : Jacob Hauptman
#include "Combined.h"
#include <iostream>
#include <iomanip> 
#include <ctime>
using namespace std;
void reports() {
	char option;
	while (true) {
		cout << setw(50) << "Serendipity Booksellers\n";
		cout << setw(43) << "Reports\n\n";
		cout << setw(46) << "- Inventory listing\n";
		cout << setw(54) << "- Inventory wholesale value\n";
		cout << setw(51) << "- Inventory retail value\n";
		cout << setw(48) << "- Listing by quantity\n";
		cout << setw(44) << "- Listing by cost\n";
		cout << setw(43) << "- Listing by age\n";
		cout << setw(49) << "- Return to main menu\n\n";
		cout << setw(47) << "Enter your choice: "; cin >> option;
		if (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6' && option != '7') {
			cout << setw(69) << "Please enter a number in the range 1 - 7\n";
		}
		switch (option) {
		case '1':
			cout << setw(47) << "You selected item 1\n\n\n";
			repListing();
			break;
		case '2':
			cout << setw(47) << "You selected item 2\n\n\n";
			repWholesale();
			break;
		case '3':
			cout << setw(47) << "You selected item 3\n\n\n";
			repRetail();
			break;
		case '4':
			cout << setw(47) << "You selected item 4\n\n\n";
			repQty();
			break;
		case '5':
			cout << setw(47) << "You selected item 5\n\n\n";
			repCost();
			break;
		case '6':
			cout << setw(47) << "You selected item 6\n\n\n";
			repAge();
			break;
		case '7':
			cout << setw(47) << "You selected item 7\n\n\n";
			MainMenu();
			break;
		}
		cout << "\n";
	}
}

void repListing() {
	cout << "You selected Inventory Listing.\n\n";
	cout << setw(10) << " "
		<< "Entire Inventory " << setw(10) << "\n\n";
	for (int i = 0; i < MAX_BOOKS; i++) {
		if (books[i].getTitle() != "\0") {
			cout << endl << endl << "Book " << i + 1;
			cout << "\n==================================\n"
				<< "Title: " << books[i].getTitle() //bookTitle[i]
				<< "\nISBN : " << books[i].getISBN() //isbn[i]
				<< "\nAuthor: " << books[i].getAuthor() //author[i]
				<< "\nPublisher: " << books[i].getPub() //publisher[i]
				<< "\nDate Added: " << books[i].getDateAdded() //dateAdded[i]
				<< "\nQuantity on Hand: " << books[i].getQty() //qtyOnHand[i]
				<< "\nWholesale Cost: $" << books[i].getWholesale() //wholesale[i]
				<< "\nRetail Price: $" << books[i].getRetail() //retail[i]
				<< "\n==================================\n";
		}
	}
	currentTime();
}

void repWholesale() {
	cout << "You selected Inventory Wholesale Value\n";
	double total = 0;
	for (int i = 0; i < MAX_BOOKS; i++) {
		if (books[i].getTitle() != "\0") {
			cout << endl << endl << "Book " << i + 1;
			cout << "\n==================================\n"
				<< "Title: " << books[i].getTitle() 
				<< "\nISBN : " << books[i].getISBN() 
				<< "\nQuantity on Hand: " << books[i].getQty() 
				<< "\nWholesale Cost: $" << books[i].getWholesale() 
				<< "\n==================================\n";
			total += books[i].getWholesale() * books[i].getQty();
		}
	}
	cout << "Total wholesale value is $" << total << "\n";
	currentTime();
}

void repRetail() {
	cout << "You selected Inventory Listing.\n\n";
	double total = 0;
	for (int i = 0; i < MAX_BOOKS; i++) {
		if (books[i].getTitle() != "\0") {
			cout << "\n\n" << "Book " << i + 1;
			cout << "\n==================================\n"
				<< "Title: " << books[i].getTitle() //bookTitle[i]
				<< "\nISBN : " << books[i].getISBN() //isbn[i]
				<< "\nQuantity on Hand: " << books[i].getQty() //qtyOnHand[i]
				<< "\nRetail Price: $" << books[i].getRetail() //retail[i]
				<< "\n==================================\n";
			//	total += retail[i] * qtyOnHand[i];
			total += books[i].getRetail() * books[i].getQty();
		}
	}
	cout << "Total retail value is $" << total << "\n";
	currentTime();
}

void repQty() {
	cout << "You selected Listing by Quantity\n";
	int count = getCount();
	long double* qtyOnHandToDoubles = new long double[count];
	for (int i = 0; i < count; i++) {
		qtyOnHandToDoubles[i] = books[i].getQty(); //qtyOnHand[i];
	}
	int* sort = bubbleSort(qtyOnHandToDoubles, count);
	for (int i = 0; i < count; i++) {
		cout << "\n\n" << "Book " << i + 1;
		cout << "\n==================================\n"
			<< "Title: " << books[sort[i]].getTitle() //bookTitle[sort[i]]
			<< "\nISBN : " << books[sort[i]].getISBN() //isbn[sort[i]]
			<< "\nQuantity on Hand: " << books[sort[i]].getQty() //qtyOnHand[sort[i]]
			<< "\nRetail Price: $" << books[sort[i]].getRetail() //retail[sort[i]]
			<< "\n==================================\n";
	}
	currentTime();
	delete[] qtyOnHandToDoubles;
}


void repCost() {
	cout << "You selected Listing by Cost\n";
	cout << "You selected Listing by Quantity\n";
	int count = getCount();
	long double* costDoubles = new long double[count];
	for (int i = 0; i < count; i++) {
		costDoubles[i] = books[i].getWholesale(); //wholesale[i];
	}
	int* sort = bubbleSort(costDoubles, count);
	for (int i = 0; i < count; i++) {
		cout << "\n\n" << "Book " << i + 1;
		cout << "\n==================================\n"
			<< "Title: " << books[sort[i]].getTitle() //bookTitle[sort[i]]
			<< "\nISBN : " << books[sort[i]].getISBN() //isbn[sort[i]]
			<< "\nQuantity on Hand: " << books[sort[i]].getQty() //qtyOnHand[sort[i]]
			<< "\nWholesale Cost: $" << books[sort[i]].getWholesale() //wholesale[sort[i]] 
			<< "\n==================================\n";
	}
	currentTime();
	delete[] costDoubles;
}


void repAge() {
	cout << "You selected Listing by Age\n";
	int count = getCount();
	long double* dates = new long double[count];
	for (int i = 0; i < count; i++) {
		int month, day, year;
		sscanf(books[i].getDateAdded().c_str(), "%d.%d.%d", &month, &day, &year);
		long long dateValue = year * 10000 + month * 100 + day;
		dates[i] = dateValue;
	}

	int* sort = bubbleSort(dates, count);
	for (int i = count - 1; i >= 0; i--) {
		cout << "\n\n" << "Book " << count - i;
		cout << "\n==================================\n"
			<< "Title: " << books[sort[i]].getTitle() //bookTitle[sort[i]]
			<< "\nISBN : " << books[sort[i]].getISBN() //isbn[sort[i]]
			<< "\nQuantity on Hand: " << books[sort[i]].getQty() //qtyOnHand[sort[i]]
			<< "\nDate Added: " << books[sort[i]].getDateAdded() //dateAdded[sort[i]]
			<< "\n==================================\n";
	}
	delete[] dates;
	currentTime();
}



void currentTime() {
	time_t currentTime = time(0);
	tm* localTime = localtime(&currentTime);
	cout << "\t\t\t\t\t\t\t\tMonth\tDay\tYear\tTime\n";
	cout << "\t\t\t\t\t\t\t\t" << localTime->tm_mon << "\t" << localTime->tm_mday << "\t" << localTime->tm_year + 1900 << "\t" << localTime->tm_hour << ":" << localTime->tm_min << "\n";
}

int* bubbleSort(long double arr[], int n) {
	int* index = new int[n];
	for (int i = 0; i < n; i++) {
		index[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[index[j]] < arr[index[j + 1]]) {
				int temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
		}
	}
	return index;
}


int getCount() {
	int count = 0;
	for (int i = 0; i < MAX_BOOKS; i++) {
		if (books[i].getTitle() != "\0") {
			count = i + 1;
		}
	}
	return count;
}
