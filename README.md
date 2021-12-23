# PendoloDoppio

Corso di Metodi Computazionali della Fisica. Anno Accademico 2019/2020.

Prof. Paolo Umari

Soluzione del moto del Pendolo Doppio attraverso il metodo di Runge-Kutta a 4 punti.

Il pendolo doppio è un esempio di un sistema dinamico semplice che mostra un comportamento complesso.
Consiste in due masse puntiformi legate da un filo. Ogni massa è un pendolo semplice: i due pendoli vengono accoppiati e il sistema è libero di oscillare su un piano.

### pendolo.cc

Contiene il main e le istanze dei vari metodi.
Gli angoli vengono presi in input in gradi e convertiti in radianti.

TODO. Chiedere in che unità di misura si preferisce inserire gli angoli.

### definitions.h

Contiene le definizioni dell'accelerazione di gravità e massa e lunghezza di ogni pendolo.

### runge_kutta.cc

Contiene la funzione per eseguire la derivata numerica e la funzione in cui si calcolano i risultati del metodo Runge-Kutta.

### energy.cc

Calcolo dell'energia totale, come somma di energia cinetica e potenziale.

### output.cc

Funzione per stampare i risultati.

### compile:

c++ -Wall -I. -o pendolo *.cc
