#Program to analyse the data of the simulation with 100 times.

import csv
names="phonons_impacts.txt"
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




    TS=[]
    L=[]
    TF=[]
    Elec=[]
    Hole=[]
    i=0


    for lines in csv_reader:
        #print(lines[9])
        #i=1+i
        #print(i)
        #Energy_Initial_e.append(float(lines[4]))


        TS.append(float(lines[0]))
        TF.append(float(lines[1]))
        L.append(float(lines[2]))
        Elec.append(float(lines[3]))
        Hole.append(float(lines[4]))


#Ploting the Histogram and Fiiting to Gaussian Distribution
import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt
data = np.random.normal(0, 1, 1000)
_, bins, _ = plt.hist(Elec, 20)
mu,sigma = norm.fit(data)
best_fit_line = norm.pdf(bins, mu, sigma)
plt.plot(bins, best_fit_line)
plt.show()
