#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.13 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xf58d;
constexpr uint24_t FX_DATA_BYTES = 680684;

constexpr uint16_t FX_SAVE_PAGE  = 0xfff0;
constexpr uint24_t FX_SAVE_BYTES = 2;

namespace Levels
{
  constexpr uint24_t Level1_FG = 0x000000;
  constexpr uint24_t Level1_BG = 0x00032A;
  constexpr uint24_t level1_Data = 0x000654;
  constexpr uint24_t Level1_Items = 0x00066D;
  constexpr uint24_t Level2_FG = 0x0007CE;
  constexpr uint24_t Level2_BG = 0x000DE6;
  constexpr uint24_t level2_Data = 0x0013FE;
  constexpr uint24_t Level2_Items = 0x00142F;
  constexpr uint24_t Level3_FG = 0x001530;
  constexpr uint24_t Level3_BG = 0x001A76;
  constexpr uint24_t level3_Data = 0x001FBC;
  constexpr uint24_t Level3_Items = 0x001FCD;
  constexpr uint24_t Level4_FG = 0x00207E;
  constexpr uint24_t Level4_BG = 0x0024B6;
  constexpr uint24_t level4_Data = 0x0028EE;
  constexpr uint24_t Level4_Items = 0x00291F;
  constexpr uint24_t Level5_FG = 0x002A80;
  constexpr uint24_t Level5_BG = 0x002FC6;
  constexpr uint24_t level5_Data = 0x00350C;
  constexpr uint24_t Level5_Items = 0x003535;
  constexpr uint24_t Level6_FG = 0x003666;
  constexpr uint24_t Level6_BG = 0x0038DC;
  constexpr uint24_t level6_Data = 0x003B52;
  constexpr uint24_t Level6_Items = 0x003B6B;
  constexpr uint24_t Level7_FG = 0x003BCC;
  constexpr uint24_t Level7_BG = 0x004004;
  constexpr uint24_t level7_Data = 0x00443C;
  constexpr uint24_t Level7_Items = 0x00445D;
  constexpr uint24_t Level8_FG = 0x0045E6;
  constexpr uint24_t Level8_BG = 0x004B0E;
  constexpr uint24_t level8_Data = 0x005036;
  constexpr uint24_t Level8_Items = 0x00505F;
  constexpr uint24_t Level9_FG = 0x0051A0;
  constexpr uint24_t Level9_BG = 0x005560;
  constexpr uint24_t level9_Data = 0x005920;
  constexpr uint24_t Level9_Items = 0x005949;
  constexpr uint24_t Level10_FG = 0x005AB2;
  constexpr uint24_t Level10_BG = 0x005D82;
  constexpr uint24_t level10_Data = 0x006052;
  constexpr uint24_t Level10_Items = 0x00607B;
  constexpr uint24_t Level11_FG = 0x0061DC;
  constexpr uint24_t Level11_BG = 0x006614;
  constexpr uint24_t level11_Data = 0x006A4C;
  constexpr uint24_t Level11_Items = 0x006A6D;
  constexpr uint24_t Level12_FG = 0x006BEE;
  constexpr uint24_t Level12_BG = 0x00727E;
  constexpr uint24_t level12_Data = 0x00790E;
  constexpr uint24_t Level12_Items = 0x007927;
  constexpr uint24_t Level13_FG = 0x007A70;
  constexpr uint24_t Level13_BG = 0x007B24;
  constexpr uint24_t level13_Data = 0x007BD8;
  constexpr uint24_t Level13_Items = 0x007BE1;
  constexpr uint24_t Level14_StandingJumps_FG = 0x007C32;
  constexpr uint24_t Level14_StandingJumps_BG = 0x007D22;
  constexpr uint24_t Level14_StandingJumps_Data = 0x007E12;
  constexpr uint24_t Level14_StandingJumps_Items = 0x007E1B;
  constexpr uint24_t Level15_RunningJumps_FG = 0x007E1C;
  constexpr uint24_t Level15_RunningJumps_BG = 0x007F0C;
  constexpr uint24_t Level15_RunningJumps_Data = 0x007FFC;
  constexpr uint24_t Level15_RunningJumps_Items = 0x008005;
  constexpr uint24_t level_FG = 0x008006;
  constexpr uint24_t Level_BG = 0x008036;
  constexpr uint24_t level_Data = 0x008066;
  constexpr uint24_t Level_Items = 0x008096;
}

