#include "book.h"
#include <sstream>
#include <string>

using namespace std;

// Constructeurs
Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}

// Get
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerName() const {
    return borrowerName;
}

// Set
void Book::setTitle(const string& t) {
    title = t;
}

void Book::setAuthor(const string& a) {
    author = a;
}

void Book::setISBN(const string& i) {
    isbn = i;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerName(const string& name) {
    borrowerName = name;
}

// Méthodes
void Book::checkOut(const string& borrower) {
    isAvailable = false;
    borrowerName = borrower;
}

void Book::returnBook() {
    isAvailable = true;
    borrowerName.clear();
}

string Book::toString() const {
    ostringstream oss;
    oss << "Titre       : " << title << "\n"
        << "Auteur      : " << author << "\n"
        << "ISBN        : " << isbn << "\n"
        << "Disponibilite : " << (isAvailable ? "Disponible" : "Emprunte");
    if (!isAvailable && !borrowerName.empty()) {
        oss << "\nEmprunteur : " << borrowerName;
    }
    return oss.str();
}

string Book::toFileFormat() const {
    // disponible:  title|author|isbn|1|
    // emprunté:    title|author|isbn|0|borrower
    ostringstream oss;
    oss << title << '|' << author << '|' << isbn << '|'
        << (isAvailable ? '1' : '0') << '|';
    if (!isAvailable && !borrowerName.empty()) {
        oss << borrowerName;
    }
    return oss.str();
}

void Book::fromFileFormat(const string& line) {
    string t, a, i, availStr, borrower;
    stringstream ss(line);

    getline(ss, t, '|');
    getline(ss, a, '|');
    getline(ss, i, '|');
    getline(ss, availStr, '|');
    getline(ss, borrower, '|'); // facultatif

    title = t;
    author = a;
    isbn = i;

    isAvailable = (availStr == "1");
    if (!isAvailable) {
        borrowerName = borrower;
    } else {
        borrowerName.clear();
    }
}
