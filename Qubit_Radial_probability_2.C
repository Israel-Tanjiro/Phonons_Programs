// This Program is to generate the new density plot by using the radial distance.
// I calculate the number of intial phonons inside of an annulus,
//Testing the Firsts Annulus with the draw options. May 23 2023

////////////Creating The Class to Analyse Several Files for Differents Parametes
//Final Program to Analyse all the event from the simulation using ROOT
//This contain the tools to put all the plots in one File of the Probability radial function.
// May 30 2023
#include <string>
#include <iostream>
#include "TMath.h"






using namespace std;
class OpenFiless{
public:
   TString nameFile;
 TString  RootFile;
 Float_t *Proh;
Float_t *Number_Phonons_Inside_Initial;
Float_t *Number_Phonons_Inside_Final;

  OpenFiless(){};
  ~OpenFiless(){};
  void Generate_Desntiy_Plot(TString RootFile,Float_t *Radius,Int_t inde,Int_t NumberR, Float_t Qubits_X,Float_t Qubits_Y);
  void Dividing(Float_t *X_i, Float_t *Y_i);
Float_t *Distance_Arrey(Double_t X_i, Double_t Y_i);





};
Float_t * OpenFiless::Distance_Arrey(Double_t X_i, Double_t Y_i){
  Float_t X[6400];
  Float_t Y[6400];

  static Float_t Dis[6400];
  Float_t counter[6400];
  for(Int_t j=0;j<80;j++){for(Int_t i=0;i<80;i++){
  X[j*80+i]=i*100-4000;// Here the Units is in microns
  Y[j*80+i]=j*100-4000;// Here the units are in Microns
  }
  }



  Int_t k=0;
  for(Int_t j=0;j<80;j++){for(Int_t i=0;i<80;i++){  Dis[j*80+i]=TMath::Sqrt((X[j*80+i]-X_i)*(X[j*80+i]-X_i)+(Y[j*80+i]-Y_i)*(Y[j*80+i]-Y_i))/10000;
  counter[j*80+i]=j*80+i;
    k=k+1;


  }}
return Dis;

}

