#pragma once
#include "String.h"

// Map Sizes
const int STARTER_MAP_HEIGHT = 10;
const int STARTER_MAP_WIDTH = 10;

const int UPGRADED_MAP_HEIGHT = 12;
const int UPGRADED_MAP_WIDTH = 20;

const int MAX_MAP_HEIGHT = 12;
const int MAX_MAP_WIDTH = 20;


// Rooms
const int EMPTY = 0;
const char EMPTY_ICON = '#';
const int ENEMY = 1;
const char ENEMY_ICON = 'E';
const int ITEM = 2;
const char ITEM_ICON = '$';
const int ENTER = 3;
const char ENTER_ICON = '@';
const int EXIT = 4;
const char EXIT_ICON = '=';

// Dropped item aren't generated
const int ITEM_DROPPED = 5;
const char ITEM_DROPPED_ICON = '$';

const int MAX_RANDOM_TYPE = 3;

// Items
const int AIR = 5; // if there's no item

// Room Descriptions
const String EMPTY_DESC = "It's an empty room, nothing to see here";
const String ENEMY_DESC = "WATCH OUT! An enemy is nearby.";
const String ITEM_DESC = "It looks like there's a chest here.";
const String ITEM_DROPPED_DEC = "You left something here earlier.";
const String EXIT_DESC = "You found the exit to go to the next floor!";
const String ENTER_DESC = "You came in this way, it seems to be blocked off.";


const char* const CSI = "\x1b[";

const char* const RESET_COLOR = "\x1b[0m";
const char* const RED = "\x1b[91m";
const char* const YELLOW = "\x1b[93m";
const char* const GREY = "\x1b[38;5;8m";
const char* const LIGHT_GREY = "\x1b[38;5;248m";
