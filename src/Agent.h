//
// Created by Patryk Zinowkin on 08/11/2025.
//

#ifndef AGENT_H
#define AGENT_H
#include <SFML/Graphics.hpp>
#include "Wierzcholek.h"
class Agent {
protected:
    int id;
    Vertex_ current_vertex;
    vector<bool> visited ;
    Vertex_ start_vertex;

public:
    Agent(int _id, const Vertex_& _current_vertex, const Vertex_& _start):id(_id), current_vertex(_current_vertex), start_vertex(_start) {};
    int getId() const { return this->id; }
    void getCurrentVertex() {current_vertex.Informacje();}

    void draw (sf::RenderWindow& window) {
        sf::RectangleShape rs;
        rs.setSize(sf::Vector2f(5.f, 5.f));
        rs.setFillColor(sf::Color::Red);
        rs.setPosition(sf::Vector2f(current_vertex.getX() -5.f, current_vertex.getY() -5.f));
        window.draw(rs);
    }
    virtual void move(vector<Vertex_>& graf) = 0;
    virtual ~Agent() = default;
};

class Agent_dfs : public Agent {
    std::stack<int> stack;

public:
    Agent_dfs(int _id, const Vertex_& _current_vertex, const Vertex_& _start):Agent(_id, _current_vertex, _start) {
        visited.resize(31, false);
        stack.push(start_vertex.getID());
    };
    void move(vector<Vertex_>& graf) override;
    ~Agent_dfs() override{
        std::cout<<"Destroying Agent_dfs"<<std::endl;
    };
};

//int DFS(vector<Vertex_>& graf, stack<int>& S, vector <bool>& visited);

#endif //AGENT_H
