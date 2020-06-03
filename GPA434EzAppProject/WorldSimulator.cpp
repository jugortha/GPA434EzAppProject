
#include "WorldSimulator.h"
#include "Vect2d.h"

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
    // run until ESCAPE is pressed

    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void WorldSimulator::processDisplay(ezapp::Screen& screen)
{
    screen.setBrush(mBackgroundColor.red(),
        mBackgroundColor.green(),
        mBackgroundColor.blue(),
        mBackgroundColor.alpha());
    
    // Define background color and apply it
    screen.setBrush(0.34f, 0.45f, 0.56f, 1.0f); // medium dark grey blue
    screen.clear();

    mPlayer.draw(screen);
}