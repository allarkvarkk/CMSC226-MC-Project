//Class: CMSC226 CRN 21504
//Program : Project 2.1
//Instructor: Ping-Wei Tsai
//Summary of Description : book info catagories formatted/listed
//Due Date : 09.25.2023
//Integrity Pledge : I pledge that I have completed the programming assignment independently.
//I have not copied the code from a student or any source.
//Student name : Jacob Hauptman
#include <iostream>
#include <iomanip>
using namespace std;

void bookInfo(char isbn[], char title[], char author[], char publisher[], char date[], int qty, double wholesale, double retail) {
	cout << setw(50) << "Serendipity Booksellers\n";
	cout << setw(53) << "Booksellers Book Information\n\n";
	cout << "\tISBN: " << isbn;
	cout << "\n\tTitle: t" << title;
	cout << "\n\tAuthor: " << author;
	cout << "\n\tPublisher: " << publisher;
	cout << "\n\tDate Added: " << date;
	cout << "\n\tQuantity-On-Hand: " << qty;
	cout << "\n\tWholesale Cost: " << wholesale;
	cout << "\n\tRetail Price: " << retail;
}


