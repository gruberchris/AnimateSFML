//
// Created by Christopher Gruber on 9/17/23.
//

#ifndef ANIMATESFML_GAME_H
#define ANIMATESFML_GAME_H

#include <SFML/Graphics.hpp>

namespace AnimateSFML {

    /*
     * Game class
     * This class is the main class for the game.
     */
    class Game {
    private:
        sf::RenderWindow *window{};
        sf::VideoMode videoMode;
        sf::Event event{};
        bool isPaused{};
        sf::CircleShape ball;

        void initVariables();
        void initWindow();
        void initBalls();

    public:
        Game();
        virtual ~Game();

        // Accessors
        [[nodiscard]] bool isRunning() const;

        // Methods
        void pollEvents();
        void update();
        void render();
    };

} // AnimateSFML

#endif //ANIMATESFML_GAME_H
