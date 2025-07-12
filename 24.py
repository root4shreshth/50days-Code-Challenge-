def get_perm(n, k):
    factorials = [1] * (n + 1)           # factorials up to n
    for i in range(1, n + 1):
        factorials[i] = factorials[i - 1] * i 
    if k < 1 or k > factorials[n]:
        return ""
    k -= 1
    num = list(range(1, n + 1))              # initialize the list of num
    result = []
    for i in range(n, 0, -1):  
        index = k // factorials[i - 1]      
        result.append(str(num[index]))        
        num.pop(index)       
        k %= factorials[i - 1]   
    return ''.join(result)

# read inputs for n and k
n = int(input(""))
k = int(input(""))
           
result = get_perm(n, k)             # geting the result
print(result)                        # print the result