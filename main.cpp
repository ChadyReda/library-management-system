#include <iostream>
#include <string>

using namespace std;

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


int main() {

    return 0;
}