void  OpenFiless::Generate_Desntiy_Plot(TString RootFile,Float_t *Radius,Int_t inde,Int_t NumberR ,Float_t Qubits_X,Float_t Qubits_Y)
{


 //this->Calis();
  TString A= RootFile;
  TFile *f = new TFile(A);
  cout<<A<<endl;

  TTree *t1,*t2;
  f = new TFile(A);
  t1 = (TTree*)f->Get("Initial");
  t2 = (TTree*)f->Get("Final");
  Double_t X_i,Y_i,Z_i,Initial_Energy,Final_Energy,X_f,Y_f,Z_f;
  Int_t trackID,ParentID,StepNumber;
  Int_t  runID;
  Char_t Name_particle[100];
  Char_t Name_particle_F[100];
  Char_t Procces_name[100];
  Char_t Volume_name[100];
  Double_t X_f2,Y_f2,Z_f2;
  Int_t nbinsx=80;
  Int_t nbinsy=80;
  t1->SetBranchAddress("X_i",&X_i);// Using this and the conditions I can obtain the final position of the phonons
  t1->SetBranchAddress("Y_i",&Y_i);
  t1->SetBranchAddress("Z_i",&Z_i);
  t2->SetBranchAddress("X_f",&X_f);// Using this and the conditions I can obtain the final position of the phonons
  t2->SetBranchAddress("Y_f",&Y_f);
  t2->SetBranchAddress("Z_f",&Z_f);
  t1->SetBranchAddress("Initial_Energy",&Initial_Energy);
  t1->SetBranchAddress("trackID",&trackID);
  t1->SetBranchAddress("ParentID",&ParentID);
  t1->SetBranchAddress("StepNumber",&StepNumber);
  t2->SetBranchAddress("Final_Energy",&Final_Energy);
  t1->SetBranchAddress("Name_particle",&Name_particle);
  t2->SetBranchAddress("Volume_Name",&Volume_name);
  t2->SetBranchAddress("Procces",&Procces_name);
  t2->SetBranchAddress("runID",&runID);
  t2->SetBranchAddress("Name_particle_F",&Name_particle_F);
  const char* Cruz_Qubits[6]={"ResonatorAssembly_0_shuntConductor","ResonatorAssembly_1_shuntConductor","ResonatorAssembly_2_shuntConductor",
  "ResonatorAssembly_3_shuntConductor","ResonatorAssembly_4_shuntConductor","ResonatorAssembly_5_shuntConductor"};


  const char* Qubits[6]={"Qubit_0","Qubit_1","Qubit_2","Qubit_3","Qubit_4","Qubit_5"};
/////////////////---------Starting the Analyse of One Qubits
// TH2F* h_0 = new TH2F("h_0", "h_0 title; X [cm]; Y [cm]", nbinsx, -0.4, 0.4, nbinsx, -0.4, 0.4);
// TH2F* h_0_F = new TH2F("h_0_F", "Probability Density Function;Phonon Starting X [cm];Phonon Starting  Y [cm]", nbinsx, -0.4, 0.4, nbinsx, -0.4, 0.4);
// TH2F* h_initial = new TH2F("h_initial", "h1 title", nbinsx, -0.4, 0.4, nbinsy, -0.4, 0.4);

// for(Int_t ll=0;ll<nbinsx;ll++){for(Int_t l=0;l<nbinsx;l++){h_0->SetBinContent(ll+1,l+1,0); h_0_F->SetBinContent(ll+1,l+1,0); }}



Int_t nentries2 = (Int_t)t2->GetEntries();
Int_t nentries = (Int_t)t1->GetEntries();
Int_t Qubits_number=inde;
Number_Phonons_Inside_Initial=new Float_t[NumberR];
Number_Phonons_Inside_Final=new Float_t[NumberR];

Proh=new Float_t[NumberR];

  for(Int_t i=0;i<NumberR;i++){Number_Phonons_Inside_Initial[i]=0;Number_Phonons_Inside_Final[i]=0;}


for (Int_t i=0; i<nentries2; i++) {
  t1->GetEntry(i);
  t2->GetEntry(i);
//h_initial->Fill(X_i,Y_i);
// Counting the Array of the Radius.
for(Int_t i=0;i<NumberR;i++){

if(Radius[i]<TMath::Sqrt((X_i-Qubits_X)*(X_i-Qubits_X)+(Y_i-Qubits_Y)*(Y_i-Qubits_Y)) && TMath::Sqrt((X_i-Qubits_X)*(X_i-Qubits_X)+(Y_i-Qubits_Y)*(Y_i-Qubits_Y)) <Radius[i+1]){
Number_Phonons_Inside_Initial[i]=Number_Phonons_Inside_Initial[i]+1;
  }




}


  int resu0 = strcmp(Cruz_Qubits[inde],Volume_name);
  if(resu0==0 ){
    for(Int_t i=0;i<NumberR;i++){
    if(Radius[i]<TMath::Sqrt((X_i-Qubits_X)*(X_i-Qubits_X)+(Y_i-Qubits_Y)*(Y_i-Qubits_Y)) && TMath::Sqrt((X_i-Qubits_X)*(X_i-Qubits_X)+(Y_i-Qubits_Y)*(Y_i-Qubits_Y)) <Radius[i+1]){
    Number_Phonons_Inside_Final[i]=Number_Phonons_Inside_Final[i]+1;




}

}
//h_0->Fill(X_i,Y_i);
}




}



  for(Int_t i=0;i<NumberR;i++){
if(Number_Phonons_Inside_Initial[i]==0){Proh[i]=0;}
else
    {Proh[i]= Number_Phonons_Inside_Final[i]/Number_Phonons_Inside_Initial[i];}

}
///////////////////////////??Calcula The Probability 2D Histogram
// for(Int_t ll=0;ll<nbinsx;ll++){for(Int_t l=0;l<nbinsx;l++){
// if(h_initial->GetBinContent(ll+1,l+1) ==0){
//
//   h_0_F->SetBinContent(ll+1,l+1, 0 );
// }
// else{
//   h_0_F->SetBinContent(ll+1,l+1,h_0->GetBinContent(ll+1,l+1)/h_initial->GetBinContent(ll+1,l+1)        );
// }
// }
// }
//
//
// //h_0_F->Draw("colz");







}
void Qubit_Radial_probability_2(){

OpenFiless *Ca=new OpenFiless();
//Coordinates of the Qubits to Calculate the Probability density Function as Function of the Distance s
Float_t Qubits_0_X=-0.1855;// In cm
Float_t Qubits_1_X=0.0;// In cm
Float_t Qubits_2_X=0.1855;// In cm

Float_t Qubits_3_X=-0.1855;// In cm
Float_t Qubits_4_X=-0.0;// In cm
Float_t Qubits_5_X=0.1855;// In cm
/////////////////////////////////////---------Coordinates in Y
Float_t Qubits_0_Y=0.1772;// In cm
Float_t Qubits_1_Y=0.1772;// In cm
Float_t Qubits_2_Y=0.1772;// In cm

Float_t Qubits_3_Y=-0.1772;// In cm
Float_t Qubits_4_Y=-0.1772;// In cm
Float_t Qubits_5_Y=-0.1772;// In cm

Float_t *Qubit_0_Dis;
Float_t *Qubit_1_Dis;
Float_t *Qubit_2_Dis;

Float_t Qubit_0_Prob[6400];
Float_t Qubit_1_Prob[6400];
Float_t Qubit_2_Prob[6400];
Float_t Qubit_3_Prob[6400];
Float_t Qubit_4_Prob[6400];
Float_t Qubit_5_Prob[6400];
Float_t Qubit_6_Prob[6400];
Float_t Qubit_7_Prob[6400];
Float_t Qubit_8_Prob[6400];
Float_t Qubit_9_Prob[6400];


///Calculating the Number of annulus as a function of the numbers of the width.
//Caculating the Maximum Distance firts.
Double_t X_max,Y_max, length;
X_max=max(abs(-0.4-Qubits_0_X),abs(0.4-Qubits_0_X));
Y_max=max(abs(-0.4-Qubits_0_Y),abs(0.4-Qubits_0_Y));
cout<<"The maximum on X is \t"<<X_max<<"Ans the Y \t"<<Y_max<<endl;

length=TMath::Sqrt(X_max*X_max+Y_max*Y_max);
//The Number of annulus with a separation of 10 microns is
Double_t width=0.001;///
Double_t Number_annulus;
Number_annulus=length/width;
cout<<"The Number of Annulus is \t"<<(int) Number_annulus<<endl;

//Caclualting the Inner and Outer Radius
Float_t *Radius,*Radius2;
Radius =new Float_t[(int) Number_annulus+1];
Radius2 =new Float_t[(int) Number_annulus+1];
for(Int_t i=0;i<(int) Number_annulus+1;i++){
Radius[i]=width*i;
Radius2[i]=width*i+0.001;

}
Float_t Pr_mean[(int) Number_annulus];
Float_t Pr_mean1[(int) Number_annulus];
Float_t Pr_mean2[(int) Number_annulus];
Float_t Pr_mean3[(int) Number_annulus];
Float_t Pr_mean4[(int) Number_annulus];

Float_t Pr_mean5[(int) Number_annulus];
Float_t Pr_mean6[(int) Number_annulus];
Float_t Pr_mean7[(int) Number_annulus];
Float_t Pr_mean8[(int) Number_annulus];
Float_t Pr_mean9[(int) Number_annulus];

Float_t Pr_mean10[(int) Number_annulus];

for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]=0;}

