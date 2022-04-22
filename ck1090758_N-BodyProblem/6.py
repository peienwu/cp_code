from vpython import *
#GlowScript 3.0 VPython
G = 6.67
M = 10
m = 1
Re = 0.1
H = 5
t = 0
dt = 0.0001
pre_mater_pos = vector(0,0,0)

def Fg(x):                                 #定義公式
    return -G*M*m/(x**2)

k = float(input("k = "))
if k > 1:
    Re *= 5
V0 = k*(G*M/H)**0.5

p = (k**2)*H
a = H/(2-k**2)
b = sqrt(a*p)
c = sqrt(a**2-b**2)


"""
    2. 畫面設定
"""
scene = canvas(align = 'left', background = color.white, width=630, height=500,center = vec(0,0,0),range = H) #設定視窗
earth = sphere(pos=vec(0,0,0), radius=1.5*Re,color = color.black)
mater = sphere(pos=vec(H,0,0), radius=Re,color=color.red, make_trail=True)
focus1 = sphere(pos=vec(H-a-c,0,0), radius=0.05*Re,color = color.red)
focus2 = sphere(pos=vec(H-a+c,0,0), radius=0.05*Re,color = color.red)
materv = vec(0,V0,0) #衛星速率=0
T_one = abs(2*pi*a*b/(H*V0))

print(f"a = {a:.4f}")
print(f"b = {b:.4f}")
print(f"c = {c:.4f}")
print(f"T = {T_one:.4f}")

"""利用curve畫橢圓 (2. 畫面設定)"""
oval = curve(color = color.black)
for N in range(0, 360, 1):
    oval.append(pos =vec((H-a)+a*cos(N*pi/180),b*sin(N*pi/180),0))
""" Fg_x圖(2. 畫面設定)"""
gd = graph(align='right',width=500,height=500,
              title='K+U=E', xtitle='t', ytitle='E(red) , K(black) , U(green)',
              foreground=color.black,background=color.white)
K_curve = gcurve(color=color.black)
U_curve = gcurve(color=color.green) 
E_curve = gcurve(color=color.red)


Fe = G*M*m/Re**2 #定義地球表面重力強度

"""
    3. 執行迴圈
"""

while True:  #執行迴圈

    rate(1/dt)
    
    t = t+dt
    pre_pre_mater_pos = pre_mater_pos
    pre_mater_pos = vector(mater.pos.x , mater.pos.y, mater.pos.z)
   
    dist = mag(mater.pos-earth.pos)
    radiavector = (mater.pos-earth.pos)/dist #距離單位向量
    Fg_vector = Fg(dist)*radiavector # 萬有引力向量=萬有引力量值*單位向量
    
    materv += Fg_vector/m*dt   #Δv = F/m *dt
    mater.pos = mater.pos + materv*dt  # S = S0 + v *dt

    
    U_val = -G*M*m/dist
    K_val = (m*mag(materv)**2)/2
    E_val = U_val+K_val
    
    U_curve.plot(pos=(t,U_val))
    K_curve.plot(pos=(t,K_val))
    E_curve.plot(pos=(t,E_val))
    


    
    