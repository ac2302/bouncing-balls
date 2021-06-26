#include <iostream>
#include<vector>

struct Circle {
    int centerX;
    int centerY;
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

int main()
{
    int frameWidth, frameHeight;
    uint8_t bgR, bgG, bgB;
    std::vector<Circle> circles;
    
    // reading the data from stdin
    std::cin >> frameWidth >> frameHeight >> bgR >> bgG >> bgB;

    std::cout << frameWidth << std::endl;
    std::cout << frameHeight << std::endl;
    std::cout << bgR << std::endl;
    std::cout << bgG << std::endl;
    std::cout << bgB << std::endl;
}