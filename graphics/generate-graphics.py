import matplotlib.pyplot as plt

FILE_NAME = 'data.in'
FIGURE_OUTPUT = 'graphic.png'

x = []
y = []

with open(FILE_NAME) as file:
    for line in file:
        row = list(map(int, line.strip().split(' ')))
        n = row[0]
        average = (sum(row) - n) / (len(row) - 1)
        x += [n]
        y += [average]

plt.plot(x, y, color = 'blue')
plt.xlabel('n: number of points')
plt.ylabel('t (ms): time')
plt.legend(['KNN'])
plt.savefig(FIGURE_OUTPUT)
