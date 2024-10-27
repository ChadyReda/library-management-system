#include <iostream>
#include <string>

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





int main() {

    return 0;
}