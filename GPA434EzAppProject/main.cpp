
#include <EzApp>
#include "WorldSimulator.h"

// Application
// Keyboard
// Screen
// Timer



int WinMain() 
{
    // Define default parameters
    size_t const windowWidth{ 1200 };
    size_t const windowHeight{ 1000 };
    std::string const title("GPA434 Projet 1");
    std::string const iconFilename("GPALogo.png");
    std::list<std::string> const fontFilename({ "Arial" });

    // Define main application and setup parameters
    ezapp::Application app(ezapp::Application::Parameters(windowWidth, windowHeight, title, iconFilename, fontFilename));

    // Define world
    WorldSimulator worldSimulator(windowWidth, windowHeight);

    // Run application
    app.run(worldSimulator, &WorldSimulator::processEvents, &WorldSimulator::processDisplay);

    // End the program
    return 0;
}