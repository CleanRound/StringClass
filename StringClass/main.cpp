#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    static int count;

public:
    String() : String(80) {}

    String(int size) : str(new char[size + 1]) {
        count++;
        cout << "Enter string: ";
        cin.getline(str, size + 1);
    }

    String(const char* s) : String(strlen(s)) {
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
        count--;
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(str, strlen(str) + 1);
    }

    void display() const {
        cout << "String: " << str << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String s1;
    String s2(50);
    String s3("Hello");

    s1.display();
    s2.display();
    s3.display();

    cout << "Number of String objects created: " << String::getCount() << endl;

    return 0;
}
