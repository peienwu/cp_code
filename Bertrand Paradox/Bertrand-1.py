from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R


class Bertrand_Paradox(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        c = Circle(color=WHITE, radius=R).shift(3*LEFT)

        tri = Triangle().shift(3*LEFT).shift(UP/2)
        tri.height = 1.5*R
        tri.width = (T)

        self.add(c, tri)
        self.wait()

        num_1 = 0
        num_2 = 0

        tmp = 500
        step = 0.5

        for i in range(tmp):
            if i > 10:
                step = 0.07
            theta1 = 2 * PI * random.uniform(0, 1)
            theta2 = 2 * PI * random.uniform(0, 1)
            p1 = Point(location=[R * math.cos(theta1) - 3,
                       R * math.sin(theta1), 0], color=YELLOW).scale(50)
            p2 = Point(location=[R * math.cos(theta2) - 3,
                       R * math.sin(theta2), 0], color=YELLOW).scale(50)
            L = Line(p1.location, p2.location, color=WHITE)
            dis = math.sqrt(
                (p1.location[0]-p2.location[0])**2 + (p1.location[1]-p2.location[1])**2)
            if(dis > T):
                num_1 += 1
            else:
                num_2 += 1
            pos = format(num_1 / (num_1+num_2), '.3f')
            v = MathTex(r"P = \frac{" + str(num_1) +
                        "}{" + str(num_1) + "+" + str(num_2) + "} = "+str((pos))+"").shift(3 * RIGHT)
            self.add(p1, p2, L, v)
            self.wait(step)
            print(pos)

            L.set_opacity(0.15)
            self.remove(p1, p2, v)
