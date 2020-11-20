Pour ce travail, j'ai commencé par analyser le contexte du projet avec lequel nous travaillions. En effet, cette analyse m'a aidé car je ne comprennais pas exactement ce que notre programme devait faire dans les faits, et savoir ce que doit faire le programme et pourquoi il doit le faire m'aide à visualiser les objectifs que je devais atteindre. 

J'ai poursuivi par trouver et corriger toutes les erreurs de mon tp1, afin de m'assurer qu'elle ne se reproduisent pas dans ce nouveau tp.

Par la suite, après avoir compris le fonctionnement du programme, j'ai commencé à  programmer la structure de traitement des transactions. J'ai implémenté la réception des transactions par le biais du stdin. En lisant une ligne à la fois, je traite chaque transaction l'une après l'autre. 

Ensuite, en traitant la ligne comme une string, j'isole le numéro de transaction et j'effectue actions qui correspondent à ce numéro sur la transaction.

Je me suis construit une structure pour stocker les différentes informations que le programme doit mémoriser, et je les mets à jours à chaque traitement de transaction.

À chaque traitement de transaction, le programme imprime directement les informations demandées sur le stdout. Ceci me permet de ne pas avoir à stocker ces informations pour la totalité du déroulement du programme (seulement pour la transaction en cours).

N'ayant pas les connaissances nécessaires pour faire les fichiers `malib.c`, `malib.h` et `tp2.yml`, j'ai gardé ces objectifs pour la fin.