#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
};

void displayBukuTersedia(Book* books, int size);
void pinjamBuku(Book* books, int size, vector<Book>& borrowed);
bool bukuYangTelahDipinjam(Book& book, vector<Book>& borrowed);
void displayPinjamBuku(vector<Book>& borrowed);

void displayBukuTersedia(Book* books, int size) {
    cout << "Buku yang tersedia :" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
    }
}

int main() {
    // Array of available books
    Book books[] = {
        {"The Great Gatsby", "F. Scott Fitzgerald"},
        {"To Kill a Mockingbird", "Harper Lee"},
        {"1984", "George Orwell"},
        {"Pride and Prejudice", "Jane Austen"},
        {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling"}
    };

    int size = sizeof(books) / sizeof(books[0]);

    vector<Book> borrowed;

    bool borrowAgain = true;
    while (borrowAgain) {
        displayBukuTersedia(books, size);

    char decision;
        cout << "Apakah anda ingin meminjam buku lagi? (y/n) ";
        cin >> decision;

        if (decision != 'y' && decision != 'Y') {
            borrowAgain = false;
        }
    }   

    cout << "Selamat datang di program meminjam buku!" << endl;

    cout << "\nTerimakasih telah meminjam buku!" << endl;

    return 0;
}