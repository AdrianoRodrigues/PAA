import sys

#counter = 1
solutions = []
def permutation(n, index, v, mset):
    #global counter
    global solutions
    #print('index = ' + str(index+1)) 
    #print(v)
    if index == n:
        solutions.append(v[:])
        #line = ''
        #for i in range(0, n):
        #    line = line + ' ' + str(v[i])
        #print(str(counter) + ' = ' + line)
        #print(solutions)
        #counter += 1
        return

    v[index] = 0
    for i in range(0, n):
        #print('i = ' + str(i+1))
        if not mset[i]:
            v[index] = i+1
            intoDiagonal = False
            for j in range(1, index+1):
                #print('j = ' + str(j+1))
                #print('v['+str(index-j)+']+' + str(j) + ' = ' + str(v[index-j] + j) + '; v[' + str(index) + '] = ' + str(v[index]))
                if v[index-j] + j == v[index] or v[index-j] - j == v[index]:
                    intoDiagonal = True
                    break
            if not intoDiagonal:
                mset[i] = True
                #print('nova')
                permutation(n, index + 1, v, mset)
                mset[i] = False

def queen(N):
    permutation(N, 0, [0] * N, [False] * N)

queen(8)

infile = sys.stdin
d = int(infile.read(1))
next(infile) # skip first line of input file
#print(d)
     #if not line:
     #    break
     #fields = line.split('#')

#cnt = 1
#for i in range(d):
dataset = 0
for line in infile:
    if line.strip():
        print('SOLN       COLUMN')
        print(' #      1 2 3 4 5 6 7 8')
        param = [int(i) for i in line.split()]
        print('')
        count = 1
        for sol in solutions:
            if sol[param[1]-1] == param[0]:
                solstr = ''.join(str(i)+' ' for i in sol)
                solstr = solstr.strip()
                print('{:>2}      {}'.format(count, solstr))
                count += 1
        dataset += 1
        if dataset <= d:        
            print('\n')
            #print(param)
            #cnt += 1

#row = 1
#col = 1

#for sol in solutions:
#    if sol[col - 1] == row:
#        print(sol)