//
//  Bird.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-07.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Bird.hpp"

namespace QT {
    Bird::Bird( GameDataRef data ): _data(data) {
        _birdSprite.setTexture( _data->assets.getTexture( "Bird Frame 1" ));
    }

    void Bird::draw() {
        _data->window.draw( _birdSprite );
    }
}
