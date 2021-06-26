#include <iostream>
#include <vector>

struct Circle
{
    int radius;
    int centerX;
    int centerY;
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

int main()
{
    int frameWidth, frameHeight, nCircles;
    unsigned short int tempR, tempG, tempB;
    uint8_t bgR, bgG, bgB;
    std::vector<Circle> circles;

    // reading the data from stdin
    std::cin >> frameWidth >> frameHeight >> tempR >> tempG >> tempB >> nCircles;
    bgR = tempR & 0xff;
    bgG = tempG & 0xff;
    bgB = tempB & 0xff;

    // reading the circles data
    for (int i = 0; i < nCircles; i++)
    {
        Circle newCircle;
        std::cin >> newCircle.radius >> newCircle.centerX >> newCircle.centerY >> tempR >> tempG >> tempB;
        newCircle.r = tempR & 0xff;
        newCircle.g = tempG & 0xff;
        newCircle.b = tempB & 0xff;
        circles.push_back(newCircle);
    }
}