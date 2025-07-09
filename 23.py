def find_first(num, target):
    left, right = 0, len(num) - 1
    first = -1
    while left <= right:
        mid = left + (right - left) // 2  # finding first no. 
        if num[mid] >= target:
            right = mid - 1
            if num[mid] == target:
                first = mid
        else:
            left = mid + 1
    return first

def find_last(num, target):
    left, right = 0, len(num) - 1
    last = -1
    while left <= right:
        mid = left + (right - left) // 2           # finding last no.
        
        if num[mid] <= target:                   
            left = mid + 1
            if num[mid] == target:
                last = mid
        else:
            right = mid - 1
    return last

def search_range(num, target):
    first = find_first(num, target)
    last = find_last(num, target)
    return [first, last]


n = int(input())                            # reading the input
num = list(map(int, input().split()))
target = int(input())


result = search_range(num, target)       # geting the result


print(result[0], result[1])                # printing the result