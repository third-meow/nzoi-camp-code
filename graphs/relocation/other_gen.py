from random import randint

node_n = 100
link_per_node = 1
with open('data', 'w') as f:
    f.write(f'{node_n} {node_n*link_per_node} 4\n')
    f.write('1\n2\n3\n4\n')
    for i in range(1, node_n):
        dest = i + 1
        f.write(f'{i} {dest} {randint(2,10)}\n')
