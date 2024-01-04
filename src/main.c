/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 12/30/2023
 * Purpose: Main file for chess ai
 */

#include "chessboard.h"
#include "moves.h"
#include "main.h"
#include <stdio.h>

int side = white;

int canCastle = 15; // 1111, 0001 is white queenside, 0010 is white kingside, 0100 is black queenside, 1000 is black kingside

int empassant = 0; // holds square where pawn can be taken after a double push

// array rep of board, big endian compared to little endian bitboard
// may switch to 0x88 int[128] representation later
int arrayBoard[64] = {
    r, n, b, q, k, b, n, r,
    p, p, p, p, p, p, p, p,
    e, e, e, e, e, e, e, e,
    e, e, e, e, e, e, e, e,
    e, e, e, e, e, e, e, e,
    e, e, e, e, e, e, e, e,
    P, P, P, P, P, P, P, P,
    R, N, B, Q, K, B, N, R};

int main()
{
    Board gameBoard = setBoard();
    printBoard(getOccupied(gameBoard));
    bitboard bb = gameBoard.black;
    printBoard(bb);
    bb = gameBoard.white;
    printBoard(bb);
    bb = gameBoard.bishops;
    printBoard(bb);
}
