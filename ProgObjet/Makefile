CC=g++
CFLAGS=-g
LDFLAGS=
EXEC=software

all: $(EXEC)

software: cabinetMedical.o patient.o medecin.o rdv.o dossierPatient.o prescription.o posologie.o medicament.o
	$(CC) *.cpp -o software $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)