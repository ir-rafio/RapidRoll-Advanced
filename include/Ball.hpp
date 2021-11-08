#ifndef BALL_H
#define BALL_H

#include "Platform.hpp"
#include "Spike.hpp"
#include "BouncyPlatform.hpp"
#include "Queue.hpp"
#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include <typeinfo>
class Ball
{
    int isProtected, isBoosted;
    Platform *standingOn;
    Ball(Platform *);
    friend class Game;
    friend void Boost::bonus(int *_isBoosted);
    friend void Protection::bonus(int *_isProtected);

public:
    sf::Texture texture;
    sf::Sprite fox;
    bool isFalling() const;
    int findPlatform(Queue<Platform *> &);
};

#endif
