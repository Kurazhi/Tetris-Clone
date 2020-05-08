#include <iostream>
#include "WindowManager.h"

int main(int argc, char* argv[])
{
    WindowManager* window = new WindowManager;
    if (!window->init())
    {
        std::cerr << "Unable to initalize the game\n" << std::endl;
    }
    window->run();
    window->close();
    delete window;
    return 0;
}