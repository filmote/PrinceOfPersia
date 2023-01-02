
#pragma once

enum GameState : uint8_t {
    SplashScreen_Init,
    SplashScreen,
    Title_Init,
    Title,
    Game_Init,
    Game,
    Game_StartLevel,
    Game_Over,
    #ifndef SAVE_MEMORY_OTHER
    Menu,
    #endif
};

enum class Direction : uint8_t {
    None,
    Left,
    Right,
    Up,
    Down,
    Forward,
    Back,
};

enum class Layer : uint8_t {
    Background,
    Foreground,
};

enum class Action : uint8_t {
    Step,
    SmallStep,
    RunStart,
    RunRepeat,
    RunJump_3,
    RunJump_2,
    RunJump_1,
    StandingJump,
    CrouchHop,
};

enum class CanJumpUpResult : uint8_t {
    None,
    Jump,
    StepThenJump,
    JumpThenFall,
    TurnThenJump,
    JumpDist10,
    JumpThenFall_CollapseFloor,             
    StepThenJumpThenFall_CollapseFloor,     
    JumpThenFall_CollapseFloorAbove,        
};

enum class CanClimbDownResult : uint8_t {
    None,
    ClimbDown,
    StepThenClimbDown,
    TurnThenClimbDown,
    StepThenTurnThenClimbDown,
};

enum class CanClimbDownPart2Result : uint8_t {
    None,
    Level_1,
    Falling,
    Level_1_Under,
};

enum class StandingJumpResult : uint8_t {
    None,
    Normal,
    DropLevel,
    Medium,
    Short, // Same level but a little shorter.
};

enum class RunningJumpResult : uint8_t {
    None,
    Normal,
    Jump4_DropLevel,
    Jump3_KeepLevel,
    Jump3_KeepLevel_Short,
    Jump3_DropLevel,
};

enum class ItemType : uint8_t {
    /* 00 */ InteractiveItemType_Start,
    /* 01 */ CollapsingFloor,
    /* 02 */ FloorButton1,
    /* 03 */ FloorButton2,
    /* 04 */ Spikes,
    /* 05 */ ExitDoor_Button,
    /* 06 */ ExitDoor_Button_Cropped,
    /* 07 */ FloorButton3_UpDown,
    /* 08 */ FloorButton3_UpOnly,
    /* 09 */ FloorButton3_DownOnly,
    /* __ */ InteractiveItemType_End = FloorButton3_DownOnly,
    /* 15 */ Skeleton = 15,
    /* 16 */ ExitDoor_SelfOpen,
    /* 17 */ Gate,               
    /* 18 */ Sword,
    /* 19 */ CollpasedFloor,
    /* 20 */ Potion_Small,
    /* 21 */ Potion_Large,
    /* 22 */ Potion_Poison,
    /* 23 */ EntryDoor,
    /* 24 */ EntryDoor_Cropped,
    /* 25 */ Blade,
    /* 26 */ ExitDoor_ButtonOpen,
    /* 27 */ Gate_StayOpen,          
    /* 28 */ EntryDoor_HalfTileLeft,
    /* 96 */ None = 96,
    /* 97 */ LoveHeart = 97,
    /* 98 */ Sign = 98,
    /* 99 */ Flash = 99,
    /* 99 */ AllItemTypes_End = Flash,
};

enum class MenuOption : uint8_t {
    Resume,
    Save,
    Load,
    MainMenu,
};

enum class TitleScreenOptions : uint8_t {
    Play,
    Credits, 
};

enum class TitleScreenMode : uint8_t {
    Intro,
    Main,
    Credits, 
    IntroGame_1A,
    CutScene_1,
    IntroGame_1B,
    CutScene_2,
    CutScene_3,
    CutScene_4,
    CutScene_5,
    CutScene_9,
    IntroGame_9,
};

enum class WallTileResults : uint8_t {
    None,
    Normal,
    GateClosed, 
};

enum class SignType : uint8_t {
    PressA,
    GameOver,
};

enum class FlashType : uint8_t {
    None,
    SwordFight,
};

enum class LevelUpdate : uint8_t {
    NoAction,
    FloorCollapsedOnPrince,
};

