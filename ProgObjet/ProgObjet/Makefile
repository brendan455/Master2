CC=g++
CFLAGS=-g
LDFLAGS=
EXEC=GestionCabinet

all: $(EXEC)

script: main.o CabinetMedical.o DossierPatient.o Patient.o Medecin.o RDV.o Prescription.o Posologie.o Medicament.o
	$(CC) *.cpp -o GestionCabinet $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
