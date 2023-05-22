//This is a Calis program to calcualte the potential probability of a Potential
// Printing the Indixes to check that they are right!
// Now This program Works for every 
void Potential_Probability_Qubits_2(){

Int_t NX=10;
Int_t NY=10;

Int_t NX_Qubits=-5;
Int_t NY_Qubits=0;
//Defining the Coordinates of the Arrey





//Defining firts withou include the zero and all the Points
//Definig an Array of 36
//The Value of K is equal to K/NX
// New Definition of K

cout<<"Maximum Number of equipotential lines \t"<<NX/2<<endl;
cout<< "Maximum Values of K \t"<<NX/2-2<<endl;
Double_t Ar[NX][NY];
Int_t L=0;
for(Int_t j=0;j<NY;j++){for(Int_t i=0;i<NX;i++){Ar[i][j]=L+1;L=L+1;}}
// for(Int_t j=0;j<NY;j++){for(Int_t i=0;i<NX;i++){cout<<i<<"\t"<<j<<"\t"<<Ar[i][j]<<endl;}}




Double_t T_odd=0;

//Calculating the Probability for the K-esimo potnsl
Int_t k=1;
Int_t c=0;
for(Int_t j=-2*k+1;j<2*k;j++){
for(Int_t i=-2*k+1;i<2*k-1;i++){

if(j<0 && NX/2+i<NX && NY/2+j<NX  && (NX/2+i+NX_Qubits)>=0 && (NY/2+j+NY_Qubits)>0){
cout<<c<<"\t"<<i<<"\t"<<j<<"\t"<<NX/2+i+NX_Qubits<<"\t"<<NY/2+j+NY_Qubits<<endl;

cout<<Ar[NX/2+i +NX_Qubits][NX/2+j+NY_Qubits]<<endl;
c=c+1;
T_odd+=Ar[NX/2+i+NX_Qubits][NX/2+j+NY_Qubits];
}
if(j>0 && NX/2+i<NX && NX/2+j<NX  && (NX/2+i+NX_Qubits)>=0 && (NX/2+j+NY_Qubits)>0){cout<<c<<"\t"<<i<<"\t"<<j<<"\t"<<NX/2+i+NX_Qubits<<"\t"<<NY/2+j+NY_Qubits<<endl;

cout<<Ar[NX/2+i+NX_Qubits][NX/2-1+j+NY_Qubits]<<endl;
c=c+1;T_odd+=Ar[NX/2+i+NX_Qubits][NX/2-1+j+NY_Qubits];}


}
}


Double_t T_even=0;
if(k+2<NX/2){
cout<<"K even"<<endl;
k=k+1;
c=0;
//Definig the total Sum of the Potential


cout<<"K even"<<endl;
for(Int_t j=-2*k+2;j<2*k-1;j++){
for(Int_t i=-2*k+2;i<2*k-2;i++){


if(j<0 && NX/2+i<NX && NY/2+j<NX  && (NX/2+i+NX_Qubits)>=0 && (NY/2+j+NY_Qubits)>0){
cout<<c<<"\t"<<i<<"\t"<<j<<"\t"<<NX/2+i+NX_Qubits<<"\t"<<NY/2+j+NY_Qubits<<endl;
cout<<Ar[NX/2+i+NX_Qubits][NX/2+j+NY_Qubits]<<endl;
c=c+1;
T_even+=Ar[NX/2+i +NX_Qubits][NX/2+j+NY_Qubits];
}
if(j>0 && NX/2+i<NX && NX/2+j<NX  && (NX/2+i+NX_Qubits)>=0 && (NX/2+j+NY_Qubits)>0){cout<<c+1<<"\t"<<i<<"\t"<<j<<endl;
cout<<Ar[NX/2+i+NX_Qubits][NX/2-1+j+NY_Qubits]<<endl;
c=c+1;T_even+=Ar[NX/2+i+NX_Qubits][NX/2-1+j+NY_Qubits];}

}


}
}
cout<<"The total Sum of the second array is\t"<<T_odd<<"\t"<<T_even<<endl;


}
