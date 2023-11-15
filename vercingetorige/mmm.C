#include "Particle.hpp"

void mmm(){
gRandom->SetSeed();

Particle pt("ci",5,5,5);


ParticleType pip("pione +",4,5);
ParticleType pim("pione -",4,5);
ParticleType kap("kaone +",4,5);
ParticleType kam("kaone -",4,5);
ParticleType prp("protone +",4,5);
ParticleType prm("protone -",4,5);
ResonanceType r1("risonanza",4,5,6);
ResonanceType r2("risonanza34234",466666,5,6);


  pt.AddParticleType("risonanza",4,5,6);
pt.PrintAll();  

Particle::AddParticleType( "risonanza",4,5,6);
Particle::AddParticleType( "protone -",4,5,0);
Particle::AddParticleType( "protone -",4,5,0);
Particle::AddParticleType( "protone -",4,5,0);
Particle::AddParticleType( "risonanza",4,5,6);
Particle::PrintAll(); 
/* r1.Print();
prm.Print(); */
/*std::vector<ParticleType*> gigio=p.pfs();;
gigio.push_back(&r1); 
gigio.push_back(&prm); 
gigio[0]->Print();
gigio[1]->Print();*/
//p.PrintParticle(); 
//Particle::o(pip);
Particle EventParticles[120];
 
  
 for (int i=0;i<1e5;i++)
{
  int count=0;
    for(i=0;i<100; i++) // qlz: sicuramente darà problemi
    {
     double x=gRandom->Rndm();
     Particle p("gg",0,0,0);

    if(x<0.4)
    {p.SetfIndex(1);
    }
    else if(x<0.8)
    {
     p.SetfIndex(2);   
    }
    else if(x<0.85)
    {
     p.SetfIndex(3);   
    }
    else if(x<0.9)
    {
     p.SetfIndex(4);   
    }
    else if(x<0.945)
    {
     p.SetfIndex(5);   
    }
    else if(x<0.99)
    {
     p.SetfIndex(6);   
    }
    else 
    {
     double x=gRandom->Rndm();
      if(x<0.5)
      {
         Particle* a= new Particle("pione +",1,1,1);
        Particle* b=new Particle("kaone -",1,1,1);
        a->Setter("pione +");
        b->Setter("kaone -");
        //int z=p.Decay2body(*a, *b);
        if(i==0)
        {
           /*EventParticles[100+count]=a;
           EventParticles[101+count]=b;
             count+=2;*/
        }
      
      }

      /*else{
        Particle a("pione -",1,1,1);
        Particle b("kaone +",1,1,1);
        a.Setter("pione -");
        b.Setter("kaone +");
        int z=p.Decay2body(a, b);
        if(z==0)
        {
           EventParticles[100+count]=a;
           EventParticles[101+count]=b;
             count+=2;
        

      }
     p.SetfIndex(7);  
    }*/
    }
      
     

double phi=gRandom->Uniform(0,2*3.14);
double theta=gRandom->Uniform(0,3.14);
double impulse=gRandom->Exp(1e9);
p.SetP(impulse*sin(theta)*cos(phi),impulse*sin(theta)*sin(phi),impulse*cos(theta));
    }
} 











std::cout <<"\n er brother";


std::cout<<"\ncifuyguygao\n";
}
