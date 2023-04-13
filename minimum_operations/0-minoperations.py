#!/usr/bin/python3
""" Minimum Operations """

import numpy as np


def minOperations(n):
    """ Calculates the fewest number of operations needed to result in exactly
        n H characters in the file

        Arguments:
            n: number of H characters

        Returns:
            fewest number of operations needed to result in exactly n H
            characters in the file
    """
    if not isinstance(n, int) or n < 2:
        return 0

    factors = []
    for i in range(2, int(np.sqrt(n))+1):
        while n % i == 0:
            factors.append(i)
            n //= i
    if n > 1:
        factors.append(n)

    return np.sum(factors)
