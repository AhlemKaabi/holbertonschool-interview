#!/usr/bin/python3
"""
0x16 - Rotate 2D Matrix
"""


def copyMat(matrix):
    """
    matrix: a 2D Matrix of type list
    """
    ln = len(matrix)
    m = []
    for i in range(ln):
        d = []
        for j in range(ln):
            d.append(matrix[i][j])
        m.append(d)
    return m


def rotate_2d_matrix(matrix):
    """
    matrix: n x n 2D Matrix of type list
    """
    ln = len(matrix)
    m = copyMat(matrix)
    for i in range(ln):
        for j in range(ln):
            matrix[j][ln-1-i] = m[i][j]
