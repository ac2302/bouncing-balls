#include <iostream>
#include <vector>
#include <cmath>

#define distance(x1, y1, x2, y2) (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)))

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
    int frameWidth, frameHeight, nCircles, x, y;
    unsigned short int tempR, tempG, tempB;
    bool set;
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

    // output the header to stdout
    std::cout << "P6\n"
              << frameWidth << ' ' << frameHeight << "\n255\n";

    // print the pixels
    for (int i = 0; i < frameHeight; i++)
        for (int j = 0; j < frameWidth; j++)
        {
            x = j;
            y = frameHeight - i - 1;

            set = false;

            for (Circle c : circles)
            {
                if (distance(c.centerX, c.centerY, x, y) <= c.radius)
                {
                    set = true;
                    tempR = c.r;
                    tempG = c.g;
                    tempB = c.b;
                }
                else if (!set)
                {
                    tempR = bgR;
                    tempG = bgG;
                    tempB = bgB;
                }
            }

            printf("%c%c%c", tempR, tempG, tempB);
        }
}