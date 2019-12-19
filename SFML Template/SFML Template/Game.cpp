//
//  Game.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Game.hpp"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>

namespace QT {

    Game::Game(int width, int height, std::string title ) {
        srand( time(nullptr) );     // Make a better randomization
        
        _data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );
        _data->machine.addState( StateRef( new SplashState( _data ) ));
        
        run();
    }


    void Game::run() {
        float newTime, frameTime, interpolation;
        
        float currentTime = _clock.getElapsedTime().asSeconds();      // This is the elapsed time since the clock started.
        float accumulator = 0.0f;
        
        while ( _data->window.isOpen() ) {     // We'll constantly running this loop while window is open
            // Check if there's any change in current state (i.e. remove/ add & init() new state)
            _data->machine.processStateChanges();
            
            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if ( frameTime > 0.25f ) {
                frameTime = 0.25f;
            }
            
            currentTime = newTime;
            accumulator += frameTime;
            
            while ( accumulator >= dt ) {
                _data->machine.getActiveState()->handleInput();
                _data->machine.getActiveState()->update( dt );
                accumulator -= dt;
            }
            
            interpolation = accumulator / dt;
            _data->machine.getActiveState()->draw( interpolation );
        }
    }


}


