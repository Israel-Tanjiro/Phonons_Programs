

#include "Riostream.h"






void Energy_Plots() {
// read file $ROOTSYS/tutorials/tree/basic.dat
// this file has 3 columns of float data

  ifstream in;
  in.open(Form("Phonons_TL.txt"));


  Float_t I_Energy,X_i,Y_i,Z_i,t_i,E_De,X_f,Y_f,Z_f,t_f;
  Int_t nlines = 0;
  TFile *f =  new TFile("Phonons_TL.root","RECREATE");
  TH1F *h1=new TH1F("h1","x distribution",100,-4,4);
  TNtuple *ntuple=new TNtuple("ntuple","data from ascii file","I_Energy:X_i:Y_i:Z_i:t_i:E_De:X_f:Y_f:Z_f:t_f");
  //Run ID,Event ID,Track ID,Particle Name,Start Energy [eV],Start X [m],Start Y [m],Start Z [m],Start Time [ns],Energy Deposited [eV],Track Weight,End X [m],End Y [m],End Z [m],Final Time [ns]

  while (1) {
     in>>I_Energy>>X_i>>Y_i>>Z_i>>t_i>>E_De>>X_f>>Y_f>>Z_f>>t_f;
     if (!in.good()) break;
     if (nlines < 5) printf("I_Energy=%8f,X_i=%8f,Y_i=%8f,Z_i=%8f,t_i=%8f,E_De=%8f,X_f=%8f,Y_f=%8f,Z_f=%8f,t_f=%8f\n",I_Energy,X_i,Y_i,Z_i,t_i,E_De,X_f,Y_f,Z_f,t_f);
     h1->Fill(I_Energy);
     ntuple->Fill(I_Energy,X_i,Y_i,Z_i,t_i,E_De,X_f,Y_f,Z_f,t_f);
     nlines++;
  }
  printf(" found %d points\n",nlines);
  //ntuple->SetMarkerColor(5);
    ntuple->SetMarkerColor(4);
//  ntuple->Draw("Z_f:X_f:Y_f");
  ntuple->Draw("E_De:X_f:Y_f","E_De>0.01");


   TPaveText *l4 = new TPaveText(-0.9,0.5,0.9,0.95);
   //l4->SetFillColor(42);
   //l4->SetTextAlign(12);
   //l4->AddText("You can interactively rotate this view in 2 ways:");
  // l4->AddText("  - With the RotateCube in clicking in this pad");
   //l4->AddText("  - Selecting View with x3d in the View menu");
  // l4->Draw();


  in.close();

  f->Write();




}
