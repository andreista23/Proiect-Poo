#include <iostream>
#include <utility>
using namespace std;

class Player;
class Fruit;
class Star;
class GridSquare;
class Grid;
class Snake;

class GridSquare{
    int x;
    int y;
    bool full;
    static const int square_size;
public:
    explicit GridSquare(int _x=1, int _y=1, bool _full=false) : x(_x), y(_y), full(_full) {}
    GridSquare(const GridSquare& other){
        this->x=other.x;
        this->y=other.y;
        this->full=other.full;
    }
    ~GridSquare()=default;
    [[nodiscard]] bool isSameSquare(const GridSquare& other) const{
        if(other.x==this->x&&other.y==this->y)
            return true;
        return false;
    }
    void  setposition(int _x, int _y){
        this->x=_x;
        this->y=_y;
    }
    friend ostream &operator<<(ostream &os, const GridSquare &square) {
        os << "x: " << square.x << " y: " << square.y << " full: " << square.full<<" square size: "<<square_size;
        return os;
    }
    GridSquare& operator=(const GridSquare& gr)= default;
};
const int GridSquare:: square_size=20;

class Grid{
    const int length;
    const int width;
public:
    explicit Grid(const int _length=40, const int _width=30) : length(_length), width(_width){}
    ~Grid()=default;

    friend ostream &operator<<(ostream &os, const Grid &grid) {
        os << "length: " << grid.length << " width: " << grid.width;
        return os;
    }
};

class Snake{
    int size;
    static const int max_size=10;
    GridSquare body[max_size];
public:
    explicit Snake(int _size=1,int _x=1, int _y=1) : size(_size) {
        body[size].setposition(_x,_y);
    }
    Snake(const Snake& other) {
        this->size=other.size;
        for(int i=0;i<max_size;i++)
            this->body[i]=other.body[i];
    }
    ~Snake()=default;
    GridSquare& getSnakeHead(){
        return this->body[size-1];
    }
    void IncreaseSize(){
        size++;
    }
    friend ostream &operator<<(ostream &os, const Snake &snake) {
        os << "size: " << snake.size << " max_size: " <<max_size << " body: ";
        for(int i=1;i<=snake.size;i++)
            cout<<snake.body[i];
        return os;
    }
};
class Fruit{
    GridSquare fruitsquare;
    const int score;
public:
    explicit Fruit(int _x=1,int _y=1,int _score=25):score{_score} {
        fruitsquare.setposition(_x,_y);
    }
    Fruit(const Fruit& other): score{other.score}{
        fruitsquare=other.fruitsquare;
    }
    ~Fruit()=default;
    GridSquare  getfruitsquare() {
        return this->fruitsquare;
    }
    [[nodiscard]] int getscore() const{
        return score;
    }
    friend ostream &operator<<(ostream &os, const Fruit &fruit) {
        os <<fruit.fruitsquare<< " score: " << fruit.score;
        return os;
    }
    Fruit& operator=([[maybe_unused]] const Fruit& other){
        this->fruitsquare=other.fruitsquare;
        return *this;
    }
};

class Star{
    GridSquare starsquare;
    const int score;
public:
    explicit Star( int _x=1, int _y=1,int _score=50):score{_score} {
        starsquare.setposition(_x,_y);
    }
    Star(const Star& other): score{other.score}, starsquare(other.starsquare){
        starsquare=other.starsquare;
    }
    ~Star()=default;
    GridSquare  getstarsquare() {
        return this->starsquare;
    }
    [[nodiscard]] int getscore() const{
        return score;
    }
    friend ostream &operator<<(ostream &os, const Star &star) {
        os <<star.starsquare<< " score: " << star.score;
        return os;
    }
    Star& operator=([[maybe_unused]] const Star& other){
        starsquare=other.starsquare;
        return *this;
    }
};


class Player{
    string name;
    int score;
    Snake playersnake;
public:
    explicit Player(string _name = "player1", int _score=0, int _x=1, int _y=1):name{std::move(_name)}{
        score=_score;
        playersnake.getSnakeHead().setposition(_x,_y);
    }
    ~Player()=default;
    friend ostream& operator<<(ostream& os,const Player& pl){
        os<<"name: "<<pl.name<<" score= "<<pl.score<<" player_snake: "<<pl.playersnake;
        return os;
    }
    int EatFruit(Fruit& fr){
        if(playersnake.getSnakeHead().isSameSquare(fr.getfruitsquare())){
            cout<<"fruct mancat"<<endl;
            score=score+fr.getscore();
            playersnake.IncreaseSize();
            return 1;
        }
        return 0;
    }
    int EatStar(Star& st){
        if(playersnake.getSnakeHead().isSameSquare(st.getstarsquare())){
            cout<<"stea mancata"<<endl;
            score=score+st.getscore();
            playersnake.IncreaseSize();
            return 1;
        }
        return 0;
    }
};


int main() {
    Grid grid(30,30);
    cout<<"grid: "<<grid<<endl;
    Player player1("andrei",0,2,3);
    Fruit fr1(2,3),fr2(5,10);
    Star st(1,1),st2(2,3);
    player1.EatFruit(fr1);
    player1.EatFruit(fr2);
    player1.EatStar(st);
    player1.EatStar(st2);
    cout<<player1;
    return 0;
}
