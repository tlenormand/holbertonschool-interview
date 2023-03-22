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
    opened_boxes = [0]

    for index, box in enumerate(boxes):
        for key in box:
            if key < number_of_boxes and key not in opened_boxes and key != index:
                opened_boxes.append(key)

        if len(opened_boxes) == number_of_boxes:
            return True

    return False
