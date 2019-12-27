from random import randint
q = 100000
n = 5000

def iseven(a):
    return (a % 2 == 0)

def match_even(a, b):
    if iseven(a) == iseven(b):
        return 0
    else:
        return 1

with open('data', 'w') as f:
    f.write(f'{q}\n')
    for i in range(q):
        a = i % 5000
        b = int(a/2)
        f.write(f'{a} {b + match_even(a, b)}\n')
