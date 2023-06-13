#!/usr/bin/env python3
""" N queens """

import sys


def place_nqueens(n, row, solutions):
    """ placing n non-attacking queens on an n x n chessboard """
    for column in range(n):
        queen = 0

        # check if no queens attack
        for solution in solutions:
            if abs(column - solution[1]) == abs(row - solution[0]):
                queen = 1
                break
            if column == solution[1]:
                queen = 1
                break

        if queen == 0:
            solutions.append([row, column])

            if row != n - 1:
                place_nqueens(n, row + 1, solutions)
            else:
                print(solutions)

            solutions.pop()


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    if not sys.argv[1].isdigit():
        print('N must be a number')
        sys.exit(1)

    n = int(sys.argv[1])

    if n < 4:
        print('N must be at least 4')
        sys.exit(1)

    row = 0
    solutions = []
    place_nqueens(n, row, solutions)
