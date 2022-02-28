#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <random>
#include <thread>
#include "arraySort.h"
#include "sorts.h"

auto getDefaultVideoMode() {
    auto [w, h, p] = sf::VideoMode::getDesktopMode();
    return sf::VideoMode(w / 1.75, h / 1.75, p);
}


int main()
{
    sf::RenderWindow window(getDefaultVideoMode(), "Sort Visualizator");


    //generating a vector sort situations
    arraySort array(300);
    array.funcSort = bubble_sort<int>;
    auto situations = array.statisticSort();
    int indx = 0;

    while (window.isOpen()) {
        //Process events of the window
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        //clear second buufer, then draw objs in the second buffer,
        //then do swap buffers to see 
        window.clear();

        if (indx == situations.size()) {
            indx -= 1;
        }

        auto situation = situations[indx++];
        const float width = window.getSize().x / (double)situation.size();
        const float height = window.getSize().y / (double)situation.size();
        sf::RectangleShape rect({ width, height * situation[0] });
        for (int i = 0; i < situation.size(); i++) {
            rect.setSize({ width, height * situation[i] });
            rect.setPosition({width * i, window.getSize().y - rect.getSize().y});
            window.draw(rect);
        }


        window.display();
    }

    return 0;
}