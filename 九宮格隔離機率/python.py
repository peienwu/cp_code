from cProfile import label
import matplotlib.pyplot as plt

x = []
y = [0, 0, 0, 256, 1536, 4480, 8320, 10896,
     10560, 7744, 4320, 1816, 560, 120, 16, 1]
y2 = []
up = 20
down = -500


def createLabels(data, beff, flag):
    k = -1
    f = 0
    for item in data:
        k += 1
        if flag and (y[k] == 0 or y[k] == y2[k]):
            continue
        height = item.get_height()
        if height == 256:
            beff = up
            f = 1
        plt.text(
            item.get_x()+item.get_width()/2.,
            height+beff,
            '%d' % int(height),
            ha="center",
            va="bottom",
            size=8
        )
        if f == 1:
            beff = down
            f = 0


def Comb(n, m):
    m = min(m, n-m)
    ans = 1
    for i in range(m):
        ans *= (n-i)
    for i in range(m):
        ans /= (i+1)
    return ans


for i in range(1, 17):
    x.append(i)
    y2.append(Comb(16, i))

width = 0.3

A = plt.bar(x, y2, color='gray', label='Combinations', align='center')
B = plt.bar(x, y, color='red', label='Cases', align='center')

createLabels(A, up, 0)
createLabels(B, down, 1)

plt.xlabel('Number of Diagnoses')
plt.ylabel('Cases')
plt.xticks(range(0, 17, 1))

plt.legend(loc='upper left')
plt.grid(True)

figure = plt.gcf()
figure.set_size_inches(10, 6)
plt.savefig("Bar chart.png", dpi=1000)
#plt.savefig("16people.png", dpi=1000)
plt.show()
