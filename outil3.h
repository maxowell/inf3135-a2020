#ifndef _OUTIL3_H_
#define _OUTIL3_H_
	//Booleans representants les arguments par ligne de commande
	bool paramD;
	bool paramI;
	bool paramS;
	bool paramT;
	//Objet pastille.
	typedef struct pastille_t{
		size_t id;
		unsigned char p;
		float sommeTH;
		int nombreTH;
		size_t erreurTH;
		int invalideTH;
		float sommeTA;
		int nombreTA;
		size_t erreurTA;
		int invalideTA;
		size_t sommePuls;
		int nombrePuls;
		size_t erreurPuls;
		int invalidePuls;
		int sizePN;
		size_t time;
		int nbTransInconnues;
		int nbTransDecroissantes;
		int nbTrans01;
		int nbTrans02;
		int nbTrans03;
		int nbTrans04;
		int nbTrans05;
		size_t idPN[];
	} pastille_s;
	//Gere les arguments de la ligne de commande.
	int cmd();
	//Initialise une pastille aux valeurs par defaut.
	void getPastille();
#endif
