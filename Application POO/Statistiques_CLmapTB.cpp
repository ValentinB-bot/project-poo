#include "Statistiques_CLmapTB.h"


System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_Panier_Moyen(void)
{
	return "SELECT AVG(Panier) Panier_Moyen from (SELECT SUM(Prix_Article*Quantite_Article) Panier from Link group by ID_Liaison_Commande) ID";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_ChiffreAffaireMois(void)
{
	return "SELECT SUM(Prix_Article*Quantite_Article) Chiffre_Mensuel, MONTH(Date_Emission) Mois FROM  Link, Commande WHERE Link.ID_Liaison_Commande = Commande.ID_Commande and MONTH(Date_Emission) = '" + Date_Emission + "' GROUP BY MONTH(Date_Emission)";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_BadVente(void)
{
	return "SELECT TOP 10 SUM(Quantite_Article) Quantite, Designation_Article FROM Article, Link WHERE Article.ID_Article = Link.ID_Liaison_Article GROUP BY Designation_Article ORDER BY Quantite ASC";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_BestVente(void)
{
	return "SELECT TOP 10 SUM(Quantite_Article) Quantite, Designation_Article FROM Article, Link WHERE Article.ID_Article = Link.ID_Liaison_Article GROUP BY Designation_Article ORDER BY Quantite DESC";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_MontantAchatClient(void)
{
	return "SELECT SUM(Quantite_Article*Prix_Article) Total from Link INNER JOIN Commande ON Commande.ID_Commande = Link.ID_Liaison_Commande INNER JOIN Client ON Commande.ID_Commande = Client.ID_Client WHERE Nom_Client = '" + Nom_Client + "' and Prenom_Client = '" + Prenom_Client + "'";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_ProduitSousSeuil(void)
{
	return "SELECT Designation_Article FROM Article WHERE Quantite_Stock < Seuil_Reapprovisionnement ";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_ValeurAchatStock(void)
{
	return "SELECT SUM(Quantite_Stock * Prix_HT_Article)  Valeur_Achat_Stock FROM Article";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_ValeurStockCommercial(void)
{
	return "SELECT SUM(Quantite_Stock * Prix_HT_Article * Taux_TVA_Article * Multiplicateur_Prix_Article)  Valeur_Commerciale_Stock FROM Article";
}
System::String^ NS_Comp_Mappage_Statistique::CLmapStatistique::Select_ValeurStockVariation(void)
{
	return "SELECT SUM(Quantite_Stock * Prix_HT_Article * Multiplicateur_Prix_Article * Convert(float,'" + Taux_TVA + "') * Convert(float,'" + Marge_Commerciale + "') * Convert(float,'" + DemarqueInconnue + "') * Convert(float,'" + Remise_Commerciale + "'))	  Valeur_Commerciale_Stock FROM Article";
}

void NS_Comp_Mappage_Statistique::CLmapStatistique::setDate_Emission(int Id)
{
	this->Date_Emission = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setDemarqueInconnue(System::String^ Id)
{
	this->DemarqueInconnue = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setMarge_Commerciale(System::String^ Id)
{
	this->Marge_Commerciale = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setNom_Client(System::String^ Id)
{
	this->Nom_Client = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setPrenom_CLient(System::String^ Id)
{
	this->Prenom_Client = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setRemise_Commerciale(System::String^ Id)
{
	this->Remise_Commerciale = Id;
}
void NS_Comp_Mappage_Statistique::CLmapStatistique::setTaux_TVA(System::String^ Id)
{
	this->Taux_TVA = Id;
}