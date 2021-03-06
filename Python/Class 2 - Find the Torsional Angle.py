#Problem: https://www.hackerrank.com/challenges/class-2-find-the-torsional-angle/problem


import math

class Points(object):

    def __init__(self, x, y, z):

        self.x = float(x)
        self.y = float(y)  
        self.z = float(z)

    def __sub__(self, no):

        x_s = self.x - no.x
        y_s = self.y - no.y
        z_s = self.z - no.z

        return Points(x_s, y_s, z_s)

    def dot(self, no):

        return (self.x * no.x) + (self.y * no.y) + (self.z * no.z)
    

    def cross(self, no):

        x_c = self.y*no.z - self.z*no.y
        y_c = self.x*no.z - self.z*no.x
        z_c = self.x*no.y - self.y*no.x

        return Points(x_c, y_c, z_c)

    def absolute(self):

        return pow((self.x**2 + self.y**2 + self.z**2), 0.5)
        


if __name__ == '__main__':
    points = list()
    for i in range(4):
        a = list(map(float, input().split()))
        points.append(a)

    a, b, c, d = Points(*points[0]), Points(*points[1]), Points(*points[2]), Points(*points[3])
    x = (b - a).cross(c - b)
    y = (c - b).cross(d - c)
    angle = math.acos(x.dot(y) / (x.absolute() * y.absolute()))

    print("%.2f" % math.degrees(angle))
