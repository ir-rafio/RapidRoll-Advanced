#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Game.hpp"
#include "misc.hpp"

int main()
{
    srand(time(0));
    arial.loadFromFile("../data/font/arial.ttf");
    ArchitectsDaughter.loadFromFile("../data/font/ArchitectsDaughter-Regular.ttf");

    window.create(sf::VideoMode(1280, 720), "Rapid Roll Advanced");
    icon();
    intro();

    int choice;

    std::set<std::pair<int, std::string>> records;
    std::ifstream fin("../data/High_Score.txt");
    readrecords(records, fin);
    fin.close();

    while(window.isOpen())
    {
        choice=menu();

        if(choice==1)
        {
            Game game;
            game.run();

            int score=game.getScore();
            if(newrecord(records, score)) addrecord(records, score);
        }

        else if(choice==2) displayrecords(records); //high scores

        else if(choice==3)
        {
            //instructions
        }

        else if(choice==4)
        {
            //credits

            std::cout << '\n';
            std::cout << "Gameplay Concept:\nRapid Roll\nNokia\n\n";
            std::cout << "Backgrounds:\nThe First Tree\nBy David Wehle\n\n";
            std::cout << "Music:\n\"Gravity Falls Main Title Theme\"\nBy Brad Breeck\nFrom Gravity Falls- Created By Alex Hirsh\nA Television Animation By Disney\n\n\"Call of Destiny\"\nBy Josh Kramer\n\n";
            std::cout << "Intro Fox:\nTenor\nhttps://i2.wp.com/media1.tenor.com/images/ab80e83e9f913b87bb33cedf9cac2ef2/tenor.gif\n\n";

            std::vector<std::string> credits;
            credits.push_back("Gameplay Concept:");
            credits.push_back("Rapid Roll");
            credits.push_back("Nokia");
            credits.push_back("");
            credits.push_back("Backgrounds:");
            credits.push_back("The First Tree");
            credits.push_back("By David Wehle");
            credits.push_back("");
            credits.push_back("Music:");
            credits.push_back("'Gravity Falls Main Title Theme'");
            credits.push_back("By Brad Breeck");
            credits.push_back("From Gravity Falls");
            credits.push_back("Created By Alex Hirsh");
            credits.push_back("A TV Animation By Disney");
            credits.push_back("");
            credits.push_back("'Call of Destiny'");
            credits.push_back("By Josh Kramer");
            //roll(credits);
        }

        else window.close();
    }

    std::ofstream fout("../data/High_Score.txt");
    for(auto it=records.begin(); it!=records.end(); it++) fout << it->first<< '#' << it->second << '#';

    return 0;
}
