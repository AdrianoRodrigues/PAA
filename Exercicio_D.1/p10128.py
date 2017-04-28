import sys

solutions = []

def verify_big(v, n, p, r):
    pos = p-1
    if n in v and (v.index(n) < p-1 or v.index(n) > n - r) :
        print('n in v: {}; v.index(n) < p-1: {}; v.index(n) > n - r: {}'.format(n in v, v.index(n) < p-1, v.index(n) < n - r))
        print('index: {}, v: {}'.format( v.index(n), v))
        return False
    
    return True

def get_bigger_pos(v, n, p, r):
    pos = [p-1]
    if p == r:
        pos.append(n - r)
    elif p > r:
        pos = [n - r]

    return pos

def verify_bigger(v, n, p, r):
    pos = [p-1]
    if p == r:
        pos.append(n - r)
    elif p > r:
        pos = [n - r]

    #print(pos)

    for i in pos:
        #print(str(i) + "=>" + str(v))
        #print('for')
        if v[i] != n:
            #print('\tv[{}] = {} != {} => {}'.format(i, v[i], n, v))
            return False
    
    #print('verify_bigger return true')
    return True

def verify(v, n, p, r):
    #print(v)
    views_p = 1
    bigger = v[0]
    for i in range(1, n):
        if v[i] > bigger:
            views_p += 1
            if views_p > p:
                #print('\tvp = {} > p = {}'.format(views_p, p))
                return False
            bigger = v[i]

    views_r = 1
    bigger = v[n-1]
    for i in range(n-2, -1, -1):
        if v[i] > bigger:
            views_r += 1
            if views_r > r:
                #print('\tvr = {} > r = {}'.format(views_r, r))
                return False
            bigger = v[i]

    if views_p != p or views_r != r:
        return False

    #print(v)
    #print('\tviews_p = {}; views_r = {}'.format(views_p, views_r))

    return True

def permutation(v, n, p, r, index, s):
    global solutions
    #print('permutation index = ' + str(index))
    if index == n:
        if verify(v, n, p, r):
            solutions.append(v[:])
        return
    
    for i in range(0, n):        
        if not s[i]:
            v[index] = i + 1
            bigger_in_position = True
            #if v[i] == n and p != r and not verify_bigger(v, n, p, r):
            #    bigger_in_position = False
            #print(v)
            #if v[index] == n and n not in get_bigger_pos(v, n, p, r): 
                #verify_big(v, n, p, r):
            #    bigger_in_position = False
                #pass
                #print('big: ', v)

            if bigger_in_position:
                s[i] = True
                permutation(v, n, p, r, index + 1, s)    
                s[i] = False    

infile = sys.stdin
nbr_dataset = int(infile.readline().strip())

for i in range(nbr_dataset):
    solutions = []
    line = [int(i) for i in infile.readline().strip().split()]    
    N = line[0]
    P = line[1]
    R = line[2]
    V = [0] * N        
    S = [False] * N    
    
    permutation(V, N, P, R, 0, S)

    print('{} Case: {} {} {}'.format(len(solutions), N, P, R))
    count = 1
    for sol in solutions:
        print('    {}: {}'.format(count, sol))
        count+=1