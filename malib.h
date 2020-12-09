#ifndef _MALIB_H_
#define _MALIB_H_

	bool paramD;
	bool paramI;
	bool paramS;
	bool paramT;

	//Gere les arguments de la ligne de commande.
	int cmd();

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
		int badTime;
		int nonReconnue;
		size_t idPN[];
	} pastille_s;

	//Objet decompte
	typedef struct decompte_t {
		int nbTransInconnues;
		int nbTransDecroissantes;
		int nbTrans01;
		int nbTrans02;
		int nbTrans03;
		int nbTrans04;
		int nbTrans05;
	} decompte_s;

	//Initilise un objet decompte aux valeurs par defaut.
	void getDecompte();

	//Changement de l'identifiant par défaut.
	void changeID();

	//Qualité du signal en mètres.
	void qualiteSignal();

	//Retourne une information contenue dans la transaction.
	char* getInfo();

	//Échange de données.
	void echangeData();

	//Calcule la distance en mètres
	float getDistance();

	//Effectue la transaction pour la moyenne des TH TA pulsations.
	void transaction21();

	//Effectue la transaction pour le cumul des valeurs invalides TH TA pulsations.
	void transaction22();

	//Effectue la transaction pour le cumul des mots ERREUR TH TA pulsations.
	void transaction23();

	//Vérifie si le timestamp d'une transaction est inférieur au timestamp précédant.
	bool checkTime();

	//Effectue la transaction pour TH.
	void transaction01();

	//Effectue la transaction pour TA.
	void transaction02();

	//Effectue la transaction pour Pulsation.
	void transaction03();

	//Effecture la transaction pour signal.
	void transaction04();

	//Initialise une pastille aux valeurs par defaut.
	void getPastille();

#endif
