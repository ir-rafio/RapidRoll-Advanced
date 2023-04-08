#include "Platform.hpp"

Platform::Platform(int x, const ItemType _itemtype): width(50+rand()%21+rand()%21+rand()%11), platformtype(regular), item(nullptr), itemtype(_itemtype)
{
    if(x+width>1200)
    {
        x=1200-width-rand()%50;
        if(!(rand()&7)) x=1200-width;
    }

    texture.loadFromFile("../data/img/Platform.jpg");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, 10));
    sprite.setColor(sf::Color::Black);
    sprite.setPosition(x, 690);

    switch(_itemtype)
    {
    case coin:
        item=new Coin(x+rand()%(width-10));
        break;

    case boost:
        item=new Boost(x+rand()%(width-10));
        break;

    case protection:
        item=new Protection(x+rand()%(width-10));
        break;

    case slowdown:
        item=new SlowDown(x+rand()%(width-10));
        break;

    case gem:
        item=new Gem(x+rand()%(width-10));
        break;
    }
}

Platform::~Platform()
{
    if(item) delete item;
}

int Platform::getWidth() const
{
    return width;
}
void Platform::setballx(const int x)
{
    ballx=x-sprite.getPosition().x;
}
int Platform::getballx() const
{
    return ballx;
}
Item* Platform::getItem() const
{
    return item;
}
ItemType Platform::getItemType() const
{
    return itemtype;
}

int Platform::getPlatformType() const
{
    return platformtype;
}

bool Platform::checkpickup() const
{
    if(!item) return 0;
    return (ballx+8 >= item->sprite.getPosition().x - sprite.getPosition().x && ballx-8 <= item->sprite.getPosition().x - sprite.getPosition().x + 10);
}

void Platform::pickup()
{
    delete item;
    item=nullptr;
    itemtype=nothing;
}

// virtual void Platform::move{
//check Platform.hpp
//}
