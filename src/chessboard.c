/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 1/3/2024
 * Purpose: Creates board structures and functions to get board states
 */
#include "chessboard.h"
#include <stdio.h>

// gets empty squares
bitboard getEmpty(Board board)
{
    bitboard bb;
    bb = ~(board.white | board.black);
    return bb;
}

// gets occupied squares
bitboard getOccupied(Board board)
{
    return board.white | board.black;
}

// sets up starting board
Board setBoard()
{
    Board board;
    board.pawns = 0xFF00000000FF00;
    board.knights = 0x4200000000000042;
    board.bishops = 0x2400000000000024;
    board.rooks = 0x8100000000000081;
    board.queens = 0x800000000000008;
    board.kings = 0x1000000000000010;

    board.white = 0xFFFF;
    board.black = 0xFFFF000000000000;

    return board;
}

// prints a bitboard in an 8x8 square
void printBoard(bitboard bb)
{
    printf("Bitboard representation: \n");
    for (int i = 7; i > -1; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            int lsb = (bb >> ((i * 8) + j)) & 1;
            printf("%d  ", lsb);
        }
        printf("\n");
    }
}
