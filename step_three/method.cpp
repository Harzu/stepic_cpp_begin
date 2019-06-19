#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
    String(const char * str = "")
    {
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    };

    ~String()
    {
        delete [] str;
        str = 0;
    };

    void append(String &other)
    {
        size += other.size;
        char * buffer = new char[size + 1];
        strcpy(buffer, str);
        strcat(buffer, other.str);

        delete [] str;
        str = new char[size + 1];

        strcpy(str, buffer);

        delete [] buffer;
    }

    size_t size;
    char * str;
};

int main()
{
    String hello("Hello");
    String world(", World");
    String empty;
    hello.append(hello);
    std::cout << "string: " << hello.str << std::endl;
    std::cout << "length: " << hello.size << std::endl;
    return 42;
}