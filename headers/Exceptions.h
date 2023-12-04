//
// Created by Andrei on 12/4/2023.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H
#include <iostream>

class ExceptionOutOfMapBounds : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class ExceptionMoveOutOfBounds : public std::exception{
public:
    [[nodiscard]] const char* what() const noexcept override;
};
#endif //OOP_EXCEPTIONS_H
