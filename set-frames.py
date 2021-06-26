import sys
import os
import math


class Ball:
    def __init__(self, x, radius, height, g, color):
        self.x = x
        self.radius = radius
        self.max_height = height
        self.pos = height
        self.g = g
        self.color = color

    def get_drop_time(self):
        return math.sqrt((2 * (self.max_height - self.radius)) / self.g)

    def get_pos(self, time):
        return int(self.max_height - ((self.g / 2) * time * time))


class Frame:
    def __init__(self, width, height, bg_color, balls, time):
        self.width = width
        self.height = height
        self.bg_color = bg_color
        self.balls = balls
        self.time = time

    def get_text_rep(self):
        text_rep = f"""{self.width} {self.height}
{self.bg_color[0]} {self.bg_color[1]} {self.bg_color[2]}
{len(balls)}
"""

        for ball in self.balls:
            text_rep += f"{ball.radius} {ball.x} {ball.get_pos(self.time)} {ball.color[0]} {ball.color[1]} {ball.color[2]}"

        return text_rep


def write_frames(frames, path):
    os.system(f"rm -r {path}")
    os.system(f"mkdir {path}")
    for (index, frame) in enumerate(frames):
        with open(f"{path}{os.path.sep}{index:06d}", 'x') as f:
            print(frame.get_text_rep(), file=f)


if __name__ == '__main__':
    output_path = os.path.abspath('taf')
    if len(sys.argv) > 1:
        output_path = os.path.abspath(sys.argv[1])

    # reading input from stdin
    frame_width = int(input("frame width: "))
    frame_height = int(input("frame height: "))
    framerate = int(input("framerate: "))
    g = abs(float(input("g in px/sec^2: ")))  # g in frames / sec^2

    num_balls = int(input("number of balls: "))
    balls = []
    for _ in range(num_balls):
        x = int(input("x coordinate of center: "))
        radius = int(input("radius: "))
        height = int(input("drop height: "))

        r = int(input("color r: "))
        g = int(input("color g: "))
        b = int(input("color b: "))

        balls.append(
            Ball(x=x, radius=radius, height=height, g=g, color=(r, g, b)))

    duration = balls[0].get_drop_time()
    n_frames = duration * framerate

    if input(f"the anumation will take {int(n_frames)} frames\nproceed? [Y/n]") == 'n':
        exit

    delta = 1 / framerate
    frames = []
    for frame_no in range(int(n_frames)):
        time = frame_no * delta
        frames.append(Frame(width=frame_width, height=frame_height,
                      bg_color=(0, 0, 0), balls=balls, time=time))

    write_frames(frames, output_path)
