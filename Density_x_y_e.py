# To plots the Density of Phonons and electrons
import csv
names="Position_detector_TF_Nb.txt"
with open(names) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter='\t')
    line_count = 0
    list_of_column_names = []

    # loop to iterate through the rows of csv
    for row in csv_reader:

        # adding the first row
        list_of_column_names.append(row)

        # breaking the loop after the
        # first iteration itself
        break




    x=[]
    y=[]
    i=0


    for lines in csv_reader:
        #print(lines[9])
        i=1+i
        #print(i)
        #Energy_Initial_e.append(float(lines[4]))


        x.append(float(lines[0]))
        y.append(float(lines[1]))

#print("List of column names : ",list_of_column_names)
# for i in range(0,10):
#     print(y[i])

# Import libraries
import numpy as np
import matplotlib.pyplot as plt
fig, ax = plt.subplots(figsize =(10, 7))
# Creating plot
plt.title("Using matplotlib hexbin function")
plt.hexbin(x, y, bins = 5000)

ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')

# show plot
plt.tight_layout()
plt.show()
#/////////
# Creating bins
x_min = np.min(x)
x_max = np.max(x)

y_min = np.min(y)
y_max = np.max(y)
x_min = -0.2
x_max = 0.2

y_min = -0.2
y_max =0.2

x_bins = np.linspace(x_min, x_max, 500)
y_bins = np.linspace(y_min, y_max, 500)

fig, ax = plt.subplots(figsize =(10, 7))
# Creating plot
plt.hist2d(x, y, bins =[x_bins, y_bins], cmap = plt.cm.nipy_spectral)
plt.title("Changing the color scale and adding color bar")

# Adding color bar
plt.colorbar()

ax.set_xlabel('X-axis')
ax.set_ylabel('X-axis')

# show plot
plt.tight_layout()
plt.show()
#///////////////////////////////////////
