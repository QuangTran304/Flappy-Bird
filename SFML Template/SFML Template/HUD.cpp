//
//  HUD.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-13.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "HUD.hpp"
#include <string>

namespace QT {

    HUD::HUD( GameDataRef data ) : _data(data) {
        _scoreText.setFont( _data->assets.getFont( "Flappy Font" ));
        _scoreText.setString( "0" );
        _scoreText.setCharacterSize( 128 );
        _scoreText.setFillColor( sf::Color::White );
        _scoreText.setOrigin( _scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2 );      // Set the origin to make sure the score-text is always at the center (no matter a large or small score)
        _scoreText.setPosition( _data->window.getSize().x / 2, _data->window.getSize().y / 5);
    }


    void HUD::draw() {
        _data->window.draw( _scoreText );
    }


    void HUD::updateScore( int score ) {
        _scoreText.setString( std::to_string( score ));
    }


}
