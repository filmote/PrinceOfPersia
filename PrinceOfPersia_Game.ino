#include "src/utils/Arduboy2Ext.h"  
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void game_Init() {

    gamePlay.init(arduboy, 1);
    level.setLevel(1);
    game_PositionChars(true);

    gamePlay.gameState = GameState::Game;
    menu.init();

    playGrab();

}

void game_PositionChars(bool clearSword) {

    enemy.init();

    #ifdef LEVEL_DATA_FROM_FX
        
        FX::seekData(Levels::level1_Data);

        {
            uint8_t xPixel = FX::readPendingUInt8();
            uint8_t yPixel = FX::readPendingUInt8();
            Direction direction = static_cast<Direction>(FX::readPendingUInt8());
            uint16_t stance = static_cast<uint16_t>(FX::readPendingUInt8());
            uint8_t health = FX::readPendingUInt8();

            prince.init(xPixel, yPixel, direction, stance, health, clearSword);
            
        }

        {
            uint8_t xTile = FX::readPendingUInt8();
            uint8_t yTile = FX::readPendingUInt8();
            FX::readEnd();

            level.init(prince, xTile, yTile);  
            
        }

        FX::seekData(Levels::level1_Data + 7);

        {
            uint8_t xTile = FX::readPendingUInt8();

            while (xTile != 255) {

                uint8_t yTile = FX::readPendingUInt8();
                uint8_t xPixel = FX::readPendingUInt8();
                uint8_t yPixel = FX::readPendingUInt8();

                Direction direction = static_cast<Direction>(FX::readPendingUInt8());
                uint8_t health = FX::readPendingUInt8();
                enemy.init((xTile * Constants::TileWidth) + xPixel, (yTile * Constants::TileHeight) + yPixel, direction, Stance::Upright, health);

                xTile = FX::readPendingUInt8();

            }
            
        }
        
        FX::readEnd();

    #else

        enemy.init(104 - 12 + (70 * Constants::TileWidth), 25+31 + (3 * Constants::TileHeight), Direction::Left, Stance::Upright, 3);          // Sword fight from Left
        enemy.init(80 + (40 * Constants::TileWidth), 25 + (0 * Constants::TileHeight), Direction::Left, Stance::Upright, 3);          // Sword fight from Left

        // prince.init(38-28, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Normal starting pos
        // prince.init(38-24, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Gate Issue
        // prince.init(38-24, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Sword Fight from Left
        // prince.init(104, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Sword Fight from Right
        // prince.init(8+78+24, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     // Double collapisble
        // prince.init(78 + 24 + 12, 25 + 31 + 31, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Spikes Upper
        // prince.init(12, 25 + 31, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Spikes Lower
        // prince.init(78 + 24, 25, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Jump 2
        // prince.init(18, 25+31, Direction::Right,Stance:: Crouch_3_End, 3, clearSword);          // Sword fight
        // prince.init(58, 25+31+31, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Second drink tonic
        // prince.init(66, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Upper gate
        // prince.init(70, 25 + 31, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // 2 leap
        // prince.init(14, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Exit Seq
        // prince.init(104, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Both floor types
        // prince.init(86, 87, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Normal starting pos but next to drop floor 3rd floor
        // prince.init(86-36+4, 87, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Normal starting pos but next to drop floor 3rd floor
        // prince.init(78, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Under collapsible floor
        // prince.init(66, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);        // Get tonic
        // prince.init(18, 25+31+31, Direction::Left, Stance::Upright, 3, clearSword);     // Column of climbs
        // prince.init(78, 25, Direction::Left, Stance::Upright, 3, clearSword);     // Below column of climbs
        // prince.init(80, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     // Top Left
        // prince.init(18, 25, Direction::Right,Stance:: Crouch_3_End, 3, clearSword);          // Long Fall
        // prince.init(18, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // problem
        // prince.init(98, 87, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // At bottom of tthree level drop.
        // prince.init(98, 87, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // At bottom of tthree level drop.
        prince.init(18, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Long Run
        // prince.init(78 - 10, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Fall Error Stading Jump
        // prince.init(78 - 4, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Fall Error running Jump

        // level.init(prince, 60, 0);  // Normal starting posa
        // level.init(prince, 37, 3);  // gate issuee
        // level.init(prince, 60, 3);  // Fight from Left
        // level.init(prince, 70, 3);  // Fight from Right
        // level.init(prince, 10, 3);   // Double collapisble
        // level.init(prince, 10, 0);   // Spikes Upper
        // level.init(prince, 10, 6);   // Spikes Lower
        // level.init(prince, 30, 3);  // Jump 2
        // level.init(prince, 70, 3);  // Sword fight
        // level.init(prince, 50, 0);  // Second drink tonic
        // level.init(prince, 50, 0);  // Upper Gate
        // level.init(prince, 40, 3);  // 2 leap
        // level.init(prince, 80, 3);  // Exit Seq
        // level.init(prince, 20, 3);  // Both floor types
        // level.init(prince, 60, 0);  //Normal starting pos but next to drop floor 3rd floor
        // level.init(prince, 50, 3);  // Under collapsible floor
        // level.init(prince, Constants::TileHeight, 0);   // Get tonic
        // level.init(prince, 0, 3);   // Column of climbs
        // level.init(prince, 0, 6);   // Below Column of climbs
        // level.init(prince, 0, 0);   // Top left
        // level.init(prince, 40, 4);  // Long Fall
        // level.init(prince, 60, 3);  // problem
        // level.init(prince, 30, 6); // At bottom of tthree level drop.
        level.init(prince, 40, 0);  // Long run
        // level.init(prince, 50, 3);  // Fall Error Stading Jump
        // level.init(prince, 50, 3);  // Fall Error running Jump

    #endif

}

void game_StartLevel() {

    gamePlay.restartLevel(arduboy);
    game_PositionChars(false);

    gamePlay.gameState = GameState::Game;
    menu.init();

    playGrab();

}

void game() {

    auto justPressed = arduboy.justPressedButtons();
    auto pressed = arduboy.pressedButtons();
    bool enemyIsVisible = false;

    #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
    DEBUG_PRINT(F("Stance: "));
    DEBUG_PRINT(prince.getStance());
    DEBUG_PRINT(F(", Direction: "));
    DEBUG_PRINT((uint8_t)prince.getDirection());
    DEBUG_PRINT(F(", X: "));
    DEBUG_PRINT(prince.getX());
    DEBUG_PRINT(F(", Y: "));
    DEBUG_PRINT(prince.getY());
    DEBUG_PRINT(F(", yOffset: "));
    DEBUG_PRINTLN(level.getYOffset());
    #endif


    // Have we scrolled to another screen ?

    testScroll(prince, level);


    #ifdef ALT_B_BUTTON
    // // Remove later !!!
    // //
    // if (justPressed & B_BUTTON) {

    //     switch (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

    //         case 0:
    //             prince.incX(2);
    //             break;

    //         case 1:
    //         case 5:
    //         case 9:
    //             prince.incX(1);
    //             break;

    //         case 3:
    //         case 7:
    //         case 11:
    //             prince.incX(-1);
    //             break;

    //         case 2:
    //         case 6:
    //         case 10:
    //             break;

    //         case 4:
    //         case 8:
    //             prince.incX(2);
    //             break;

    //     }

    // }
    // //
    // // REmove later !!
    // if (justPressed & B_BUTTON) {
    //     prince.pushSequence(Stance::Draw_Sword_01_Start, Stance::Draw_Sword_06_End, Stance::Sword_Normal, true);
    // }
    
    // if (justPressed & B_BUTTON) {
    //     processRunJump(prince, level);
    //     // prince.pushSequence(Stance::Run_Start_1_Start, Stance::Run_Start_6_End, true);
    // }
    #endif

    #ifdef GIVE_SWORD
        prince.setSword(true);
    #endif




    // Update the objects ..

    prince.update(level.getXLocation(), level.getYLocation());
    enemy.update();
    level.update(arduboy);
    gamePlay.update(arduboy);

    if (menu.update()) gamePlay.gameState = GameState::Game;
    




    // Is the prince within distance of the enemy (cycle through all enemies to find it any closest)?

    // enemyIsVisible = false;

    if (enemy.isEmpty()) {

        enemyIsVisible = isEnemyVisible(true);

    }
    else {

        enemyIsVisible = isEnemyVisible(false);

    }



    // If within distance, we can draw swords if we have one!

    if (justPressed & B_BUTTON && enemyIsVisible && prince.getSword() && prince.getStance() == Stance::Upright && prince.isEmpty() && enemy.getHealth() > 0) {
        
        prince.pushSequence(Stance::Draw_Sword_01_Start, Stance::Draw_Sword_06_End, Stance::Sword_Normal, true);
        justPressed = 0;

    }



    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  If enemy queue is empty then determine next move ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (gamePlay.gameState == GameState::Game && enemy.isEmpty()) {

        BaseEntity enemyBase = enemy.getActiveBase();

        int16_t xDelta = prince.getPosition().x - enemy.getPosition().x;
        int16_t yDelta = prince.getPosition().y - enemy.getPosition().y;

        switch (enemy.getStance()) {

            case Stance::Upright:

                // Draw sword? Not if the prince is dead!

                if (abs(xDelta) < 70 && yDelta == 0) {

                    switch (prince.getStance()) {

                        case Stance::Falling_Dead_1_Start ... Stance::Falling_Dead_3_End:
                            break;

                        default:
                            enemy.pushSequence(Stance::Draw_Sword_01_Start, Stance::Draw_Sword_06_End, Stance::Sword_Normal, true);
                            break;

                    }                    

                }

                break;


            // The enemy is at the end of the move sequence, what next?

            case Stance::Sword_Step_03_End:

                if (yDelta == 0) {

                    switch(abs(xDelta)) {

                        // If the enemy and prince are within striking distance then stop the enemy moving forward ..

                        case 0 ... Constants::StrikeDistance:

                            if (level.canMoveForward(enemyBase, Action::SmallStep)) {
                                enemy.push(Stance::Sword_Normal, false);
                            }
                            break;


                        // If the enemy and prince are close to striking distance then the enemy should either get ready for combat or move forward ..

                        case Constants::StrikeDistance + 1 ... 30:

                            if (prince.isSwordDrawn()) {

                                enemy.push(Stance::Sword_Normal, false);

                            }
                            else {

                                if (level.canMoveForward(enemyBase, Action::SmallStep)) {
                                    enemy.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, true);
                                }
                                
                            }

                            break;

                        default:


                            // If the enemy and prince are far apart then the enemy should advance on the prince ..

                            if (level.canMoveForward(enemyBase, Action::SmallStep)) {
                                enemy.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, true);
                            }
                            break;

                    }


                }
                
                break;


            // The enemy is ready to attack / move / retreat ..

            case Stance::Sword_Normal:


                // Has the enemy gone past the prince?  If so, turn around ..

                if (xDelta > 0 && enemy.getDirection() == Direction::Left){

                    enemy.setDirection(Direction::Right);
                    moveBackwardsWithSword(enemyBase, enemy);

                    if (prince.isSwordDrawn() && prince.getDirection() == Direction::Right) {

                        prince.setDirection(Direction::Left);
                        moveBackwardsWithSword(prince, prince);

                    }
                    else if (!prince.isSwordDrawn() && xDelta <= 24) {

                        pushDead(prince, level, gamePlay, true);

                    }

                    break;

                }

                else if (xDelta < 0 && enemy.getDirection() == Direction::Right){

                    enemy.setDirection(Direction::Left);
                    moveBackwardsWithSword(enemyBase, enemy);

                    if (prince.isSwordDrawn() && prince.getDirection() == Direction::Left) {

                        prince.setDirection(Direction::Right);
                        moveBackwardsWithSword(prince, prince);

                    }
                    else if (!prince.isSwordDrawn() && xDelta >= -24) {

                        pushDead(prince, level, gamePlay, true);
                        
                    }

                    break;

                }


                // Otherwise take action!

                switch (prince.getStance()) {


                    // The prince is dying, put away the sword ..

                    case Stance::Falling_Dead_1_Start ... Stance::Falling_Dead_3_End:

                        enemy.pushSequence(Stance::Pickup_Sword_7_PutAway, Stance::Pickup_Sword_16_End, Stance::Upright, false);
                        break;


                    // The prince is attacking, can the enemy block the attack or move?

                    case Stance::Sword_Attack_01_Start ... Stance::Sword_Attack_02:

                        if (random(0, 12) == 0) {    

                            prince.clear();
                            prince.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, false);
                            enemy.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, false);
                            
                        }
                        else if (random(0, 12) == 0) {    

                            moveBackwardsWithSword(enemyBase, enemy);
                            
                        } 

                        break;


                    // The prince is attacking but its too late to move back, can the enemy block the attack?

                    case Stance::Sword_Attack_03 ... Stance::Sword_Attack_04:

                        if (random(0, 8) == 0) {    

                            prince.clear();
                            prince.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, false);
                            enemy.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, false);
                            
                        }

                        break;
                       
                    default:

                        if (yDelta == 0) {

                            switch(abs(xDelta)) {


                                // If the enemy and prince are within stirking distance then ..

                                case 0 ... Constants::StrikeDistance:

                                    switch (prince.getStance()) {


                                        // The prince is dying, do nothing ..

                                        case Stance::Falling_Dead_1_Start ... Stance::Falling_Dead_3_End: 
                                            break;


                                        // If the prince is ready for combat (but not attacking) then the enemy should attack ..

                                        case Stance::Attack_Block_01_Start ... Stance::Attack_Block_03_End:
                                        case Stance::Draw_Sword_01_Start ... Stance::Draw_Sword_06_End:
                                        case Stance::Sword_Step_01_Start ... Stance::Sword_Step_03_End:
                                        case Stance::Sword_Normal:

                                            if (random(0, 16) == 0) {
                                                enemy.pushSequence(Stance::Sword_Attack_01_Start, Stance::Sword_Attack_08_End, Stance::Sword_Normal, true);
                                            }
                                            break;


                                        // The prince is not ready for combat, kill him immediately ..

                                        default:

                                            enemy.pushSequence(Stance::Sword_Attack_01_Start, Stance::Sword_Attack_08_End, Stance::Sword_Normal, true);
                                            break;

                                    }

                                    break;


                                // If the enemy and prince are close to striking distance then the enemy should either get ready for combat or move forward ..

                                case Constants::StrikeDistance + 1 ... Constants::StrikeDistance + 28:

                                    if (random(0, 16) == 0) {

                                        if (level.canMoveForward(enemyBase, Action::SmallStep)) {
                                            enemy.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, true); //, Stance::Sword_Normal, true);
                                        }

                                    }
                                    else {

                                        if (enemy.getStance() == Stance::Sword_Step_03_End) {
                                            enemy.push(Stance::Sword_Normal, false);
                                        }

                                    }

                                    break;

                                default:

                                    // Advance on prince ..

                                    if (level.canMoveForward(enemyBase, Action::SmallStep)) {
                                       enemy.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, true);
                                    }

                                    break;

                            }


                        }

                        break;

                }                    

                break;

        }

    }



    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  If prince queue is empty then accept input from player ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (gamePlay.gameState == GameState::Game && prince.isEmpty()) {


        // Check to see if we can leave the level, otherise 

        if (!leaveLevel(prince, level)) {

            switch (prince.getStance()) {

                case Stance::Upright:

                    fixPosition();  // Fix the position if we are not in positions 2, 6 or 10.

                    if (prince.getDirection() == Direction::Right) {

                        if ((pressed & RIGHT_BUTTON) && (pressed & DOWN_BUTTON)) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::Step)) {

                                prince.push(Stance::Single_Step_1_Start, true);
                                break;

                            }
                            else if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                            break;

                        }
                        else if (pressed & A_BUTTON) {

                            processStandingJump(prince, level);
                            break;

                        }
                        
                    }
                    else {

                        if ((pressed & LEFT_BUTTON) && (pressed & DOWN_BUTTON)) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::Step)) {

                                prince.push(Stance::Single_Step_1_Start, true);
                                break;

                            }
                            else if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }
                            
                        }
                        else if (pressed & RIGHT_BUTTON) {

                            prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                            break;

                        }
                        else if (pressed & A_BUTTON) {

                            processStandingJump(prince, level);
                            break;

                        }

                    }

                    if (pressed & DOWN_BUTTON) {
                    
                        CanClimbDownResult canClimbDownResult = level.canClimbDown(prince);

                        switch (canClimbDownResult) {

                            case CanClimbDownResult::ClimbDown:

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                break;

                            case CanClimbDownResult::StepThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Small_Step_6_End, Stance::Small_Step_1_Start, Stance::Upright, false);
                                break;

                            case CanClimbDownResult::TurnThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, false);
                                break;

                            case CanClimbDownResult::StepThenTurnThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then turn then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, false);
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);
                                break;

                            default:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Cannot climb down, squat"));
                                #endif

                                gamePlay.crouchTimer++;
                                
                                if (gamePlay.crouchTimer == 4) {
                                    prince.pushSequence(Stance::Crouch_1_Start, Stance::Crouch_3_End, false);
                                }
                                break;

                        }

                    }
                    else if (pressed & UP_BUTTON) {

                        CanJumpUpResult jumpResult = level.canJumpUp(prince);

                        switch (jumpResult) {

                            case CanJumpUpResult::Jump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, true);
                                break;

                            case CanJumpUpResult::JumpThenFall:
                                pushJumpUp_Drop(prince);
                                break;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x) + prince.getDirectionOffset(1);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);

                                }
                                break;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);

                                }
                                break;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x) + prince.getDirectionOffset(1);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);
                                    prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);

                                }
                                break;

                            case CanJumpUpResult::StepThenJump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, Stance::Upright, true);
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);
                                break;

                            case CanJumpUpResult::TurnThenJump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, false);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                                break;

                            case CanJumpUpResult::JumpDist10:
                                prince.pushSequence(Stance::Jump_Up_B_1_Start, Stance::Jump_Up_B_14_End, true);
                                break;

                            default: break;

                        }

                    }

                    break;

                case Stance::Jump_Up_A_14_End:     // Hanging on ledge  (dist 2)..
                case Stance::Jump_Up_B_14_End:    
                
                    if (pressed & DOWN_BUTTON) {

                        CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                        switch (climbDownResult) {

                            case CanClimbDownPart2Result::Level_1_Under:
                                prince.pushSequence(Stance::Jump_Up_Drop_B_1_Start, Stance::Jump_Up_Drop_B_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Level_1:
                                prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Falling:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                DEBUG_PRINTLN(F("Jump_Up_A_14_End, Jump_Up_B_14_End, setFalling(1)"));
                                #endif

                                prince.setFalling(1);
                                prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);
                                break;

                            default:
                                break;

                        }

                    }
                    else if (pressed & UP_BUTTON) {

                        if (level.canJumpUp_Part2(prince)) {
                            prince.pushSequence(Stance::Step_Climbing_1_Start, Stance::Step_Climbing_15_End, Stance::Upright, true);
                        }
                        else {
                            prince.pushSequence(Stance::Step_Climbing_Block_1_Start, Stance::Step_Climbing_Block_9_End, Stance::Upright, true);                        
                        }

                    }

                    // Drop after a period of time hanging ..

                    else if(prince.getHangingCounter() == 0) {

                        CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                        switch (climbDownResult) {

                            case CanClimbDownPart2Result::Level_1_Under:
                                prince.pushSequence(Stance::Jump_Up_Drop_B_1_Start, Stance::Jump_Up_Drop_B_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Level_1:
                                prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Falling:
                                
                                #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                DEBUG_PRINTLN(F("Drop after hanging, setFalling(1)"));
                                #endif

                                prince.setFalling(1);
                                prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);
                                break;

                            default:
                                break;

                        }

                    }

                    break;

                case Stance::Single_Step_1_Start:

                    // If the user is still holding the left / right button then escalate the movement to a run ..

                    if (prince.getDirection() == Direction::Right) {

                        if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunStart)) {
                                prince.pushSequence(Stance::Run_Start_2, Stance::Run_Start_6_End, true);
                            }
                            else {
                                prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                            }

                        }
                        else if (!(pressed & RIGHT_BUTTON)) {
                            prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                        }

                    }
                    else {

                        if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunStart)) {
                                prince.pushSequence(Stance::Run_Start_2, Stance::Run_Start_6_End, true);
                            }
                            else {
                                prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                            }     
                                                
                        }
                        else if (!(pressed & LEFT_BUTTON)) {
                            prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                        }

                    }
                    break;

                case Stance::Run_Repeat_4:

                    if (prince.getDirection() == Direction::Right) {
                            
                        if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Repeat_4"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Repeat (1)"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_5_Mid, Stance::Run_Repeat_8_End, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (1)"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Switch Directions"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed  & RIGHT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (2)"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    else {

                        if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Repeat_4"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_5_Mid, Stance::Run_Repeat_8_End, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start,Stance:: Stopping_5_End, Stance::Upright, true);
                            }                        
                        }
                        else if (pressed & RIGHT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Start"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed & LEFT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop (4)"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    break;

                case Stance::Run_Start_6_End:
                case Stance::Run_Repeat_8_End:
                case Stance::Run_Repeat_8_End_Turn:

                    if (prince.getDirection() == Direction::Right) {
                                        
                        if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Start_6_End, Run_Repeat_8_End or Run_Repeat_8_End_Turn"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Repeat"));
                                #endif
                                
                                prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Turn"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed & RIGHT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    else {
                                        
                        if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Start_6_End, Run_Repeat_8_End or Run_Repeat_8_End_Turn"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);

                            }
                            else {
                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }         

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);

                        }
                        else if (!(pressed & LEFT_BUTTON)) {

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);

                        }

                    }

                    break;

                case Stance::Crouch_3_End:
                case Stance::Crouch_HOP_7_End:

                    if (prince.getCrouchingCounter() == 0) {

                        if (!(pressed & DOWN_BUTTON)) {

                            prince.pushSequence(Stance::Crouch_Stand_3, Stance::Crouch_Stand_12_End, Stance::Upright, true);

                        }
                        else if ((pressed & LEFT_BUTTON) || (pressed & RIGHT_BUTTON)) {

                            if (level.canMoveForward(prince, Action::CrouchHop)) {
                                prince.pushSequence(Stance::Crouch_HOP_1_Start, Stance::Crouch_HOP_7_End, true);
                            }

                        }
                        else if (pressed & A_BUTTON) {

                            uint8_t itemIdx = level.canReachItem(prince, ItemType::Potion_Small);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &item = level.getItem(itemIdx);
                                item.itemType = ItemType::None;
                                prince.pushSequence(Stance::Drink_Tonic_1_Start, Stance::Drink_Tonic_15_End, Stance::Upright, true);

                                break;

                            }

                            itemIdx = level.canReachItem(prince, ItemType::Sword);

                            if (itemIdx != Constants::NoItemFound) {

                                #ifndef SAVE_MEMORY_SOUND
                                    sound.tonesFromFX(Sounds::Tada);
                                #endif

                                Item &item = level.getItem(itemIdx);
                                item.itemType = ItemType::None;
                                prince.setSword(true);
                                prince.clear();
                                prince.pushSequence(Stance::Pickup_Sword_1_Start, Stance::Pickup_Sword_16_End, Stance::Upright, true);

                            }

                        }

                    }

                    break;


                case Stance::Sword_Normal:

                    if (pressed & B_BUTTON) {

                        prince.pushSequence(Stance::Pickup_Sword_7_PutAway, Stance::Pickup_Sword_16_End, Stance::Upright, true);

                    }

                    else if (pressed & A_BUTTON) {

                        prince.pushSequence(Stance::Sword_Attack_01_Start, Stance::Sword_Attack_08_End, Stance::Sword_Normal, true);

                    }

                    else if (pressed & UP_BUTTON) { // Block attack?

                        switch (enemy.getStance()) {

                            // Block attack from enemy only if not all the way through sequence ..

                            case Stance::Sword_Attack_02 ... Stance::Sword_Attack_04:

                                enemy.clear();
                                enemy.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, false);
                                break;

                            default: break;

                        }

                        prince.pushSequence(Stance::Attack_Block_01_Start, Stance::Attack_Block_03_End, Stance::Sword_Normal, true);

                    }

                    else if (pressed & RIGHT_BUTTON) {

                        if (prince.getDirection() == Direction::Right) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {
                                prince.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, Stance::Sword_Normal, true);
                                break;
                            }

                        }
                        else {

                            if (level.canMoveForward(prince, Action::SmallStep, prince.getOppositeDirection())) {
                                prince.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, true);
                                break;
                            }
                            
                        }

                    }
                            
                    else if (pressed & LEFT_BUTTON) {
                        
                        if (prince.getDirection() == Direction::Left) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {
                                prince.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, Stance::Sword_Normal, true);
                                break;
                            }

                        }
                        else {

                            if (level.canMoveForward(prince, Action::SmallStep, prince.getOppositeDirection())) {
                                prince.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, true);
                                break;
                            }
                            
                        }

                    }

                    else {
                            
                        if (pressed & LEFT_BUTTON) {

                            prince.pushSequence(Stance::Sword_Step_01_Start, Stance::Sword_Step_03_End, Stance::Sword_Normal, true);

                        }
                            
                        if (pressed & RIGHT_BUTTON) {

                            prince.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, true);

                        }

                    }


                    break;
                

                default: break;

            }

        }

    }



    // Post input cleanup!

    if (!(pressed & DOWN_BUTTON)) {

        gamePlay.crouchTimer = 0;

    }



    // Handle menu

    #ifndef SAVE_MEMORY_OTHER

        switch (gamePlay.gameState) {

            case GameState::Game:

                #ifndef ALT_B_BUTTON
                    if (justPressed & B_BUTTON) {

                        gamePlay.gameState = GameState::Menu;
                        menu.direction = Direction::Left;
                        menu.cursor = static_cast<uint8_t>(MenuOption::Resume);

                    }
                #endif

                break;

            case GameState::Menu:

                #ifndef ALT_B_BUTTON
                    if (justPressed & B_BUTTON)                     menu.direction = Direction::Right;
                #endif

                if (justPressed & UP_BUTTON && menu.cursor > 0)     menu.cursor--;
                if (justPressed & DOWN_BUTTON && menu.cursor < 3)   menu.cursor++;

                if (justPressed & A_BUTTON) {

                    switch (static_cast<MenuOption>(menu.cursor)) {

                        case MenuOption::Resume:
                            menu.direction = Direction::Right;  
                            break;

                        case MenuOption::Save:
                            EEPROM_Utils::saveGame(cookie);
                            menu.direction = Direction::Right;  
                            break;

                        case MenuOption::Load:
                            EEPROM_Utils::loadGame(cookie);
                            menu.direction = Direction::Right;  
                            break;

                        case MenuOption::MainMenu:
                            gamePlay.gameState = GameState::Title_Init;  
                            break;
                            
                    }

                }   

            default: break;


        }
    #endif


    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  Prince Queue handling ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (prince.getStackFrame() == 0) {

        if (!prince.isEmpty()) {

            Point offset;

            int16_t newStance = prince.pop();
            prince.setStance(abs(newStance));


            // Handle specific events .. such as turning at end of sequences, falling after a land, etc.

            switch (prince.getStance()) {

                case Stance::Leave_Gate_14_End:
                    gamePlay.gameState = GameState::Title;
                    titleScreenVars.setMode(static_cast<TitleScreenMode>(static_cast<uint8_t>(titleScreenVars.getMode()) + 1), level);
                    gamePlay.incLevel();
                    break;

                case Stance::Upright_Turn:
                    newStance = Stance::Upright;
                    prince.setStance(Stance::Upright);
                    prince.changeDirection();
                    break;

                case Stance::Run_Repeat_8_End_Turn:
                    prince.changeDirection();
                    break;

                case Stance::Jump_Up_Drop_A_4: // Ripple collapsible floors.
                case Stance::Jump_Up_Drop_B_4: 

                    for (uint8_t i =0; i < Constants::Items_Count; i++) {
                        
                        Item &item = level.getItem(i);

                        if (item.itemType == ItemType::CollapsingFloor && item.data.collapsingFloor.frame == 0) {

                            item.data.collapsingFloor.frame = 3;

                        }

                    }

                    break;

                case Stance::Jump_Up_Drop_C_5_End: // Falling after climbing down ..

                    if (level.canFall(prince)) { // Fall some more

                        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                        DEBUG_PRINT(F("FallSomMore at Jump_Up_Drop_C_5_End, incFalling() from "));
                        DEBUG_PRINT(prince.getFalling());
                        #endif

                        prince.incFalling();

                        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                        DEBUG_PRINT(F(" to"));
                        DEBUG_PRINTLN(prince.getFalling());
                        #endif

                        prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);

                    }
                    else {

                        uint8_t itemIdx = activateSpikes(prince, level);

                        if (itemIdx == Constants::NoItemFound) {

                            switch (prince.getFalling()) {

                                case 1:

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                    DEBUG_PRINTLN(F("Land and enter crouch, falling = 1"));
                                    #endif

                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    break;

                                case 2:

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                    DEBUG_PRINTLN(F("Land and enter crouch, falling = 2"));
                                    #endif

                                    initFlash(prince, level, FlashType::None);

                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    prince.pushSequence(Stance::Falling_Injured_1_Start, Stance::Falling_Injured_2_End, true);

                                    if (prince.decHealth(1) == 0) {;

                                        pushDead(prince, level, gamePlay, false);

                                    }

                                    break;

                                default:    // Dead!

                                    pushDead(prince, level, gamePlay, false);
                                    break;

                            }

                        }
                        else {

                            pushDead(prince, level, gamePlay, false);

                        }
                        
                    }

                    break;

                case Stance::Falling_Down_P2_5_Check_CanFall:
                case Stance::Falling_Down_P1_5_Check_CanFall:
                case Stance::Falling_Down_P0_5_Check_CanFall:
                case Stance::Falling_Down_M1_5_Check_CanFall:
                case Stance::Falling_Down_M2_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall:
                case Stance::Collide_Wall_P2_Start_End:
                case Stance::Collide_Wall_P1_Start_End:
                case Stance::Collide_Wall_P0_Start_End:
                case Stance::Collide_Wall_M1_Start_End:
                case Stance::Collide_Wall_M2_Start_End:

                    if (level.canFallSomeMore(prince)) { // Fall some more

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                        DEBUG_PRINTLN(F("Fall some more"));
                        #endif

                        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                        DEBUG_PRINT(F("FallSomMore at *_Check_CanFall, incFalling() from "));
                        DEBUG_PRINT(prince.getFalling());
                        #endif

                        prince.incFalling();

                        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                        DEBUG_PRINT(F(" to"));
                        DEBUG_PRINTLN(prince.getFalling());
                        #endif

                        switch (prince.getStance()) {

                            case Stance::Collide_Wall_P2_Start_End:
                            case Stance::Collide_Wall_P1_Start_End:
                            case Stance::Collide_Wall_P0_Start_End:
                            case Stance::Collide_Wall_M1_Start_End:
                            case Stance::Collide_Wall_M2_Start_End: 
                                prince.setPrevStance(Stance::None);
                                break;

                            default:
                                prince.setPrevStance(prince.getStance());
                                break;

                        }

                        prince.pushSequence(Stance::Falling_Down_P0_1_Start, Stance::Falling_Down_P0_5_Check_CanFall, true);
                        prince.push(Stance::Falling_Down_P0_6_End, true);

                    }
                    else {

                        uint8_t itemIdx = activateSpikes(prince, level);

                        if (itemIdx == Constants::NoItemFound) {
                                
                            switch (prince.getFalling()) {

                                case 1:
                                    
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                    DEBUG_PRINTLN(F("Land and enter crouch, falling = 1"));
                                    #endif

                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    break;

                                case 2:     // OK but lose some health as well
                                    
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                                    DEBUG_PRINTLN(F("Land and enter crouch, falling = 2"));
                                    #endif

                                    initFlash(prince, level, FlashType::None);  

                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    prince.pushSequence(Stance::Falling_Injured_1_Start, Stance::Falling_Injured_2_End, true);

                                    if (prince.decHealth(1) == 0) {;
                                        pushDead(prince, level, gamePlay, false);
                                    }

                                    break;

                                default:    // Dead!

                                    pushDead(prince, level, gamePlay, false);
                                    break;

                            }

                        }
                        else {

                            pushDead(prince, level, gamePlay, false);

                        }

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                        DEBUG_PRINT(F("End jump, stand up "));
                        DEBUG_PRINTLN(prince.getFalling());
                        #endif

                        switch (prince.getStance()) {

                            case Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall:

                                prince.push(prince.getStance() + 1, true);
                                break;

                            case Stance::Falling_Down_P2_5_Check_CanFall:
                            case Stance::Falling_Down_P1_5_Check_CanFall:
                            case Stance::Falling_Down_P0_5_Check_CanFall:
                            case Stance::Falling_Down_M1_5_Check_CanFall:
                            case Stance::Falling_Down_M2_5_Check_CanFall:

                                if (prince.getPrevStance() != Stance::None) {
                                    prince.push(prince.getPrevStance() + 1, true);
                                }
                                break;

                            default:  
                                break;

                        }

                        prince.setPrevStance(Stance::None);

                    }

                    break;

                case Stance::Drink_Tonic_14:
                    prince.incHealth(2);
                    break;

                case Stance::Upright:

                    #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
                    DEBUG_PRINTLN(F("Landed, setFalling(0)"));
                    #endif

                    prince.setFalling(0);
                    break;


                case Stance::Sword_Attack_05:
                    {
                        int16_t xDelta = prince.getPosition().x - enemy.getPosition().x;
                        int16_t yDelta = prince.getPosition().y - enemy.getPosition().y;

                        if (abs(xDelta) <= Constants::StrikeDistance && yDelta == 0) {

                            initFlash(enemy, level, FlashType::SwordFight);
                         
                            if (enemy.decHealth(1) == 0) {

                                pushDead(enemy, true);
                                
                                prince.clear();
                                prince.pushSequence(Stance::Pickup_Sword_7_PutAway, Stance::Pickup_Sword_16_End, Stance::Upright, false);
                                prince.pushSequence(Stance::Sword_Attack_06, Stance::Sword_Attack_08_End, Stance::Upright, false);

                            }
                            else {

                                BaseEntity enemyBase = enemy.getActiveBase();
                                moveBackwardsWithSword(enemyBase, enemy);

                            }

                        }

                    }

            }


            getStance_Offsets(prince.getDirection(), offset, prince.getStance());
            prince.incX(offset.x * (newStance < 0 ? -1 : 1));
            prince.incY(offset.y * (newStance < 0 ? -1 : 1));



            // Has the player stepped on anything ?

            if (prince.isFootDown()) {
// Serial.println("Footdown");

                // Check for floor buttons and collapsing floors ..

                ImageDetails imageDetails;
                prince.getImageDetails(imageDetails);


                // Test with player's toe ..

                int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x + imageDetails.toe);
                int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y);
                uint8_t itemIdx = level.getItem(ItemType::InteractiveItemType_Start, ItemType::InteractiveItemType_End, tileXIdx, tileYIdx);


                // If no match, test with player's heel ..

                if (itemIdx == Constants::NoItemFound) {

                    tileXIdx = level.coordToTileIndexX(prince.getPosition().x + imageDetails.heel);
                    itemIdx = level.getItem(ItemType::InteractiveItemType_Start, ItemType::InteractiveItemType_End, tileXIdx, tileYIdx);

                }


                if (itemIdx != Constants::NoItemFound) {

                    Item &item = level.getItem(itemIdx);

                    switch (item.itemType) {
                        
                        case ItemType::CollapsingFloor:

                            if (item.x == tileXIdx && item.y == tileYIdx && item.data.collapsingFloor.timeToFall == 0) {

                                item.data.collapsingFloor.timeToFall = 24;//12;

                            }

                            break;

                        case ItemType::FloorButton1:

                            itemIdx = level.getItem(ItemType::Gate, item.data.floorButton1.gateX, item.data.floorButton1.gateY);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &gate = level.getItem(itemIdx);

                                item.data.floorButton1.frame = 1;
                                item.data.floorButton1.timeToFall = 24;
                                gate.data.gate.closingDelay = 64;
                                gate.data.gate.closingDelayMax = 64;

                            }

                            break;

                        case ItemType::FloorButton2:

                            itemIdx = level.getItem(ItemType::Gate, item.data.floorButton2.gateX, item.data.floorButton2.gateY);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &gate = level.getItem(itemIdx);

                                item.data.floorButton2.frame = 1;
                                item.data.floorButton2.timeToFall = 24;
                                gate.data.gate.closingDelay = 10;
                                gate.data.gate.closingDelayMax = 255;

                            }

                            break;

                        case ItemType::Spikes:

                           if (prince.getHealth() > 0) {

                                activateSpikes(prince, level);

                                if (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX()) > 2) {
                                        
                                    switch (prince.getStance()) {

                                        case Stance::Run_Start_1_Start ... Stance::Run_Start_6_End:
                                        case Stance::Run_Repeat_1_Start ... Stance::Run_Repeat_8_End:
                                        case Stance::Standing_Jump_1_Start ... Stance::Standing_Jump_18_End:
                                        case Stance::Running_Jump_1_Start ... Stance::Running_Jump_11_End:

                                            pushDead(prince, level, gamePlay, true);
                                            break;

                                        default:
                                            break;

                                    }

                                }

                           }

                            break;

                        default: break;

                    }

                }

            }


            #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
            DEBUG_PRINT(F("Stance: "));
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(F(", Direction: "));
            DEBUG_PRINT((uint8_t)prince.getDirection());
            DEBUG_PRINT(F(", xOffset: "));
            DEBUG_PRINT(offset.x);
            DEBUG_PRINT(F(", yOffset: "));
            DEBUG_PRINTLN(offset.y);
            #endif

        }
        else {


            // Nothing in the queue .. stand around doing nothing !

            prince.setIgnoreWallCollisions(false);

        }

    }



    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  Enemy Queue handling ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (enemy.getStackFrame() == 0) {

        if (!enemy.isEmpty()) {

            Point offset;

            int16_t newStance = enemy.pop();
            enemy.setStance(abs(newStance));

            switch (enemy.getStance()) {

                case Stance::Sword_Attack_05:
                    {

                        int16_t xDelta = prince.getPosition().x - enemy.getPosition().x;
                        int16_t yDelta = prince.getPosition().y - enemy.getPosition().y;

                        switch (prince.getStance()) {

                            case Stance::Sword_Normal:
                            case Stance::Draw_Sword_01_Start ... Stance::Draw_Sword_06_End:
                            case Stance::Sword_Attack_01_Start ... Stance::Sword_Attack_08_End:
                            case Stance::Sword_Step_01_Start ... Stance::Sword_Step_03_End:

                                if(abs(xDelta) < Constants::StrikeDistance && yDelta == 0) {

                                    initFlash(prince, level, FlashType::SwordFight);

                                    if (prince.decHealth(1) == 0) {

                                        pushDead(prince, level, gamePlay, true);

                                    }
                                    else {

                                        if (level.canMoveForward(enemy.getActiveBase(), Action::SmallStep, enemy.getOppositeDirection())) {

                                            prince.clear();
                                            prince.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, false);
                                            break;

                                        }

                                    }

                                }

                                break;

                            case Stance::Falling_Dead_1_Start ... Stance::Falling_Dead_3_End: // Already dying ..

                                break;

                            default:

                                if(abs(xDelta) < Constants::StrikeDistance && yDelta == 0) {

                                    pushDead(prince, level, gamePlay, true);

                                }

                                break;                            

                        }

                    }

                    break;


            }


            // Move enemy .. 

            getStance_Offsets(enemy.getDirection(), offset, enemy.getStance());
            enemy.incX(offset.x * (newStance < 0 ? -1 : 1));
            enemy.incY(offset.y * (newStance < 0 ? -1 : 1));

        }

    }


    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  Falling ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (!prince.getIgnoreWallCollisions() && prince.isFootDown() && level.canFall(prince) && prince.getFalling() == 0) {

        uint8_t distToEdgeOfCurrentTile = level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX());
                                            
        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
        DEBUG_PRINTLN(F("Starting to fall, setFalling(1)"));
        #endif

        prince.clear();
        prince.setFalling(1);
        prince.setPrevStance(prince.getStance());


        // If we are at the edge of a tile and their is an adjacent wall, then we need to fall straight down otherwise fall in an arc ..

        bool fallStraight = false;
