import numpy as np
from matplotlib import pyplot as plt

x = np.arange(-700, 100)
y = np.arange(-300, 400)
y = 2*x**2+3*x+1
plt.title("clown Matplotlib ")
plt.xlabel("x axis ")
plt.ylabel("y axis ")
plt.plot(x, y,"")
plt.show()
