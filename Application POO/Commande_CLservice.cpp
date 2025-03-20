
#include "Commande_CLservice.h"

NS_Comp_Svc_Commande::CLservicesCommande::CLservicesCommande(void)
{
	this->oCad = gcnew NS_Comp_Data::CLcad();
	this->oMappTB = gcnew NS_Comp_Mappage_Commande::CLmapCommande();
}
System::Data::DataSet^ NS_Comp_Svc_Commande::CLservicesCommande::selectionnerToutesLesCommandes(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}
System::Data::DataSet^ NS_Comp_Svc_Commande::CLservicesCommande::selectionnerTousLesPaiment(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->SelectPaiment();
	return this->oCad->getRows(sql, dataTableName);
}
void NS_Comp_Svc_Commande::CLservicesCommande::AjouterUneCommande(System::String^ reference_commande, System::DateTime^ date_emission, System::DateTime^ date_livraison, int id_client)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);
	this->oMappTB->setDateEmission(date_emission);
	this->oMappTB->setDate_Livraison(date_livraison);
	this->oMappTB->setID_Client(id_client);

	sql = this->oMappTB->InsertCommande();

	this->oCad->actionRows(sql);
}


void NS_Comp_Svc_Commande::CLservicesCommande::AjouterUnLien(System::String^ reference_commande, System::String^ reference_article, int quantite)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);
	this->oMappTB->setReference_Article(reference_article);
	this->oMappTB->setQuantite(quantite);

	sql = this->oMappTB->InsertLink();

	this->oCad->actionRows(sql);
}

void NS_Comp_Svc_Commande::CLservicesCommande::ModifierUnLien(int id_liaison, System::String^ reference_commande, System::String^ reference_article, int quantite)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);
	this->oMappTB->setReference_Article(reference_article);
	this->oMappTB->setQuantite(quantite);
	this->oMappTB->setID_Liaison(id_liaison);

	sql = this->oMappTB->UpdateLink();

	this->oCad->actionRows(sql);
}

void NS_Comp_Svc_Commande::CLservicesCommande::SupprimerUnLien(System::String^ reference_commande, System::String^ reference_article)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);
	this->oMappTB->setReference_Article(reference_article);

	sql = this->oMappTB->DeleteLink();

	this->oCad->actionRows(sql);
}

void NS_Comp_Svc_Commande::CLservicesCommande::AjouterUnPaiment(System::DateTime^ date_paiment, System::Decimal^ montant, int id_paiment_moyent, int id_paiment_commande)
{
	System::String^ sql;


	this->oMappTB->setDate_Paiment(date_paiment);
	this->oMappTB->setMontant(montant);
	this->oMappTB->setID_Paiment_Moyen(id_paiment_moyent);
	this->oMappTB->setID_Commande(id_paiment_commande);

	sql = this->oMappTB->InsertPaiment();

	this->oCad->actionRows(sql);
}
void NS_Comp_Svc_Commande::CLservicesCommande::SupprimerUneCommande(System::String^ reference_commande)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);


	sql = this->oMappTB->DeleteCommande();

	this->oCad->actionRows(sql);
}
void NS_Comp_Svc_Commande::CLservicesCommande::SupprimerUnPaiment(int id_paiement)
{
	System::String^ sql;

	this->oMappTB->setID_Paiment(id_paiement);


	sql = this->oMappTB->DeletePaiment();

	this->oCad->actionRows(sql);
}
void NS_Comp_Svc_Commande::CLservicesCommande::ModifierUneCommande(int id_commande, System::String^ reference_commande, System::DateTime^ date_emission, System::DateTime^ date_livraison, int id_client)
{
	System::String^ sql;

	this->oMappTB->setReference_Commande(reference_commande);
	this->oMappTB->setDateEmission(date_emission);
	this->oMappTB->setDate_Livraison(date_livraison);
	this->oMappTB->setID_Client(id_client);
	this->oMappTB->setID_Commande(id_commande);
	sql = this->oMappTB->UpdateCommande();

	this->oCad->actionRows(sql);
}
void NS_Comp_Svc_Commande::CLservicesCommande::ModifierUnPaiment(int id_paiment, System::DateTime^ date_paiment, System::Decimal^ montant, int id_paiment_moyent, int id_paiment_commande)
{
	System::String^ sql;

	this->oMappTB->setID_Paiment(id_paiment);
	this->oMappTB->setDate_Paiment(date_paiment);
	this->oMappTB->setMontant(montant);
	this->oMappTB->setID_Paiment_Moyen(id_paiment_moyent);
	this->oMappTB->setID_Commande(id_paiment_commande);

	sql = this->oMappTB->UpdatePaiment();

	this->oCad->actionRows(sql);
}