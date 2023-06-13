#!/usr/bin/python3
"""
module containing function validUTF8
"""


def validUTF8(data):
    """
    function that determines if a given data set
        represents a valid UTF-8 encoding
    Args:
        data: data set represented by a list of integers
    Return: True if data is a valid UTF-8 encoding, else return False
    10001100 : 1st digit = 0, 2nd digit = 0, ...
    """
    i = 0
    while i < len(data):
        # print("{0:b}".format(data[i]))
        # print("{0:b}".format(data[i] >> 4))
        # print("{0:b}".format((data[i] >> 4) & 15))
        if data[i] < 0:
            return False

        # digit 5 to 8: 0000 to 1011
        if 0 <= ((data[i] >> 4) & 15) <= 11:
            i += 1

        # digit 5 to 8: 1100 to 1101
        elif 12 <= ((data[i] >> 4) & 15) <= 13:
            if i + 1 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191:
                    i += 2
                else:
                    return False
            else:
                return False

        # digit 5 to 8: 1110
        elif ((data[i] >> 4) & 15) == 14:
            if i + 2 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191 and 128 <= data[i + 2] <= 191:
                    i += 3
                else:
                    return False
            else:
                return False

        # digit 5 to 8: 1111
        elif ((data[i] >> 3) & 31) == 30:
            if i + 3 < len(data):
                # 1000 0000 to 1011 1111
                if 128 <= data[i + 1] <= 191 and \
                    128 <= data[i + 2] <= 191 and \
                        128 <= data[i + 3] <= 191:
                    i += 4
                else:
                    return False
            else:
                return False

        else:
            return False

    return True
