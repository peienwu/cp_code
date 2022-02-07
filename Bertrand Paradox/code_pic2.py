from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R
theta = math.pi / 6


class Bo(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        c = Circle(color=WHITE, radius=R)

        tri = Triangle().shift(UP/2)
        tri.height = 1.5*R
        tri.width = (T)

        d = Dot(point=[R*math.cos(theta), R*math.sin(theta), 0], color=RED)
        mid = Dot(point=[R*math.cos(theta)/2, R *
                  math.sin(theta)/2, 0], color=RED)
        t = MathTex("A").next_to(d, UR, buff=0.1)
        line1 = Line([0, 0, 0], mid.get_center(), color=GREEN)
        line2 = Line(mid.get_center(), d.get_center(), color=YELLOW)

        self.add(c, tri, d, t, line1, line2, mid)