namespace Sounds
{
  constexpr uint24_t Dead = 0x0080C6;
  constexpr uint24_t Grab1 = 0x0080E4;
  constexpr uint24_t Grab2 = 0x00810E;
  constexpr uint24_t Grab3 = 0x008138;
  constexpr uint24_t Grab4 = 0x008172;
  constexpr uint24_t Seque = 0x0081C8;
  constexpr uint24_t Tada = 0x008242;
  constexpr uint24_t Theme = 0x008260;
  constexpr uint24_t Triumph = 0x00842E;
  constexpr uint24_t Victory = 0x00844C;
  constexpr uint24_t Ending = 0x0084BE;
  constexpr uint24_t OutOfTime = 0x00873C;
  constexpr uint24_t GateGoingDown = 0x008782;
  constexpr uint24_t GateGoingUp = 0x0087C0;
  constexpr uint24_t ChopChop = 0x0087FE;
  constexpr uint24_t Thump = 0x008810;
  constexpr uint24_t Strike = 0x008822;
}

namespace Images
{
  constexpr uint24_t PPOT = 0x008830;
  constexpr uint16_t PPOT_WIDTH  = 65;
  constexpr uint16_t PPOTHEIGHT  = 31;
  constexpr uint8_t  PPOT_FRAMES = 4;

  constexpr uint24_t Title_PoP = 0x008C44;
  constexpr uint16_t Title_PoP_width  = 128;
  constexpr uint16_t Title_PoP_height = 33;

  constexpr uint24_t Title_Main_NoHigh = 0x009148;
  constexpr uint16_t Title_Main_NoHigh_width  = 128;
  constexpr uint16_t Title_Main_NoHigh_height = 88;

  constexpr uint24_t Title_Main_WithHigh = 0x0096CC;
  constexpr uint16_t Title_Main_WithHigh_width  = 128;
  constexpr uint16_t Title_Main_WithHigh_height = 88;

  constexpr uint24_t Title_Cursor = 0x009C50;
  constexpr uint16_t Title_Cursor_width  = 5;
  constexpr uint16_t Title_Cursor_height = 5;

  constexpr uint24_t Title_Credits = 0x009C59;
  constexpr uint16_t Title_Credits_width  = 73;
  constexpr uint16_t Title_Credits_height = 136;

  constexpr uint24_t TimeRemaining = 0x00A136;
  constexpr uint16_t TimeRemainingWidth  = 81;
  constexpr uint16_t TimeRemainingHeight = 15;

  constexpr uint24_t LevelNumber = 0x00A27E;
  constexpr uint16_t LevelNumberWidth  = 81;
  constexpr uint16_t LevelNumberHeight = 15;

  constexpr uint24_t GameOver = 0x00A3C6;
  constexpr uint16_t GameOverWidth  = 49;
  constexpr uint16_t GameOverHeight = 15;

  constexpr uint24_t PressA = 0x00A48E;
  constexpr uint16_t PressAWidth  = 79;
  constexpr uint16_t PressAHeight = 15;

  constexpr uint24_t TimeOut = 0x00A5CE;
  constexpr uint16_t TimeOutWidth  = 86;
  constexpr uint16_t TimeOutHeight = 114;

  constexpr uint24_t IntroGame_1A = 0x00AADC;
  constexpr uint16_t IntroGame_1A_width  = 118;
  constexpr uint16_t IntroGame_1A_height = 96;

