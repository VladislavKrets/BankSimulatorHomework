#include "String.h"
#include <iostream>
#include "Utils.h"

void String::initString(char *line) {
    int length = countLength(line);
    this->line = new char[length + 1];
    for (int i = 0; i < length; i++) {
        this->line[i] = line[i];
    }
    this->line[length] = '\0';
    this->length = length;
}


String::String() {
    this->length = 0;
    line = new char[1]{'\0'};
}

String::String(char *line) {
    initString(line);
}

String::String(const char *line) {
    initString(const_cast<char *>(line));
}

int String::getLength() {
    return length;
}

char *String::getLine() const {
    return line;
}


String &String::operator+(String &line) {
    int newLength = this->length + line.length;
    char *newLine = new char[this->length + 1];
    for (int i = 0; i < this->length; i++) {
        newLine[i] = this->line[i];
    }
    for (int i = this->length; i < newLength; i++) {
        newLine[i] = line.line[i - this->length];
    }
    newLine[newLength] = '\0';
    this->length = newLength;
    delete[] this->line;
    this->line = newLine;
    return *this;
}


String &String::operator=(char &line) {
    this->initString(&line);
    return *this;
}

String &String::operator=(const char *line) {
    this->initString(const_cast<char *>(line));
    return *this;
}


String &String::operator=(String *line) {
    *this = line->line;
    return *this;
}

std::ostream &operator<<(std::ostream &os, String const &m) {
    return os << m.getLine();
}

std::istream &operator>>(std::istream &is, String &m) {

    char c;
    int length = 0;
    int buffLength = 10;
    char *newLine = new char[buffLength];
    while (true) {
        is.get(c);
        if (c == '\n') break;
        if (length == buffLength){
            buffLength = buffLength * 3 / 2;
            char * tempArray = new char[buffLength];
            for (int i = 0; i < length; i++) {
                tempArray[i] = newLine[i];
            }
            delete [] newLine;
            newLine = tempArray;
        }
        newLine[length] = c;
        length++;
    }

    delete [] m.line;
    m.line = new char[length + 1];
    for (int i = 0; i < length; i++) {
        m.line[i] = newLine[i];
    }
    m.line[length] = '\0';
    delete [] newLine;
    m.length = length;

    return is;
}

String &String::operator+(const char *charLine) {
    String *line = new String(charLine);
    *this = *this + *line;
    delete line;
    return *this;
}

bool &String::operator==(const char *line) {
    bool b = isLinesEquals(this->getLine(), const_cast<char *>(line));
    return *(new bool(b));
}

bool &String::operator==(String *line) {
    bool b = isLinesEquals(this->getLine(), line->getLine());
    return b;
}

bool &String::operator==(String &line) {
    bool b = isLinesEquals(this->getLine(), line.getLine());
    return b;
}

String::~String() {
    delete[] line;

}

long String::parseLong() {
    return strtol(this->getLine(), nullptr, 10);
}


