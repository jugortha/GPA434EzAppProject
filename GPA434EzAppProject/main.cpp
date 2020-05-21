
#include <EzApp>

// Application
// Keyboard
// Screen
// Timer

bool processEvents(ezapp::Keyboard const & keyboard, ezapp::Timer const & timer) {
    // ...

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}


void processDisplay(ezapp::Screen & screen) {
    // Define background color and apply it
    screen.setBrush(0.34f, 0.45f, 0.56f, 1.0f); // medium dark grey blue
    screen.clear();

    // ...
}


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

    // Run application
    app.run(processEvents, processDisplay);

    // End the program
    return 0;
}