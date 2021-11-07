#include "Ball.hpp"

Ball::Ball(Platform* platform): standingOn(platform), isProtected(0), isBoosted(0)
{
    texture.loadFromFile("data/img/running.png");//setting the first square
    fox.setTexture(texture);
    fox.setTextureRect(sf::IntRect(0, 0, 108, 108));
    platform->setballx(platform->sprite.getPosition().x + platform->getWidth()/2 + (1-2*(rand()&1))*(rand()%(platform->getWidth()/2-5)));
    fox.setOrigin(54, 80);
    fox.setScale(0.5, 0.5);
    fox.setPosition(platform->sprite.getPosition().x+platform->getballx(), platform->sprite.getPosition().y);
}

bool Ball::isFalling() const
{
    return !standingOn;
}

int Ball::findPlatform(Queue<Platform*>& platforms)
{
    standingOn=nullptr;

    for(int i=0; i<platforms.size(); i++)
    {
        if(fox.getPosition().y >= platforms[i]->sprite.getPosition().y && fox.getPosition().y <= platforms[i]->sprite.getPosition().y+11)
            if(fox.getPosition().x+7> platforms[i]->sprite.getPosition().x)
                if(fox.getPosition().x-7 < platforms[i]->sprite.getPosition().x+platforms[i]->getWidth())
                {
                    if(typeid(*platforms[i])==typeid(Spike)) return 3*(!isProtected);
                    if(typeid(*platforms[i])==typeid(BouncyPlatform)) return 4;
                    standingOn=platforms[i];
                    platforms[i]->setballx(fox.getPosition().x);
                    if(platforms[i]->checkpickup()) return 2;
                    return 1;
                }
    }

    return 0;
}
