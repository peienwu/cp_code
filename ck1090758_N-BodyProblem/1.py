from vpython import *
#GlowScript 2.7 VPython

G = 6.67
m1 = 2.0
m2 = 2.0
m3 = 2.0
L = 6.0 
R = L*cos(pi/6)*2/3
v0 =0.6* (G*m1/L)**0.5

def Fg(x): 
    return -G*m1*m2/(x**2)
 
scene = canvas(width=800, height=500, center=vec(0,0,0),background=color.white,range=1.2*R)

ball_m1 = sphere(pos=vec(0,R,0), radius=0.2, color = color.black, make_trail=True)
ball_m2 = sphere(pos=vec(R*cos(pi/6),-R*sin(pi/6),0), radius=0.2, color = color.red, make_trail=True)
ball_m3 = sphere(pos=vec(-R*cos(pi/6),-R*sin(pi/6),0), radius=0.2, color = color.blue, make_trail=True)

ball_m1_v = vector(-v0,0,0)  
ball_m2_v = vector(v0*cos(pi/3),v0*sin(pi/3),0)
ball_m3_v = vector(v0*cos(pi/3),-v0*sin(pi/3),0)


t = 0
dt = 0.0001


while True:
    rate(1/dt)

    dist_12 = mag(ball_m1.pos - ball_m2.pos)
    radiavector_12 = (ball_m1.pos-ball_m2.pos)/dist_12
    Fg_vector_12 = Fg(dist_12)*radiavector_12

    dist_23 = mag(ball_m2.pos - ball_m3.pos)
    radiavector_23 = (ball_m2.pos-ball_m3.pos)/dist_23
    Fg_vector_23 = Fg(dist_23)*radiavector_23

    dist_31 = mag(ball_m3.pos - ball_m1.pos)
    radiavector_31 = (ball_m3.pos-ball_m1.pos)/dist_31
    Fg_vector_31 = Fg(dist_31)*radiavector_31

    ball_m1_v += (-Fg_vector_31+Fg_vector_12)/m1*dt
    ball_m1.pos = ball_m1.pos + ball_m1_v*dt
    
    ball_m2_v += (-Fg_vector_12+Fg_vector_23)/m2*dt
    ball_m2.pos = ball_m2.pos + ball_m2_v*dt
    
    ball_m3_v += (-Fg_vector_23+Fg_vector_31)/m3*dt
    ball_m3.pos = ball_m3.pos + ball_m3_v*dt
 

 
    t = t+dt
