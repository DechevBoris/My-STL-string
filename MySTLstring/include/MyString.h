#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char* buffer;
    size_t size;
    size_t capacity;

    void copy(const MyString& other);
    void erase();
    void resize();
public:
    MyString();
    MyString(const MyString& other);
    MyString(const char* _buffer);
    MyString& operator=(const MyString& other);
    ~MyString();
    char* getBuffer()const;
    size_t getSize()const;
    size_t getCapacity()const;
    char first()const;                               //Returns the first character
    char last()const;                                //Returns the last character
    bool operator==(const MyString& other);          //Compares two strings
    char operator[](size_t index);
    MyString& operator+(const MyString& other);      //Concatenates two strings
    MyString& concat(const MyString& other);
    void reverse();
    void clear();                                    //Clears the content and make the string an empty string
    char at(size_t pos);                             //Returns the character at position 'pos'
    void pushBack(char el);
    void pushFront(char el);
    void pushAt(char el, size_t index);
    void replace(char el, size_t index);
    void popBack();                                  //Delete last charecter
    void popFront();                                 //Delete first character
    void popAt(size_t index);                        //Delete the character at position 'index'
    char* substring(size_t start, size_t length);    //Return substring from position 'start' with the given length
    ostream& operator <<(ostream& out);
    void print()const;
};
