#ifndef MISC_H
#define MISC_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

extern int bg;
extern sf::RenderWindow window;
extern sf::Event event;
extern sf::Clock clk;
extern sf::Music music;
extern sf::Font arial;
extern sf::Font ArchitectsDaughter;

enum PlatformType
{
    regular,
    spike,
    moving,
    bouncing
};
enum ItemType
{
    nothing,
    coin,
    booster,
    protection,
    slowdown,
    gem
};

#define XButton event.mouseButton.x*1280/window.getSize().x
#define YButton event.mouseButton.y*720/window.getSize().y
#define XCursor event.mouseMove.x*1280/window.getSize().x
#define YCursor event.mouseMove.y*720/window.getSize().y

void icon();
void intro();
int menu();
void drawbg();
void drawframe();
std::string scanfromscreen(sf::Text& text, sf::IntRect rect);

void readrecords(std::set<std::pair<int, std::string>> &records, std::ifstream &fin);
void displayrecords(const std::set<std::pair<int, std::string>> &records);
void drawrecord(int score);
bool newrecord(std::set<std::pair<int, std::string>> &records, int score);
void addrecord(std::set<std::pair<int, std::string>> &records, int score);

void roll(std::vector<std::string>& text);

#endif
