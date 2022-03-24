#This program to analyse the energy of the Simulation.
# To plots the Density of Phonons and electrons
import csv
names="Energy_Analysis.txt"
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
for i in range(0,10):
    print(y[i])

# Import libraries
import numpy as np
import matplotlib.pyplot as plt
fig, axs = plt.subplots(1, 3, sharey=True, tight_layout=True)

# Creating plot
plt.title("Using matplotlib hexbin function")
#plt.plot(x, y)
x_min = 90
x_max = 100

y_min = 0
y_max =200

x_bins = np.linspace(x_min, x_max, 50)
y_bins = np.linspace(y_min, y_max, 5)
axs[0].hist(x, bins=100,range=(90, 100))
axs[1].hist(y, bins=100,range=(0,1))
Dife=[]
for i in range(0,len(x)):
    Dife.append(y[i]-x[i])

axs[2].hist(Dife, bins=100)

# show plot

plt.show()
