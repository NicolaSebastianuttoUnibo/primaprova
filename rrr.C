Edoardo Massari, Andrea Meletti, Lorenzo Piva, Nicola Sebastianutto

                                    Relazione

Struttura della relazione:
(1) Introduzione: descrivere brevemente lo scopo del programma
(2) Struttura del codice: quali classi sono state implementate, con che funzione,
quali meccanismi di reimpiego di codice sono stati usati, e perchè
(3) Generazione: quanti eventi sono stati generati, quante particelle, quali tipi
di particelle e con che proporzioni, come sono state generate le proprietà
cinematiche.
(4) Analisi: Discutere la congruenza delle distribuzioni osservate con i dati in input
alla generazione, spiegare brevemente l’approccio seguito per estrarre il segnale
della risonanza


/////////////////////////////////////////////////////////////////////////////////



Introduzione (1)

/*implementare un prototipo di codice utilizzabile per
rappresentare e analizzare il contenuto di eventi fisici simulati risultanti da
collisioni di particelle elementari

La presente relazione riguarda l'analisi di eventi fisici simulati derivanti da collisioni di particelle elementari,

Nel contesto di questa relazione, ci concentreremo sulla generazione di istogrammi delle proprietà delle particelle,
inclusi modulo dell'impulso, angolo polare, angolo azimutale ed energia,
nonché sull'analisi delle distribuzioni di massa invariante. 

*/

INTRODUZIONE

///MAX 250-300 parole per sezione

Lo scopo di questa esperienza di laboratorio è quella di implementare un prototipo di codice utilizzabile   //16
per rappresentare e analizzare particelle simulate derivanti da collisioni di particelle elementari.        //12
Durante questa simulazione sono state generate diverse particelle tra cui pioni, kaoni e protoni.           //14
Inoltre sono state generate delle risonanze che decadono in pioni e kaoni con carica discorde               //15
delle quali verifichiamo la distribuzione.                                                                  //5
Per fare questo verifichiamo che il picco dell'invariante di massa generato                                '//12
dalla risonanza sia lo stesso di quello ottenuto                                                            //8
tramite la differenza fatto  tra due grafici, uno con particelle di carica discorde                         //13
l'altro con particelle di carica concorde.                                                                 '//7

//TOT: 16+12+14+15+5+12+8+13+7=102 parole

STRUTTURA DEL CODICE

///MAX 250-300 parole per sezione

Il codice implementato per la generazione e l'analisi degli eventi fisici simulati '//13
si basa su un'architettura orientata agli oggetti, che sfrutta meccanismi di ereditarietà e aggregazione,   '//15
nonché l'utilizzo di attributi/metodi statici e const e il polimorfismo al run-time tramite l'ereditarietà virtuale.  //18

Le principali classi implementate sono:

1. ParticleType:
Questa classe rappresenta le proprietà di base delle particelle,  //9
che contiene il nome, la massa e la carica. ParticleType contiene dei metodi pubblici  //14
per richiamare i membri privati che sono di tipo const  //11
e in aggiunta possiede i metodi Print e GetWidth, che sono invece dei metodi virtuali.  //15

2. ResonanceType:
Questa classe che è figlia di ParticleType e quindi eredita  //10
tutti i suoi membri e funzioni,   //6
rappresenta le proprietà delle particelle delle risonanze.  ///8
Oltre  alle stesse informazioni di base delle particelle, viene aggiunto il parametro della larghezza,  //14
che è legata alla vita media della risonanza.  //8

3. Particle:
Questa ultima classe invece è un contenitore di tutte le particelle sia ParticleType che ResonanceType,
possibile grazie ai suoi membri statici (come la funzione FindPartcle e l'array fParticleType).             ')
Inoltre attraverso il membro privato fIndex e le funzioni che lo gestiscono (i Setter), è possibile 
selezionare una particella che si trova all'interno dell'arrrrrrrray condiviso.
In aggiunta con questa classe è possibile modificare e ottenere le informazioni sull'impulso e sulla masssa invariante.   '


Le classi ParticleType e ResonanceType sono progettate per consentire una rappresentazione efficiente  //13
e flessibile delle proprietà delle particelle e delle risonanze,  //9
consentendo alla classe Particle una gestione ottimale delle informazioni necessarie
per la generazione e l'analisi degli eventi.'  //15

/*Inoltre, il codice fa ampio uso di metodi per la generazione secondo definite proporzioni, distribuzioni esponenziali,
distribuzioni uniformi e distribuzioni gaussiane, al fine di garantire la corretta simulazione degli eventi fisici.*/



Continua con la sezione relativa alla generazione degli eventi, fornendo dettagli su quanti eventi sono stati generati,  //17
quante particelle e quali tipi di particelle sono stati inclusi, insieme alle proporzioni utilizzate per la generazione.  //18


GENERAZIONE (3)

Durante l'implementazione del codice, sono stati generati 10^5 eventi,
al fine di ottenere un campione statisticamente significativo
per l'analisi successiva. All'interno di ciascun evento, sono state simulate 100 particelle
con l'aggiunta di eventuali decadimenti derivanti da risonanze,
con una distribuzione predefinita dei tipi di particelle coinvolte.

Le proporzioni utilizzate per la generazione delle particelle sono state le seguenti:
- 40% pioni carichi positivi
- 40% pioni carichi negativi
- 5% kaoni carichi positivi
- 5% kaoni carichi negativi
- 4.5% protoni
- 4.5% antiprotoni
- 1% risonanze

Queste proporzioni sono state selezionate per riflettere le distribuzioni tipiche delle particelle coinvolte
in determinati processi fisici, consentendo così una simulazione realistica degli eventi.

Inoltre, le proprietà cinematiche delle particelle sono state generate utilizzando distribuzioni appropriate
per l'energia, ottenute con gli angoli polari e azimutali che hanno una probabilità uniforme
e con l'impulso, che segue un andamento esponenziale,
al fine di garantire una rappresentazione accurata delle caratteristiche dei processi fisici simulati.



Analisi (4)

Nella fase di analisi, ci concentreremo sull'esame delle distribuzioni
ottenute dalla generazione degli eventi, con particolare attenzione alle proprietà delle particelle
e alle distribuzioni di massa invariante.

Per le distribuzioni delle proprietà delle particelle, quali modulo dell'impulso, angolo polare,
angolo azimutale ed energia, abbiamo esaminato tramite fit la congruenza di tali distribuzioni
con i dati in input alla generazione,
valutando la corrispondenza con le distribuzioni attese per i processi fisici simulati.

Inoltre, abbiamo eseguito un'analisi dettagliata delle distribuzioni di massa invariante,
includendo sia le particelle "primarie" che le "figlie" dei decadimenti. In particolare,
abbiamo effettuato le seguenti combinazioni a due a due per ciascun evento:
- Massa invariante fra tutte le particelle di carica concorde
- Massa invariante fra tutte le particelle di carica discorde
- Massa invariante fra tutte le combinazioni di kaoni/pioni di carica concorde
- Massa invariante fra tutte le combinazioni di kaoni/pioni di carica discorde
- Istogramma di controllo: Massa invariante fra i soli prodotti di decadimento della particella della risonanza

Attraverso quest'analisi, abbiamo valutato la presenza di segnali di risonanze nelle distribuzioni di massa invariante,
confrontando i risultati ottenuti con le aspettative teoriche e verificando la corrispondenza con i dati simulati.

Nella sezione successiva, presenteremo i risultati ottenuti in forma tabellare
e discuteremo le implicazioni delle osservazioni emerse durante l'analisi.

