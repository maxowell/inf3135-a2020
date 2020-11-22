#ifndef _MALIB_H_
#define _MALIB_H_
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
		size_t idPN[];
	} pastille_s;

	//Retourne le timestamp (size_t) d'une transaction.
	size_t getTimestamp();

	//Retourne le numéro (int) d'une transaction.
	int getNumTrans();

	//Retourne l'id (size_t) d'une transaction. Position 3 si v != 0, 4 si v == 0.
	size_t getId();

	//Retourne la puissance de l'émetteur d'une transaction.
	unsigned char getPuissance();

	//Changement de l'identifiant par défaut.
	void changeID();

	//Qualité du signal en mètres.
	void qualiteSignal();

	//Échange de données.
	void echangeData();

	//Retourne le signal RSSI d'une transaction.
	signed short getSignal();

	//Calcule la distance en mètres
	float getDistance();

	//Retourne la température d'une transaction
	char* getTemp();

	//Retourne une température sous forme signed short
	signed short getTempShort();

	//Effectue la transaction pour la moyenne des TH TA pulsations.
	void transaction21();

	//Effectue la transaction pour le cumul des valeurs invalides TH TA pulsations.
	void transaction22();

	//Effectue la transaction pour le cumul des mots ERREUR TH TA pulsations.
	void transaction23();

	//Vérifie si le timestamp d'une transaction est inférieur au timestamp précédant.
	bool checkTime();

#endif
