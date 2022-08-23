#!/usr/bin/python3
"""
    This is the island_perimeter module.
"""


def neighbour(grid, y, x):
    """
        Finds the number of neighbours of a square.
        Args:
            grid (list): the matrix.
            y (int): height parameter.
            x (int): width parameter.
    """
    nb = 4

    if (y > 0) and grid[y - 1][x]:
        nb -= 1
    if (x > 0) and grid[y][x - 1]:
        nb -= 1
    if (y < len(grid) - 1) and grid[y + 1][x]:
        nb -= 1
    if (x < len(grid[0]) - 1) and grid[y][x + 1]:
        nb -= 1
    return nb


def island_perimeter(grid):
    """
        Finds the island perimeter.
        Args:
            grid (list): the matrix.
    """
    perimeter = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x] == 1:
                perimeter += neighbour(grid, y, x)
    return perimeter
