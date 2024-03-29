//Program to Analyse the TS phonon only form Python for Silicon for te moment
#include <string>
Double_t *Vector_In_Paral(Double_t *V,Double_t theta,Double_t phi){
  //Rotation around Z axis

  Double_t Tra[3][3]={{TMath::Cos(phi),-TMath::Sin(phi),0}
, {TMath::Sin(phi),TMath::Cos(phi),0}, {0,0,1}};
//Rotation on Y AXis
Double_t Tra2[3][3]={{TMath::Cos(theta),0,TMath::Sin(theta)}
, {0,1,0}, {-TMath::Sin(theta),0,TMath::Cos(theta)}};





Double_t *TryV_p = new Double_t[3];
Double_t *TryV_p2 = new Double_t[3];
TryV_p[0]=0.0;
TryV_p[1]=0.0;
TryV_p[2]=0.0;
TryV_p2[0]=0.0;
TryV_p2[1]=0.0;
TryV_p2[2]=0.0;

  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          //cout<<(Tra[i][j])<<endl;
          TryV_p[i]+=Tra[i][j]*V[j];

      }

  }
//Rotation around Y axis

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //cout<<(Tra[i][j])<<endl;
            TryV_p2[i]+=Tra2[i][j]*TryV_p[j];

        }

    }



return TryV_p2;

}

Double_t CO_Normal(Double_t *V,Double_t *N){
Double_t theta;
Double_t V_N;
Double_t N_N;
V_N=TMath::Abs(TMath::Sqrt(V[0]*V[0]+V[1]*V[1]+V[2]*V[2]));
N_N=TMath::Abs(TMath::Sqrt(N[0]*N[0]+N[1]*N[1]+N[2]*N[2]));
Double_t VN;
VN=V[0]*N[0]+V[1]*N[1]+V[2]*N[2];
theta=TMath::ACos(VN/(V_N*N_N));
return theta;
}



class OpenFiless{
public:
   TString nameFile;
 TString  RootFile;

  OpenFiless( TString name){};
  void GenerateRoot( TString  nameFile, TString  RootFile);
  void PlotPhonons_velocities(TString RootFile);
};
void OpenFiless::GenerateRoot( TString  nameFile,  TString  RootFile){
  ifstream in;
  TString B= nameFile;
  in.open(Form(B));
  Int_t nlines = 0;
   TString   A= RootFile;
   Double_t PX_i,PY_i,PZ_i;
   //Double_t VX1_Phonon,VY1_Phonon,VZ1_Phonon,VX2_Phonon,VY2_Phonon,VZ2_Phonon,VX3_Phonon,VY3_Phonon,VZ3_Phonon;
  TFile *f =  new TFile(A,"RECREATE");
  TNtuple *ntuple=new TNtuple("ntuple","data from ascii file","PX_i:PY_i:PZ_i");
  //Run ID,Event ID,Track ID,Particle Name,Start Energy [eV],Start X [m],Start Y [m],Start Z [m],Start Time [ns],Energy Deposited [eV],Track Weight,End X [m],End Y [m],End Z [m],Final Time [ns]

  while (1) {
     //in>>VX1_Phonon>>VY1_Phonon>>VZ1_Phonon>>VX2_Phonon>>VY2_Phonon>>VZ2_Phonon>>VX3_Phonon>>VY3_Phonon>>VZ3_Phonon;
     in>>PX_i>>PY_i>>PZ_i;

     if (!in.good()) break;
     //if (nlines < 5) printf("I_Energy=%8f,X_i=%8f,Y_i=%8f,Z_i=%8f,t_i=%8f,E_De=%8f,X_f=%8f,Y_f=%8f,Z_f=%8f,t_f=%8f\n",I_Energy,X_i,Y_i,Z_i,t_i,E_De,X_f,Y_f,Z_f,t_f);

     //ntuple->Fill(VX1_Phonon,VY1_Phonon,VZ1_Phonon,VX2_Phonon,VY2_Phonon,VZ2_Phonon,VX3_Phonon,VY3_Phonon,VZ3_Phonon);
      ntuple->Fill( PX_i,PY_i,PZ_i);
     nlines++;
  }
  printf(" found %d points\n",nlines);

ntuple->Draw("PZ_:i:PX_i:PY_i");



in.close();

  f->Write();


}

