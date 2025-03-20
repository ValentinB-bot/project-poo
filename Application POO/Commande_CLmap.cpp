
#include "Commande_CLmapTB.h"

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::Select(void)
{
	return "Select ID_Liaison,ID_Commande,ID_Commande_Client,Reference_Commande,Date_Livraison,Date_Emission,Designation_Article,Quantite_Article,Prix_Article from Commande inner join Link ON ID_Commande = ID_Liaison_Commande inner join Article on Link.ID_Liaison_Article = Article.ID_Article";
}
System::String^ NS_Comp_Mappage_Commande::CLmapCommande::SelectPaiment(void)
{
	return "select * from Paiement";
}
System::String^ NS_Comp_Mappage_Commande::CLmapCommande::Insert(void)
{
	return "";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::DeleteCommande(void)
{
	return "delete from Commande where Reference_Commande = '" + this->Reference_Commande + "'";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::InsertCommande(void)
{
	return "insert into Commande values ('" + Reference_Commande + "','" + Date_Emission + "','" + Date_Livraison + "','" + ID_Client + "')";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::InsertPaiment(void)
{
	return "insert into Paiement values ('" + Date_Paiment + "','" + Montant + "','" + ID_Commande + "','" + id_paiment_moyen + "')";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::DeletePaiment(void)
{
	return "delete from Paiement where ID_Paiement = '" + this->id_paiment + "'";
}
System::String^ NS_Comp_Mappage_Commande::CLmapCommande::UpdateCommande(void)
{
	return "update Commande SET Date_Livraison = '" + Date_Livraison + "', Date_Emission = '" + Date_Emission + "', ID_Commande_Client = '" + ID_Client + "', Reference_Commande = '" + Reference_Commande + "' WHERE ID_Commande = '" + ID_Commande + "'";
}
System::String^ NS_Comp_Mappage_Commande::CLmapCommande::UpdatePaiment(void)
{
	return "update Paiement SET Date_Paiement = '" + Date_Paiment + "', Montant_Paiement = '" + Montant + "', ID_Paiement_Commande = '" + ID_Commande + "', ID_Paiement_MoyPaiement = '" + id_paiment_moyen + "' Where ID_Paiement = '" + id_paiment + "'";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::InsertLink(void)
{
	return "insert into link values(" + Link_Quantite + ", (select Prix_HT_Article * (1+(Taux_TVA_Article/100)) as prix_ttc from Article where ID_Article = (SELECT ID_Article FROM Article WHERE Reference_Article = '" + Reference_Article + "')), (SELECT ID_Commande FROM Commande WHERE Reference_Commande = '" + Reference_Commande + "'), (SELECT ID_Article FROM Article WHERE Reference_Article = '" + Reference_Article + "'))";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::DeleteLink(void)
{
	return "delete from Link where ID_Liaison_Commande = (SELECT ID_Commande FROM Commande WHERE Reference_Commande = '" + Reference_Commande + "') and ID_Liaison_Article = (SELECT ID_Article FROM Article WHERE Reference_Article = '" + Reference_Article + "')";
}

System::String^ NS_Comp_Mappage_Commande::CLmapCommande::UpdateLink(void)
{
	return "update Link SET ID_Liaison_Article = (SELECT ID_Article FROM Article WHERE Reference_Article = '" + Reference_Article + "'), ID_Liaison_Commande = (SELECT ID_Commande FROM Commande WHERE Reference_Commande = '" + Reference_Commande + "'), Quantite_Article = '" + Link_Quantite + "', Prix_Article = (select Prix_HT_Article * (1+(Taux_TVA_Article/100)) as prix_ttc from Article where ID_Article = (SELECT ID_Article FROM Article WHERE Reference_Article = '" + Reference_Article + "')) WHERE ID_Liaison = '" + ID_Liaison + "'";
}

void NS_Comp_Mappage_Commande::CLmapCommande::setID_Client(int Id)
{
	this->ID_Client = Id;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setID_Paiment(int Id)
{
	this->id_paiment = Id;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setID_Paiment_Moyen(int Id)
{
	this->id_paiment_moyen = Id;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setID_Commande(int Id)
{
	this->ID_Commande = Id;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setID_Facture(int Id)
{
	this->ID_Facture = Id;
}

void NS_Comp_Mappage_Commande::CLmapCommande::setID_Liaison(int Id)
{
	this->ID_Liaison = Id;
}

void NS_Comp_Mappage_Commande::CLmapCommande::setQuantite(int Quantite)
{
	this->Link_Quantite = Quantite;
}

void NS_Comp_Mappage_Commande::CLmapCommande::setReference_Article(System::String^ reference_article)
{
	this->Reference_Article = reference_article;
}

void NS_Comp_Mappage_Commande::CLmapCommande::setReference_Commande(System::String^ reference_commande)
{
	this->Reference_Commande = reference_commande;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setMontant(System::Decimal^ montant)
{
	this->Montant = montant;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setDate_Paiment(System::DateTime^ date_paiment)
{
	this->Date_Paiment = date_paiment;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setDateEmission(System::DateTime^ date_emission)
{
	this->Date_Emission = date_emission;
}
void NS_Comp_Mappage_Commande::CLmapCommande::setDate_Livraison(System::DateTime^ date_livraison)
{
	this->Date_Livraison = date_livraison;
}



int NS_Comp_Mappage_Commande::CLmapCommande::getID_Client(void) { return this->ID_Client; }
int NS_Comp_Mappage_Commande::CLmapCommande::getID_Commande(void) { return this->ID_Commande; }
int NS_Comp_Mappage_Commande::CLmapCommande::getID_Facture(void) { return this->ID_Facture; }
System::String^ NS_Comp_Mappage_Commande::CLmapCommande::getReference_Commande(void) { return this->Reference_Commande; }
System::DateTime^ NS_Comp_Mappage_Commande::CLmapCommande::getDate_Emission(void) { return this->Date_Emission; }
System::DateTime^ NS_Comp_Mappage_Commande::CLmapCommande::getDate_Livraison(void) { return this->Date_Livraison; }