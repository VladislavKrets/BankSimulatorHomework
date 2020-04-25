#ifndef BANKSIMULATOR_LIST_H
#define BANKSIMULATOR_LIST_H

template <typename T>
class List{
    T * array;
    int length;
    int maxLength;

    void resize(){
        maxLength = maxLength * 3 / 2;
        T * newArray = new T[maxLength];
        for (int i = 0; i < this->length; i++){
            newArray[i] = array[i];
        }
        delete [] array;
        array = newArray;
    }

public:
    List(){
        maxLength = 10;
        array = new T[maxLength];
        length = 0;
    }

    T get(int index){
        return array[index];
    }

    void add(T element){
        if (length == maxLength){
            resize();
        }
        array[length] = element;
        length++;
    }

    void remove(int index){
        for (int i = index + 1; i < this->length; i++){
            array[i - 1] = array[i];
        }
        this->length--;
    }

    int getSize(){
        return length;
    }
};

#endif //BANKSIMULATOR_LIST_H
