#include <iostream>
#include <fstream>
#include <string>

char* _my_strchr(const char* string, int c){
    while(*string != char(c)){
        if(!*string++){
            return NULL;
        }
    }
    return (char*) string;
}

int main() {
    std::ifstream fin("input.rxr");

    char str[1000];
    char symbol;
    fin >> str;
    fin >> symbol;
    fin.close();
    char *symb = _my_strchr(str, symbol);
    std::ofstream fout("output.txt");
    fout << symb;
    fout.close();
    return 0;
}