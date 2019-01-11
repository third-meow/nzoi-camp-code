import sys

l = []
for i in range(0, int(sys.argv[1])):
    l.append(f'f {i} {i+1}\n')

with open('data.txt', 'w') as f:
    f.write(f'{int(sys.argv[1]) + 1} 4')
    for line in l:
        f.write(line)
    f.write(f'q 0 {sys.argv[1]}')

