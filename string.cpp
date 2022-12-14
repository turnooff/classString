#include <iostream>
#include "my_string.h"
#include <cmath>

int String::strlen(const char* str){
        int count = 0;
        while (str[count] != '\0'){
            count++;
        }
        return count;
    }
String::String(){
        pointer = nullptr;
    }

String::String(char* str){
        size = strlen(str);
        pointer = new char[size + 1];
        for (int i = 0; i < size; ++i){
            pointer[i] = str[i];
        }
        pointer[size] = '\0';
    }
String::~String(){
        delete[] pointer;
    }
    void String::Print(){
        std::cout << pointer << "\n";
    }
    String& String::operator= (const char* str){
        if (pointer != nullptr){
            delete[] pointer;
        }
        size = strlen(str);
        pointer = new char[size + 1];
        for (int i = 0; i < size; ++i){
            pointer[i] = str[i];
        }
        pointer[size] = '\0';

        return *this;
    }
    char& String::operator[] (std::size_t pos){
        for (int i = 0; i < size; ++i){
            if (i == pos){
                return pointer[i];
            }
        }
        return pointer[size];
    }
    int String::compare(String& str){
        int min_size = 0;
        if (size > str.size){
            min_size = str.size;
        }
        else{
            min_size = size;
        }
        for (int i = 0; i < min_size; ++i){
            if (pointer[i] > str[i]){
                return 1;
            }
            else if (pointer[i] < str[i]){
                return -1;
            }
        }
        if (size == str.size){
            return 0;
        }
        else{
            if (min_size == str.size){
                return -1;
            }
            else{
                return 1;
            }
        }
    }
    String& String::insert (std::size_t pos, const char* str){
        int new_size = size + strlen(str);
        char* new_str = new char[size];
        for (int i = 0; i < size; ++i){
            new_str[i] = pointer[i];
        }
        delete[] pointer;
        pointer = new char[new_size];
        bool pos_i = false;
        for (int i = 0; i < new_size; ++i){
            if (i == pos){
                pos_i = true;
                pointer[i] = str[i - pos];
            }
            else{
                if (!pos_i){
                    pointer[i] = new_str[i];
                }
                else{
                    if (i < pos + strlen(str)){
                        pointer[i] = str[i - pos];
                    }
                    else{
                        pointer[i] = new_str[i - strlen(str)];
                    }
                }
            }
        }
        pointer[new_size] = '\0';
        return *this;
    }

String::String(String &str){
        size = str.size;
        pointer = new char[size + 1];
        for (int i = 0; i < size; ++i){
            pointer[i] = str[i];
        }
        pointer[size] = '\0';
    }

String::String(String &&str) noexcept{
        size = str.size;
        pointer = str.pointer;
        str.pointer = nullptr;
    }

    String& String::operator= (String&& str)noexcept{
        if (pointer != nullptr){
            delete[] pointer;
        }
        size = strlen(str.pointer);
        pointer = new char[size + 1];
        for (int i = 0; i < size; ++i){
            pointer[i] = str[i];
        }
        pointer[size] = '\0';
        return *this;
    }
