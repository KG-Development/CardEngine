#pragma once

class Color{

public:
    Color(int red = 255, int green = 255, int blue = 255);

    int getRed();
    int getGreen();
    int getBlue();

    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);
private:
    int red;
    int green;
    int blue;
};
