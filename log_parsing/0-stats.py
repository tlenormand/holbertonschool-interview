#!/usr/bin/python3
""" Reads stdin line by line and computes metrics """

import sys


status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
file_size = 0
count = 0


def print_stats():
    """ Prints the accumulated statistics """
    print("File size: {}".format(file_size))
    for key in sorted(status.keys()):
        if status[key]:
            print("{}: {}".format(key, status[key]))


def is_formatted(lime):
    """ Checks if a line is formatted correctly """
    # check the format <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    # <status code> <file size>
    if len(split) != 9:
        return False

    # check the IP Address
    if len(split[0].split('.')) != 4:
        return False
    for num in split[0].split('.'):
        if not num.isdigit():
            return False
        if int(num) < 0 or int(num) > 255:
            return False

    # check the status code
    if not split[-2].isdigit():
        return False

    # check the file size
    if not split[-1].isdigit():
        return False
    if int(split[-1]) < 0:
        return False

    return True


if __name__ == "__main__":
    for line in sys.stdin:
        if count == 10:
            print_stats()
            count = 1
        else:
            count += 1

        split = line.split()
        if not is_formatted(split):
            continue

        file_size += int(split[-1])
        status[split[-2]] += 1

    print_stats()
