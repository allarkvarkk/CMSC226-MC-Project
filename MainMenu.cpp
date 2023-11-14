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

BookData books[MAX_BOOKS];

int main() {
	books[0].setISBN("0439706378");
	books[0].setTitle("BONE - DRAGONSLAYER");
	books[0].setAuthor("JEFF SMITH");
	books[0].setPub("GRAPHIX");
	books[0].setDateAdded("09.18.2023");
	books[0].setQty(1);
	books[0].setWholesale(7.69);
	books[0].setRetail(9.99);

	books[1].setISBN("1081511206");
	books[1].setTitle("FRANKENSTEIN: OR THE MODERN PROMETHEUS");
	books[1].setAuthor("MARY SHELLEY");
	books[1].setPub("LACKINGTON, HUGHES, HARDING, MAVOR & JONES");
	books[1].setDateAdded("09.18.2023");
	books[1].setQty(2);
	books[1].setWholesale(6.00);
	books[1].setRetail(8.20);

	books[2].setISBN("9780451524935");
	books[2].setTitle("1984");
	books[2].setAuthor("GEORGE ORWELL");
	books[2].setPub("SECKER & WARBURG");
	books[2].setDateAdded("09.18.2023");
	books[2].setQty(2);
	books[2].setWholesale(7.11);
	books[2].setRetail(9.30);

	books[3].setISBN("0452264014");
	books[3].setTitle("FENCES");
	books[3].setAuthor("AUGUST WILSON");
	books[3].setPub("NEW YORK: PLUME");
	books[3].setDateAdded("09.18.2023");
	books[3].setQty(1);
	books[3].setWholesale(12.33);
	books[3].setRetail(8.32);

	books[4].setISBN("0140449132");
	books[4].setTitle("CRIME AND PUNISHMENT");
	books[4].setAuthor("FYODOR DOSTOYEVSKY");
	books[4].setPub("THE RUSSIAN MESSENGER (RUSSKIY VESTNIK)");
	books[4].setDateAdded("09.18.2023");
	books[4].setQty(2);
	books[4].setWholesale(13.99);
	books[4].setRetail(16.75);

	books[5].setISBN("0399501487");
	books[5].setTitle("LORD OF THE FLIES");
	books[5].setAuthor("WILLIAM GOLDING");
	books[5].setPub("PENGUIN BOOKS");
	books[5].setDateAdded("09.18.2023");
	books[5].setQty(2);
	books[5].setWholesale(6.29);
	books[5].setRetail(10.09);


	books[6].setISBN("1481462962");
	books[6].setTitle("ONE SHADOW ON THE WALL");
	books[6].setAuthor("LEAH HENDERSON");
	books[6].setPub("SIMON & SCHUSTER BOOKS FOR YOUNG READERS");
	books[6].setDateAdded("09.18.2023");
	books[6].setQty(1);
	books[6].setWholesale(10.41);
	books[6].setRetail(16.00);

	books[7].setISBN("1557427666");
	books[7].setTitle("THE METAMORPHOSIS");
	books[7].setAuthor("FRANZ KAFKA");
	books[7].setPub("KURT WOLFF VERLAG");
	books[7].setDateAdded("09.18.2023");
	books[7].setQty(1);
	books[7].setWholesale(3.99);
	books[7].setRetail(6.20);

	books[8].setISBN("0544045521");
	books[8].setTitle("THE HOBBIT: DELUX POCKET EDITION");
	books[8].setAuthor("J.R.R. TOLKIEN");
	books[8].setPub("GEORGE ALLEN & UNWIN LTD");
	books[8].setDateAdded("09.18.2023");
	books[8].setQty(1);
	books[8].setWholesale(15.99);
	books[8].setRetail(21.50);

	books[9].setISBN("1423140591");
	books[9].setTitle("THE SON OF NEPTUNE");
	books[9].setAuthor("RICK RIORDAN");
	books[9].setPub("MIRAMAX BOOKS (DISNEY-HYPERION)");
	books[9].setDateAdded("09.19.2023");
	books[9].setQty(1);
	books[9].setWholesale(11.39);
	books[9].setRetail(15.00);

	books[10].setISBN("0786856297");
	books[10].setTitle("THE LIGHTNING THIEF");
	books[10].setAuthor("RICK RIORDAN");
	books[10].setPub("MIRAMAX BOOKS (DISNEY-HYPERION)");
	books[10].setDateAdded("09.19.2023");
	books[10].setQty(1);
	books[10].setWholesale(16.89);
	books[10].setRetail(23.20);

	books[11].setISBN("9780545429900");
	books[11].setTitle("THE GOLDEN DOOR");
	books[11].setAuthor("EMILY RODDA");
	books[11].setPub("SCHOLASTIC");
	books[11].setDateAdded("09.18.2023");
	books[11].setQty(1);
	books[11].setWholesale(13.97);
	books[11].setRetail(17.30);

	books[12].setISBN("1442421835");
	books[12].setTitle("SPY SCHOOL");
	books[12].setAuthor("STUART GIBBS");
	books[12].setPub("SIMON & SCHUSTER BOOKS FOR YOUNG READERS");
	books[12].setDateAdded("09.18.2023");
	books[12].setQty(2);
	books[12].setWholesale(8.99);
	books[12].setRetail(13.15);

	books[13].setISBN("1442494905");
	books[13].setTitle("EVIL SPY SCHOOL");
	books[13].setAuthor("STUART GIBBS");
	books[13].setPub("SIMON & SCHUSTER BOOKS FOR YOUNG READERS");
	books[13].setDateAdded("09.18.2023");
	books[13].setQty(4);
	books[13].setWholesale(8.26);
	books[13].setRetail(12.97);

	books[14].setISBN("9781416987314");
	books[14].setTitle("BELLY UP");
	books[14].setAuthor("STUART GIBBS");
	books[14].setPub("SIMON & SCHUSTER BOOKS FOR YOUNG READERS");
	books[14].setDateAdded("09.18.2023");
	books[14].setQty(1);
	books[14].setWholesale(13.60);
	books[14].setRetail(18.95);

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

