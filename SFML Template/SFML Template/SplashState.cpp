//
//  SplashState.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-28.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace QT {
    SplashState::SplashState( GameDataRef data): _data(data) {
        
    }


    // Loading the texture (i.e. company's logo) using AssetManager
    void SplashState::init() {
        _data->assets.loadTexture( "Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH );
        _background.setTexture( this->_data->assets.getTexture( "Splash State Background" ));
    }


    void SplashState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event ) ) {
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
        }
    }


    void SplashState::update( float dt ) {
        // If the time in the game already passed the Splash State's time (2 secs), go to Main Menu
        if ( _clock.getElapsedTime().asSeconds()  >  SPLASH_STATE_SHOW_TIME ) {
            _data->machine.addState( StateRef( new MainMenuState( _data )), true );
        }
    }


    void SplashState::draw( float dt ) {
        _data->window.clear();
        _data->window.draw( _background );
        _data->window.display();
    }
}
