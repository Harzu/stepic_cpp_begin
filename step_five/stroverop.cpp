#include <cstddef> // size_t
#include <cstring> // strcpy strlen

struct String
{
    String(const char *str = "");
    String(size_t n, char c);
    ~String();
    String(const String &other);
    void append(const String &other);
    String &operator=(const String &other);

    struct String_1 {
        String_1(const size_t i, char *str)
        {
            this->i = i;
            size = strlen(str);
            this->str = new char[size + 1];
            strcpy(this->str, str);
        }
    
        ~String_1() { delete [] str; }

        String operator [] (const size_t k)
        {
            if (i == k)
            {
                String new_string;
                return new_string;
            };

            char * buffer = new char[(k - i) + 1];
            size_t j = 0;
            while (i < k || j < (k - i) + 1)
            {
                buffer[j++] = str[i++];
            }

            String result(buffer);
            delete [] buffer;
            return result;
        };

    private:
        size_t i;
        size_t size;
        char *str;
    };
  
    String_1 operator [] (const size_t i) const
    {
        String_1 a(i, this->str);
        return a;
    };

    size_t size;
    char *str;
};