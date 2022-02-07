from manim import *
import random
import math

R = 3.0
T = math.sqrt(3)*R
theta = math.pi / 6


class Bot(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        c = Circle(color=WHITE, radius=R)

        tri = Triangle().shift(UP/2)
        tri.height = 1.5*R
        tri.width = (T)

        c2 = Circle(color=WHITE, radius=R/2)

        self.add(c, tri, c2)
