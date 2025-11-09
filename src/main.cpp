#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Wierzcholek.h"
#include "Agent.h"
using namespace std;
using namespace sf;



int main()
{
    auto window = RenderWindow(VideoMode({450u, 450u}), "ProjectMapping.ver1");
    window.setFramerateLimit(144);
    vector<Vertex_> vertex;
    vector<RectangleShape> squares;
    vector<vector<Vertex>> line;
    create_map(vertex, squares, line);
    Agent_dfs a1(1, vertex[0], vertex[0]);
    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
            {
                window.close();
            }
            if (const auto keyEvent = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyEvent->code == sf::Keyboard::Key::Space)
                {
                    a1.getCurrentVertex();
                    a1.move(vertex);
                }
            }
        }
        window.clear();
        for (const auto & i : squares) {
            window.draw(i);
            for (const auto& l : line) {
                window.draw(l.data(), l.size(), PrimitiveType::Lines);
            }
        }
        a1.draw(window);

        window.display();
    }
}