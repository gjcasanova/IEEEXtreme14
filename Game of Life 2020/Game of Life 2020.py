def get_neighbors(matrix, index_x, index_y):
    if index_y == 0:
        up = matrix[-1][index_x]
    else:
        up = matrix[index_y-1][index_x]

    if index_y == len(matrix)-1:
        down = matrix[0][index_x]
    else:
        down = matrix[index_y+1][index_x]

    if index_x == 0:
        left = matrix[index_y][len(matrix[0])-1]
    else:
        left = matrix[index_y][index_x-1]

    if index_x == len(matrix[0])-1:
        right = matrix[index_y][0]
    else:
        right = matrix[index_y][index_x+1]

    return [up, right, down, left]


def solve(matrix, generations, rule_a, rule_b):
    aux = [x[:] for x in matrix]
    for _ in range(generations):
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                neighbors = get_neighbors(matrix, j, i)
                alive_neighbors = neighbors.count('1')

                if matrix[i][j] == '0':
                    if rule_a[alive_neighbors] == '1':
                        aux[i][j] = '1'
                    else:
                        aux[i][j] = '0'

                elif matrix[i][j] == '1':
                    if rule_b[alive_neighbors] != '1':
                        aux[i][j] = '0'
                    else:
                        aux[i][j] = '1'

        matrix = [x[:] for x in aux]
    return matrix


def main():
    rule_a, rule_b = input().split(';')
    dim, generations = map(int, input().split())
    matrix = []
    for _ in range(dim):
        matrix.append(input().replace('', ' ').split())

    result = solve(matrix, generations, rule_a, rule_b)

    for row in result:
        print(''.join(row))


if __name__ == '__main__':
    main()
