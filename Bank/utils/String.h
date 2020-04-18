#ifndef BANKSIMULATOR_STRING_H
#define BANKSIMULATOR_STRING_H

#include <istream>


class String{
    char * line = nullptr;
    int length;
    void initString(char *line);
public:

    String();

    String(char * line);

    String(const char * line);

    int getLength();

    char * getLine() const;

    ~String();

    String & operator+(String & line);
    String & operator+(const char * charLine);

    String & operator=(char & line);

    String & operator=(const char * line);


    String & operator=(String * line);
    bool & operator==(const char * line);
    bool & operator==(String * line);
    bool & operator==(String &line);
    friend std::istream & operator>>(std::istream &is, String &m);
    long parseLong();

};
std::ostream &operator<<(std::ostream &os, String const &m);
std::istream &operator>>(std::istream &is, String &m);

#endif //BANKSIMULATOR_STRING_H
