//
//  Pipe.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Pipe.hpp"

namespace QT {

Pipe::Pipe( GameDataRef data ): _data(data) {
    
}

void Pipe::DrawPipes() {
    for (unsigned short int i = 0; i < pipeSprites.size(); ++i) {
        _data->window.draw( pipeSprites.at(i) );
    }
}

}
