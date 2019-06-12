#include <cstddef>
#include <cstring>
#include <algorithm>

struct String {
	String(const char *str = "") {
    size = strlen(str);
    this->str = new char[size + 1];
    strcpy(this->str, str);
  };
	
  String(size_t n, char c) {
    size = n;
    str = new char[size + 1];
    if (size > 0) {
      for (size_t i = 0; i < size; i++) str[i] = c;
    }
    str[size] = '\0';
  };

	String(const String & other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
  }

  String & operator=(const String & other) {
    if (this != &other) String(other).swap(*this);
    return *this;
  };
	
  ~String() {
    delete [] str;
    str = 0;
  };

  void swap(String & other) {
    std::swap(size, other.size);
    std::swap(str, other.str);    
  }

	void append(const String & other) {
    size += other.size;
    char * buffer = new char[size + 1];
    strcpy(buffer, str);
    strcat(buffer, other.str);

    delete [] str;
    str = new char[size + 1];

    strcpy(str, buffer);

    delete [] buffer;
  };

	size_t size;
	char *str;
};

int main() {
  return 42;
}