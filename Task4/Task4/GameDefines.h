#pragma once
#include "String.h"

// Map Sizes
const int STARTER_MAP_HEIGHT = 5;
const int STARTER_MAP_WIDTH = 6;

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
const int ITEM_DROPPED = 3;
const char ITEM_DROPPED_ICON = '$';
const int ENTER = 4;
const char ENTER_ICON = '@';
const int EXIT = 5;
const char EXIT_ICON = '=';

// Items
const int AIR = 5; // if there's no item

// Room Descriptions
const String EMPTY_DESC = "It’s an empty room, nothing to see here";
const String ENEMY_DESC = "WATCH OUT! An enemy is nearby.";
const String ITEM_DESC = "It looks like there's a chest here.";
const String ITEM_DROPPED_DEC = "You left something here earlier.";
const String EXIT_DESC = "You found the exit to go to the next floor!";
const String ENTER_DESC = "You came in this way, it seems to be blocked off.";