/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 12/30/2023
 * Purpose: Logic for which moves are available
 */

#include "chessboard.h"
#include "moves.h"

const QWORD notAFile = 0xfefefefefefefefe;
const QWORD notHFile = 0x7f7f7f7f7f7f7f7f;

const QWORD avoidWrap[8] = {
    0xffffffffffffff00,
    0xfefefefefefefe00,
    0xfefefefefefefefe,
    0x00fefefefefefefe,
    0x00ffffffffffffff,
    0x007f7f7f7f7f7f7f,
    0x7f7f7f7f7f7f7f7f,
    0x7f7f7f7f7f7f7f00};

// direction array with index 0 = north
const int shift[8] = {8, 9, 1, -7, -8, -9, -1, 7};

// general shift

bitboard genShift(bitboard bb, int s)
{
    return s > 0 ? bb << s : bb >> -s;
}

// One step only function

bitboard shiftOne(bitboard bb, int dir)
{
    return (genShift(bb, shift[dir])) & avoidWrap[dir];
}

// Occluded fill fucntion, generator for pieces, propagator for empty squares, direction for compass direction to move

bitboard occlFill(bitboard gen, bitboard prop, int dir)
{
    bitboard flood = 0;
    if (gen)
    {
        do
        {
            flood |= gen;
            gen = (shiftOne(gen, dir) & prop);
        } while (gen);
    }
    return flood;
}

bitboard slidingAttacks(bitboard gen, bitboard prop, int dir)
{
    bitboard fill = occlFill(gen, prop, dir);
    return shiftOne(fill, dir);
}