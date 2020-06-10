
#include "WorldSimulator.h"
#include "Vect2d.h"
#include <sstream>
#include <EzApp>

WorldSimulator::WorldSimulator(size_t width, size_t height)
    : mWidth{ width },
    mHeight{ height },
    mBackgroundColor(0.34f, 0.45f, 0.56f, 1.0f),
    mPlayer(),
    asteroidMilestone{ 500 },
    bestScore{0.0f}
{
}

WorldSimulator::~WorldSimulator()
{
}

bool WorldSimulator::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer)
{
    userInput(keyboard);
    userDefence(keyboard);
    asteroidGeneration(asteroidMilestone);
    CollisionManager();

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
    
    for (auto& Asteroid : mAsteroids) {
        Asteroid.updateAsteroid(mWidth, mHeight);
    }
    
    //Draw ech asteroid
    for (auto& Asteroid : mAsteroids) {
        Asteroid.draw(screen);
    }
   
    mPlayer.draw(screen);
    
    std::stringstream stream;
    stream << "Mileage: " << mPlayer.getMileage() << " PX" << std::endl << "Best Score: " << bestScore;
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

void WorldSimulator::asteroidGeneration(int milestone)
{
    if(!((int)mPlayer.getMileage() /milestone < mAsteroids.size()))
    {
        Asteroid newAsteroid(10.0f, 50.0f, 0.0f, (float)mWidth, 0, (float)mHeight, 1.f, 3.0f, 5, 10, 0, 2 * PI);
        
        mAsteroids.push_back(newAsteroid);
        
    }
    
}
void WorldSimulator::CollisionManager()
{
    for (auto& Asteroid : mAsteroids) {
        //float instantDistance{ pow(Asteroid.mShape.position().x() - mPlayer.mShape.position().x(), 2) + pow(Asteroid.mShape.position().y() - mPlayer.mShape.position().y(), 2) };
        mPlayer.mShape.position().distance_squared(Asteroid.mShape.position());
       // if (instantDistance <= pow(Asteroid.mShape.radius() + mPlayer.mShape.radius(), 2))
        if (mPlayer.mShape.position().distance_squared(Asteroid.mShape.position()) <= pow(Asteroid.mShape.radius() + mPlayer.mShape.radius(), 2))
        {
            if (bestScore < mPlayer.mMileage)
            {
                //set bestscore
                bestScore = mPlayer.mMileage;
                
            }
            if (mPlayer.getShealding() == false)
            {
                //reset mileage
                mPlayer.mMileage = 0;
                
            }
            

            
        } 
    }
   
}


