from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R


class Bertrand_Paradox2(Scene):

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
            theta = 2 * PI * random.uniform(0, 1)

            p = Point(location=[R * math.cos(theta) - 3,
                                R * math.sin(theta), 0], color=BLUE).scale(10)
            L = Line(c.get_center(), p.location, color=RED).set_opacity(0.5)

            posx = random.uniform(0, 1)*R
            print(posx / R)
            posy = math.sqrt(R**2 - posx**2)
            p_mid = Point(location=[posx-3, 0, 0], color=RED).scale(
                50).rotate(theta, about_point=c.get_center())

            line = Line([posx-3, posy, 0], [posx-3, -posy, 0], color=WHITE)
            line.rotate(theta, about_point=c.get_center())

            if posx > 0.5 * R:
                num_1 += 1
                line.set_color(YELLOW)
            else:
                num_2 += 1
                line.set_color(GREEN)
            tmp = format(num_1 / (num_1 + num_2), '.3f')
            v = MathTex(r"P = \frac{" + str(num_1) +
                        "}{" + str(num_1) + "+" + str(num_2) + "} = "+str((tmp))+"").shift(3 * RIGHT)

            self.add(p, L, line, p_mid, v)
            self.wait(step)
            line.set_opacity(0.15).set_color(WHITE)
            self.remove(p, L, p_mid, v)
