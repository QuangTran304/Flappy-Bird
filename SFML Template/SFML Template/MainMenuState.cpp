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
#include "GameState.hpp"
#include <iostream>
#include <memory>

namespace QT {

    MainMenuState::MainMenuState( GameDataRef data): _data(data) {
        
    }


    // Loading the textures using AssetManager then set them accordingly with the MainMenu components (i.e. background, title, playButton)
    void MainMenuState::init() {
        _data->assets.loadTexture( "Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
//        _data->assets.loadTexture( "Game Title", GAME_TITLE_FILEPATH );
//        _data->assets.loadTexture( "Play Button", PLAY_BUTTON_FILEPATH );
        
        _background.setTexture( _data->assets.getTexture( "Main Menu Background" ));
//        _title.setTexture( _data->assets.getTexture( "Game Title" ));
//        _playButton.setTexture( _data->assets.getTexture( "Play Button" ));
        
//        // Set the x,y positions of the title: "FlappyBird" (on top of the background)
//        _title.setPosition( (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2 );
//
//        // Set the x,y positions of the Play button: all the formulas do just that.
//        _playButton.setPosition( (SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2) );
    }


    void MainMenuState::handleInput() {
        sf::Event event;
        
        // Accquire the top event from Event Queue
        while ( _data->window.pollEvent( event ) ) {
            
            // If the input/event is "close the window", then close it.
            if ( event.type == sf::Event::Closed ) {
                _data->window.close();
            }
            
//            // If user clicks on the sprite (i.e. the Play button), go to Game State
//            if ( _data->input.isSpriteClicked( _playButton, sf::Mouse::Left, _data->window ) ) {
//                _data->machine.addState( std::make_unique<GameState>( _data ), true );
//            }
            
            // If user clicks on the sprite (i.e. the background), go to Game State
            if ( _data->input.isSpriteClicked( _background, sf::Mouse::Left, _data->window ) ) {
                _data->machine.addState( std::make_unique<GameState>( _data ), true );
            }
        }
    }


    void MainMenuState::update( float dt ) {
        
    }


    void MainMenuState::draw( float dt ) {
        _data->window.clear();
        
        _data->window.draw( _background );
//        _data->window.draw( _title );
//        _data->window.draw( _playButton );
        
        _data->window.display();
    }
}
