class point
{
private:
    float x;
    float y;

public:
    point();
    point(float X, float Y);
    void setX(float X);
    void setY(float Y);
    float getX();
    float getY();
    void display();
    float distance(point p);
};
point Center(point *C, int n);
point *closest(point *A, int nA, point *B, int nB, point p);
