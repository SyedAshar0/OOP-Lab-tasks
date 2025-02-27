#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Book {
public:
    string title;
    string author;
    string isbn;

    Book(const string& t, const string& a, const string& i) : title(t), author(a), isbn(i) {}
};
class Catalog {
private:
    unordered_map<string, weak_ptr<Book>> index; 
public:
    void addBook(shared_ptr<Book> book) {
        index[book->isbn] = book;
    }

    void removeBook(const string& isbn) {
        index.erase(isbn);
    }

    shared_ptr<Book> findBook(const string& isbn) {
        auto it = index.find(isbn);
        return (it != index.end()) ? it->second.lock() : nullptr; 
    }
};
class Library {
private:
    Catalog catalog; 
    vector<shared_ptr<Book>> books;

public:
    string name, address;
    Library(const string& n, const string& addr) : name(n), address(addr) {}
    void addBook(shared_ptr<Book> book) {
        books.push_back(book);
        catalog.addBook(book);
    }
    void removeBook(const string& isbn) {
        catalog.removeBook(isbn);
        books.erase(remove_if(books.begin(), books.end(),
                              [&](const shared_ptr<Book>& b) { return b->isbn == isbn; }),
                    books.end());
    }
    void searchBook(const string& isbn) {
        shared_ptr<Book> book = catalog.findBook(isbn);
        if (book)
            cout << "Found Book: " << book->title << " by " << book->author << endl;
        else
            cout << " Book not found in catalog." << endl;
    }
    void displayBooks() {
        cout << "\n Library: " << name << " | Location: " << address << "\n Books Available:\n";
        if (books.empty()) {
            cout << "   (No books available)\n";
        } else {
            for (const auto& book : books) {
                cout << "   - " << book->title << " (ISBN: " << book->isbn << ")\n";
            }
        }
    }
};
int main() {
    Library myLibrary("Karachi Library", "Shah Faisal");
    auto book1 = make_shared<Book>("Effective Communication", "John Doe", "10101");
    auto book2 = make_shared<Book>("Drastic Measures", "Pep Guardiola", "415141");
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.displayBooks();
    myLibrary.searchBook("10101");
    myLibrary.removeBook("415141");
    myLibrary.displayBooks();
    return 0;
}
