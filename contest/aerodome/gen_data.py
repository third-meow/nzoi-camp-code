from random import randint

#ppl = 300000
#desks = 100000

ppl = 30
desks = 1000
with open('data', 'w') as f:
    f.write(f'{desks} {ppl}\n')
    for i in range(desks):
        f.write(f'{randint(1, (10e9 - 1))}\n')
