def rearrange(arr):
    n = len(arr)
    arr.sort()
    max_idx = n - 1
    min_idx = 0
    max_elem = arr[-1] + 1

    for i in range(n):
        if i % 2 == 0:
            arr[i] += (arr[max_idx] % max_elem) * max_elem
            max_idx -= 1
        else:
            arr[i] += (arr[min_idx] % max_elem) * max_elem
            min_idx += 1

    for i in range(n):
        arr[i] = arr[i] // max_elem

    return arr
