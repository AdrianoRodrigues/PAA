import sys

solutions = []
def permutation(n, index, v, mset):
    global solutions
    if index == n:
        solutions.append(v[:])
        return

    v[index] = 0
    for i in range(0, n):
        if not mset[i]:
            v[index] = i+1
            intoDiagonal = False
            for j in range(1, index+1):
                if v[index-j] + j == v[index] or v[index-j] - j == v[index]:
                    intoDiagonal = True
                    break
            if not intoDiagonal:
                mset[i] = True
                permutation(n, index + 1, v, mset)
                mset[i] = False

def queen(N):
    permutation(N, 0, [0] * N, [False] * N)

queen(8)

infile = sys.stdin

case_nbr = 1
for line in infile:
    if line.strip():
        a = [int(i) for i in line.split()]
        sol = [0] * 8
        best = 0
        for s in solutions:
            temp = [0] * 8
            for i in range(len(a)):
                if s[i] == a[i]:
                    temp[i] = 1
            if sum(temp) > best:
                sol_s = s[:]
                best = sum(temp)
        print('Case {}: {}'.format(case_nbr, 8 - best))
        case_nbr += 1

#print('a = ' + str(a))
#print('sol = ' + str(sol_s))
#print('best = ' + str(best))
#print('case = ' + str(8 - best))