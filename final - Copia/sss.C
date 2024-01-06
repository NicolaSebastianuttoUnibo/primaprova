void sss() {

    TFile *inputFile = TFile::Open("output.root");

    TH1F *h1 = (TH1F*)inputFile->Get("abbondanza di particelle");
    TH1F *h2 = (TH1F*)inputFile->Get("angoli azitumali");
    TH1F *h3 = (TH1F*)inputFile->Get("angoli polari");
    TH1F *h4 = (TH1F*)inputFile->Get("impulso");
    TH1F *h8 = (TH1F*)inputFile->Get("massa invarianti di particelle discorde");
    TH1F *h9 = (TH1F*)inputFile->Get("massa invarianti di particelle concorde");
    TH1F *h10 = (TH1F*)inputFile->Get("kaone+- pione+- discordi");
    TH1F *h11 = (TH1F*)inputFile->Get("kaone+- pione+- concordi");
    TH1F *h12 = (TH1F*)inputFile->Get("risonanza");



    TF1 *Fit1 = new TF1("uniform1", "pol0");
    TF1 *Fit2 = new TF1("uniform2", "pol0");
    TF1 *Fit3 = new TF1("exponential", "expo");
    TF1 *Fit4 = new TF1("gaussian1", "gaus",0.2,8);
    TF1 *Fit5 = new TF1("gaussian2", "gaus",0.5,8);
    TF1 *Fit6 = new TF1("gaussian3", "gaus",0.5,8);

       

    h2->Fit(Fit1, "Q");
    h3->Fit(Fit2, "Q");
    h4->Fit(Fit3, "Q");
    h12->Fit(Fit6, "Q");
    


    TH1F *h_diff1 = (TH1F*)h8->Clone("h_diff1"); 
    h_diff1->Add(h8,h9,1.,-1.);
    h_diff1->Fit(Fit4, "Q");

    h_diff1->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
    h_diff1->GetYaxis()->SetTitle("occorrenze");


    TH1F *h_diff2 = (TH1F*)h10->Clone("h_diff2"); 
    h_diff2->Add(h10,h11,1, -1);
    h_diff2->Fit(Fit5, "Q");

    h_diff2->GetXaxis()->SetTitle("invariante di massa (GeV/c^2)");
    h_diff2->GetYaxis()->SetTitle("occorrenze");



    TCanvas *canvas = new TCanvas("canvas", "Canvas", 800, 600);
    canvas->Divide(2,2);
    
    canvas->cd(1);
    h1->SetLineColor(2);
    h1->Draw();


    canvas->cd(2);
    h2->SetLineColor(40);
    h2->Draw();
    Fit1->Draw("same");
    std::cout << "Fit per angoli azimutali:" << "\n";
    std::cout << "Parametro: " << Fit1->GetParameter(0) << "+/-"<<Fit1->GetParError(0)<<"\n";
    std::cout << "Chi2: " << Fit1->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit1->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit1->GetChisquare() / Fit1->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit1->GetProb() << "\n\n";


    canvas->cd(3);
    h3->SetLineColor(40);
    h3->Draw();
    Fit2->Draw("same");
    std::cout << "\nFit per angoli polari:" << "\n";
    std::cout << "Parametro: " << Fit2->GetParameter(0) << "+/-"<<Fit2->GetParError(0)<<"\n";
    std::cout << "Chi2: " << Fit2->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit2->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit2->GetChisquare() / Fit2->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit2->GetProb() << "\n\n";


    canvas->cd(4);
    h4->SetLineColor(8);
    h4->Draw();
    Fit3->Draw("same");
    std::cout << "\nFit per impulso:" << "\n";
    std::cout << "Media: " << h4->GetMean() << "+/-"<<h4->GetMeanError()<<"\n";
    std::cout << "Chi2: " << Fit3->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit3->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit3->GetChisquare() / Fit3->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit3->GetProb() << "\n\n";

 
    TCanvas *canvas4 = new TCanvas("canvas4", "Canvas4", 800, 600);
    canvas4->Divide(1,3);
    canvas4->cd(1);
    h_diff1->SetLineColor(25);
    //TH1F *h_diff1 = new TH1F(*h8);
    //h_diff1->Add(h8,h9,1.,-1.);
    h_diff1->Draw();
    //h_diff1->Fit(Fit4, "Q");
    //Fit4->Draw("same");
    std::cout << "Fit per prima differenza:" << "\n";
    std::cout << "Ampiezza: " << Fit4->GetParameter(0) << "+/-"<<Fit4->GetParError(0)<<"\n";
    std::cout << "Media: " << Fit4->GetParameter(1) << "+/-"<<Fit4->GetParError(1)<<"\n";
    std::cout << "Sigma: " << Fit4->GetParameter(2) << "+/-"<<Fit4->GetParError(2)<<"\n";
    std::cout << "Chi2: " << Fit4->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit4->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit4->GetChisquare() / Fit4->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit4->GetProb() << "\n\n";
        
    
    canvas4->cd(2);
    h_diff2->SetLineColor(25);
    //TH1F *h_diff2 = new TH1F(*h10); 
    //h_diff2->Add(h10,h11,1, -1);
    h_diff2->Draw();
    //h_diff2->Fit(Fit5, "Q");
    //Fit5->Draw("same");
    std::cout << "Fit per seconda differenza:" << "\n";
    std::cout << "Ampiezza: " << Fit5->GetParameter(0) << "+/-"<<Fit5->GetParError(0)<<"\n";
    std::cout << "Media: " << Fit5->GetParameter(1) << "+/-"<<Fit5->GetParError(1)<<"\n";
    std::cout << "Sigma: " << Fit5->GetParameter(2) << "+/-"<<Fit5->GetParError(2)<<"\n";
    std::cout << "Chi2: " << Fit5->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit5->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit5->GetChisquare() / Fit5->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit5->GetProb() << "\n\n";   


    canvas4->cd(3);
    h12->SetLineColor(8);
    h12->Draw();
    h12->Fit(Fit6, "Q");
    std::cout << "Fit per massa invariante vere k*:" << "\n";
    std::cout << "Ampiezza: " << Fit6->GetParameter(0) << "+/-"<<Fit6->GetParError(0)<<"\n";
    std::cout << "Media: " << Fit6->GetParameter(1) << "+/-"<<Fit6->GetParError(1)<<"\n";
    std::cout << "Sigma: " << Fit6->GetParameter(2) << "+/-"<<Fit6->GetParError(2)<<"\n";
    std::cout << "Chi2: " << Fit6->GetChisquare() << "\n";
    std::cout << "NDF: " << Fit6->GetNDF() << "\n";
    std::cout << "Chi2/NDF: " << Fit6->GetChisquare() / Fit6->GetNDF() << "\n";
    std::cout << "Probabilità del fit: " << Fit6->GetProb() << "\n\n";   
}