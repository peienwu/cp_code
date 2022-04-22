from vpython import *
#GlowScript 3.1 VPython

import random

G = 6.67430
m = 1
t = 0
n = 50
dt = 0.001
size = 0.1
w = 10

def Fg(x):
    return G*m**2/(x**2)

scene = canvas(align = 'left',width=650, height=500,center=vec(w/2,w/2,0),range = 0.75*w,background=color.black)
ball = []


for i in range(n):
    pos_rad = vec(random.random()*w,random.random()*w,0)
#    pos_spd = vec(random.random()*10,random.random()*10,random.random()*10)
    pos_spd = vec(0,0,0)
    ball.append(sphere(pos=pos_rad, v=pos_spd, radius=size, color=color.white,make_trail=True,retain=100,trail_radius = 0.01))


gd = graph(align = 'right',width=450,height=500,
              title='K+U=E', xtitle='t', ytitle='E(red) , K(black) , U(green)',
              foreground=color.black,background=color.white)
              
K_curve = gcurve(graph = gd,color=color.black)
U_curve = gcurve(graph = gd,color=color.green)
E_curve = gcurve(graph = gd,color=color.red)

while True:
    rate(500)
    
    EK = 0
    PK = 0
    for i in range(0,n):
        for j in range(0,n):
            if i==j:
                continue
            dist = mag(ball[i].pos - ball[j].pos)
            radiavector = norm(ball[j].pos - ball[i].pos)
            if dist > size:
                Fg_vector = Fg(dist) * radiavector
                ball[i].v += (Fg_vector)/m*dt
                PK += mag(Fg_vector)*dist
            
    for i in range(0,n):
        ball[i].pos += ball[i].v*dt
        EK += 0.5*m*(mag(ball[i].v)**2)
    
#    mag(Fg_vector_23)*dist_23+mag(Fg_vector_24)*dist_24+mag(Fg_vector_34)*dist_34)

    PK *= -0.5
    U_curve.plot(pos=(t,PK))
    K_curve.plot(pos=(t,EK))
    E_curve.plot(pos=(t,EK+PK))
    
    
    t = t+dt
    
    