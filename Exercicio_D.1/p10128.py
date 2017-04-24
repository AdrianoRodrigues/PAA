import itertools

a = range(1, 5)

solutions = list(itertools.permutations(range(13)))

counter = 1
for sol in solutions:
    print(str(counter) + ': ' + str(sol))
    counter+=1

def permutation(n, p, r, index):
    if index == n:
        print('terminou')
    