from vpython import *
#GlowScript 3.1 VPython

G = 6.67
m1 = 1
m2 = 5
t = 0 ; dt = 0.00001

def Fg(a,b,x): #定義萬有引力函數
    return -G*a*b/(x**2)

d = 3
r1 = m2 / (m1+m2)*d
r2 = m1 / (m1+m2)*d
v_m1 = m2 * (G/(d*(m1+m2)))**0.5/2
v_m2 = m1 * (G/(d*(m1+m2)))**0.5/2

alpha = m2 / (m1+m2)

scene = canvas(align = 'left',width=620, height=500, center=vec(0,0,0),background=color.white)

ball_m1 = sphere(pos=vector(-r1,0,0), radius=0.1*m1, color = color.yellow, make_trail=True)
ball_m2 = sphere(pos=vector(r2,0,0), radius=0.2, color = color.red, make_trail=True)

ball_mass = sphere(pos=((m1*ball_m1.pos)+(m2*ball_m2.pos))/(m1+m2), radius=0.1, color = color.black, make_trail=True)
ball_m1_v = vec(0,-v_m1,0)
ball_m2_v = vec(0,v_m2,0)

gd = graph(align = 'right',width=500,height=500,title='K1+K2+U=E', xtitle='t', ytitle='E,U,K1,K2',foreground=color.black,background=color.white)
K1_curve = gcurve(color=color.yellow)
K2_curve = gcurve(color=color.red) 
U_curve = gcurve(color=color.green)
E_curve = gcurve(color=color.black)

print(f"m1 &= {m1:.4f}\\\\")
print(f"m2 &= {m2:.4f}\\\\")
print(f"v1 &= {v_m1:.4f}\\\\")
print(f"v2 &= {v_m2:.4f}\\\\")


while True:
    rate(1/dt)
    dist = mag(ball_m1.pos-ball_m2.pos)#純量
    radiavector = norm(ball_m2.pos-ball_m1.pos)#單位向量
    Fg_vector = Fg(m1,m2,dist)*radiavector 
    
    ball_m2_v += Fg_vector/m2*dt
    ball_m2.pos = ball_m2.pos + ball_m2_v*dt

    ball_m1_v += -Fg_vector/m1*dt
    ball_m1.pos = ball_m1.pos + ball_m1_v*dt
    
    ball_mass.pos = ((m1*ball_m1.pos)+(m2*ball_m2.pos))/(m1+m2)
    
    K1_val = 0.5*(m1*mag(ball_m1_v)**2)
    K2_val = 0.5*(m2*mag(ball_m2_v)**2)
    U_val = -(G*m1*m2)/abs(dist)
    E_val = K1_val+K2_val+U_val
    
    K1_curve.plot(pos=(t,K1_val))
    K2_curve.plot(pos=(t,K2_val))
    U_curve.plot(pos=(t,U_val))
    E_curve.plot(pos=(t,E_val))
    
    t = t+dt
    