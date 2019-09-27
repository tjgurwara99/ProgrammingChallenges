import numpy as np
from math import sqrt

vert_dist = 25 * (sqrt(2) - 1)
speeds = [10,9,8,7,6,5,10]
distances = [vert_dist,10,10,10,10,10,vert_dist]

def ith_diff(xs, i):
    return (xs[i]-xs[i+1]) / (speeds[i] * sqrt(distances[i]**2 + (xs[i] - xs[i+1])**2))

def ith_derivative(xs, i): return ith_diff(xs, i) - ith_diff(xs, i-1)

def derivative(xs):
    ans = np.zeros(8)
    for i in range(1,7): ans[i] = ith_derivative(xs, i)
    return ans

def path_time(xs):
    total_time = 0
    for i in range(7):
        total_time += sqrt(distances[i]**2 + (xs[i] - xs[i+1])**2) / speeds[i]
    return total_time

xs = np.zeros(8)
xs[7] = 50*sqrt(2)
for i in range(100000): xs -= derivative(xs)

print("{:.10f}".format(path_time(xs)))
