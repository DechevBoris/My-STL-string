#include "MyString.h"

ostream& operator<<(ostream& out, const MyString& str)
{
    out << str.getBuffer();
    return out;
}

int main()
{

    return 0;
}
