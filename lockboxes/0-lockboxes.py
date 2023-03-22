#!/usr/bin/python3
"""
    Functions:
        add_arrays: function that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """ function that determines if all the boxes can be opened

    Arguments:
        boxes: list of lists

    Returns:
        True if all boxes can be opened, else return False
    """
    number_of_boxes = len(boxes)
    key_list = {"box0": [0]}

    for i in range(number_of_boxes):
        index = "box" + str(i)
        for j in range(number_of_boxes):
            if j == i:
                continue

            if index in key_list:
                key_list[index] = key_list[index] + boxes[j]
            else:
                key_list[index] = boxes[j]

        if i not in key_list[index]:
            return False

    return True
