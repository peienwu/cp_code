from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R


class Bertrand_Paradox3(Scene):

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

            x = y = R
            while(x * x + y * y > R*R):
                x = random.uniform(-R, R)
                y = random.uniform(-R, R)

            p = Dot(point=[x-3, y, 0], color=RED, radius=0.1)

            np = x * x + y * y
            posx = math.sqrt(np)
            posy = math.sqrt(R**2 - np)

            line = Line([posx-3, posy, 0], [posx-3, -posy, 0], color=WHITE)
            line.rotate(angle_of_vector(
                [x, y, 0]), about_point=c.get_center()).set_opacity(0.9)

            if 2 * posy > T:
                num_1 += 1
                line.set_color(YELLOW)
            else:
                num_2 += 1
                line.set_color(GREEN)
            tmp = format(num_1 / (num_1 + num_2), '.3f')
            v = MathTex(r"P = \frac{" + str(num_1) +
                        "}{" + str(num_1) + "+" + str(num_2) + "} = "+str((tmp))+"").shift(3 * RIGHT)
            print(tmp)
            self.add(line, p, v)
            self.wait(step)
            line.set_opacity(0.15).set_color(WHITE)
            self.remove(p, v)
