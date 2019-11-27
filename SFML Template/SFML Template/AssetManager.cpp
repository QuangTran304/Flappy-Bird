//
//  AssetManager.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "AssetManager.hpp"

namespace QT {
    void AssetManager::loadTexture(std::string name, std::string fileName) {
        
        sf::Texture tex;
        
        if ( tex.loadFromFile( fileName )) {
            this->_textures[name] = tex;
        }
    }

    sf::Texture& AssetManager::getTexture( std::string name ) {
        return this->_textures.at( name );
    }



    void AssetManager::loadFont(std::string name, std::string fileName) {
        
        sf::Font font;
        
        if ( font.loadFromFile( fileName )) {
            this->_fonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont( std::string name ) {
        return this->_fonts.at( name );
    }
}

