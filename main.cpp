#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    private:
        string title;
        string author;
        bool available;
    public:
        string getTitle() const {
            return title;
        }
        string getAuthor() const {
            return author;
        }
        bool isAvailable() const {
            return available;
        }
        void setAvailability(const bool& availability) {
            available = availability;
        }
        void getDetails() const {
            cout << "Title: " << title 
                 << " Author: " << author 
                 << " Available: " << available
                 << endl; 
        }
        void setTitle(const string& t) {title = t;}
        void setAuthor(const string& a) {author = a;}
};



class Person {
    protected: 
        string name;
        int id;

    public:
        Person(string name, int id): name(name), id(id){}
        // Getters
        string getName() const {
            return name;
        }
        int getId() const {
            return id;
        }
        // Setters
        void setName(const string& n) {
            name = n;
        }
        void setId(const int& id_p) {
            id = id_p;
        }

};

class Admin : public Person {
    public:
        Admin(string name, int id): Person(name, id) {}
        void manageBooks () {
            cout << "Managing books ..." << endl;
        }
        void manageMembers () {
            cout << "Managing members ..." << endl;
        }

};

class Member : public Person {
    public:
        Member (string name, int id): Person (name, id) {}
        void borrowBook(Book& book) {
            if (book.isAvailable()) {
                cout << name << " borrowed the book : " << book.getTitle() << endl;
                book.setAvailability(false);
            }     
            cout << "Book is currently unavailable!" << endl;
        }
        void returnBook(Book& book) {
            book.setAvailability(true);
            cout << name << " returned the book: " << book.getTitle() << endl;
        }
};


class Library {
    private: 
        vector<Book> books;
        vector<Member> members;
    public:
        void addBook(const Book& book) {
            books.push_back(book);
            cout << "Book added to library: " << book.getTitle() << endl;
        }
        void removeBook(const string& title) {
            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->getTitle() == title) {
                    books.erase(it);
                    cout << "Book removed from the library: " << title << endl;
                } 
            }
            cout << "Book not found!" << endl;
        }
        void addMember(const Member& member) {
            members.push_back(member);
            cout << "Member added: " << member.getName() << endl;
        }
        void issueBook(const string& title, Member& member) {
            for (auto &book : books) {
                if(book.getTitle() == title && book.isAvailable()) {
                    member.borrowBook(book);
                    return;
                }
            }
            cout << "Book not available or not found" << endl;
        }
        void returnBook (const string& title, Member& member) {
            for (auto &book : books) {
                if (book.getTitle() == title) {
                    member.returnBook(book);
                    return;
                }
            }
            cout << "book does not exist in the library" << endl;
        }
        void displayBooks() const {
            cout << "Books in the library: " << endl;
            for (const auto &book : books) {
                book.getDetails();
            }
        }
};


int main() {
    return 0;
}