  constexpr uint24_t IntroGame_1B = 0x00B068;
  constexpr uint16_t IntroGame_1B_width  = 123;
  constexpr uint16_t IntroGame_1B_height = 96;

  constexpr uint24_t IntroGame_9 = 0x00B630;
  constexpr uint16_t IntroGame_9_width  = 123;
  constexpr uint16_t IntroGame_9_height = 160;

  constexpr uint24_t Chambers_BG = 0x00BFD0;
  constexpr uint16_t Chambers_BG_width  = 128;
  constexpr uint16_t Chambers_BG_height = 64;

  constexpr uint24_t Chambers_FG = 0x00C3D4;
  constexpr uint16_t Chambers_FG_width  = 128;
  constexpr uint16_t Chambers_FG_height = 64;

  constexpr uint24_t Credits_BG = 0x00CBD8;
  constexpr uint16_t Credits_BG_width  = 128;
  constexpr uint16_t Credits_BG_height = 9;

  constexpr uint24_t Eeek = 0x00CCDC;
  constexpr uint16_t EeekWidth  = 43;
  constexpr uint16_t EeekHeight = 19;

  constexpr uint24_t Mouse = 0x00CDE2;
  constexpr uint16_t MouseWidth  = 16;
  constexpr uint16_t MouseHeight = 16;
  constexpr uint8_t  MouseFrames = 3;

  constexpr uint24_t HourGlasses = 0x00CEA6;
  constexpr uint16_t HourGlassesWidth  = 19;
  constexpr uint16_t HourGlassesHeight = 23;
  constexpr uint8_t  HourGlassesFrames = 21;

  constexpr uint24_t Menu = 0x00D804;
  constexpr uint16_t MenuWidth  = 42;
  constexpr uint16_t MenuHeight = 64;
  constexpr uint8_t  MenuFrames = 3;

  constexpr uint24_t Sword_Cursor = 0x00DBF8;
  constexpr uint16_t Sword_Cursor_width  = 8;
  constexpr uint16_t Sword_Cursor_height = 10;

  constexpr uint24_t HUD_Backgrounds = 0x00DC0C;
  constexpr uint16_t HUD_Backgrounds_width  = 8;
  constexpr uint16_t HUD_Backgrounds_height = 64;
  constexpr uint8_t  HUD_Backgrounds_frames = 2;

  constexpr uint24_t Numbers_Upright = 0x00DC90;
  constexpr uint16_t Numbers_Upright_width  = 7;
  constexpr uint16_t Numbers_Upright_height = 5;
  constexpr uint8_t  Numbers_Upright_frames = 60;

  constexpr uint24_t Numbers = 0x00DE38;
  constexpr uint16_t NumbersWidth  = 11;
  constexpr uint16_t NumbersHeight = 7;
  constexpr uint8_t  NumbersFrames = 60;

  constexpr uint24_t Numbers_Large = 0x00E0D0;
  constexpr uint16_t Numbers_Large_width  = 22;
  constexpr uint16_t Numbers_Large_height = 14;
  constexpr uint8_t  Numbers_Large_frames = 60;

  constexpr uint24_t Numbers_Small = 0x00EB24;
  constexpr uint16_t Numbers_Small_width  = 5;
  constexpr uint16_t Numbers_Small_height = 7;
  constexpr uint8_t  Numbers_Small_frames = 60;

  constexpr uint24_t Numbers_Divider = 0x00EC54;
  constexpr uint16_t Numbers_Divider_width  = 4;
  constexpr uint16_t Numbers_Divider_height = 8;

  constexpr uint24_t Healths = 0x00EC5C;
  constexpr uint16_t HealthsWidth  = 5;
  constexpr uint16_t HealthsHeight = 3;
  constexpr uint8_t  HealthsFrames = 2;

  constexpr uint24_t Sword_HUD = 0x00EC6A;
  constexpr uint16_t Sword_HUD_width  = 5;
  constexpr uint16_t Sword_HUD_height = 5;

