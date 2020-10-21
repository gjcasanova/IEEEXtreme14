import scipy
import numpy
import json

INF = float('inf')


def solve():
    pass


def main():
    # For create a matrix of zeros.
    dim_x, dim_y = 5, 5

    matrix = [[0 for _ in range(dim_x)] for __ in range(dim_y)]
    print(matrix)

    # For read data.
    number_of_cases = int(input())
    for _ in range(number_of_cases):
        a, b = map(int, input().split())
        print(a, b)

    print('Hello World!')


if __name__ == '__main__':
    main()
