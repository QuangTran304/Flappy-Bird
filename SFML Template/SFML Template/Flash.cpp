//
//  Flash.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-12.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Flash.hpp"

namespace QT {

    Flash::Flash( GameDataRef data ) : _data( data ) {
        _shape = sf::RectangleShape( sf::Vector2f( _data->window.getSize() ));
        _shape.setFillColor( sf::Color( 255, 255, 255, 0 ));    // Last value = 0 because we want to turn it off at the start, otherwise it will be all white.
        _flashOn = true;
    }


    void Flash::show( float dt ) {
        if ( _flashOn ) {
            
            int alpha = (int)_shape.getFillColor().a + ( FLASH_SPEED * dt );    // Get the 'alpha' value - the opacity
            
            if ( alpha >= 255.0f ) {
                alpha = 255.0f;
                _flashOn = false;
            }
            
            _shape.setFillColor( sf::Color( 255, 255, 255, alpha ));
            
        } else {
            
            int alpha = (int)_shape.getFillColor().a - ( FLASH_SPEED * dt );    // Get the 'alpha' value - the opacity
            
            if ( alpha <= 0.0f ) {
                alpha = 0.0f;
                _flashOn = false;
            }
            
            _shape.setFillColor( sf::Color( 255, 255, 255, alpha ));
        }
    }


    void Flash::draw() {
        _data->window.draw( _shape );
    }
}