// Serial.print("distToEdgeOfCurrentTile:");
// Serial.println(distToEdgeOfCurrentTile);        
        if (distToEdgeOfCurrentTile <= 6) {

            int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x) + (prince.getDirection() == Direction::Left ? -1 : 1) - level.getXLocation();
            int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y) + 1 - level.getYLocation();
            int8_t fgTile = level.getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
// Serial.print("Fall straight? x:");
// Serial.print(tileXIdx);
// Serial.print(" y:");
// Serial.print(tileYIdx);
// Serial.print(" fg:");
// Serial.print(fgTile);

            WallTileResults wallTileResult = level.isWallTile(fgTile);
// Serial.print(" wt:");
// Serial.print((uint8_t)wallTileResult);
            if (wallTileResult != WallTileResults::None) {

                fallStraight = true;

            }

        }

        if (fallStraight) {

            #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
            DEBUG_PRINT(F("Falling straight down, distToEdge: "));
            DEBUG_PRINTLN(distToEdgeOfCurrentTile);
            #endif
            
            switch (distToEdgeOfCurrentTile) {

                case 0:
                    prince.pushSequence(Stance::Falling_Down_M2_1_Start, Stance::Falling_Down_M2_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_Down_M2_5_Check_CanFall);
                    break;

                case 1:
                case 5:
                case 9:
                    prince.pushSequence(Stance::Falling_Down_M1_1_Start, Stance::Falling_Down_M1_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_Down_M1_5_Check_CanFall);
                    break;

                case 3:
                case 7:
                    prince.pushSequence(Stance::Falling_Down_P1_1_Start, Stance::Falling_Down_P1_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_Down_P1_5_Check_CanFall);
                    break;

                case 4:
                case 8:
                    prince.pushSequence(Stance::Falling_Down_P2_1_Start, Stance::Falling_Down_P2_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_Down_P2_5_Check_CanFall);
                    break;

                case 2:
                case 6:
                case 10:
                    prince.pushSequence(Stance::Falling_Down_P0_1_Start, Stance::Falling_Down_P0_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_Down_P0_5_Check_CanFall);
                    break;

            }

        }
        else {

            #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
            DEBUG_PRINT(F("Falling in arc, x % 12 ="));
            DEBUG_PRINTLN(prince.getX() % 12);
            #endif

            switch (prince.getX() % 12) {

                case 0:
                case 4:
                case 8:
                    prince.pushSequence(Stance::Falling_StepWalkRun_P0_4_8_1_Start, Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall);
                    break;

                case 1:
                case 5:
                case 9:
                    prince.pushSequence(Stance::Falling_StepWalkRun_P1_5_9_1_Start, Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall);
                    break;

                case 2:
                case 6:
                case 10:
                    prince.pushSequence(Stance::Falling_StepWalkRun_P2_6_10_1_Start, Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall);
                    break;

                case 3:
                case 7:
                case 11:
                    prince.pushSequence(Stance::Falling_StepWalkRun_P3_7_11_1_Start, Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall, true);
                    prince.setPrevStance(Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall);
                    break;

            }

        }

    }


    // If in the air and touching wall, then move backwards ..

    if (!prince.getIgnoreWallCollisions() && prince.inAir() && prince.getFalling() == 0 && level.collideWithWall(prince)) {

        #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
        DEBUG_PRINT(F("Collide with wall - X:"));
        DEBUG_PRINT(prince.getX());
        DEBUG_PRINT(", Y:");
        DEBUG_PRINT(prince.getY());
        DEBUG_PRINT(", inAir:");
        DEBUG_PRINT(prince.inAir());
        DEBUG_PRINT(", falling:");
        DEBUG_PRINT(prince.getFalling());
        DEBUG_PRINT(", Coll:");
        DEBUG_PRINTLN(level.collideWithWall(prince));
        #endif

        #if defined(DEBUG) && defined(DEBUG_ACTION_FALLING)
        DEBUG_PRINTLN(F("Collide with wall, setFalling(1)"));
        #endif

        prince.clear();
        prince.setFalling(1);


        // Do we need to apply any horizontal adjustment?

        switch (prince.getX() % 12) {

            case 0:
                prince.push(Stance::Collide_Wall_M2_Start_End, false);
                break;

            case 1:
            case 5:
            case 9:
            case 3:
                prince.push(Stance::Collide_Wall_M1_Start_End, false);
                break;

            case 2:
            case 6:
            case 10:
                prince.push(Stance::Collide_Wall_P0_Start_End, false);
                break;

            // case 3:
            case 7:
            case 11:
                prince.push(Stance::Collide_Wall_P1_Start_End, false);
                break;

            case 4:
            case 8:
            case 12:
                prince.push(Stance::Collide_Wall_P2_Start_End, false);
                break;

        }                    


        // Do we need to apply some vertical adjustment?
        
        uint8_t adj = (prince.getY() - 25) % 31;

        #if defined(DEBUG) && defined(DEBUG_VERT_ADJ)
        DEBUG_PRINT(F("Vert AJD, prince.getY():"));
        DEBUG_PRINT(prince.getY());
        SDEBUG_PRINT(", Adj:");
        DEBUG_PRINT(adj);
        #endif

        if (adj != 0) {

            adj = 31 - adj;
            adj = (adj - 1) * 5;

            uint24_t startPos = Constants::VertAdjustments + adj;
            FX::seekData(startPos);

            for (uint8_t i = adj; i < adj + 5; i++) {
                
                uint8_t adjustment = FX::readPendingUInt8();

                if (adjustment > 0) {

                    #if defined(DEBUG) && defined(DEBUG_VERT_ADJ)
                    DEBUG_PRINT(F(", adjustment: "));
                    DEBUG_PRINT(adjustment);
                    SDEBUG_PRINT(", Base: ");
                    DEBUG_PRINT(Stance::Vert_Adjustment_1_Start_End);
                    #endif

                    prince.push(Stance::Vert_Adjustment_1_Start_End - 1 + adjustment, false);

                }

            }

            FX::readEnd();

        }

        #if defined(DEBUG) && defined(DEBUG_VERT_ADJ)
        DEBUG_PRINTLN(F(" "));
        #endif

    }


    // Open exit door ?

    {

        Item &item = level.getItem(Constants::Item_ExitDoor);

        if (item.data.exitDoor.position == 0) {

            int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x);
            int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y);

            if (tileXIdx >= item.data.exitDoor.left && tileXIdx <= item.data.exitDoor.right && item.y == tileYIdx) {

                item.data.exitDoor.direction = Direction::Up;

            }

        }

    }


    // Is the prince dead?

    if (prince.getStance() == Stance::Falling_Dead_3_End) {

        if (justPressed & A_BUTTON) {

            if (!gamePlay.isGameOver()) {

                gamePlay.gameState = GameState::Game_StartLevel;

            }
            else {

                gamePlay.gameState = GameState::Game_Over;

            }

        }

    }



    // Render scene ..

    render(enemyIsVisible);
    
    #ifndef SAVE_MEMORY_OTHER
        if (gamePlay.gameState == GameState::Menu) {
            renderMenu();
        }
    #endif

    #if defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS)
    font3x5.setTextColor(0);
    arduboy.fillRect(0, 0, 128, 7);
    font3x5.setCursor(0, 0);
    font3x5.print(F("St"));
    font3x5.print(prince.getStance());
    font3x5.print(F(" px"));
    font3x5.print(prince.getX());
    font3x5.print(F(" x"));
    font3x5.print(level.coordToTileIndexX((level.getXLocation() * Constants::TileWidth) + prince.getX()));
    font3x5.print(F(" "));
    font3x5.print((level.getXLocation() * Constants::TileWidth) + prince.getX());
    font3x5.print(F(" y"));
    font3x5.print(level.coordToTileIndexY((level.getYLocation() * Constants::TileHeight) + prince.getY()));
    font3x5.print(F(" "));
    font3x5.print(prince.getY());
    font3x5.print(F(" D"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    #endif


    #if defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS_MIN)
    font3x5.setTextColor(0);
    font3x5.setCursor(1, 0);
    arduboy.fillRect(0, 0, 13, 7);
    font3x5.print(F("D"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(),  (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    #endif

}


void moveBackwardsWithSword(BaseEntity entity, BaseStack stack) { 

    if (level.canMoveForward(entity, Action::Step, entity.getOppositeDirection())) {

        stack.clear();
        stack.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, false);
        stack.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, false);

    }
    else if (level.canMoveForward(entity, Action::SmallStep, entity.getOppositeDirection())) {

        stack.clear();
        stack.pushSequence(Stance::Sword_Step_03_End, Stance::Sword_Step_01_Start, Stance::Sword_Normal, false);

    }

}
