
#include <EzApp>
#include <math.h>

#include <array>
#include <vector>


#include "Color.h"
#include "Vect2d.h"
#include "Polygon.h"

// Application
// Keyboard
// Screen
// Timer

bool processEvents(ezapp::Keyboard const & keyboard, ezapp::Timer const & timer) {
    // ...

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
    //bool isEscapePressed{ keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape) };
    //if (isEscapePressed) {
    //    return false;
    //} else {
    //    return true;
    //}
}
float v{ 0.0f };

void processDisplay(ezapp::Screen & screen) {
    Color myAwesomeColor1(1.0f, 1.0f, 0.0f);        // jaune
    Color myAwesomeColor2(1.0f, 0.0f, 1.0f, 1.0f);  // magenta
    Color myAwesomeColor3;                          // noir
    myAwesomeColor3 = myAwesomeColor1.processGradient(myAwesomeColor2, std::sin(v) * 0.5f + 0.5f, false);
    v += 0.005f;

    screen.setBrush(myAwesomeColor3.red(),
        myAwesomeColor3.green(),
        myAwesomeColor3.blue(),
        myAwesomeColor3.alpha());
    screen.clear();


    //std::vector<Vect2d> polygon(3);
    //polygon[0].set(0.0f, 0.0f);
    //polygon[1].set(100.0f, 100.0f);
    //polygon[2].set(-100.0f, 100.0f);
    //screen.setPolygonVertices(polygon);
    //myAwesomeColor3.invert();
    //screen.setBrush(myAwesomeColor3.red(), 
    //                myAwesomeColor3.green(), 
    //                myAwesomeColor3.blue(), 
    //                myAwesomeColor3.alpha());
    //screen.drawPolygon(200.0f + v * 40.0f, 200.0f);


    Polygon p;
    myAwesomeColor3.invert();
    p.buildRegular(7, 100.0f);
    p.setColors(myAwesomeColor3, Color(), 1.0f);
    p.draw(screen, 200.0f + v * 40.0f, 200.0f, v * 1.0f);
}


int WinMain() 
{ //// tableau statique
    //int tableau[10]; // c
    //std::array<int, 10> tableauCpp; // c++

    //for (int i{}; i < 10; ++i) {
    //    tableau[i] = 0;
    //    tableauCpp[i] = 0;
    //}

    //// tableau dynamique
    //int n = 72;
    //int* tableauDyn = (int*) malloc(sizeof(int) * n); // c
    //free(tableauDyn);

    //std::vector<int> tableauDynCpp(n);
    //tableauDynCpp.resize(n);
    //size_t taille{ tableauDynCpp.size() };

    //for (int i{}; i < 10; ++i) {
    //    tableauDyn[i] = 0;
    //    tableauDynCpp[i] = 0;
    //}

    //// for range loop
    //int sum{};
    //for (int value : tableauDynCpp) {
    //    sum += value;
    //}









    size_t windowWidth{ 1200 };
    size_t windowHeight{ 1000 };
    std::string title("GPA434 Projet 1");
    std::string iconFilename("GPALogo.png");

    ezapp::Application::Parameters parameters(windowWidth, windowHeight, title, iconFilename);
    ezapp::Application app(parameters);

    app.run(processEvents, processDisplay);

    return 0;
}