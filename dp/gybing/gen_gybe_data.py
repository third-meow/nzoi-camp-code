import random

l = 5
w = 4

def gen():
    with open('data_from_gen.txt', 'w') as f:
        f.write(f'{w} {l}\n')
        for i in range(l):
            for j in range(w):
                f.write(str(random.randint(0, 10)))
                f.write(" ")
            f.write("\n")

if __name__ == '__main__':
    gen()