  constexpr uint24_t Potion_Float_HUD = 0x00EC73;
  constexpr uint16_t Potion_Float_HUD_width  = 5;
  constexpr uint16_t Potion_Float_HUD_height = 5;

  constexpr uint24_t HighScore = 0x00EC7C;
  constexpr uint16_t HighScoreWidth  = 52;
  constexpr uint16_t HighScoreHeight = 5;

  constexpr uint24_t Sword = 0x00ECB4;
  constexpr uint16_t SwordWidth  = 14;
  constexpr uint16_t SwordHeight = 5;

  constexpr uint24_t Skeleton = 0x00ECD4;
  constexpr uint16_t SkeletonWidth  = 15;
  constexpr uint16_t SkeletonHeight = 12;

  constexpr uint24_t Gates = 0x00ED14;
  constexpr uint16_t GatesWidth  = 9;
  constexpr uint16_t GatesHeight = 28;
  constexpr uint8_t  GatesFrames = 10;

  constexpr uint24_t Blades = 0x00EFE8;
  constexpr uint16_t BladesWidth  = 9;
  constexpr uint16_t BladesHeight = 28;
  constexpr uint8_t  BladesFrames = 6;

  constexpr uint24_t ExitDoors = 0x00F19C;
  constexpr uint16_t ExitDoorsWidth  = 25;
  constexpr uint16_t ExitDoorsHeight = 33;
  constexpr uint8_t  ExitDoorsFrames = 13;

  constexpr uint24_t Potions_Small = 0x00F7F9;
  constexpr uint16_t Potions_Small_width  = 6;
  constexpr uint16_t Potions_Small_height = 15;
  constexpr uint8_t  Potions_Small_frames = 2;

  constexpr uint24_t Potions_Large = 0x00F82D;
  constexpr uint16_t Potions_Large_width  = 6;
  constexpr uint16_t Potions_Large_height = 15;
  constexpr uint8_t  Potions_Large_frames = 2;

  constexpr uint24_t Potions_Poison = 0x00F861;
  constexpr uint16_t Potions_Poison_width  = 6;
  constexpr uint16_t Potions_Poison_height = 15;
  constexpr uint8_t  Potions_Poison_frames = 6;

  constexpr uint24_t Potions_Float = 0x00F8F5;
  constexpr uint16_t Potions_Float_width  = 6;
  constexpr uint16_t Potions_Float_height = 15;
  constexpr uint8_t  Potions_Float_frames = 7;

  constexpr uint24_t DecorativeDoor = 0x00F9A1;
  constexpr uint16_t DecorativeDoorWidth  = 23;
  constexpr uint16_t DecorativeDoorHeight = 40;

  constexpr uint24_t CollapsedFloor = 0x00FA18;
  constexpr uint16_t CollapsedFloorWidth  = 21;
  constexpr uint16_t CollapsedFloorHeight = 13;

  constexpr uint24_t CollapsingFloors = 0x00FA70;
  constexpr uint16_t CollapsingFloorsWidth  = 21;
  constexpr uint16_t CollapsingFloorsHeight = 31;
  constexpr uint8_t  CollapsingFloorsFrames = 4;

  constexpr uint24_t FloorButtons_0and1 = 0x00FD14;
  constexpr uint16_t FloorButtons_0and1_width  = 21;
  constexpr uint16_t FloorButtons_0and1_height = 32;
  constexpr uint8_t  FloorButtons_0and1_frames = 4;

  constexpr uint24_t FloorButtons_2 = 0x00FFB8;
  constexpr uint16_t FloorButtons_2_width  = 12;
  constexpr uint16_t FloorButtons_2_height = 31;
  constexpr uint8_t  FloorButtons_2_frames = 2;

  constexpr uint24_t Torches = 0x01007C;
  constexpr uint16_t TorchesWidth  = 3;
  constexpr uint16_t TorchesHeight = 11;
  constexpr uint8_t  TorchesFrames = 5;

