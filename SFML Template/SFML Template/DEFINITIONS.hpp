//
//  DEFINITIONS.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-28.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 2.0      // How long do we want the splash to be visible
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/SplashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define LAND_FILEPATH "Resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.5f

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

enum GameStates {
    eREADY,         // Set to eREADY by default, the bird won't move - pipes won't response.
    ePLAYING,       // As soon as user hit "Play" at Game screen, GameStates will be set to ePLAYING.
    eGAMEOVER       // When collide with the ground/ pipe, GameStates will be eGAMEOVER, everything will stop moving.
};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
