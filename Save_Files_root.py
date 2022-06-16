names=input('Introduce the name of the file  ')



import csv
#names="charge_hits_1.txt"// You can uncomment this and It is going to work
with open(names) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
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
    x_i=[]
    y=[]
    y_i=[]
    t_i=[]
    names=[]
    Energy_Deposited=[]
    Start_Energy=[]
    i=0
    z=[]# the final position
    z_i=[]
    t_f=[]

    for lines in csv_reader:
        #print(lines[9])
        i=1+i
        #print(i)
        #Energy_Initial_e.append(float(lines[4]))

        Start_Energy.append(float(lines[4]))
        x_i.append(float(lines[5])*100)
        y_i.append(float(lines[6])*100)
        z_i.append(float(lines[7])*100)
        t_i.append(float(lines[8]))
        Energy_Deposited.append(float(lines[9]))
        x.append(float(lines[11])*100)
        y.append(float(lines[12])*100)
        names.append(lines[3])
        t_f.append(float(lines[14]))
        z.append(float(lines[13])*100)#Converting to cm from meter
print("List of column names : ",list_of_column_names[0][4])
#Saving the data from all TL, TF and TS phonons.

Sum = sum(Start_Energy)
print("The total Energy of the System is \t",Sum)
Sum2 = sum(Energy_Deposited)
print("The Final Energy of the System is \t",Sum2)
A="phononTF"

B="phononTS"
C="phononL"
D='G4CMPDriftElectron'
E='G4CMPDriftHole'
ETF=[]
xTF=[]
yTF=[]
zTF=[]
ETF_i=[]
xTF_i=[]
yTF_i=[]
zTF_i=[]
tTF_i=[]
tTF_f=[]
#////////////////////////TS

ETS=[]
xTS=[]
yTS=[]
zTS=[]
ETS_i=[]
xTS_i=[]
yTS_i=[]
zTS_i=[]
tTS_i=[]
tTS_f=[]
#//////////////////////TL
ETL=[]
xTL=[]
yTL=[]
zTL=[]
ETL_i=[]
xTL_i=[]
yTL_i=[]
zTL_i=[]
tTL_i=[]
tTL_f=[]

#//////////////////////Electron
E_E=[]
xE=[]
yE=[]
zE=[]
E_E_i=[]
xE_i=[]
yE_i=[]
zE_i=[]
tE_i=[]
tE_f=[]

#//////////////////////Holes
E_H=[]
xH=[]
yH=[]
zH=[]
E_H_i=[]
xH_i=[]
yH_i=[]
zH_i=[]
tH_i=[]
tH_f=[]


for i in range(len(x)):
    if names[i]==A:

        ETF.append(Energy_Deposited[i])
        xTF.append(x[i])
        yTF.append(y[i])
        zTF.append(z[i])
        tTF_i.append(t_i[i])
        ETF_i.append(Start_Energy[i])
        xTF_i.append(x_i[i])
        yTF_i.append(y_i[i])
        zTF_i.append(z_i[i])

        tTF_f.append(t_f[i])

    if names[i]==B:

        ETS.append(Energy_Deposited[i])
        xTS.append(x[i])
        yTS.append(y[i])
        zTS.append(z[i])
        tTS_i.append(t_i[i])
        ETS_i.append(Start_Energy[i])
        xTS_i.append(x_i[i])
        yTS_i.append(y_i[i])
        zTS_i.append(z_i[i])
        tTS_f.append(t_f[i])

    if names[i]==C:

        ETL.append(Energy_Deposited[i])
        xTL.append(x[i])
        yTL.append(y[i])
        zTL.append(z[i])
        tTL_i.append(t_i[i])
        ETL_i.append(Start_Energy[i])
        xTL_i.append(x_i[i])
        yTL_i.append(y_i[i])
        zTL_i.append(z_i[i])

        tTL_f.append(t_f[i])

    if names[i]==D:

        E_E.append(Energy_Deposited[i])
        xE.append(x[i])
        yE.append(y[i])
        zE.append(z[i])
        tE_i.append(t_i[i])
        E_E_i.append(Start_Energy[i])
        xE_i.append(x_i[i])
        yE_i.append(y_i[i])
        zE_i.append(z_i[i])

        tE_f.append(t_f[i])

    if names[i]==E:

        E_H.append(Energy_Deposited[i])
        xH.append(x[i])
        yH.append(y[i])
        zH.append(z[i])
        tH_i.append(t_i[i])
        E_H_i.append(Start_Energy[i])
        xH_i.append(x_i[i])
        yH_i.append(y_i[i])
        zH_i.append(z_i[i])

        tH_f.append(t_f[i])



#zip(ETF_i,xTF_i,yTF_i,zTF_i,tTF_i,ETF,xTF,yTF,zTF,tTF_f)

Radial_posTF="Phonons_TF.txt"
import csv
with open(Radial_posTF, 'a') as f:
     writer = csv.writer(f, delimiter='\t')
     writer.writerows(zip(ETF_i,xTF_i,yTF_i,zTF_i,tTF_i,ETF,xTF,yTF,zTF,tTF_f))



#zip(ETS,xTS,yTS,zTS,tTS_i,ETS_i,xTS_i,yTS_i,zTS_i)

Radial_posTS="Phonons_TS.txt"

with open(Radial_posTS, 'a') as f:
     writer = csv.writer(f, delimiter='\t')
     writer.writerows(zip(ETS_i,xTS_i,yTS_i,zTS_i,tTS_i,ETS,xTS,yTS,zTS,tTS_f))


zip(ETL,xTL,yTL,zTL,tTL_i,ETL_i,xTL_i,yTL_i,zTL_i)

Radial_posL="Phonons_TL.txt"

with open(Radial_posL, 'a') as f:
     writer = csv.writer(f, delimiter='\t')
     writer.writerows(zip(ETL_i,xTL_i,yTL_i,zTL_i,tTL_i,ETL,xTL,yTL,zTL,tTL_f))

Radial_posE="Electrons.txt"

with open(Radial_posE, 'a') as f:
     writer = csv.writer(f, delimiter='\t')
     writer.writerows(zip(E_E_i,xE_i,yE_i,zE_i,tE_i,E_E,xE,yE,zE,tE_f))


Radial_posH="Holes.txt"

with open(Radial_posH, 'a') as f:
     writer = csv.writer(f, delimiter='\t')
     writer.writerows(zip(E_H_i,xH_i,yH_i,zH_i,tH_i,E_H,xH,yH,zH,tH_f))
