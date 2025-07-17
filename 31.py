import ast
def merge_intervals(x):
    if not x:
        return []
    x.sort(key=lambda a: a[0])
    i = 0
    for j in range(1, len(x)):
        if x[j][0] <= x[i][1]:
            x[i][1] = max(x[i][1], x[j][1])
        else:
            i += 1
            x[i] = x[j]
    return x[:i+1]
# input
x = ast.literal_eval(input().strip())
# merge
merged = merge_intervals(x)
# outputt
output = '[' + ','.join(f'[{a},{b}]' for a, b in merged) + ']'
print(output)
