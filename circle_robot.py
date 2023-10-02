# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 10:59:25 2022

@author: AKBAR
"""

import numpy as np
import matplotlib.pyplot as plt

def getJacobian(th):
    J1 = np.matrix([[np.cos(th), 0.], [np.sin(th), 0.], [0., 1.]])
    J2 = np.matrix([[r/2., r/2.], [r/L, -r/L]])
    return J1*J2

r = 0.05 # satuan dalam meter
L = 0.15 # satuan dalam meter
Ts = 0.1 # satuan dalam detik
rpm = [[2, 3.] ] # kecepatan roda kiri dan kanan dalam rpm

x = np.matrix([[0., 0., np.radians(0.)]]).transpose()
#print("Posisi Awal : ", x)

# variable untuk merekam posisi setiap sampling
x_plot = [x[0,0]]
y_plot = [x[1,0]]
th_plot = [x[2,0]]
#print(x_plot)

for i in range(0, 1000):
    J = getJacobian(x[2, 0])
    q_dot = np.matrix([[rpm[0][1], rpm[0][0]]]).transpose()
    x_dot = J*q_dot
    #update posisi
    x = x + x_dot*Ts
    x_plot.append(x[0,0]) # menambahkan data pada list
    y_plot.append(x[1,0])
    th_plot.append(x[2,0])

print("Posisi Akhir : ", x, i*Ts)
#print(x_plot)

# visualisasi
plt.figure(0)
plt.plot(x_plot[0], y_plot[0], marker='s', color='b')
for i in range(0, len(x_plot), 8):
    plt.quiver(x_plot[i], y_plot[i], np.cos(th_plot[i]), np.sin(th_plot[i]), scale=0.9, scale_units='xy', angles = 'xy', color="r")
plt.plot(x_plot[-1], y_plot[-1], marker='*', color='k')
plt.grid()
plt.xlim(-1, 2)
plt.ylim(-1, 2)
plt.show()
