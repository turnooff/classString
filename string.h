#pragma once
#include <iostream>

class String {
private:
    std::size_t size;
    std::size_t capacity;
    char* pointer;
    int strlen(const char* str);
public:
    String(){};
    String(char* str);
    ~String();
    void Print();
    String& operator= (const char* str);
    char& operator[] (std::size_t pos);
    int compare(String& str);
    String& insert (std::size_t pos, const char* str);
    String(String &str);
    String(String &&str) noexcept;
    String& operator= (String&& str)noexcept;
};