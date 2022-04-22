from vpython import *
#GlowScript 3.1 VPython


G = 6.67430
m = 10
l = 1
L = sqrt(2)*l
R = l*(sqrt(3))/2
t = 0
dt = 0.00001
v0 = sqrt(3/2*G*m/L)

def Fg(x):
    return G*pow(m,2)/(pow(x,2))

scene = canvas(align = 'left',width=600, height=500,center=vec(0.5*l,0.5*l,0.5*l),range=2*l,background=color.black)
                
ball_m1 = sphere(pos=vec(0,0,0), radius=0.1, color = color.yellow, make_trail=True)
ball_m2 = sphere(pos=vec(l,l,0), radius=0.1, color = color.red, make_trail=True)
ball_m3 = sphere(pos=vec(0,l,l), radius=0.1, color = color.blue, make_trail=True)
ball_m4 = sphere(pos=vec(l,0,l), radius=0.1, color = color.green, make_trail=True)

center_mass = (ball_m1.pos+ball_m2.pos+ball_m3.pos+ball_m4.pos)/4
ball = sphere(pos=center_mass, radius=0.05, color = color.white, make_trail=True)

ball_m1_v = vec(v0*cos(pi/4*3),v0*sin(pi/4*3),0)  
ball_m2_v = vec(v0*cos(pi/4*7),v0*sin(pi/4*7),0)
ball_m3_v = vec(v0*cos(pi/4),v0*sin(pi/4),0)
ball_m4_v = vec(v0*cos(pi/4*5),v0*sin(pi/4*5),0)

gd = graph(align = 'right',width=500,height=220,
              title='K+U=E', xtitle='t', ytitle='E(red) , K(black) , U(green)',
              foreground=color.black,background=color.white)
              
K_curve = gcurve(graph = gd,color=color.black)
U_curve = gcurve(graph = gd,color=color.green)
E_curve = gcurve(graph = gd,color=color.red)

gd2 = graph(align = 'right',width=500,height=220,
              title='Distance', xtitle='t', ytitle='R,B,G',
              foreground=color.black,background=color.white)

R_cur = gcurve(graph = gd2,color=color.red)
B_cur = gcurve(graph = gd2,color=color.blue)
G_cur = gcurve(graph = gd2,color=color.green)
M_cur = gcurve(graph = gd2,color=color.black)

KE = 0
PE = 0

while True:
    rate(100000)
    
    dist_12 = mag(ball_m2.pos - ball_m1.pos)
    radiavector_12 = norm(ball_m2.pos - ball_m1.pos)
    Fg_vector_12 = Fg(dist_12) * radiavector_12
    
    dist_13 = mag(ball_m3.pos - ball_m1.pos)
    radiavector_13 = norm(ball_m3.pos-ball_m1.pos)
    Fg_vector_13 = Fg(dist_13)*radiavector_13
    
    dist_14 = mag(ball_m4.pos - ball_m1.pos)
    radiavector_14 = norm(ball_m4.pos-ball_m1.pos)
    Fg_vector_14 = Fg(dist_14)*radiavector_14
    
    dist_23 = mag(ball_m3.pos - ball_m2.pos)
    radiavector_23 = norm(ball_m3.pos-ball_m2.pos)
    Fg_vector_23 = Fg(dist_23)*radiavector_23
    
    dist_24 = mag(ball_m4.pos - ball_m2.pos)
    radiavector_24 = norm(ball_m4.pos-ball_m2.pos)
    Fg_vector_24 = Fg(dist_24)*radiavector_24
    
    dist_34 = mag(ball_m4.pos - ball_m3.pos)
    radiavector_34 = norm(ball_m4.pos-ball_m3.pos)
    Fg_vector_34 = Fg(dist_34)*radiavector_34
    
    ball_m1_v += (Fg_vector_13 + Fg_vector_12 + Fg_vector_14)/m*dt
    ball_m1.pos += ball_m1_v*dt
    
    ball_m2_v += (Fg_vector_23 - Fg_vector_12 + Fg_vector_24)/m*dt
    ball_m2.pos += ball_m2_v*dt
    
    ball_m3_v += (-Fg_vector_13 - Fg_vector_23 + Fg_vector_34)/m*dt
    ball_m3.pos += ball_m3_v*dt
    
    ball_m4_v += (-Fg_vector_14 - Fg_vector_24 - Fg_vector_34)/m*dt
    ball_m4.pos += ball_m4_v*dt
    
    ball.pos= (ball_m1.pos+ball_m2.pos+ball_m3.pos+ball_m4.pos)/4
    
    EK = 0.5*m*(mag(ball_m1_v)**2+mag(ball_m2_v)**2+mag(ball_m3_v)**2+mag(ball_m4_v)**2)
    PK = -(mag(Fg_vector_12)*dist_12+mag(Fg_vector_13)*dist_13+mag(Fg_vector_14)*dist_14+\
    mag(Fg_vector_23)*dist_23+mag(Fg_vector_24)*dist_24+mag(Fg_vector_34)*dist_34)
    
    U_curve.plot(pos=(t,PK))
    K_curve.plot(pos=(t,EK))
    E_curve.plot(pos=(t,EK+PK))
    
    R_cur.plot(pos=(t,dist_12))
    B_cur.plot(pos=(t,dist_13))
    G_cur.plot(pos=(t,dist_14))
    M_cur.plot(pos=(t,mag(ball_m1.pos-ball.pos)))
    
    t = t+dt
    
    