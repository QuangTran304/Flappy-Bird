//
//  AssetManager.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace QT {
    class AssetManager {
    public:
        AssetManager() { }
        ~AssetManager() { }
        
        void loadTexture( std::string name, std::string fileName );
        sf::Texture& getTexture( std::string name );
        
        void loadFont( std::string name, std::string fileName );
        sf::Font& getFont( std::string name );
    
    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        
    };
}
