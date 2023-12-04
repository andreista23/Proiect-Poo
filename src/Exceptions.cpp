//
// Created by Andrei on 12/4/2023.
//
#include "../headers/Exceptions.h"

const char *ExceptionOutOfMapBounds::what() const noexcept {
    return "Object is out of bounds";
}

const char *ExceptionMoveOutOfBounds::what() const noexcept {
    return "Object cannot move out of bounds";
}
