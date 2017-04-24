import sys

solutions = []

def verify_bigger(v, n, p, r):
    pos = [p-1]
    if p == r:
        pos.append(n - r)
    elif p > r:
        pos = [n - r]

    for i in pos:
        print(str(i) + "=>" + str(v))
        if v[i] != n:
            return False
    
    return True

def verify(v, n, p, r):                
    views_p = 1
    bigger = v[0]
    for i in range(1, n):
        if v[i] > bigger:
            views_p += 1
            if views_p > p:
                return False
            bigger = v[i]

    views_r = 1
    bigger = v[n-1]
    for i in range(n-2, -1, -1):
        if v[i] > bigger:
            views_r += 1
            if views_r > r:
                return False
            bigger = v[i]

def permutation(v, n, p, r, index):
    print('permutation index = ' + str(index))
    if index == n - 1:
        if verify(v, n, p, r):
            solutions.append(v[:])
        return
    
    for i in range(0, index + 1):
        if i+1 not in v:            
            v[i] = index + 1
            if v[i] == n and not verify_bigger(v, n, p, r):
                break
        permutation(v, n, p, r, index + 1)    

infile = sys.stdin
nbr_dataset = int(infile.readline().strip())
print ('d = ' + str(nbr_dataset))
for i in range(nbr_dataset):    
    line = [int(i) for i in infile.readline().strip().split()]    
    N = line[0]
    P = line[1]
    R = line[2]
    V = [0] * N        
    permutation(V, N, P, R, 0)
    for sol in solutions:
        print(sol)