void OpenFiless::PlotPhonons_velocities(TString RootFile){
// read the Tree generated by tree1w and fill two histograms
// note that we use "new" to create the TFile and TTree objects,
// to keep them alive after leaving this function.
TFile *f = new TFile(RootFile);
TTree *t1 = (TTree*)f->Get("Momentum");



Double_t  PX_i,PY_i,PZ_i;
Double_t  PX_k,PY_k,PZ_k;
Double_t  PX_l,PY_l,PZ_l;
 Double_t PX2_i,PY2_i,PZ2_i;
 Double_t PX3_i,PY3_i,PZ3_i;
 Double_t VX1_Phonon,VY1_Phonon,VZ1_Phonon;

 t1->SetBranchAddress("PX_i",&PX_i);
 t1->SetBranchAddress("PY_i",&PY_i);
 t1->SetBranchAddress("PZ_i",&PZ_i);
 //
 // t1->SetBranchAddress("PX_k",&PX_k);
 // t1->SetBranchAddress("PY_k",&PY_k);
 // t1->SetBranchAddress("PZ_k",&PZ_k);
 //
 // t1->SetBranchAddress("PX_l",&PX_l);
 // t1->SetBranchAddress("PY_l",&PY_l);
 // t1->SetBranchAddress("PZ_l",&PZ_l);


//

// TCanvas *c3 = new TCanvas("c3","c3",600,800);
// t1->Draw("PZ_i:(PY_i-PX_i)/2:(PY_i+PX_i)/2");
//
// TCanvas *c33 = new TCanvas("c33","c33",600,800);
// // t1->Draw("PZ_i:(PY_i-PX_i)/2");
// t1->Draw("PZ_k:(PY_k-PX_k)/2:(PY_k+PX_k)/2");
// TCanvas *c333 = new TCanvas("c333","c333",600,800);
//  // t1->Draw("PZ_i:(PY_i+PX_i)/2");
// t1->Draw("PZ_l:(PY_l-PX_l)/2:(PY_l+PX_l)/2");
//  TCanvas *c00 = new TCanvas("c00","c00",600,800);
//   // t1->Draw("(PY_i+PX_i)/2:(PY_i-PX_i)/2");
TCanvas *c33 = new TCanvas("c33","c33",600,800);
t1->Draw("PZ_i/TMath::Sqrt(TMath::Abs(PZ_i*PZ_i+PX_i*PX_i+PY_i*PY_i)):(PX_i-PY_i)*0.707/TMath::Sqrt(TMath::Abs(PZ_i*PZ_i+PX_i*PX_i+PY_i*PY_i)):(PX_i+PY_i)*0.707/TMath::Sqrt(TMath::Abs(PZ_i*PZ_i+PX_i*PX_i+PY_i*PY_i))","PZ_i>0  && (PX_i+PY_i)*0.707>-03");
t1->Draw("PZ_i:PY_i:PX_i");

//t1->Draw("VZ1_Phonon:(VY1_Phonon-VX1_Phonon)/2:(VY1_Phonon+VX1_Phonon)/2");
//t1->Draw("VZ1_Phonon:(VY1_Phonon-VX1_Phonon)/2:(VY1_Phonon+VX1_Phonon)/2");
Double_t X_sa;
Double_t Y_sa;
Double_t Z_sa;

// create two histograms

Double_t n[3]={1,1,1};
Double_t r=TMath::Sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
Double_t theta=TMath::Pi()/2-TMath::ACos(n[2]/r);
Double_t rr=TMath::Sqrt(n[0]*n[0]+n[1]*n[1]);
Double_t phi= TMath::ACos(n[0]/rr);
cout<<theta*180/3.14159<<endl;
cout<<phi*180/3.14159<<endl;

//Filling the Matrix of transformation
Double_t Tra[3][3]={{TMath::Sin(theta)*TMath::Cos(phi),TMath::Sin(theta)*TMath::Sin(phi),TMath::Cos(theta)}
, {TMath::Cos(theta)*TMath::Cos(phi),TMath::Cos(theta)*TMath::Sin(phi),-TMath::Sin(theta)}, {-TMath::Sin(phi),TMath::Cos(phi),0}};
Double_t TryV[3]={1,0,0};
Double_t TryV_p[3]={1,0,0};

for(int i = 0; i < 3; i++){
 for(int j = 0; j < 3; j++){
   //  cout<<(Tra[i][j])<<endl;
     TryV_p[i]+=Tra[i][j]*TryV[j];}}
Double_t *PP;
// PP=Vector_In_Paral(TryV,theta,phi);

//
// for(int i = 0; i < 3; i++){cout<<PP[i]<<"\t"<<TryV_p[i]<<endl;}
//
/////Testing the Dot product
Double_t TryV_ptest[3]={-1,-1,0};
cout<<"The angle is \t "<<180*CO_Normal(TryV,TryV_ptest)/TMath::Pi()<<endl;










///Pnly for the momern
Double_t A;
Double_t B;

TH3D *Momen = new TH3D("Momen","Momemtum Space",100,-1,1,100,-1,1,100,-1,1);
 TH2D *Momen2 = new TH2D("Momen2","Momemtum Space2",400,-1,1,400,-1,1);
//read all entries and fill the histograms
Int_t nentries = (Int_t)t1->GetEntries();
cout<<nentries<<endl;
for (Int_t i=0; i<nentries; i++) {
   t1->GetEntry(i);
   //cout<<"The valiue of "<<PX_i<<PY_i<<PZ_i<<endl;
   // TryV[0]=1.414213562*0.5*(PX_i+PY_i);
   // TryV[1]=1.414213562*0.5*(PX_i-PY_i);
   // TryV[2]=PZ_i;


//For Sapphire
    // Momen->Fill((PX_k+PY_k),(PX_k-PY_k),PZ_k);
    //   Momen2->Fill((PX_l+PY_l)/2,(PX_l-PY_l)/2);
//Fpor Silicon

A=TMath::Abs(PZ_i*PZ_i+PX_i*PX_i+PY_i*PY_i);
B=TMath::Sqrt(A);
      //Momen->Fill(PZ_i/B,0.5*(PY_i+PX_i)/B,0.5*(PX_i-PY_i)/B);
      // TryV[0]=0.707*(PX_i+PY_i)/B;
      // TryV[1]=0.707*(PX_i-PY_i)/B;
      // TryV[2]=PZ_i/B;

      TryV[0]=PX_i/B;
      TryV[1]=PY_i/B;
      TryV[2]=PZ_i/B;

       Momen->Fill(TryV[0],TryV[1],TryV[2]);
    //  ntuple->Draw("(PX_i-PY_i)/2:(PX_i+PY_i)/2","PZ_i>0 && (PX_i+PY_i)/2>0");
//if(PZ_i>0){Momen2->Fill(0.707*(PX_i+PY_i)/B,0.707*(PX_i-PY_i)/B);}
 PP=Vector_In_Paral(TryV,theta,phi);
if(PP[2]>0 ){


 //Momen->Fill(TryV[0],TryV[1],TryV[2]);
//cout<<PX_i/0.005<<"\t"<<PP[2]<<"\t"<<TryV[0]<<endl;
Momen2->Fill(-PP[0],-PP[1]);
//Momen2->Fill(TryV[2],TryV[0]);
}

}
//
// // Int_t nentries2 = (Int_t)t2->GetEntries();
// // for (Int_t i=0; i<nentries2; i++) {
// //    t2->GetEntry(i);
// //    X_sa=PX2_i;
// //    Y_sa=-PX2_i+PY2_i;
// //    Z_sa=PZ2_i;
// //   Momen->Fill(PZ2_i,Y_sa,X_sa);
// //    if(PZ_i>0 && PX_i>0){
// //   //  Momen2->Fill(X_sa,Z_sa);}
// // //Momen2->Fill(Y_sa,Z_sa);
// // }
// //
// // }
// //
// //




      TCanvas *c1 = new TCanvas("c1","c1",600,800);
    Momen->SetXTitle(" ");
   Momen->SetYTitle("  ");
     Momen->SetZTitle("");
Momen->Draw("BOX2Z");
TCanvas *c2 = new TCanvas("c2","c2",600,800);
Momen2->SetXTitle("Momentum X");
Momen2->SetYTitle("Momemtum Y  ");
Momen2->Draw("colz");





}



void Phonons_Caustic(){
printf("Let me check\n" );

TString  Holes="Phonons_Velocities_TS_Sapphire.txt";
OpenFiless *Ca=new OpenFiless(Holes);
//TString H2="Phonon_Velocities.root";
TString H2="out0_TS.root";
//Checking the Rotation
// Double_t n[3]={1,1,0};
// Double_t r=TMath::Sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
// Double_t theta=TMath::ACos(n[2]/r);
// Double_t rr=TMath::Sqrt(n[0]*n[0]+n[1]*n[1]);
// Double_t phi=TMath::ACos(n[0]/rr);
// cout<<"The angle is \t "<<180*theta/TMath::Pi()<<endl;
// cout<<"The angle is \t "<<180*phi/TMath::Pi()<<endl;
// Double_t *PP;
// PP=Vector_In_Paral(n,-1*theta, -1*phi);
//
// cout<<PP[0]<<"\t"<<PP[1]<<"\t"<<PP[2]<<endl;
//Ca->GenerateRoot(Holes,H2);
Ca->PlotPhonons_velocities(H2);
}
