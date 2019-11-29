//
//  MainMenuState.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-28.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace QT {

    MainMenuState::MainMenuState( GameDataRef data): _data(data) {
        
    }

    // Loading the texture using AssetManager
    void MainMenuState::init() {
        _data->assets.loadTexture( "Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
        _data->assets.loadTexture( "Game Title", GAME_TITLE_FILEPATH );
        _data->assets.loadTexture( "Play Button", PLAY_BUTTON_FILEPATH );
        
        _background.setTexture( this->_data->assets.getTexture( "Main Menu Background" ));
        _title.setTexture( this->_data->assets.getTexture( "Game Title" ));
        _playButton.setTexture( this->_data->assets.getTexture( "Play Button" ));
        
        // Set the x,y positions of the title: "FlappyBird" (on top of the background)
        _title.setPosition( (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2 );
        
        // Set the x,y positions of the Play button: all the formulas do just that.
        _playButton.setPosition( (SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2) );
        
    }

    void MainMenuState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event )) {
            
            // If the input is "close the window", then close it.
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
            
            // If user clicks on the sprite (i.e. the Play button), go to game screen
            if ( _data->input.isSpriteClicked( _playButton, sf::Mouse::Left, _data->window ) ) {
                std::cout << "Go to Game Screen" << std::endl;
            }
        }
    }

    void MainMenuState::update( float dt ) {
        
    }

    void MainMenuState::draw( float dt ) {
        _data->window.clear();
        
        _data->window.draw( _background );
        _data->window.draw( _title );
        _data->window.draw( _playButton );
        
        _data->window.display();
    }
}
