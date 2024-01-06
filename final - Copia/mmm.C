#include "Particle.hpp"


void makeParticle(Particle* particle, int n, TH1F *h2, TH1F *h3){
(*particle).SetfIndex(n);
double phi=gRandom->Uniform(0,2*TMath::Pi());
double theta=gRandom->Uniform(0,TMath::Pi());
double impulse=gRandom->Exp(1);

(*particle).SetP(impulse*sin(theta)*cos(phi),impulse*sin(theta)*sin(phi),impulse*cos(theta));

h2->Fill(phi); 
h3->Fill(theta); 

}


void mmm(){

gRandom->SetSeed();


Particle::AddParticleType("pione+",0.13957,+1,0);
Particle::AddParticleType( "pione-",0.13957,-1,0);
Particle::AddParticleType( "kaone+",0.49367,+1,0);
Particle::AddParticleType( "kaone-",0.49367,-1,0);
Particle::AddParticleType( "protone+",0.93827,+1,0);
Particle::AddParticleType( "protone-",0.93827,-1,0);
Particle::AddParticleType( "risonanza",0.89166,0,0.050);



TH1F *h1 = new TH1F("abbondanza di particelle","", Particle::fParticleType.size(), 0, Particle::fParticleType.size());
TH1F *h2 = new TH1F("angoli azitumali","", 10000, 0,2*TMath::Pi());
TH1F *h3 = new TH1F("angoli polari","", 10000, 0,TMath::Pi());
TH1F *h4 = new TH1F("impulso","", 10000,0,2);
TH1F *h5 = new TH1F("impulso trasverso","", 10000,0,2);
TH1F *h6 = new TH1F("energia","", 10000,0, 2);
TH1F *h7 = new TH1F("invariante di massa","", 10000,0,1e1);
TH1F *h8 = new TH1F("massa invarianti di particelle discorde","", 1000,0,8);
TH1F *h9 = new TH1F("massa invarianti di particelle concorde","", 1000,0,8);
TH1F *h10 = new TH1F("kaone+- pione+- discordi","", 10000,0,1e1);
TH1F *h11 = new TH1F("kaone+- pione+- concordi","", 10000,0,1e1);
TH1F *h12 = new TH1F("risonanza","", 10000,0,1.5);

h1->GetXaxis()->SetTitle("tipi di particella");
h1->GetYaxis()->SetTitle("occorrenze");

h2->GetXaxis()->SetTitle("angolo (rad)");
h2->GetYaxis()->SetTitle("occorrenze");

h3->GetXaxis()->SetTitle("angolo (rad)");
h3->GetYaxis()->SetTitle("occorrenze");

h4->GetXaxis()->SetTitle("impulso (kg*m/s)");
h4->GetYaxis()->SetTitle("occorrenze");

h5->GetXaxis()->SetTitle("impulso (kg*m/s)");
h5->GetYaxis()->SetTitle("occorrenze");

h6->GetXaxis()->SetTitle("energia (GeV)");
h6->GetYaxis()->SetTitle("occorrenze");

h7->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h7->GetYaxis()->SetTitle("occorrenze");

h8->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h8->GetYaxis()->SetTitle("occorrenze");

h9->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h9->GetYaxis()->SetTitle("occorrenze");

h10->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h10->GetYaxis()->SetTitle("occorrenze");

h11->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h11->GetYaxis()->SetTitle("occorrenze");

h12->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
h12->GetYaxis()->SetTitle("occorrenze");


h1->Sumw2();
h2->Sumw2();
h3->Sumw2();
h4->Sumw2();
h5->Sumw2();
h6->Sumw2();
h7->Sumw2();
h8->Sumw2();
h9->Sumw2();
h10->Sumw2();
h11->Sumw2();
h12->Sumw2();



Particle EventParticles[300];

int count{0};

 for (int i=0;i<100000;i++)
{
 count=0;
 
   for(int j=0;j<100; j++) 
   {
    
   double x=gRandom->Rndm();
  
   if(x<0.4)
   {
    makeParticle(&EventParticles[j],0,h2,h3);
   }
  
   else if(x<0.8)
   {
   
    makeParticle(&EventParticles[j],1,h2,h3);


   }
   else if(x<0.85)
   {
    makeParticle(&EventParticles[j],2,h2,h3);


   }
   else if(x<0.9)
   {
    makeParticle(&EventParticles[j],3,h2,h3);


   }
   else if(x<0.945)
   {
    makeParticle(&EventParticles[j],4,h2,h3);


   }
   else if(x<0.99)
   {
    makeParticle(&EventParticles[j],5,h2,h3);


   }
  
   else
   {
    makeParticle(&EventParticles[j],6,h2,h3);
     
    double y=gRandom->Rndm();
  
     if(y<0.5)
     {

       Particle* a= new Particle("pione+",0.13957,+1,0);
       Particle* b=new Particle("kaone-",0.49367,-1,0);

       int z=EventParticles[j].Decay2body(*a, *b);
      
       if(z==0)
       {
          EventParticles[100+count]=*a;
          EventParticles[101+count]=*b;

          count+=2;
       }
    

   
     }

else{

  Particle* a= new Particle("pione-",0.13957,-1,0);
  Particle* b=new Particle("kaone+",0.49367,+1,0);
   
  int z=EventParticles[j].Decay2body(*a, *b);
       
  if(z==0)
       {
    EventParticles[100+count]=*a;
    EventParticles[101+count]=*b;

    count+=2;
       }
    
}



   }//fine else
    

h1->Fill(EventParticles[j].GetfIndex()); 
h4->Fill(EventParticles[j].GetImpulse());
h5->Fill(std::sqrt(EventParticles[j].GetPx()*EventParticles[j].GetPx()  +EventParticles[j].GetPy()*EventParticles[j].GetPy()          ));
h6->Fill(EventParticles[j].GetEnergy());


  }//fine secondo for (j)

    Particle p("particle",0,0,0);


for(int m=0;m<100+count;m++){
for(int n=m+1;n<100+count;n++){
  if(EventParticles[m].GetfIndex()!=6 && EventParticles[n].GetfIndex()!=6)
    {
      double invmass=EventParticles[m].InvMass(EventParticles[n]);

      h7->Fill(invmass);

  if((p.fParticleType[EventParticles[m].GetfIndex()])->GetCharge()*(p.fParticleType[EventParticles[n].GetfIndex()])->GetCharge()<0)
    {
      h8->Fill(invmass);

    }
  else
    {
      h9->Fill(invmass);

    }
  const char* p1=(p.fParticleType[EventParticles[m].GetfIndex()])->GetName();
  const char* p2=(p.fParticleType[EventParticles[n].GetfIndex()])->GetName();


  if (p1 && p2) {

  if(
  (std::strcmp(p1,"pione+")==0&&std::strcmp(p2,"kaone-")==0)||
  (std::strcmp(p1,"pione-")==0&&std::strcmp(p2,"kaone+")==0)||
  (std::strcmp(p1,"kaone+")==0&&std::strcmp(p2,"pione-")==0)||
  (std::strcmp(p1,"kaone-")==0&&std::strcmp(p2,"pione+")==0)
  ){
    h10->Fill(invmass);

  }

  if(
  (std::strcmp(p1,"pione+")==0&&std::strcmp(p2,"kaone+")==0)||
  (std::strcmp(p1,"pione-")==0&&std::strcmp(p2,"kaone-")==0)||
  (std::strcmp(p1,"kaone+")==0&&std::strcmp(p2,"pione+")==0)||
  (std::strcmp(p1,"kaone-")==0&&std::strcmp(p2,"pione-")==0)
  ){
    h11->Fill(invmass);
  }

}

}}
}

/*for(int j=100;j<100+count;j++){
    for(int s=j+1;s<100+count;s+=2){
double invmass=EventParticles[j].InvMass(EventParticles[s]);
h8->Fill(invmass);
h10->Fill(invmass);}}*/

for(int i=100;i<100+count;i+=2){

double invmass=EventParticles[i].InvMass(EventParticles[i+1]);

h12->Fill(invmass);

}
} ///fine primo for (i)

std::cout <<"\n qui sotto vengono stampati i dati di analisi: \n";

TCanvas*canvas1=new TCanvas("canvas  1","Canvas1",800,500);
h1->Draw("E");
canvas1->Draw();
for(int i=0; i<8;i++){
std::cout<< h1->GetBinContent(i)<<"+/-"<<h1->GetBinError(i)<<"\n";}


TCanvas*canvas2=new TCanvas("canvas 2","Canvas2",800,500);
h2->Draw();
canvas2->Draw();


TCanvas*canvas3=new TCanvas("canvas 3 ","Canvas3",800,500);
h3->Draw();
canvas3->Draw();


TCanvas*canvas4=new TCanvas("canvas 4 ","Canvas4",800,500);
h4->Draw();
canvas4->Draw();


TCanvas*canvas5=new TCanvas("canvas 5 ","Canvas5",800,500);
h5->Draw();
canvas5->Draw();


TCanvas*canvas6=new TCanvas("canvas 6 ","Canvas6",800,500);
h6->Draw();
canvas6->Draw();


TCanvas*canvas7=new TCanvas("canvas 7 ","Canvas7",800,500);
h7->Draw();
canvas7->Draw();

TCanvas*canvas8=new TCanvas("canvas 8 ","Canvas8",800,500);
h8->Draw();
canvas8->Draw();

TCanvas*canvas9=new TCanvas("canvas 9 ","Canvas9",800,500);
h9->Draw();
canvas9->Draw();


TCanvas*canvas10=new TCanvas("canvas 10 ","Canvas10",800,500);
h10->Draw();
canvas10->Draw();

TCanvas*canvas11=new TCanvas("canvas 11 ","Canvas11",800,500);
h11->Draw();
canvas11->Draw();

TCanvas*canvas12=new TCanvas("canvas 12 ","Canvas12",800,500);
h12->Draw();
canvas12->Draw();


 TFile *outputFile = new TFile("output.root", "RECREATE");

    // Salva i canvas nel file
    h1->Write();
    h2->Write();
    h3->Write();
    h4->Write();
    h5->Write();
    h6->Write();
    h7->Write();
    h8->Write();
    h9->Write();
    h10->Write();
    h11->Write();
    h12->Write();


    // Chiudi il file
    outputFile->Close();

}