from cProfile import label
import matplotlib.pyplot as plt

x = []
y = [1, 10, 48, 106, 122, 84, 36, 9, 1]
y2 = []
up = 1
down = -5


def createLabels(data, beff, flag):
    k = -1
    f = 0
    for item in data:
        k += 1
        if flag and (y[k] == 0 or y[k] == y2[k]):
            continue
        height = item.get_height()
        plt.text(
            item.get_x()+item.get_width()/2.,
            height+beff,
            '%d' % int(height),
            ha="center",
            va="bottom",
            size=15
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


for i in range(1, 10):
    x.append(i)
    y2.append(Comb(9, i))

width = 0.3

A = plt.bar(x, y2, color='gray', label='Combinations',
            align='center', width=0.8)
B = plt.bar(x, y, color='red', label='Cases', align='center', width=0.8)

createLabels(A, up, 0)
createLabels(B, down, 1)

plt.xlabel('Number of Diagnoses')
plt.ylabel('Cases')
plt.xlim(0, 10)
plt.xticks(range(0, 10, 1))

plt.legend(loc='upper left')
plt.grid(True)


figure = plt.gcf()
figure.set_size_inches(15, 10)
#plt.savefig("Bar chart.png", dpi=200)
plt.savefig("9people.png", dpi=1000)
plt.show()
