class Player{
    int x, y;

    public:
    Player(const int Y = 0, const int X = 0);

    void setPlayerCoords(const int Y, const int X){y = Y, x = X;}
};