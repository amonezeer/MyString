#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

int MyString::objectCount = 0;

MyString::MyString() : str(new char[81]), length(80)
{
    for (int i = 0; i < length; i++)
    {
        str[i] = ' ';
    }
    str[length] = '\0';
    objectCount++;
}

MyString::MyString(int size) : str(new char[size + 1]), length(size)
{
    for (int i = 0; i < length; i++)
    {
        str[i] = ' ';
    }
    str[length] = '\0';
    objectCount++;
}

MyString::MyString(const char* inputStr) : str(new char[strlen(inputStr) + 1]), length(strlen(inputStr))
{
    strcpy(str, inputStr);
    objectCount++;
}

MyString::~MyString()
{
    delete[] str;
    objectCount--;
}

void MyString::inputString()
{
    cout << "Enter a string: ";
    cin.getline(str, length);
    length = strlen(str);
}

void MyString::displayString() const
{
    cout << str;
}

MyString MyString::operator+(const MyString& other) const
{
    MyString result(length + other.length);
    strcpy(result.str, str);
    strcat(result.str, other.str);
    return result;
}

void MyString::MyStrcpy(const MyString& obj)
{
    strcpy(str, obj.str);
    length = obj.length;
}

bool MyString::MyStrStr(const char* substr) const
{
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c) const
{
    const char* found = strchr(str, c);
    return (found != nullptr) ? (found - str) : -1;
}

int MyString::MyStrLen() const
{
    return length;
}

void MyString::MyStrCat(const MyString& b)
{
    char* temp = new char[length + b.length + 1];
    strcpy(temp, str);
    strcat(temp, b.str);
    delete[] str;
    str = temp;
    length += b.length;
}

void MyString::MyDelChr(char c)
{
    char* temp = new char[length];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    delete[] str;
    str = temp;
    length = j;
}

int MyString::MyStrCmp(const MyString& b) const
{
    int cmpResult = strcmp(str, b.str);
    if (cmpResult < 0)
    {
        return -1;
    }
    else if (cmpResult > 0)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int MyString::getObjectCount()
{
    return objectCount;
}

ostream& MyString::operator<<(ostream& os) const
{
    os << str;
    return os;
}

istream& MyString::operator>>(istream& is)
{
    char buffer[1000];
    is.getline(buffer, 1000);
    *this = buffer;
    return is;
}


char& MyString::operator[](int index)
{
    if (index >= 0 && index < length)
    {
        return str[index];
    }
}

void MyString::operator()(const char* inputStr)
{
    delete[] str;
    length = strlen(inputStr);
    str = new char[length + 1];
    strcpy(str, inputStr);
}

MyString MyString::operator+(char ch) const
{
    MyString result(length + 1);
    strcpy(result.str, str);
    result.str[length] = ch;
    result.str[length + 1] = '\0';
    return result;
}

MyString operator+(char ch, const MyString& obj)
{
    MyString result(obj.length + 1);
    result.str[0] = ch;
    strcpy(result.str + 1, obj.str);
    return result;
}

MyString MyString::operator+(int num) const
{
    MyString result(length + num);
    strcpy(result.str, str);
    for (int i = length; i < result.length; i++)
    {
        result.str[i] = 'x';
    }
    result.str[result.length] = '\0';
    return result;
}

MyString operator+(int num, const MyString& obj)
{
    MyString result(obj.length + num);
    for (int i = 0; i < num; i++)
    {
        result.str[i] = 'x';
    }
    strcpy(result.str + num, obj.str);
    return result;
}

MyString MyString::operator++(int)
{
    MyString temp(*this);
    char randomChar = 'X';
    *this = *this + randomChar;
    return temp;
}

MyString MyString::operator++()
{
    char randomChar = 'X';
    *this = randomChar + *this;
    return *this;
}


MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete[] str;

        length = other.length;
        str = new char[length + 1];

        strcpy(str, other.str);
    }
    return *this;
}

MyString::MyString(MyString&& other) : str(nullptr), length(0)
{
    str = other.str;
    length = other.length;

    other.str = nullptr;
    other.length = 0;
}

MyString& MyString::operator=(MyString&& other)
{
    if (this != &other)
    {
        delete[] str;

        str = other.str;
        length = other.length;

        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}