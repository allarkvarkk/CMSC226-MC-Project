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

int getCount(int[]);

const int MAX_BOOKS = 20;

extern char bookTitle[20][51];

extern char isbn[20][14];

extern char author[20][51];

extern char publisher[20][42];

extern char dateAdded[20][11];

extern int qtyOnHand[MAX_BOOKS];

extern double wholesale[MAX_BOOKS];

extern double retail[MAX_BOOKS];

void strUpper(char*);

vector<int> searchBookBySubstring(const string&);

void displayWithIndexes(vector<int>);