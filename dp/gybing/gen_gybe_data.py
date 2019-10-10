import random

l = 250000
w = 3

with open('data_from_gen.txt', 'w') as f:
    f.write(f'{w} {l}\n')
    for i in range(l):
        for j in range(w):
            f.write(str(random.randint(0, 100)))
            f.write(" ")
        f.write("\n")


