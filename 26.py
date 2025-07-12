def rotate(matrix):
    n = len(matrix)
    # Step 1: Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    # Step 2: Reverse each row
    for i in range(n):
        matrix[i].reverse()

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    index = 1
    matrix = []
    for _ in range(n):
        row = list(map(int, data[index:index + n]))
        matrix.append(row)
        index += n
    
    # Verify matrix is square
    if len(matrix) != n or any(len(row) != n for row in matrix):
        print("Error: Matrix must be square (n x n).")
        return
    
    rotate(matrix)
    
    # Print the rotated matrix
    for row in matrix:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()