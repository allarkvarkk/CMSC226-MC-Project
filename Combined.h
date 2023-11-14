#include <string>
#include <vector>
using namespace std;
//bookinfo.cpp
void bookInfo(string, string, string, string, string, int, double, double);
//cashier.cpp
void cashier();
/*
	invMenu.cpp
*/
void invMenu();

void lookUpBook();

void addBook();

void editBook();

void deleteBook();

void MainMenu();
/*
	reports.cpp
*/
void reports();

void repListing();

void repWholesale();

void repRetail();

void repQty();

void repCost();

void repAge();

void currentTime();

int* bubbleSort(long double[], int);

int getCount();

const int MAX_BOOKS = 20;

void strUpper(char*);

vector<int> searchBookBySubstring(const string&);

void displayWithIndexes(vector<int>);


struct BookData {
private:
	char bookTitle[51];
	char isbn[15];
	char author[31];
	char publisher[31];
	char dateAdded[11];

	int qtyOnHand;

	double wholesale;
	double retail;

public:
	void setTitle(string tit) { strcpy(this->bookTitle, tit.c_str()); }

	string getTitle() { return this->bookTitle; }

	void setISBN(string i) { strcpy(this->isbn, i.c_str()); }

	string getISBN() { return this->isbn; }

	void setAuthor(string auth) { strcpy(this->author, auth.c_str()); }

	string getAuthor() { return this->isbn; }

	void setPub(string pub) { strcpy(this->publisher, pub.c_str()); }

	string getPub() { return this->publisher; }

	void setDateAdded(string date) { strcpy(this->dateAdded, date.c_str()); }

	string getDateAdded() { return this->dateAdded; }

	void setQty(int qty) { this->qtyOnHand = qty; }

	int getQty() { return this->qtyOnHand; }

	void setWholesale(double val) { this->wholesale = val; }

	double getWholesale() { return this->wholesale; }

	void setRetail(double val) { this->retail = val; }

	double getRetail() { return this->retail; }

	int isEmpty(int i) { return bookTitle[i] == '\0'; }

	void removeBook(int index) {
		if (index < 0 || index >= MAX_BOOKS - 1) {
			return;
		}
		for (int i = index; i < MAX_BOOKS - 1; i++) {
			strcpy(this[i].bookTitle, this[i + 1].bookTitle);
			strcpy(this[i].isbn, this[i + 1].isbn);
			strcpy(this[i].author, this[i + 1].author);
			strcpy(this[i].publisher, this[i + 1].publisher);
			strcpy(this[i].dateAdded, this[i + 1].dateAdded);

			this[i].qtyOnHand = this[i + 1].qtyOnHand;
			this[i].wholesale = this[i + 1].wholesale;
			this[i].retail = this[i + 1].retail;
		}
		strcpy(this[MAX_BOOKS - 1].bookTitle, "\0");
		strcpy(this[MAX_BOOKS - 1].isbn, "\0");
		strcpy(this[MAX_BOOKS - 1].author, "\0");
		strcpy(this[MAX_BOOKS - 1].publisher, "\0");
		strcpy(this[MAX_BOOKS - 1].dateAdded, "\0");
		this[MAX_BOOKS - 1].qtyOnHand = 0;
		this[MAX_BOOKS - 1].wholesale = 0.0;
		this[MAX_BOOKS - 1].retail = 0.0;
	}



};

extern BookData books[MAX_BOOKS];