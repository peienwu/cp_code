from cProfile import label
import matplotlib.pyplot as plt

x = []
y = [0, 0, 0, 79, 1593, 14672, 81524, 307244, 842506, 1764068, 2918828, 3909834, 4311034,
     3955232, 3038092, 1957940, 1056965, 475304, 176256, 53046, 12646, 2300, 300, 25, 1]
y2 = []


def Comb(n, m):
    m = min(m, n-m)
    ans = 1
    for i in range(m):
        ans *= (n-i)
    for i in range(m):
        ans /= (i+1)
    return ans


for i in range(1, 26):
    x.append(i)
    y2.append(float(y[i-1]) / Comb(25, i))

width = 0.3

A = plt.plot(x, y2, 'o-', color='red', label='Possibility of Quarantine')

plt.legend(loc='upper left')
plt.grid(True)

plt.xlabel('Number of Diagnoses')
plt.ylabel('P')

figure = plt.gcf()
figure.set_size_inches(10, 5)
#plt.savefig("Bar chart2.png", dpi=100)
plt.savefig("25people-2.png", dpi=1000)
plt.show()
