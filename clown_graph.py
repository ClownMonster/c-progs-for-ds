# including  the modules for multi array and graph
import numpy as np 
from  matplotlib import pyplot as plt 

# takling input from the user for the range of the graph
x_range_initial = int(input("Input the Initial range of X >>  "))
print("\n")
x_range_final = int(input("Input the Final range of X >>"))
print("\n")
y_range_initial = int(input("Input the Initial range of Y >>"))
print("\n")
y_range_final = int(input("Input the Final range of Y >>"))
print("\n")

# assigning the range
x = np.arange(x_range_initial, x_range_final)
y = np.arange(y_range_initial, y_range_final)

# asking the user to input the equation to be ploted
eqn = input("Enter the standard equation to be Ploted >>")
y = eval(eqn)
# ploting the graph
plt.title("Required Graph for your equation :")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.plot(x, y)
plt.show()
