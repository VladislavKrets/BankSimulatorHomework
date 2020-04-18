//
// Created by lollipop on 09.03.20.
//

#ifndef BANKSIMULATOR_UTILS_H
#define BANKSIMULATOR_UTILS_H

#include <type_traits>
int countLength(char * line);
bool isLinesEquals(char * line1, char * line2);
template<typename Base, typename T>
inline bool instanceof(T * t) {
    return dynamic_cast<Base*>(t) != nullptr;
}

#endif //BANKSIMULATOR_UTILS_H
