
#include "Utils.h"

int countLength(char * line){
    char c = ' ';
    int length = 0;
    while (c != '\0'){
        c = line[length];
        length++;
    }
    return length - 1;
}


bool isLinesEquals(char * line1, char * line2){
    int length1 = countLength(line1);
    int length2 = countLength(line2);

    if (length1 != length2) return false;

    for (int i = 0; i < length1; i++){
        if (line1[i] != line2[i]) return false;
    }

    return true;
}



