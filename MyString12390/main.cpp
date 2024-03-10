#include "MyString.h"

int main() {

    MyString str1;
    cout << "Default Constructor: ";
    str1.displayString();
    cout << endl;

    MyString str2(10);
    cout << "Constructor with size 10: ";
    str2.displayString();
    cout << endl;

    MyString str3;
    cout << "Enter a string for Constructor with user input: ";
    str3.inputString();
    cout << "User input: ";
    str3.displayString();
    cout << endl;

    MyString str4("Hello");
    MyString str5(" World");

    MyString str6;
    str6.MyStrcpy(str4);
    cout << "Copied String: ";
    str6.displayString();
    cout << endl;

    cout << "Substring 'lo' found in str4: " << boolalpha << str4.find("lo") << endl;

    cout << "Index of 'e' in str4: " << str4.findChar('e') << endl;

    cout << "Length of str4: " << str4.length() << endl;

    str4 += str5;
    cout << "Concatenated String: ";
    str4.displayString();
    cout << endl;

    str4 -= 'o';
    cout << "String after deleting 'o': ";
    str4.displayString();
    cout << endl;

    MyString str7("Hello");
    MyString str8("World");
    cout << "Comparison Result: " << (str7 == str8) << endl;

    cout << "Number of MyString objects: " << MyString::getObjectCount() << endl;

    MyString str9("Hello");

    str9[1] = 'a';
    cout << "After using operator[]: ";
    str9.displayString();
    cout << endl;

    str9.setString("New String");
    cout << "After using method (): ";
    str9.displayString();
    cout << endl;

    MyString result1 = str9 + 'A';
    cout << "Result of obj + 'A': ";
    result1.displayString();
    cout << endl;

    MyString result2 = 'A' + str9;
    cout << "Result of 'A' + obj: ";
    result2.displayString();
    cout << endl;

    MyString result3 = 10 + str9;
    cout << "Result of 10 + obj: ";
    result3.displayString();
    cout << endl;

    MyString result4 = str9 + 10;
    cout << "Result of obj + 10: ";
    result4.displayString();
    cout << endl;

    MyString str11;
    str11 = str9;
    cout << "Copy using operator=: ";
    str10.displayString();
    cout << endl;

    MyString str12("Hello");
    cout << "str12: ";
    str12.displayString();
    cout << endl;

    MyString str13 = move(str12);
    cout << "str13 (after move): ";
    str13.displayString();
    cout << endl;

    cout << "str12 (after move): ";
    str12.displayString();
    cout << endl;

    return 0;
}

