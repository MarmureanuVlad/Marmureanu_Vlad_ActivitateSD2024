#include <stdio.h>
#include <malloc.h>

struct masina {
	char* marca;
	float capacitateCil;
	int an;
};

void afisareMasina(const struct masina* m) {
	if (m->marca != NULL) {
		printf("Marca: %s\n", m->marca);
	}
		printf("Capacitate cilindrica:%5.2f\n", m->capacitateCil);
		printf("An: %d\n\n", m->an);

}

struct masina initializareMasina(const char* marca, int an, float cc) {
	struct masina m;
	m.an = an;
	m.capacitateCil = cc;
	if (marca != NULL) {
		m.marca = malloc(strlen(marca) + 1);
		strcpy(m.marca, marca);
	}
	else {
		m.marca = malloc(strlen("N/A") + 1);
		strcpy(m.marca, "N/A");
	}
	return m;
}

void dezalocareMasina(struct masina* masina) {
	free(masina->marca);
	masina->marca = NULL;
}

int main() {

	struct masina masina1;
	//Dacia
	masina1.marca = (char*)malloc(sizeof(char) * (strlen("Dacia") + 1));
	strcpy(masina1.marca, "Dacia");
	masina1.capacitateCil = 1.9;
	masina1.an = 2023;

	afisareMasina(&masina1); //adresa & ca e transmis prin pointer 

	//free(masina1.marca);
	//masina1.marca = NULL;

	dezalocareMasina(&masina1);

	struct masina masina2 = initializareMasina("Ford", 2022, 2.49);
	
	afisareMasina(&masina2);
	dezalocareMasina(&masina2);

	return 0;
}
