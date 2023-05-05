#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics
"""
import sys


nb_line_read = 0
total_size = 0
status_code_line = 0
status_code_dict = {200: 0, 301: 0, 400: 0, 401: 0,
                    403: 0, 404: 0, 405: 0, 500: 0}

try:
    for line in sys.stdin:
        nb_line_read += 1

        try:
            splited_line = line.split()
            # get sum of size
            size_line = int(splited_line[-1])
            total_size += size_line

            # get status code
            status_code_line = int(splited_line[-2])

            if status_code_line not in status_code_dict.keys():
                pass
            for status_code in sorted(status_code_dict):
                if status_code_line == status_code:
                    status_code_dict[status_code_line] += 1

        except ValueError:
            pass

        if nb_line_read % 10 == 0:
            print("File size: {}".format(total_size))
            for status_code in sorted(status_code_dict):
                if status_code_dict[status_code] != 0:
                    print("{}: {}".format(status_code,
                                          status_code_dict[status_code]))

except KeyboardInterrupt:
    pass

print("File size: {}".format(total_size))
for status_code in sorted(status_code_dict):
    if status_code_dict[status_code] != 0:
        print("{}: {}".format(status_code,
                              status_code_dict[status_code]))