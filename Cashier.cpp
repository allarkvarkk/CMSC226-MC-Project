//Class: CMSC226 CRN 21504
//Program : Project 2.1
//Instructor: Ping-Wei Tsai
//Summary of Description : checkout with placeholder values to see functionality
//Due Date : 09.25.2023
//Integrity Pledge : I pledge that I have completed the programming assignment independently.
//I have not copied the code from a student or any source.
//Student name : Jacob Hauptman
#include "Combined.h"
#include <iostream>
#include <iomanip>
#include <vector>
	using namespace std;
void cashier() {
	string ISBN;
	short index, qty;
	vector <string> shoppingCart;
	float subtotal = 0, total = 0, tax = 0;
	const float taxPercentage = 0.06;
	bool isValidISBN;
	cout << "\tSerendipity Book\n";
	cout << "\tSellers\n\n\n\n";
	while (true) {
		isValidISBN = false;
		while (!isValidISBN) {
			cout << "Please enter the ISBN number: "; cin >> ISBN;
			for (int i = 0; i < MAX_BOOKS; i++) {
				if (ISBN == isbn[i]) {
					index = i;
					isValidISBN = true;
					break;
				}
				if (i == MAX_BOOKS - 1) {
					cout << "\tError !! invalid ISBN. Please try again\n";
					break;
				}
			}
		}
		qty = 100;
		while (qty > qtyOnHand[index]) {
			cout << "\nPlease enter the quantity you wish to purchase: "; cin >> qty;
			cin.ignore();
			if (qty <= qtyOnHand[index]) {
				break;
			}
			cout << "\nError!! Invalid quantity. Please try again\n";
		}
			shoppingCart.push_back("\t" + to_string(qty) + "\t\t" + isbn[index] + "\t" + bookTitle[index] + "\t\t$" + to_string(retail[index]));

		subtotal += retail[index] * qty;
		tax = subtotal * taxPercentage;
		total = subtotal + tax;
		cout << "\tDate: " << dateAdded[index];
		cout << "\n\tQuantity: " << qtyOnHand[index];
		cout << "\n\tISBN: " << isbn[index];
		cout << "\n\tTitle: " << bookTitle[index];
		cout << "\n\tPrice: $" << retail[index];
		cout << "\n\n\tQuantity\t\tISBN\t\tTitle\t\tPrice\n";
		cout << "------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < shoppingCart.size(); i++) {
			if (shoppingCart[i] != "") {
				cout << shoppingCart[i] << "\n";
			}
		}
		cout << "\n\n\n" << setw(14) << "Sub-total: \t" << setw(6) << fixed << setprecision(2) << "$" << subtotal;
		cout << "\n" << setw(14) << "Tax: \t" << setw(6) << fixed << setprecision(2) << "$" << tax;
		cout << "\n" << setw(14) << "Total: \t" << setw(6) << fixed << setprecision(2) << "$" << total;
		cout << "\n\nIs that all? (Y) or do you have another item to add? (N)\n";
		string finished;
		cin >> finished;
		if (finished == "Y" || finished == "y")
		{
			break;
		}
		continue;
	}
	cout << "\n\nThank You for Shopping at Serendipity!";
}
