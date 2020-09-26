#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "Player.hpp"

void displayBoard(Board& b, Player& p) {
    for (int row = 0; row < b.getHeight(); row++) {
        for (int col = 0; col < b.getWidth(); col++) {
            std::cout << "[ ";
            if (b.getField(col, row).isWall) {
                std::cout << "W";
            } else if (p.getCol() == col && p.getRow() == row) {
                std::cout << "P";
            } else {
                std::cout << " ";
            }
            std::cout << " ]";
        }
        std::cout << '\n';
    }
}

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 608), "Bomberman");
    Board board(19, 25);

    window.display();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(board.getSprite());
        board.draw(window);
        window.display();
    
    }

    return 0;
}
