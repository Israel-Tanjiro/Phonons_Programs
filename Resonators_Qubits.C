//Program to Determinated the Number of Phonons Absorbed in the Resonators for the Transmmon Qubits.
void Resonators_Qubits(){
TString RootFile;
RootFile="out0.root";
TFile *f;
TTree *t1,*t2;
f = new TFile(RootFile);
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
Int_t nbinsx=800;
Int_t nbinsy=800;
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
//////////////////Histograms To plot the Density Probability
TH2F* h_initial = new TH2F("h_initial", "h1 title", nbinsx, -0.4, 0.4, nbinsy, -0.4, 0.4);
TH2F* h_0_F = new TH2F("h_0_F", "Probability Density Function;Y [CCm];X [cm]", nbinsx, -0.4, 0.4, nbinsx, -0.4, 0.4);


TH1F *Particle = new TH1F("Particle", "Particle", 3, 0, 3);
TH1F *Particle_Finals = new TH1F("Particle_Finals", "Particle_Finals", 3, 0, 3);
t1->Draw("Name_particle>>Particle","trackID==1");
t2->Draw("Name_particle_F>>Particle_Finals");
TH1*hP = (TH1*)(Particle->Clone("hP"));
TH1*hP_F = (TH1*)(Particle_Finals->Clone("hP_F"));
TCanvas *c0=new TCanvas();
c0->Divide(1,2);
hP->Scale(1./hP->Integral(), "width");
hP->SetFillColor(kBlue);
c0->cd(1);
hP_F->Scale(1./hP_F->Integral(), "width");
hP_F->SetFillColor(kBlue);

hP->Draw("bar1");
//t1->Draw("Name_particle");
cout<<"Percentage Initial of the Numbers of Phonons \t"<<hP->GetBinContent(1)*100<<"\t"<<hP->GetBinContent(2)*100<<"\t"<<hP->GetBinContent(3)*100<<endl;
c0->cd(2);
hP_F->Draw("bar1");
cout<<"Percentage Initial of the Numbers of Phonons \t"<<hP_F->GetBinContent(1)*100<<"\t"<<hP_F->GetBinContent(2)*100<<"\t"<<hP_F->GetBinContent(3)*100<<endl;


///////////////////////Histogram of Final Energy ///////////////////////////////
TH1F *Final_Energy_Hist = new TH1F("Final_Energy_Hist", "Particle; Energy [eV]; Counts", 100, 0,0.07);
TH1F *Initial_Energy_Hist = new TH1F("Initial_Energy_Hist", "Particle; Energy [eV]; Counts", 100, 0,0.07);


TCanvas *c1=new TCanvas();
c1->Divide(1,2);


c1->cd(1);
t2->Draw("Final_Energy>>Final_Energy_Hist");
Final_Energy_Hist->Draw("bar1");
c1->cd(2);
t1->Draw("Initial_Energy>>Initial_Energy_Hist","trackID==1");
Initial_Energy_Hist->Draw("bar1");
//////////Calcualting the area of the Histogrma
Double_t Area1=0;
Double_t Area2=0;
  TAxis *xaxis = Initial_Energy_Hist->GetXaxis();
  TAxis *xaxis2 = Final_Energy_Hist->GetXaxis();
for(Int_t j=1;j<101;j++){Area1+=xaxis->GetBinCenter(j)*Initial_Energy_Hist->GetBinContent(j+1);
Area2+=xaxis2->GetBinCenter(j)*Final_Energy_Hist->GetBinContent(j+1);}
  //cout<<Initial_Energy_Hist->GetBinContent(j+1)<<endl;cout<<Initial_Energy_Hist->GetXaxis()->GetBinCenter(Initial_Energy_Hist->GetXaxis()->FindFixBin(j))<<endl;}


cout<<"The integral is \t"<<Area1<<"\t"<<Area2<<endl;

const char* Sensors[20]={"ResonatorAssembly_0_curve1Conductor",
"ResonatorAssembly_0_curve2Conductor",
"ResonatorAssembly_0_curve3Conductor",
"ResonatorAssembly_0_halfCircle1Conductor",
"ResonatorAssembly_0_halfCircle2Conductor",
"ResonatorAssembly_0_halfCircle3Conductor",
"ResonatorAssembly_0_halfCircle4Conductor",
"ResonatorAssembly_0_halfCircle5Conductor",
"ResonatorAssembly_0_halfCircle6Conductor",
"ResonatorAssembly_0_shuntCouplerConductor",
"ResonatorAssembly_0_shuntConductor",
"ResonatorAssembly_0_tlCouplingConductor",
"ResonatorAssembly_0_shl1Conductor",
"ResonatorAssembly_0_shl2Conductor",
"ResonatorAssembly_0_shl3Conductor",
"ResonatorAssembly_0_shl4Conductor",
"ResonatorAssembly_0_shl5Conductor",
"ResonatorAssembly_0_shl6Conductor",
"ResonatorAssembly_0_shl7Conductor",
"ResonatorAssembly_0_svl1Conductor"
};

const char* Sensors_Names[20]={"curve1Conductor","curve2Conductor","curve3Conductor","halfCircle1Conductor","halfCircle2Conductor",
"halfCircle3Conductor",
"halfCircle4Conductor",
"halfCircle5Conductor",
"halfCircle6Conductor",
"shuntCouplerConductor",
"shuntConductor",
"tlCouplingConductor",
"shl1Conductor",
"shl2Conductor",
"shl3Conductor",
"shl4Conductor",
"shl5Conductor",
"shl6Conductor",
"shl7Conductor",
"svl1Conductor"
};

Char_t phononsL[20]="phononL";
Char_t phononsTF[20]="phononTF";
Char_t phononsTS[20]="phononTS";

Char_t Resonator[50]="ResonatorAssembly_0";

Int_t Phonons_Impact_L[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Int_t labe[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
Int_t Phonons_Impact_TS[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Int_t Phonons_Impact_TF[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Double_t Energy_DepositedL[20]={0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
Double_t Energy_DepositedTF[20]={0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
Double_t Energy_DepositedTS[20]={0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};


TH2F* h_0 = new TH2F("h_0", "h_0 title; X [cm]; Y [cm]", nbinsx, -0.4, 0.4, nbinsx, -0.4, 0.4);
TH2F* h_Calis = new TH2F("h_Calis", "h_0Calis title; X [cm]; Y [cm]", nbinsx, -0.4, 0.4, nbinsx, -0.4, 0.4);
for(Int_t ll=0;ll<nbinsx;ll++){for(Int_t l=0;l<nbinsx;l++){h_0->SetBinContent(ll+1,l+1,0); h_0_F->SetBinContent(ll+1,l+1,0);  h_Calis->SetBinContent(ll+1,l+1,0);}}
Int_t nentries = (Int_t)t1->GetEntries();
Int_t nentries2 = (Int_t)t2->GetEntries();
cout<<"The number of particles created after the phononDownconversion are \t"<<nentries2<<endl;

TH1F* h2_ET = new TH1F("h2_ET", "h2 Phonons Impacted Longitudinal; Sensitive part; # of Phonons ", 40,0,0.03);
TH1F* h3_ET = new TH1F("h3_ET", "h3 Phonons Impacted TF; Sensitive part; # of Phonons ", 40,0,0.03);
TH1F* h4_ET = new TH1F("h4_ET", "h4 Phonons Impacted TS; Sensitive part; # of Phonons ", 40,0,0.03);
for (Int_t i=0; i<nentries2; i++) {
 h_initial->Fill(X_i,Y_i);
  //cout<<Volume_name<<endl;
   t1->GetEntry(i);
   t2->GetEntry(i);

int Calis1=strcmp(Resonator,Volume_name);
if(Calis1==0){h_Calis->Fill(X_i,Y_i);}


  int Pho_Name1 = strcmp(phononsL,Name_particle_F);
  int Pho_Name2 = strcmp(phononsTF,Name_particle_F);
  int Pho_Name3 = strcmp(phononsTS,Name_particle_F);


  int resu0 = strcmp(Sensors[0],Volume_name);
  if(resu0==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){Phonons_Impact_L[0]=Phonons_Impact_L[0]+1;Energy_DepositedL[0]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[0]=Phonons_Impact_TF[0]+1;Energy_DepositedTF[0]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[0]=Phonons_Impact_TS[0]+1;Energy_DepositedTS[0]+=Final_Energy;h4_ET->Fill(Final_Energy);}


  }

  int resu1 = strcmp(Sensors[1],Volume_name);
  if(resu1==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){Phonons_Impact_L[1]=Phonons_Impact_L[1]+1;Energy_DepositedL[1]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[1]=Phonons_Impact_TF[1]+1;Energy_DepositedTF[1]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[1]=Phonons_Impact_TS[1]+1;Energy_DepositedTS[1]+=Final_Energy;h4_ET->Fill(Final_Energy);}

  }

  int resu2 = strcmp(Sensors[2],Volume_name);
  if(resu2==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[2]=Phonons_Impact_L[2]+1;Energy_DepositedL[2]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[2]=Phonons_Impact_TF[2]+1;Energy_DepositedTF[2]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[2]=Phonons_Impact_TS[2]+1;Energy_DepositedTS[2]+=Final_Energy;h4_ET->Fill(Final_Energy);}
  }

  int resu3 = strcmp(Sensors[3],Volume_name);
  if(resu3==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[3]=Phonons_Impact_L[3]+1;Energy_DepositedL[3]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[3]=Phonons_Impact_TF[3]+1;Energy_DepositedTF[3]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[3]=Phonons_Impact_TS[3]+1;Energy_DepositedTS[3]+=Final_Energy;h4_ET->Fill(Final_Energy);}


  }

  int resu4 = strcmp(Sensors[4],Volume_name);
  if(resu4==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[4]=Phonons_Impact_L[4]+1;Energy_DepositedL[4]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[4]=Phonons_Impact_TF[4]+1;Energy_DepositedTF[4]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[4]=Phonons_Impact_TS[4]+1;Energy_DepositedTS[4]+=Final_Energy;h4_ET->Fill(Final_Energy);}


  }

  int resu5 = strcmp(Sensors[5],Volume_name);
  if(resu5==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[5]=Phonons_Impact_L[5]+1;Energy_DepositedL[5]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[5]=Phonons_Impact_TF[5]+1;Energy_DepositedTF[5]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[5]=Phonons_Impact_TS[5]+1;Energy_DepositedTS[5]+=Final_Energy;h4_ET->Fill(Final_Energy);}

}

  int resu6 = strcmp(Sensors[6],Volume_name);
  if(resu6==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[6]=Phonons_Impact_L[6]+1;Energy_DepositedL[6]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[6]=Phonons_Impact_TF[6]+1;Energy_DepositedTF[6]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[6]=Phonons_Impact_TS[6]+1;Energy_DepositedTS[6]+=Final_Energy;h4_ET->Fill(Final_Energy);}



  }

  int resu7 = strcmp(Sensors[7],Volume_name);
  if(resu7==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[7]=Phonons_Impact_L[7]+1;Energy_DepositedL[7]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[7]=Phonons_Impact_TF[7]+1;Energy_DepositedTF[7]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[7]=Phonons_Impact_TS[7]+1;Energy_DepositedTS[7]+=Final_Energy;h4_ET->Fill(Final_Energy);}


  }

  int resu8 = strcmp(Sensors[8],Volume_name);
  if(resu8==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[8]=Phonons_Impact_L[8]+1;Energy_DepositedL[8]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[8]=Phonons_Impact_TF[8]+1;Energy_DepositedTF[8]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[8]=Phonons_Impact_TS[8]+1;Energy_DepositedTS[8]+=Final_Energy;h4_ET->Fill(Final_Energy);}



  }

  int resu9 = strcmp(Sensors[9],Volume_name);
  if(resu9==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[9]=Phonons_Impact_L[9]+1;Energy_DepositedL[9]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[9]=Phonons_Impact_TF[9]+1;Energy_DepositedTF[9]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[9]=Phonons_Impact_TS[9]+1;Energy_DepositedTS[9]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu10 = strcmp(Sensors[10],Volume_name);
  if(resu10==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[10]=Phonons_Impact_L[10]+1;Energy_DepositedL[10]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[10]=Phonons_Impact_TF[10]+1;Energy_DepositedTF[10]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[10]=Phonons_Impact_TS[10]+1;Energy_DepositedTS[10]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}
  int resu11 = strcmp(Sensors[11],Volume_name);
  if(resu11==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[11]=Phonons_Impact_L[11]+1;Energy_DepositedL[11]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[11]=Phonons_Impact_TF[11]+1;Energy_DepositedTF[11]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[11]=Phonons_Impact_TS[11]+1;Energy_DepositedTS[11]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu12 = strcmp(Sensors[12],Volume_name);
  if(resu12==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[12]=Phonons_Impact_L[12]+1;Energy_DepositedL[12]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[12]=Phonons_Impact_TF[12]+1;Energy_DepositedTF[12]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[12]=Phonons_Impact_TS[12]+1;Energy_DepositedTS[12]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu13 = strcmp(Sensors[13],Volume_name);
  if(resu13==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[13]=Phonons_Impact_L[13]+1;Energy_DepositedL[13]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[13]=Phonons_Impact_TF[13]+1;Energy_DepositedTF[13]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[13]=Phonons_Impact_TS[13]+1;Energy_DepositedTS[13]+=Final_Energy;h4_ET->Fill(Final_Energy);}

}

  int resu14 = strcmp(Sensors[14],Volume_name);
  if(resu14==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[14]=Phonons_Impact_L[14]+1;Energy_DepositedL[14]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[14]=Phonons_Impact_TF[14]+1;Energy_DepositedTF[14]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[14]=Phonons_Impact_TS[14]+1;Energy_DepositedTS[14]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu15 = strcmp(Sensors[15],Volume_name);
  if(resu15==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[15]=Phonons_Impact_L[15]+1;Energy_DepositedL[15]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[15]=Phonons_Impact_TF[15]+1;Energy_DepositedTF[15]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[15]=Phonons_Impact_TS[15]+1;Energy_DepositedTS[15]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu16 = strcmp(Sensors[16],Volume_name);
  if(resu16==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[16]=Phonons_Impact_L[16]+1;Energy_DepositedL[16]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[16]=Phonons_Impact_TF[16]+1;Energy_DepositedTF[16]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[16]=Phonons_Impact_TS[16]+1;Energy_DepositedTS[16]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu17 = strcmp(Sensors[17],Volume_name);
  if(resu17==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[17]=Phonons_Impact_L[17]+1;Energy_DepositedL[17]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[17]=Phonons_Impact_TF[17]+1;Energy_DepositedTF[17]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[17]=Phonons_Impact_TS[17]+1;Energy_DepositedTS[17]+=Final_Energy;h4_ET->Fill(Final_Energy);}
}

  int resu18 = strcmp(Sensors[18],Volume_name);
  if(resu18==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[18]=Phonons_Impact_L[18]+1;Energy_DepositedL[18]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[18]=Phonons_Impact_TF[18]+1;Energy_DepositedTF[18]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[18]=Phonons_Impact_TS[18]+1;Energy_DepositedTS[18]+=Final_Energy;h4_ET->Fill(Final_Energy);}



  }

  int resu19 = strcmp(Sensors[19],Volume_name);
  if(resu19==0 ){h_0->Fill(X_i,Y_i);
    if(Pho_Name1==0){ Phonons_Impact_L[19]=Phonons_Impact_L[19]+1;Energy_DepositedL[19]+=Final_Energy;h2_ET->Fill(Final_Energy);}
    if(Pho_Name2==0){Phonons_Impact_TF[19]=Phonons_Impact_TF[19]+1;Energy_DepositedTF[19]+=Final_Energy;h3_ET->Fill(Final_Energy);}
    if(Pho_Name3==0){Phonons_Impact_TS[19]=Phonons_Impact_TS[19]+1;Energy_DepositedTS[19]+=Final_Energy;h4_ET->Fill(Final_Energy);}
  }









 }


TCanvas *c2=new TCanvas();
h_0->Draw("colz");

////////Counting the Energy Deposited by part of the Resonator_0.
// I am going to fill with Numbers for the moment.
TH1F* h1 = new TH1F("h1", "h1 Energy Deposited; Sensitive part; Total Energy", 20,1,20);
TH1F* h2 = new TH1F("h2", "h2 Phonons Impacted Longitudinal; Sensitive part; # of Phonons ", 5,0,10);
TH1F* h3 = new TH1F("h3", "h3 Phonons Impacted TF; Sensitive part; # of Phonons ", 5,0,10);
TH1F* h4 = new TH1F("h4", "h4 Phonons Impacted TS; Sensitive part; # of Phonons ", 5,0,10);
////////////////////////Histograsm of Energy Deposited///////////////////
TH1F* h2_E = new TH1F("h2_E", "h2 Phonons Impacted Longitudinal; Sensitive part; # of Phonons ", 5,0,10);
TH1F* h3_E = new TH1F("h3_E", "h3 Phonons Impacted TF; Sensitive part; # of Phonons ", 5,0,10);
TH1F* h4_E = new TH1F("h4_E", "h4 Phonons Impacted TS; Sensitive part; # of Phonons ", 5,0,10);
///Histogrmas of the Spectrum of the Energy


///Histogrmas of the Spectrum of the Energy

Double_t Total_PhononsL=0;
Double_t Total_PhononsTF=0;
Double_t Total_PhononsTS=0;


Double_t Energy_Total_PhononsL=0;
Double_t Energy_Total_PhononsTF=0;
Double_t Energy_Total_PhononsTS=0;

for(Int_t ll=0;ll<20;ll++){//h1->SetBinContent(ll+1,Energy_Deposited[ll]);
  h2->Fill(Sensors_Names[ll],0);
  h2->SetBinContent(ll+1,Phonons_Impact_L[ll]);
  h3->Fill(Sensors_Names[ll],0);
  h3->SetBinContent(ll+1,Phonons_Impact_TF[ll]);
  h4->Fill(Sensors_Names[ll],0);
  h4->SetBinContent(ll+1,Phonons_Impact_TS[ll]);
///////////////////////////////////
h2_E->Fill(Sensors_Names[ll],0);
h2_E->SetBinContent(ll+1,Energy_DepositedL[ll]);
h3_E->Fill(Sensors_Names[ll],0);
h3_E->SetBinContent(ll+1,Energy_DepositedTF[ll]);
h4_E->Fill(Sensors_Names[ll],0);
h4_E->SetBinContent(ll+1,Energy_DepositedTS[ll]);
//////////////////////////////////////////
Total_PhononsL+=Phonons_Impact_L[ll];
Total_PhononsTF+=Phonons_Impact_TF[ll];
Total_PhononsTS+=Phonons_Impact_TS[ll];

Energy_Total_PhononsL+=Energy_DepositedL[ll];
Energy_Total_PhononsTF+=Energy_DepositedTF[ll];
Energy_Total_PhononsTS+=Energy_DepositedTS[ll];
}

cout<<"The total Phonons Impacted on the Sensitive area are"<<endl;
cout<<Total_PhononsL<<"\t"<<Total_PhononsTF<<"\t"<<Total_PhononsTS<<endl;
cout<<Energy_Total_PhononsL<<"\t"<<Energy_Total_PhononsTF<<"\t"<<Energy_Total_PhononsTS<<endl;


THStack *hs=new THStack("hs","histograms;; # of Phonons");
h2->SetStats(0);
h3->SetStats(0);
h4->SetStats(0);
  h2->SetCanExtend(TH1::kAllAxes);
    h3->SetCanExtend(TH1::kAllAxes);
      h4->SetCanExtend(TH1::kAllAxes);
h2->SetLineColor(kRed);
hs->Add(h2);
h3->SetLineColor(kBlue);
      hs->Add(h3);
      h4->SetLineColor(kGreen);
      hs->Add(h4);
      TCanvas *c3=new TCanvas();
      hs->Draw("nostack");

// TGraph *Long= new TGraph(20,labe,Phonons_Impact_L);
// Long->SetMarkerSize(1.3);
// Long->SetMarkerColor(7);
// Long->Draw();

auto legend = new TLegend(0.1,0.7,0.48,0.9);
legend->SetHeader("# of Phonons Impacted on Sensitive Area of Qubit","C"); // option "C" allows to center the header
legend->AddEntry("h2","Longitudinal","l");
legend->AddEntry("h3","Transverse Fast","l");
legend->AddEntry("h4","Transverse Slow","l");
legend->Draw();
///////////////////////////??Energy Deposited///////////////////

THStack *hs_E=new THStack("hs_E","histograms;; Energy [eV]");
h2_E->SetStats(0);
h3_E->SetStats(0);
h4_E->SetStats(0);
  h2_E->SetCanExtend(TH1::kAllAxes);
    h3_E->SetCanExtend(TH1::kAllAxes);
      h4_E->SetCanExtend(TH1::kAllAxes);
h2_E->SetLineColor(kRed);
hs_E->Add(h2_E);
h3_E->SetLineColor(kBlue);
      hs_E->Add(h3_E);
      h4_E->SetLineColor(kGreen);
      hs_E->Add(h4_E);
      TCanvas *c3_E=new TCanvas();
      hs_E->Draw("nostack");

// TGraph *Long= new TGraph(20,labe,Phonons_Impact_L);
// Long->SetMarkerSize(1.3);
// Long->SetMarkerColor(7);
// Long->Draw();

auto legend_E = new TLegend(0.1,0.7,0.48,0.9);
legend_E->SetHeader("# of Phonons Impacted on Sensitive Area of Qubit Energy","C"); // option "C" allows to center the header
legend_E->AddEntry("h2_E","Longitudinal","l");
legend_E->AddEntry("h3_E","Transverse Fast","l");
legend_E->AddEntry("h4_E","Transverse Slow","l");
legend_E->Draw();

//////////////////////////////////////////Total Spectrum of Energy Deposited///////////////////////
THStack *hs_ET=new THStack("hs_ET","histograms;Energy [eV]; Counts");
h2_ET->SetStats(0);
h3_ET->SetStats(0);
h4_ET->SetStats(0);
  h2_ET->SetCanExtend(TH1::kAllAxes);
    h3_ET->SetCanExtend(TH1::kAllAxes);
      h4_ET->SetCanExtend(TH1::kAllAxes);
h2_ET->SetLineColor(kRed);
hs_ET->Add(h2_ET);
h3_ET->SetLineColor(kBlue);
      hs_ET->Add(h3_ET);
      h4_ET->SetLineColor(kGreen);
      hs_ET->Add(h4_ET);
      TCanvas *c3_ET=new TCanvas();
      hs_ET->Draw("nostack");

// TGraph *Long= new TGraph(20,labe,Phonons_Impact_L);
// Long->SetMarkerSize(1.3);
// Long->SetMarkerColor(7);
// Long->Draw();

auto legend_ET= new TLegend(0.1,0.7,0.48,0.9);
legend_ET->SetHeader("# of Phonons Impacted on Sensitive Area of Qubit Energy Total","C"); // option "C" allows to center the header
legend_ET->AddEntry("h2_ET","Longitudinal","l");
legend_ET->AddEntry("h3_ET","Transverse Fast","l");
legend_ET->AddEntry("h4_ET","Transverse Slow","l");
legend_ET->Draw();


////////////////////////////Generating the Plot Density Probability Function
//Plotting the Initial Positon of the Phonons

for(Int_t ll=0;ll<nbinsx;ll++){for(Int_t l=0;l<nbinsx;l++){
if(h_initial->GetBinContent(ll+1,l+1) ==0){

  h_0_F->SetBinContent(ll+1,l+1, 0 );
}
else{
  h_0_F->SetBinContent(ll+1,l+1,h_Calis->GetBinContent(ll+1,l+1)/h_initial->GetBinContent(ll+1,l+1)        );}
}

}



TCanvas *c15=new TCanvas();
h_0_F->Draw("colz");



}
