#include <iostream>
class GridSquare{
    int x;
    int y;
    bool full;
    static const int square_size;
public:
    explicit GridSquare(int x=1, int y=1, bool full=false) : x(x), y(y), full() {}
    GridSquare(const GridSquare& other){
        this->x=other.x;
        this->y=other.y;
        this->full=other.full;
    }
    ~GridSquare()=default;
};
const int GridSquare:: square_size=20;


class Grid{
    const int length;
    const int width;
    GridSquare gridsquares[30][40];
public:
    Grid(const int _length, const int _width) : length(_length), width(_width){}
    ~Grid()=default;
};

class Snake{
    int size;
    const int max_size;
    GridSquare *body;
public:
    Snake(int size, const int maxSize, GridSquare *body) : size(size), max_size(maxSize), body(body) {}
    Snake(const Snake& other): max_size(other.max_size) {
        this->size=other.size;
        this->body=other.body;
    }
    ~Snake()=default;
};

class Fruit{
    int x;
    int y;
    const int score;
public:
    explicit Fruit(int _x=0,int _y=0,int _score=0):score{_score} {
        this->x=_x;
        this->y=_y;
    }
};

class Star{
    int x;
    int y;
    const int score;
public:
    explicit Star(int _x=0,int _y=0,int _score=0):score{_score} {
        this->x=_x;
        this->y=_y;
    }
public:
};
int main() {
    std::cout << "Hello, world!\n";
    return 0;
}
