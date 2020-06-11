
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
    bestScore{0.0f},
    mCollisionIndicator{false},
    mTimeCounter{0},
    mTimeCounter2{ 0 }
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
    CollisionDetector();

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void WorldSimulator::processDisplay(ezapp::Screen& screen)
{
    //BackgroundColor and animation
    CollisionAnimation(screen);
    screen.clear();
    mPlayer.updatePlayer(mWidth, mHeight);
    updateAsteroidsSwarm(screen);
    mPlayer.draw(screen);
    screenText(screen);
    
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
    if(!((int)mPlayer.Mileage() /milestone < mAsteroids.size()))
    {
        Asteroid newAsteroid(15.0f, 60.0f, 0.0f, (float)mWidth, 0, (float)mHeight, 1.f, 3.0f, 5, 10, 0, 2 * PI);
        
        mAsteroids.push_back(newAsteroid);
        
    }
    
}
void WorldSimulator::CollisionDetector()
{
    for (auto& Asteroid : mAsteroids) {
       
        mPlayer.mShape.position().distance_squared(Asteroid.mShape.position());
       
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
                mCollisionIndicator = true;
                Asteroid.mCollisionSpin = true;
                
            }
            

            
        } 
    }
   
}

void WorldSimulator::updateAsteroidsSwarm(ezapp::Screen& screen) {
    //Draw ech asteroid

    for (auto& Asteroid : mAsteroids) {
        Asteroid.updateAsteroid(mWidth, mHeight);

        if (Asteroid.mCollisionSpin)
        {
            mTimeCounter2 += 0.025f;

            Asteroid.draw(screen, mTimeCounter2);

            if (mTimeCounter2 > 6.24f)
            {
                mTimeCounter2 = 0;
                Asteroid.mCollisionSpin = false;
            }
        }
        else
        {
            Asteroid.draw(screen);
        }
    }
}

void WorldSimulator::CollisionAnimation(ezapp::Screen& screen){
    // Define background color and apply it
    // medium dark grey blue
    if (mCollisionIndicator)
    {
        screen.setBrush(1, 0, 0, 1);
        mTimeCounter++;

        if (mTimeCounter == 100)
        {
            mCollisionIndicator = false;
            mTimeCounter = 0;
        }
    }
    else
    {
        screen.setBrush(mBackgroundColor.red(),
            mBackgroundColor.green(),
            mBackgroundColor.blue(),
            mBackgroundColor.alpha());
    }
}

void WorldSimulator::screenText(ezapp::Screen& screen){
    std::stringstream stream;
    stream << "Mileage: " << (int)mPlayer.Mileage() << " PX" << std::endl << "Best Score: " << (int)bestScore << std::endl << "Asteroids on screen: " << mAsteroids.size();
    screen.setTextFont({ "arial" });
    screen.setTextSizes();
    screen.drawText(stream.str(), 0.0f, 0.0f);
}