Ca->Generate_Desntiy_Plot("out_0_0.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g1 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i]; Pr_mean1[i]=Ca->Proh[i]; }
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_1_1.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g2 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean2[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_2_2.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g3 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i]; Pr_mean3[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_3_3.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g4 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean4[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_4_4.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g5 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i]; Pr_mean5[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_5_5.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g6 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean6[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_6_6.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g7 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean7[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_7_7.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g8 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean8[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_8_8.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g9 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean9[i]=Ca->Proh[i];}
Ca->~OpenFiless();

Ca->Generate_Desntiy_Plot("out_9_9.root",Radius,0,(int) Number_annulus,Qubits_0_X,Qubits_0_Y);
//TGraph * g10 = new TGraph((int) Number_annulus,Radius2,Ca->Proh);
for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]+=Ca->Proh[i];Pr_mean10[i]=Ca->Proh[i];}
Ca->~OpenFiless();


for(Int_t i=0;i<(int) Number_annulus;i++){Pr_mean[i]=Pr_mean[i]/10;}
 TCanvas *c1=new TCanvas();
 TGraph * gP = new TGraph((int) Number_annulus,Radius2,Pr_mean);
 gP->Fit("exp0");

 gP->Draw("ALP");

 //open file for writing
 ofstream fw("Prob_Nb_1_Cu_1.txt", std::ofstream::out);
 //check if file was successfully opened for writing
if (fw.is_open())
{
  //store array contents to text file
  for (int i = 0; i < (int) Number_annulus; i++) {
    fw << Radius2[i] << "\t"<<Pr_mean1[i]<< "\t"<<Pr_mean2[i]<< "\t"<<Pr_mean3[i]<< "\t"<<Pr_mean4[i]<< "\t"<<Pr_mean5[i]<< "\t"<<Pr_mean6[i]<< "\t"<<Pr_mean7[i]<< "\t"<<Pr_mean8[i]<< "\t"<<Pr_mean9[i]<< "\t"<<Pr_mean10[i]<<endl;
  }
  fw.close();
}
else cout << "Problem with opening file";





}
