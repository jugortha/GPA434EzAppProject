
#include "WorldSimulator.h"
#include "Vect2d.h"
#include <sstream>
#include <EzApp>

WorldSimulator::WorldSimulator(size_t width, size_t height)
    : mWidth{ width },
    mHeight{ height },
    mBackgroundColor(0.34f, 0.45f, 0.56f, 1.0f),
    mPlayer()
{
}

WorldSimulator::~WorldSimulator()
{
}

bool WorldSimulator::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer)
{
    userInput(keyboard);
    userDefence(keyboard);
    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void WorldSimulator::processDisplay(ezapp::Screen& screen)
{
    // Define background color and apply it
    // medium dark grey blue

    screen.setBrush(mBackgroundColor.red(),
        mBackgroundColor.green(),
        mBackgroundColor.blue(),
        mBackgroundColor.alpha());  
    screen.clear();

    mPlayer.updatePlayer(mWidth, mHeight);
    mPlayer.draw(screen);
    
    std::stringstream stream;
    stream << "Mileage: " << this->mPlayer.getMileage() << " PX" ;
   screen.setTextFont({ "arial" });
   screen.setTextSizes();
   screen.drawText(stream.str(), 0.0f, 0.0f);
}

void WorldSimulator::userInput(ezapp::Keyboard const& keyboard)
{
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Right)) {
        mPlayer.streeringWheel(1);
    }
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Left)) {
        mPlayer.streeringWheel(-1);
    }
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Up)) {
        mPlayer.setGas(true);
    }
    else  mPlayer.setGas(false) ;

}

void WorldSimulator::userDefence(ezapp::Keyboard const& keyboard) {
    //Sheald
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Space)) { mPlayer.setShealding(true);
    }
    else
    {
        mPlayer.setShealding(false);
    }

}