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
// Function to display borrowed books
void displayPinjamBuku(vector<Book>& borrowed) {
    cout << "\nBuku-buku yang telah anda pinjam:" << endl;
    for (Book& book : borrowed) {
        cout << "- " << book.title << " oleh " << book.author << endl;
    }
}

//Function to borrow a book
void pinjamBuku(Book* books, int size, vector<Book>& borrowed) {
    int choice;
    cout << "silahkan pilih nomor buku yang anda ingin pinjam: ";
    cin >> choice;

    // Check if the book is already borrowed
    if (choice >= 1 && choice <= size && !bukuYangTelahDipinjam(books[choice - 1], borrowed)) {
        borrowed.push_back(books[choice - 1]);
        cout << "Anda telah meminjam \"" << books[choice - 1].title << "\" oleh " << books[choice - 1].author << "." << endl;
    } else {
        if (bukuYangTelahDipinjam(books[choice - 1], borrowed)) {
            cout << "Error: Buku ini telah dipinjam. Silahkan pilih buku lain." << endl;
        } else {
            cout << "Invalid. Silahkan coba ulang." << endl;
        }
    }
}

// Function to check if a book is already borrowed
bool bukuYangTelahDipinjam(Book& book, vector<Book>& borrowed) {
    for (Book& b : borrowed) {
        if (b.title == book.title) {
            return true;
        }
    }
    return false;
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

        pinjamBuku(books, size, borrowed);

    char decision;
        cout << "Apakah anda ingin meminjam buku lagi? (y/n) ";
        cin >> decision;

        if (decision != 'y' && decision != 'Y') {
            borrowAgain = false;
        }
    }   

    cout << "Selamat datang di program meminjam buku!" << endl;

// Display borrowed books
    displayPinjamBuku(borrowed);
    
    cout << "\nTerimakasih telah meminjam buku!" << endl;

    return 0;
}