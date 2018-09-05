#include "MyString.h"

void MyString::copy(const MyString& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    if(other.buffer == nullptr)
        this->buffer = nullptr;
    else
    {
        this->buffer = new char[this->capacity];
        for(size_t i = 0; i < this->size; i++)
            this->buffer[i] = other.buffer[i];
    }
}

void MyString::erase()
{
    delete[] this->buffer;
}

void MyString::resize()
{
    this->capacity *= 2;
    char* tmp = new char[this->capacity];
    for(size_t i = 0; i < this->size; i++)
        tmp[i] = this->buffer[i];
    delete[] this->buffer;
    this->buffer = tmp;
}

MyString::MyString()
{
    this->buffer = new char[1];
    strcpy(this->buffer, "");
    this->size = 0;
    this->capacity = 8;
}

MyString::MyString(const MyString& other)
{
    this->copy(other);
}

MyString::MyString(const char* _buffer)
{
    this->capacity = 8;
    this->size = strlen(_buffer);
    while(this->size >= this->capacity)
        this->capacity *= 2;
    this->buffer = new char[this->capacity];
    strcpy(this->buffer, _buffer);
}

MyString& MyString::operator=(const MyString& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

MyString::~MyString()
{
    this->erase();
}

char* MyString::getBuffer()const
{
    return this->buffer;
}

size_t MyString::getSize()const
{
    return this->size;
}

size_t MyString::getCapacity()const
{
    return this->capacity;
}

char MyString::first()const
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    return this->buffer[0];
}

char MyString::last()const
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    return this->buffer[this->size - 1];
}

bool MyString::operator==(const MyString& other)
{
    if(this->size != other.size)
        return false;
    for(size_t i = 0; i < this->size; i++)
        if(this->buffer[i] != other.buffer[i])
            return false;
    return true;
}

char MyString::operator[](size_t index)
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    if(index < 0 || index >= this->size)
        throw invalid_argument("Invalid index!");
    return this->buffer[index];
}

MyString& MyString::operator+(const MyString& other)
{
    while(this->size + other.size >= this->capacity)
        this->resize();
    size_t tmp = this->size;
    this->size += other.size;
    for(size_t i = tmp; i < this->size; i++)
        this->buffer[i] = other.buffer[i - tmp];
    return *this;
}

MyString& MyString::concat(const MyString& other)
{
    while(this->size + other.size >= this->capacity)
        this->resize();
    size_t tmp = this->size;
    this->size += other.size;
    for(size_t i = tmp; i < this->size; i++)
        this->buffer[i] = other.buffer[i - tmp];
    return *this;
}

void MyString::reverse()
{
    if(this->size % 2 != 0)
        for(size_t i = 0; i <= this->size / 2; i++)
        {
            char fst = this->buffer[i];
            char lst = this->buffer[this->size - i - 1];
            this->buffer[i] = lst;
            this->buffer[this->size - i - 1] = fst;
        }
    else
        for(size_t i = 0; i < this->size / 2; i++)
        {
            char fst = this->buffer[i];
            char lst = this->buffer[this->size - i - 1];
            this->buffer[i] = lst;
            this->buffer[this->size - i - 1] = fst;
        }
}

void MyString::clear()
{
    this->erase();
    this->buffer = new char[1];
    strcpy(this->buffer, "");
    this->size = 0;
    this->capacity = 8;
}

char MyString::at(size_t pos)
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    if(pos < 0 || pos >= this->size)
        throw invalid_argument("Invalid index!");
    return this->buffer[pos];
}

void MyString::pushBack(char el)
{
    if(this->size + 1 >= this->capacity)
        this->resize();
    this->buffer[this->size++] = el;
}

void MyString::pushFront(char el)
{
    if(this->size + 1 >= this->capacity)
        this->resize();
    this->size++;
    for(size_t i = this->size - 1; i > 0; i--)
        this->buffer[i] = this->buffer[i - 1];
    this->buffer[0] = el;
}

void MyString::pushAt(char el, size_t index)
{
    if(index > this->size || index < 0)
        throw logic_error("Invalid position!");
    if(this->size + 1 >= this->capacity)
        this->resize();
    this->size++;
    for(size_t i = this->size - 1; i > index; i--)
        this->buffer[i] = this->buffer[i - 1];
    this->buffer[index] = el;
}

void MyString::replace(char el, size_t index)
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    this->buffer[index] = el;
}

void MyString::popBack()
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    this->size--;
}

void MyString::popFront()
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    for(size_t i = 0; i < this->size - 1; i++)
        this->buffer[i] = this->buffer[i + 1];
    this->size--;
}

void MyString::popAt(size_t index)
{
    if(this->size == 0)
        throw logic_error("Empty string!");
    if(index >= this->size || index < 0)
        throw logic_error("Invalid index!");
    for(size_t i = index; i < this->size - 1; i++)
        this->buffer[i] = this->buffer[i + 1];
    this->size--;
}

char* MyString::substring(size_t start, size_t length)
{
    if(start + length > this->size)
        throw logic_error("Invalid substring start or length!");
    if(start < 0 || start >= this->size)
        throw invalid_argument("Invalid starting point!");
    char* res = new char[length + 1];
    size_t count = 0;
    for(size_t i = start; i < start + length; i++)
    {
        res[count] = this->buffer[i];
        count++;
    }
    res[length] = '\0';
    return res;
}

ostream& MyString::operator<<(ostream& out)
{
    out << this->buffer;
    return out;
}

void MyString::print()const
{
    if(this->buffer == nullptr)
        cout << "";
    else
        for(size_t i = 0; i < this->size; i++)
            cout << this->buffer[i];
}
