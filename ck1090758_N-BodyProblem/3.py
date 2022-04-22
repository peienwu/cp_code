from vpython import *
#GlowScript 3.1 VPython

"""
    1. 參數設定，設定變數及定義萬有引力公式
"""

G = 6.67430 ; m = 1 ; R = 10 ; t = 0 ; dt = 0.001
L = R*(3)**0.5
v0 = (G*m/L)**0.5

def Fg(x):
    return G*m**2/(x**2)
 
scene = canvas(width=1000, height=500, center=vec(0,0,0),background=color.white,range=2*R)
                
ball_m1 = sphere(pos=vec(0,R,0), radius=0.5, color = color.yellow, make_trail=True)
ball_m2 = sphere(pos=vec(R*cos(pi/6),-R*sin(pi/6),0), radius=0.5, color = color.red, make_trail=True)#pi/6 = 30 
ball_m3 = sphere(pos=vec(-R*cos(pi/6),-R*sin(pi/6),0), radius=0.5, color = color.blue, make_trail=True)

ball_m1_v = vec(-v0,0,0)  
ball_m2_v = vec(v0*cos(pi/3),v0*sin(pi/3),0)
ball_m3_v = vec(v0*cos(pi/3),-v0*sin(pi/3),0)

F1_arrow = arrow(pos=ball_m1.pos,axis=vec(0,0,0),shaftwidth=0.1 ,color = color.black)
F13_arrow = arrow(pos=ball_m1.pos,axis=vec(0,0,0),shaftwidth=0.1 ,color = color.blue)
F12_arrow = arrow(pos=ball_m1.pos,axis=vec(0,0,0),shaftwidth=0.1 ,color = color.red)
v1_arrow = arrow(pos=ball_m1.pos,axis=vec(0,0,0),shaftwidth=0.1 ,color = color.yellow)

while True:
    rate(10000)
    
    dist_12 = mag(ball_m2.pos - ball_m1.pos)
    radiavector_12 = norm(ball_m2.pos-ball_m1.pos)
    Fg_vector_12 = Fg(dist_12)*radiavector_12
    
    dist_23 = mag(ball_m3.pos - ball_m2.pos)
    radiavector_23 = norm(ball_m3.pos-ball_m2.pos)
    Fg_vector_23 = Fg(dist_23)*radiavector_23
    
    dist_13 = mag(ball_m3.pos - ball_m1.pos)
    radiavector_13 = norm(ball_m3.pos-ball_m1.pos)
    Fg_vector_13 = Fg(dist_13)*radiavector_13
    
    ball_m1_v += (Fg_vector_13 + Fg_vector_12)/m*dt
    ball_m1.pos += ball_m1_v*dt
    
    ball_m2_v += (Fg_vector_23 - Fg_vector_12)/m*dt
    ball_m2.pos += ball_m2_v*dt
    
    ball_m3_v += (-Fg_vector_13 - Fg_vector_23)/m*dt
    ball_m3.pos += ball_m3_v*dt
    
    F1_arrow.pos = ball_m1.pos
    F1_arrow.axis = (Fg_vector_13 + Fg_vector_12)*100

    F13_arrow.pos = ball_m1.pos
    F13_arrow.axis = (Fg_vector_13)*100

    F12_arrow.pos = ball_m1.pos
    F12_arrow.axis = (Fg_vector_12)*100

    v1_arrow.pos = ball_m1.pos
    v1_arrow.axis = ball_m1_v*8
    
  
    t = t+dt