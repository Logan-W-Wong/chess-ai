/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 12/30/2023
 */
#ifndef MOVES_H
#define MOVES_H

#include "chessboard.h"

// an int representing a move
typedef int move;

// one step functions
bitboard shiftOne(bitboard, int);

// occluded fill functions
bitboard occlFill(bitboard, bitboard, int);

#endif