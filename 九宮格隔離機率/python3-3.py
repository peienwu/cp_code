from cProfile import label
import matplotlib.pyplot as plt

x = []
y = [0, 0, 0, 79, 1315, 10071, 46491, 144369, 322245, 541848, 709954, 741982,
     627844, 433574, 244784, 112468, 41556, 12084, 2667, 420, 42, 2, 0, 0, 0]
y2 = []
up = 50


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
            size=5
        )


for i in range(1, 26):
    x.append(i)

B = plt.bar(x, y, color='y', label='Cases', align='center')

createLabels(B, up)

plt.xlabel('Number of Diagnoses')
plt.ylabel('Cases')
plt.xlim(0, 26)
plt.ylim(0, 790000)
plt.xticks(range(0, 26, 1))

plt.legend(loc='upper left')
plt.grid(True)

figure = plt.gcf()
figure.set_size_inches(10, 6)
#plt.savefig("Bar chart3.png", dpi=200)
plt.savefig("25people.png", dpi=1000)
plt.show()
