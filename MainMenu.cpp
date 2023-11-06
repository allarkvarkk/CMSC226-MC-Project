//Class: CMSC226 CRN 21504
//Program : Project 2.1
//Instructor: Ping-Wei Tsai
//Summary of Description : A basic main menu
//Due Date : 09.25.2023
//Integrity Pledge : I pledge that I have completed the programming assignment independently.
//I have not copied the code from a student or any source.
//Student name : Jacob Hauptman
#include <iostream>
#include <iomanip>
#include "Combined.h";

using namespace std;
char bookTitle[20][51] = {"BONE - DRAGONSLAYER","FRANKENSTEIN: OR THE MODERN PROMETHEUS","1984","FENCES","CRIME AND PUNISHMENT","LORD OF THE FLIES","ONE SHADOW ON THE WALL",
"THE METAMORPHOSIS","THE HOBBIT: DELUX POCKET EDITION","THE SON OF NEPTUNE","THE LIGHTNING THIEF","THE GOLDEN DOOR","SPY SCHOOL","EVIL SPY SCHOOL","BELLY UP"};
char isbn[20][14] = {"0439706378","1081511206","9780451524935","0452264014","0140449132","0399501487","1481462962","1557427666", "0544045521", "1423140591","0786856297","9780545429900",
"1442421835","1442494905","9781416987314" };
char author[20][51] = {"JEFF SMITH","MARY SHELLEY","GEORGE ORWELL","AUGUST WILSON","FYODOR DOSTOYEVSKY","WILLIAM GOLDING","LEAH HENDERSON","FRANZ KAFKA","J.R.R. TOLKIEN","RICK RIORDAN",
"RICK RIORDAN","EMILY RODDA","STUART GIBBS","STUART GIBBS","STUART GIBBS"};
char publisher[20][42] = {"GRAPHIX","LACKINGTON","SECKER & WARBURG","NEW YORK: PLUME","THE RUSSIAN MESSENGER (RUSSKIY VESTNIK)","PENGUIN BOOKS","SIMON & SCHUSTER BOOKS FOR YOUNG READERS",
"KURT WOLFF VERLAG","GEORGE ALLEN & UNWIN LTD","MIRAMAX BOOKS (DISNEY-HYPERION)","MIRAMAX BOOKS (DISNEY-HYPERION)","SCHOLASTIC","SIMON & SCHUSTER BOOKS FOR YOUNG READERS",
"SIMON & SCHUSTER BOOKS FOR YOUNG READERS","SIMON & SCHUSTER BOOKS FOR YOUNG READERS"};
char dateAdded[20][11] = {"09.18.2023", "09.18.2021", "09.18.2023", "09.18.2023", "09.18.2023", "09.18.2023", "09.18.2023", "09.18.2023", "09.18.2023",
	"09.18.2023", "09.18.2022", "09.18.2023", "09.18.2023", "09.18.2023", "09.18.2023" };
int qtyOnHand[MAX_BOOKS] = { 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 2, 4, 1 };
double wholesale[MAX_BOOKS] = { 7.69, 6.00, 7.11, 12.33, 13.99, 6.29, 10.41, 3.99, 15.99, 11.39, 16.89, 13.97, 8.99, 8.26, 13.60 };
double retail[MAX_BOOKS] = { 9.99, 8.20, 9.30, 18.32, 16.75, 10.09, 16.00, 6.20, 21.50, 15.00, 23.20, 17.30, 13.15, 12.97, 18.95 };

int main() {
	MainMenu();
	return 0;
}

void MainMenu() {
	char option;
	while (true) {
		cout << setw(50) << "Serendipity Booksellers\n\n";
		cout << setw(43) << "Main Menu\n\n";
		cout << setw(43) << "- Cashier Module\n";
		cout << setw(54) << "- Inventory Database Module\n";
		cout << setw(42) << "- Report Module\n";
		cout << setw(34) << "- Exit\n\n";
		cout << setw(47) << "Enter your choice: "; cin >> option;
		if (option < '1' || option > '4') {
			cout << setw(69) << "Please enter a number in the range 1 - 4\n";
			continue;
		}


		switch (option) {
		case '1':
			cout << setw(47) << "You selected item 1\n";
			cashier();
			break;
		case '2':
			cout << setw(47) << "You selected item 2\n";
			invMenu();
			break;
		case '3':
			cout << setw(47) << "You selected item 3\n";
			reports();
			break;
		case '4':
			cout << setw(47) << "You selected item 4\n";
			exit(0);
			break;
		}
		cout << "\n";
	}
}

