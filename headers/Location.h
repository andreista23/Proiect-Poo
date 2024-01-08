//
// Created by Andrei on 1/6/2024.
//

#ifndef OOP_LOCATION_H
#define OOP_LOCATION_H
#include "Exceptions.h"

class Location {
public:
    int x;
    int y;
public:
    explicit Location(int x=0, int y=0);
    bool operator==(const Location &rhs) const;
    bool operator!=(const Location &rhs) const;
    void SetLoc(Location newloc);
    void Add(Location delta_loc);
    Location operator+(const Location& other) const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
};


#endif //OOP_LOCATION_H
