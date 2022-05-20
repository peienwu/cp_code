from cProfile import label
import matplotlib.pyplot as plt

x = []
y = [0, 0, 0, 256, 1024, 1984, 2400, 1984, 1160, 480, 136, 24, 2, 0, 0, 0]
y2 = []
up = 10


def createLabels(data, beff):
    k = -1
    for item in data:
        k += 1
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
            size=10
        )


for i in range(1, 17):
    x.append(i)

B = plt.bar(x, y, color='y', label='Cases', align='center')

createLabels(B, up)

plt.xlabel('Number of Diagnoses')
plt.ylabel('Cases')
plt.xlim(0, 17)
plt.ylim(0, 2500)
plt.xticks(range(0, 17, 1))

plt.legend(loc='upper left')
plt.grid(True)

figure = plt.gcf()
figure.set_size_inches(10, 6)
#plt.savefig("Bar chart3.png", dpi=200)
plt.savefig("16people.png", dpi=1000)
plt.show()
