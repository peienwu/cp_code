import numpy as np
import math
import random
import matplotlib.pyplot as plt

x = []
y = []

R = 1

def randPoint1():
    theta1 = 2.0 * math.pi * random.uniform(0, 1)
    theta2 = 2.0 * math.pi * random.uniform(0, 1)
    x1 = math.cos(theta1)
    x2 = math.cos(theta2)
    y1 = math.sin(theta1)
    y2 = math.sin(theta2)
    
    ans = [(x1 + x2)/2,(y1+y2)/2]
    return ans;

def randPoint2():
    theta = 2.0 * math.pi * random.uniform(0, 1)
    pos = random.uniform(0,1)
    x = math.cos(theta)*pos
    y = math.sin(theta)*pos
    ans = [x,y]
    return ans;

def randPoint3():
    while(True):
        x = R * random.uniform(-1, 1)
        y = R * random.uniform(-1, 1)
        if(x*x + y*y <= R * R):
            return [x,y];

    

for i in range(360):
    theta = i / 180 * math.pi
    x.append(R * math.cos(theta));
    y.append(R * math.sin(theta));
    
xdot = []
ydot = []

for i in range(1000000):
    p = randPoint3();
    xdot.append(p[0]);
    ydot.append(p[1]);



plt.figure(figsize=(6,6))
plt.plot(x,y,markersize = 1,color = 'red')
plt.plot(xdot,ydot,'.',markersize = 0.01,color = 'blue')
plt.show()
