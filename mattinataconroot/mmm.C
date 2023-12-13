#include "Particle.hpp"
#include <TH1F.h>
#include <TCanvas.h>
#include <cstring>




void mmm(){
int c1{0};
int c2{0};
int c3{0};



gRandom->SetSeed();




//Particle pt("ci",5,5,5);











int n=Particle::fParticleType.size();


Particle::AddParticleType("pione+",1,5,0);
Particle::AddParticleType( "pione-",1,-5,0);
Particle::AddParticleType( "kaone+",1,5,0);
Particle::AddParticleType( "kaone-",1,-5,0);
n=Particle::fParticleType.size();

//Particle::AddParticleType( "kaone-",4,-5,0);
//if(kap==kam){std::cout<<"uguali";}
Particle::AddParticleType( "protone+",1,5,6);
Particle::AddParticleType( "protone-",1,-5,6);
Particle::AddParticleType( "risonanza",1,5,6);
n=Particle::fParticleType.size();





TH1F *h1 = new TH1F("tipi di particelle","Title", Particle::fParticleType.size(), 0, Particle::fParticleType.size());
TH1F *h2 = new TH1F("angoli azitumali","Title", 10, 0,6.18);
TH1F *h3 = new TH1F("angoli polari","Title", 10, 0,3.14);
TH1F *h4 = new TH1F("impulso","Title", 10,0,1e9*2);
TH1F *h5 = new TH1F("impulso morto trasverso","Title", 10,0,1e9*2);
TH1F *h6 = new TH1F("energia","Title", 10,0,1e9*2);
TH1F *h7 = new TH1F("invariante di massa","Title", 1000,0,1e10);
TH1F *h8 = new TH1F("massa invarianti di particelle discorde","Title", 1000,0,1e10);
TH1F *h9 = new TH1F("massa invarianti di particelle concorde","Title", 1000,0,1e10);
TH1F *h10 = new TH1F("kaone+ pione-","Title", 100,0,1e10);
TH1F *h11 = new TH1F("kaone- pione+","Title", 100,0,1e10);
TH1F *h12 = new TH1F("risonanza","Title", 100,0,1e10);













Particle EventParticles[300];

int count{0};

 for (int i=0;i<5;i++)
{
 count=0;
 
   for(int j=0;j<100; j++) // qlz: sicuramente darà problemi
   {
    
   double x=gRandom->Rndm();
  
    Particle p("gg",3,3,3);
   if(x<0.4)
   {p.SetfIndex(0);
   //std::cout<< x;
   h1->Fill(0);
   }
  
   else if(x<0.8)
   {
   
    p.SetfIndex(1);  
   // std::cout<< x;
   h1->Fill(1);
   }
   else if(x<0.85)
   {
    p.SetfIndex(2); 
    //std::cout<< x;
    h1->Fill(2);
   }
   else if(x<0.9)
   {
    p.SetfIndex(3);
   // std::cout<< x; 
   h1->Fill(3);
   }
   else if(x<0.945)
   {
    p.SetfIndex(4);  
    //std::cout<< x;
    h1->Fill(4);
   }
   else if(x<0.99)
   {
    p.SetfIndex(5);
    //std::cout<< x;
    h1->Fill(5); 
   }
  
   else
   {p.SetfIndex(6); 
    h1->Fill(6);
    c1++;
    
     
    double y=gRandom->Rndm();
  
     if(y<0.5)
     {

       Particle* a= new Particle("pione+",1,1,1);
       Particle* b=new Particle("kaone-",1,1,1);


     
       int z=p.Decay2body(*a, *b);
       
      
       if(z==0)
       {
          EventParticles[100+count]=*a;
          EventParticles[101+count]=*b;
            count+=2;
       }
    

   
     }

else{

///

Particle* a= new Particle("pione-",1,1,1);
       Particle* b=new Particle("kaone+",1,1,1);


     
       int z=p.Decay2body(*a, *b);
       
      
       if(z==0)
       {
          EventParticles[100+count]=*a;
          EventParticles[101+count]=*b;
            count+=2;
       }
       /////
    
}



   }//fine else
    




double phi=gRandom->Uniform(0,2*3.14);
double theta=gRandom->Uniform(0,3.14);
    h2->Fill(phi); 
    h3->Fill(theta); 






double impulse=gRandom->Exp(1e9);
p.SetP(impulse*sin(theta)*cos(phi),impulse*sin(theta)*sin(phi),impulse*cos(theta));



   EventParticles[j]=p;
h4->Fill(p.GetImpulse());
h5->Fill(std::sqrt(p.GetPx()*p.GetPx()  +p.GetPy()*p.GetPy()          ));
h6->Fill(p.GetEnergy());


// std::cout<<count<<"\n";
  }//fine secondo for (j)

    Particle p("gg",3,3,3);

for(int m=0;m<100+count;m++){
for(int n=m+1;n<100+count;n++){
double invmass=EventParticles[m].InvMass(EventParticles[n]);
h7->Fill(invmass);

 if((p.fParticleType[EventParticles[m].GetfIndex()])->GetCharge()*(p.fParticleType[EventParticles[n].GetfIndex()])->GetCharge()<0){
h8->Fill(invmass);
 }
 else
 {
h9->Fill(invmass);
 }
 const char* p1=(p.fParticleType[EventParticles[m].GetfIndex()])->GetName();
 const char* p2=(p.fParticleType[EventParticles[n].GetfIndex()])->GetName();


if (p1 && p2) {

if((std::strcmp(p1,"pione-")==0&&std::strcmp(p2,"kaone+")==0)||(std::strcmp(p1,"kaone+")==0&&std::strcmp(p2,"pione-")==0)){
h10->Fill(invmass);
}

if((std::strcmp(p1,"pione+")==0&&std::strcmp(p2,"kaone-")==0)||(std::strcmp(p1,"kaone-")==0&&std::strcmp(p2,"pione+")==0)){
h11->Fill(invmass);
}

}

}
}


for(int i=100;i<100+count;i+=2){
double invmass=EventParticles[i].InvMass(EventParticles[i+1]);

h12->Fill(invmass);

}




} ///fine primo for (i)





std::cout <<"\n er brother";
std::cout<<"\nc1: "<<c1<<"\n";



TCanvas*canvas1=new TCanvas("canvas  1","Canvas",800,500);
h1->Draw();
canvas1->Draw();


TCanvas*canvas2=new TCanvas("canvas 2","Canvas",800,500);


h2->Draw();
canvas2->Draw();


TCanvas*canvas3=new TCanvas("canvas 3 ","Canvas",800,500);
h3->Draw();
canvas3->Draw();


TCanvas*canvas4=new TCanvas("canvas 4 ","Canvas",800,500);
h4->Draw();
canvas4->Draw();


TCanvas*canvas5=new TCanvas("canvas 5 ","Canvas",800,500);
h5->Draw();
canvas5->Draw();


TCanvas*canvas6=new TCanvas("canvas 6 ","Canvas",800,500);
h6->Draw();
canvas6->Draw();


TCanvas*canvas7=new TCanvas("canvas 7 ","Canvas",800,500);
h7->Draw();
canvas7->Draw();

TCanvas*canvas8=new TCanvas("canvas 8 ","Canvas",800,500);
h8->Draw();
canvas8->Draw();

TCanvas*canvas9=new TCanvas("canvas 9 ","Canvas",800,500);
h9->Draw();
canvas9->Draw();


TCanvas*canvas10=new TCanvas("canvas 10 ","Canvas",800,500);
h10->Draw();
canvas10->Draw();

TCanvas*canvas11=new TCanvas("canvas 11 ","Canvas",800,500);
h11->Draw();
canvas11->Draw();

TCanvas*canvas12=new TCanvas("canvas 12 ","Canvas",800,500);
h12->Draw();
canvas12->Draw();


 TFile *outputFile = new TFile("output.root", "RECREATE");

    // Salva i canvas nel file
    canvas1->Write();
    canvas2->Write();
    canvas3->Write();
    canvas4->Write();
    canvas5->Write();
    canvas6->Write();
    canvas7->Write();
    canvas8->Write();
    canvas9->Write();
    canvas10->Write();
    canvas11->Write();
    canvas12->Write();


    // Chiudi il file
    outputFile->Close();

    

}
