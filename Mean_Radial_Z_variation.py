# // This Program is to Plot the Radial Probability mean of all 10 Simulation in z Variation
# // Taking the Data File Saved and calcualting the Mean and  the sigam
# //Using Python to Generate the  Read the File
import csv
import math
class Mean_Radial_Z_variation:
    Radius=[]
    Z_1=[]
    Z_2=[]
    Z_3=[]
    Z_4=[]
    Z_5=[]
    Z_6=[]
    Z_7=[]
    Z_8=[]
    Z_9=[]
    Z_10=[]
    Mean_Nb_01_Cu_0=[]
    Sigma_Nb_01_Cu_0=[]
    def __init__(self,nameFile):
        self.nameFile= nameFile
    def Ploting_Mean(self):
        with open(self.nameFile) as csv_file:
            csv_reader = csv.reader(csv_file, delimiter='\t')
            line_count = 0
            list_of_column_names = []
            for row in csv_reader:
                list_of_column_names.append(row)

                        # breaking the loop after the
                        # first iteration itself
                break


            for lines in csv_reader:
                            #print(lines[9])
                        #i=1+i
                        #print(i)
                            #Energy_Initial_e.append(float(lines[4]))


                self.Radius.append(float(lines[0]))#Converting to cm from mete
                self.Z_1.append(float(lines[1]))#Converting to cm from mete
                self.Z_2.append(float(lines[2]))#Converting to cm from mete
                self.Z_3.append(float(lines[3]))#Converting to cm from mete
                self.Z_4.append(float(lines[4]))#Converting to cm from mete
                self.Z_5.append(float(lines[5]))#Converting to cm from mete
                self.Z_6.append(float(lines[6]))#Converting to cm from mete
                self.Z_7.append(float(lines[7]))#Converting to cm from mete
                self.Z_8.append(float(lines[8]))#Converting to cm from mete
                self.Z_9.append(float(lines[9]))#Converting to cm from mete
                self.Z_10.append(float(lines[10]))#Converting to cm from mete



            for i in range(0,len(self.Z_1)):
                self.Mean_Nb_01_Cu_0.append((+self.Z_1[i]+self.Z_2[i]+self.Z_3[i]+self.Z_4[i]+self.Z_5[i]+self.Z_6[i]+self.Z_7[i]+self.Z_8[i]+self.Z_9[i]+self.Z_10[i])/10.0)
                #print(self.Z_1[i])

            for i in range(0,len(self.Z_1)):
                self.Sigma_Nb_01_Cu_0.append(math.sqrt( (pow(self.Mean_Nb_01_Cu_0[i]-self.Z_1[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_2[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_3[i],2)
                +pow(self.Mean_Nb_01_Cu_0[i]-self.Z_4[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_5[i],2)
                +pow(self.Mean_Nb_01_Cu_0[i]-self.Z_6[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_7[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_8[i],2)
                +pow(self.Mean_Nb_01_Cu_0[i]-self.Z_9[i],2)+pow(self.Mean_Nb_01_Cu_0[i]-self.Z_10[i],2) ))/10.0)

    def Cleaner(self):

        self.Radius.clear()
        self.Z_1.clear()
        self.Z_2.clear()
        self.Z_3.clear()
        self.Z_4.clear()
        self.Z_5.clear()
        self.Z_6.clear()
        self.Z_7.clear()
        self.Z_8.clear()
        self.Z_9.clear()
        self.Z_10.clear()
        self.Mean_Nb_01_Cu_0.clear()
        self.Sigma_Nb_01_Cu_0.clear()




name='Prob_Nb_1_Cu_1.txt'
Nb=Mean_Radial_Z_variation(name)
#Saving the Data for the Files
Nb.Ploting_Mean()
Mean_Nb_1_Cu_1=[]
Sigma_Nb_1_Cu_1=[]
Radius=[]
for i in range(0,len(Nb.Z_1)):
    Mean_Nb_1_Cu_1.append(Nb.Mean_Nb_01_Cu_0[i])
    Sigma_Nb_1_Cu_1.append(Nb.Sigma_Nb_01_Cu_0[i])
    Radius.append(Nb.Radius[i])

Nb.Cleaner()
#----------------------------------------
name='Prob_Nb_01_Cu_1.txt'
Nb=Mean_Radial_Z_variation(name)
Nb.Ploting_Mean()
Mean_Nb_01_Cu_1=[]
Sigma_Nb_01_Cu_1=[]
Radius2=[]
for i in range(0,len(Nb.Z_1)):
    Mean_Nb_01_Cu_1.append(Nb.Mean_Nb_01_Cu_0[i])
    Sigma_Nb_01_Cu_1.append(Nb.Sigma_Nb_01_Cu_0[i])
    Radius2.append(Nb.Radius[i])

Nb.Cleaner()
#-------------------------------------------

#----------------------------------------
name='Prob_Nb_1_Cu_0.txt'
Nb=Mean_Radial_Z_variation(name)
Nb.Ploting_Mean()
Mean_Nb_1_Cu_0=[]
Sigma_Nb_1_Cu_0=[]
Radius3=[]
for i in range(0,len(Nb.Z_1)):
    Mean_Nb_1_Cu_0.append(Nb.Mean_Nb_01_Cu_0[i])
    Sigma_Nb_1_Cu_0.append(Nb.Sigma_Nb_01_Cu_0[i])
    Radius3.append(Nb.Radius[i])

Nb.Cleaner()
#-------------------------------------------

#----------------------------------------
name='Prob_Nb_01_Cu_0.txt'
Nb=Mean_Radial_Z_variation(name)
Nb.Ploting_Mean()
Mean_Nb_01_Cu_0=[]
Sigma_Nb_01_Cu_0=[]
Radius4=[]
for i in range(0,len(Nb.Z_1)):
    Mean_Nb_01_Cu_0.append(Nb.Mean_Nb_01_Cu_0[i])
    Sigma_Nb_01_Cu_0.append(Nb.Sigma_Nb_01_Cu_0[i])
    Radius4.append(Nb.Radius[i])

Nb.Cleaner()
#-------------------------------------------
import matplotlib.pyplot as plt
import numpy as np
A = 6  # Want figure to be A6
plt.rc('figure', figsize=[46.82 * .5**(.5 * A), 33.11 * .5**(.5 * A)])
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
plt.rc('text.latex', preamble=r'\usepackage{textgreek}')


# make data:


# plot:
ax = plt.axes()


ax.errorbar(Radius3, Mean_Nb_1_Cu_0,Sigma_Nb_1_Cu_0, fmt='o', linewidth=2, capsize=3,label='Nb=1 Cu=0')
ax.errorbar(Radius4, Mean_Nb_01_Cu_0,Sigma_Nb_01_Cu_0, fmt='o', linewidth=2, capsize=3,label='Nb=0.1 Cu = 0')
ax.errorbar(Radius, Mean_Nb_1_Cu_1,Sigma_Nb_1_Cu_1, fmt='o', linewidth=2, capsize=3,label='Nb=1 Cu = 1')
ax.errorbar(Radius2, Mean_Nb_01_Cu_1,Sigma_Nb_01_Cu_1, fmt='o', linewidth=2, capsize=3,label='Nb=0.1 Cu = 1')

ax.set(ylim=(0.00000000000000001,0.12))
#ax.set_xscale('log')
#ax.set_yscale('log')
plt.ylabel(' Mean Radial  Probability')
plt.xlabel('Distance to Qubit Cross [cm]')
ax.legend()
plt.show()
