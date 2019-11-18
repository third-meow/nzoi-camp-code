from random import randint

node_n = 1000
link_per_node = 5
with open('data', 'w') as f:
    f.write(f'{node_n} {node_n*link_per_node} 4\n')
    f.write('1\n2\n3\n4\n')
    for i in range(1, node_n+1):
        for m in range(0, link_per_node + randint(-2, 2)):
            dest = i
            while dest == i:
                dest = randint(1, node_n)
            f.write(f'{i} {dest} {randint(2,10)}\n')
