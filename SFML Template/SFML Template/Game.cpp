//
//  Game.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Game.hpp"
#include "SplashState.hpp"

namespace QT {
    Game::Game(int width, int height, std::string title ) {
        _data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );
        _data->machine.addState( StateRef(new SplashState(this->_data)) );
        
        this->run();
    }

    void Game::run() {
        float newTime, frameTime, interpolation;
        
        float currentTime = this->_clock.getElapsedTime().asSeconds();      // This is the elapsed time since the clock started.
        float accumulator = 0.0f;
        
        while ( this->_data->window.isOpen() ) {     // We'll constantly running this loop while window is open
            this->_data->machine.processStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if ( frameTime > 0.25f ) {
                frameTime = 0.25f;
            }
            
            currentTime = newTime;
            accumulator += frameTime;
            
            while ( accumulator >= dt ) {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update( dt );
                accumulator -= dt;
            }
            
            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw( interpolation );
            
        }
    }
}


