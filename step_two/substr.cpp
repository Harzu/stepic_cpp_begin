#include <iostream>
using namespace std;

struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};

unsigned str_len(const char *str) {
  unsigned counter = 0;
  for (; *str != '\0'; str++) counter++;
  return counter;
}

int string_eq(const char * text, const char * pattern) {
  if (str_len(pattern) == 0) return 0;
  if (str_len(text) < str_len(pattern)) return -1;

  unsigned counter = 0;

  while (true) {
    if (*text == '\0' || *pattern == '\0') break;
    if (*text++ == *pattern++) {
      counter++;
    } else {
      return -1;
    }
  }

  return counter;
}

int substring(const char * text, const char * pattern) {
  if (str_len(pattern) == 0) return 0;
  if (str_len(text) < str_len(pattern)) return -1;

  int counter = 0;

  while (*text != '\0') {
    if (string_eq(text, pattern) == str_len(pattern)) {
      return counter;
    };
    text++;
    counter++;
  }

  return -1;
}

int main() {
  test tests[] = {
    {0, "", ""}, //0
    {0, "a", ""}, //1
    {0, "a", "a"}, //2
    {-1, "a", "b"}, //3
    {0, "aa", ""}, //4
    {0, "aa", "a"}, //5
    {0, "ab", "a"}, //6
    {1, "ba", "a"}, //7
    {-1, "bb", "a"}, //8
    {0, "aaa", ""}, //9
    {0, "aaa", "a"}, //10
    {1, "abc", "b"}, //11
    {2, "abc", "c"}, //12
    {-1, "abc", "d"}, //13
    {-1, "a", "aa"}, //14
    {-1, "a", "ba"}, //15
    {-1, "a", "ab"}, //16
    {-1, "a", "bb"}, //17
    {-1, "a", "aaa"}, //18
    {-1, "aa", "aaa"}, //19
    {0, "aaa", "aaa"}, //20
    {0, "aaab", "aaa"}, //21
    {1, "baaa", "aaa"}, //22
    {1, "baaaa", "aaa"}, //23
    {1, "baaab", "aaa"}, //24
    {-1, "abd", "abc"}, //25
    {2, "ababc", "abc"}, //26
    {3, "abdabc", "abc"}, //27
    {-1, "", "a"}, //28
    {2, "asasaf", "asaf"}, //29
    {2, "ababac", "abac"} //30
  };
  
  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    int ret = substring(tests[i].text, tests[i].pattern);
    (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
     cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
  }

  return 42;
}