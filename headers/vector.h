//
// Created by Andrei on 1/7/2024.
//

#ifndef OOP_VECTOR_H
#define OOP_VECTOR_H


template <typename T, int size>
class vector{
    T array[size];
public:
    T& at(int index){
        return array[index];
    }
    vector()=default;
};



#endif //OOP_VECTOR_H
