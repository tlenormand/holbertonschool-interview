#!/usr/bin/python3
""" Minimum Operations """

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

    operations = 0

    biggest_mod = 0
    result_biggest_mod = 0

    for i in reversed(range(1, n)):
        if n % i == 0:
            biggest_mod = i
            result_biggest_mod = n // i
            n = biggest_mod
            break

    operations += result_biggest_mod

    return operations + minOperations(n)