  constexpr uint24_t Mirrors = 0x0100BC;
  constexpr uint16_t MirrorsWidth  = 12;
  constexpr uint16_t MirrorsHeight = 31;
  constexpr uint8_t  MirrorsFrames = 2;

  constexpr uint24_t Spikes_FG_Full = 0x010120;
  constexpr uint16_t Spikes_FG_Full_width  = 19;
  constexpr uint16_t Spikes_FG_Full_height = 18;
  constexpr uint8_t  Spikes_FG_Full_frames = 5;

  constexpr uint24_t Spikes_BG_Full = 0x01035E;
  constexpr uint16_t Spikes_BG_Full_width  = 19;
  constexpr uint16_t Spikes_BG_Full_height = 18;
  constexpr uint8_t  Spikes_BG_Full_frames = 5;

  constexpr uint24_t Spikes_FG_Half = 0x01059C;
  constexpr uint16_t Spikes_FG_Half_width  = 11;
  constexpr uint16_t Spikes_FG_Half_height = 18;
  constexpr uint8_t  Spikes_FG_Half_frames = 5;

  constexpr uint24_t Spikes_BG_Half = 0x0106EA;
  constexpr uint16_t Spikes_BG_Half_width  = 11;
  constexpr uint16_t Spikes_BG_Half_height = 18;
  constexpr uint8_t  Spikes_BG_Half_frames = 5;

  constexpr uint24_t Flashes = 0x010838;
  constexpr uint16_t FlashesWidth  = 22;
  constexpr uint16_t FlashesHeight = 20;
  constexpr uint8_t  FlashesFrames = 4;

  constexpr uint24_t Tiles_Dungeon = 0x010A4C;
  constexpr uint16_t Tiles_Dungeon_width  = 12;
  constexpr uint16_t Tiles_Dungeon_height = 31;
  constexpr uint8_t  Tiles_Dungeon_frames = 100;

  constexpr uint24_t Tile_Dungeon_97 = 0x012FD0;
  constexpr uint16_t Tile_Dungeon_97_width  = 21;
  constexpr uint16_t Tile_Dungeon_97_height = 31;

  constexpr uint24_t Tile_Dungeon_98 = 0x01307C;
  constexpr uint16_t Tile_Dungeon_98_width  = 12;
  constexpr uint16_t Tile_Dungeon_98_height = 31;

  constexpr uint24_t Tiles_Dungeon_Torch = 0x0130E0;
  constexpr uint16_t Tiles_Dungeon_Torch_width  = 12;
  constexpr uint16_t Tiles_Dungeon_Torch_height = 31;
  constexpr uint8_t  Tiles_Dungeon_Torch_frames = 60;

  constexpr uint24_t Princess = 0x014764;
  constexpr uint16_t PrincessWidth  = 32;
  constexpr uint16_t PrincessHeight = 32;
  constexpr uint8_t  PrincessFrames = 40;

  constexpr uint24_t Princess_Bounce = 0x016F68;
  constexpr uint16_t Princess_Bounce_width  = 48;
  constexpr uint16_t Princess_Bounce_height = 32;
  constexpr uint8_t  Princess_Bounce_frames = 20;

  constexpr uint24_t Hearts = 0x018D6C;
  constexpr uint16_t HeartsWidth  = 7;
  constexpr uint16_t HeartsHeight = 6;
  constexpr uint8_t  HeartsFrames = 4;

  constexpr uint24_t Zaffar = 0x018D8C;
  constexpr uint16_t ZaffarWidth  = 32;
  constexpr uint16_t ZaffarHeight = 32;
  constexpr uint8_t  ZaffarFrames = 30;

  constexpr uint24_t Prince_Left = 0x01AB90;
  constexpr uint16_t Prince_Left_width  = 36;
  constexpr uint16_t Prince_Left_height = 36;
  constexpr uint8_t  Prince_Left_frames = 225;

