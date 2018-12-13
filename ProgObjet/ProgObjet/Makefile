CC=g++
CFLAGS=-g
LDFLAGS=
EXEC=GestionCabinet

all: $(EXEC)

script: main.o CabinetMedical.o Date.o DossierPatient.o Main.o Patient.o Medicament.o Medecin.o RDV.o Prescription.o Posologie.o Personne.o
	$(CC) *.cpp -o GestionCabinet $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
