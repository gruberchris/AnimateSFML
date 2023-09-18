//
// Created by Christopher Gruber on 9/17/23.
//

#include "Game.h"

namespace AnimateSFML {
    Game::Game() {
        this->initVariables();
        this->initWindow();
        this->initBalls();
    }

    void Game::initVariables() {
        this->window = nullptr;
    }

    void Game::initWindow() {
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        this->videoMode = sf::VideoMode(800, 600);
        this->window = new sf::RenderWindow(this->videoMode, "Animate SFML", sf::Style::Titlebar | sf::Style::Close, settings);
        this->isPaused = false;
        this->window->setFramerateLimit(60);
    }

    void Game::initBalls() {
        this->ball.setRadius(100.f);
        this->ball.setFillColor(sf::Color::Blue);
        this->ball.setPosition(50.f, 50.f);
        this->ball.setOutlineColor(sf::Color::Cyan);
        this->ball.setOutlineThickness(10.f);
        this->ball.setScale(sf::Vector2f(0.5f, 0.5f));
    }

    Game::~Game() {
        delete this->window;
    }

    void Game::pollEvents() {
        while (this->window->pollEvent(this->event)) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        this->window->close();
                    }

                    if (event.key.code == sf::Keyboard::Space) {
                        this->isPaused = !this->isPaused;
                    }

                    if (event.key.code == sf::Keyboard::Up) {
                        this->ball.move(0.f, -10.f);
                    }

                    if (event.key.code == sf::Keyboard::Down) {
                        this->ball.move(0.f, 10.f);
                    }

                    if (event.key.code == sf::Keyboard::Left) {
                        this->ball.move(-10.f, 0.f);
                    }

                    if (event.key.code == sf::Keyboard::Right) {
                        this->ball.move(10.f, 0.f);
                    }

                    if (event.key.code == sf::Keyboard::N) {
                        this->ball.setPosition(50.f, 50.f);
                    }

                    break;

                default:
                    break;
            }
        }
    }

    void Game::update() {
        this->pollEvents();
    }

    void Game::render() {
        this->window->clear();

        // Draw game objects
        if (!this->isPaused) {
            this->ball.move(1.f, 1.f);
        }

        window->draw(this->ball);

        this->window->display();
    }

    bool Game::isRunning() const {
        return this->window->isOpen();
    }
} // AnimateSFML