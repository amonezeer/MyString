#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int length;
    static int objectCount;

public:
    MyString();
    MyString(int size);
    MyString(const char* inputStr);
    ~MyString();

    void inputString();
    void displayString() const;

    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;

    void MyStrcpy(const MyString& obj);
    bool MyStrStr(const char* substr) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

    static int getObjectCount();

    ostream& operator<<(ostream& os) const;

    istream& operator>>(istream& is);

    char& operator[](int index);
    void operator()(const char* inputStr);
    MyString operator+(char ch) const;
    friend MyString operator+(char ch, const MyString& obj);
    MyString operator+(int num) const;
    friend MyString operator+(int num, const MyString& obj);
    MyString operator++(int);  
    MyString operator++();  

    MyString(MyString&& other);
    MyString& operator=(MyString&& other);
};