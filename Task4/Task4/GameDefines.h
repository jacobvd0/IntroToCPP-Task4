#pragma once

// Map Sizes
const int STARTER_MAP_HEIGHT = 2;
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
const int ENTER = 3;
const char ENTER_ICON = '@';
const int EXIT = 4;
const char EXIT_ICON = '=';

// Items
const int AIR = 5; // if there's no item