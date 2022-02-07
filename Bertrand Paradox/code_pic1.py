from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R


class B(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        c = Circle(color=WHITE, radius=R)

        tri = Triangle().shift(UP/2)
        tri.height = 1.5*R
        tri.width = (T)

        d = Dot(point=[0, R, 0], color=RED)
        t = MathTex("A").next_to(d, UR, buff=0.1)

        t1 = MathTex("A1").next_to(tri, LEFT).shift(0.8*RIGHT)
        t2 = MathTex("A2").next_to(tri, RIGHT).shift(0.8*LEFT)
        t3 = MathTex("A3").next_to(tri, DOWN, buff=0.5)

        self.add(c, tri, d, t, t1, t2, t3)