  constexpr uint24_t Prince_Right = 0x02E7FC;
  constexpr uint16_t Prince_Right_width  = 36;
  constexpr uint16_t Prince_Right_height = 36;
  constexpr uint8_t  Prince_Right_frames = 225;

  constexpr uint24_t Mirror_Right = 0x042468;
  constexpr uint16_t Mirror_Right_width  = 36;
  constexpr uint16_t Mirror_Right_height = 36;
  constexpr uint8_t  Mirror_Right_frames = 225;

  constexpr uint24_t Mirror_Left = 0x0560D4;
  constexpr uint16_t Mirror_Left_width  = 36;
  constexpr uint16_t Mirror_Left_height = 36;
  constexpr uint8_t  Mirror_Left_frames = 225;

  constexpr uint24_t Enemy_Right = 0x069D40;
  constexpr uint16_t Enemy_Right_width  = 36;
  constexpr uint16_t Enemy_Right_height = 36;
  constexpr uint8_t  Enemy_Right_frames = 225;

  constexpr uint24_t Enemy_Left = 0x07D9AC;
  constexpr uint16_t Enemy_Left_width  = 36;
  constexpr uint16_t Enemy_Left_height = 36;
  constexpr uint8_t  Enemy_Left_frames = 225;

}

namespace Constants
{
  constexpr uint24_t StanceToImageXRefFX = 0x091618;
  constexpr uint24_t Stance_XYOffsetsFX = 0x0918A8;
  constexpr uint24_t VertAdjustments = 0x091DC6;
  constexpr uint24_t Prince_ImageDetails = 0x091E5C;
}

constexpr uint24_t splashScreen_Frame = 0x0920A5;
constexpr uint24_t Title_Intro_Frame_NoHigh = 0x0920C9;
constexpr uint24_t Title_Intro_Last_Frame_NoHigh = 0x092549;
constexpr uint24_t Title_Intro_Frame_WithHigh = 0x09255B;
constexpr uint24_t Title_Intro_Last_Frame_WithHigh = 0x0929DB;
constexpr uint24_t Title_Main_Frame_NoHigh = 0x0929ED;
constexpr uint24_t Title_Main_Last_Frame_NoFrame = 0x092B79;
constexpr uint24_t Title_Main_Frame_WithHigh = 0x092B8B;
constexpr uint24_t Title_Main_Last_Frame_WithHigh = 0x092D17;
constexpr uint24_t Title_Main_Game_Frame_NoHigh = 0x092D29;
constexpr uint24_t Title_Main_Game_Frame_WithHigh = 0x092D44;
constexpr uint24_t Title_Main_Credits_Frame_NoHigh = 0x092D5F;
constexpr uint24_t Title_Main_Credits_Frame_WithHigh = 0x092D7A;
constexpr uint24_t Title_Main_High_Frame_WithHigh = 0x092D95;
constexpr uint24_t Title_Credits_Frame = 0x092DB0;
constexpr uint24_t Title_TimeOut_Frame = 0x095F27;
constexpr uint24_t Title_High_Frame = 0x098BA9;
constexpr uint24_t Title_IntroGame_1A_Frame = 0x098C30;
constexpr uint24_t Title_CutScene_1_Frame = 0x099206;
constexpr uint24_t Title_IntroGame_1B_Frame = 0x09C713;
constexpr uint24_t Title_CutScene_2_Frame = 0x09CCE9;
constexpr uint24_t Title_CutScene_3_Frame = 0x09E129;
constexpr uint24_t Title_CutScene_4_Frame = 0x09F569;
constexpr uint24_t Title_CutScene_5_Frame = 0x09FF89;
constexpr uint24_t Title_CutScene_6_Frame = 0x0A150D;
constexpr uint24_t Title_CutScene_End_Frame = 0x0A3FD6;
constexpr uint24_t Title_IntroGame_End_Frame = 0x0A5A46;
constexpr uint24_t Chambers_BG_frame = 0x0A6292;
constexpr uint24_t Chambers_FG_frame = 0x0A62E3;
