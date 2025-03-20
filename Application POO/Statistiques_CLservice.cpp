#include "Statistiques_CLservice.h"

NS_Comp_Svc_Statistique::CLservicesStatistique::CLservicesStatistique(void)
{
	this->oCad = gcnew NS_Comp_Data::CLcad();
	this->oMappTB = gcnew NS_Comp_Mappage_Statistique::CLmapStatistique();
}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::Panier_Moyen(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_Panier_Moyen();
	return this->oCad->getRows(sql, dataTableName);
	
}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::ProduitSousSeuil(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_ProduitSousSeuil();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::BestVente(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_BestVente();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::BADVente(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_BadVente();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::ValeurAchatStock(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_ValeurAchatStock();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::ValeurStockCommercial(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_ValeurStockCommercial();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::selectChiffreAffaireMois(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_ChiffreAffaireMois();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::selectMontantAchatClient(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_MontantAchatClient();
	return this->oCad->getRows(sql, dataTableName);

}
System::Data::DataSet^ NS_Comp_Svc_Statistique::CLservicesStatistique::selectValeurStockVariation(System::String^ dataTableName)
{
	System::String^ sql;
	sql = this->oMappTB->Select_ValeurStockVariation();
	return this->oCad->getRows(sql, dataTableName);

}
void NS_Comp_Svc_Statistique::CLservicesStatistique::ChiffreAffaireMois(int date_Emission)
{

	this->oMappTB->setDate_Emission(date_Emission);


}
void NS_Comp_Svc_Statistique::CLservicesStatistique::MontantAchatClient(System::String^ nom, System::String^ prenom)
{

	this->oMappTB->setNom_Client(nom);
	this->oMappTB->setPrenom_CLient(prenom);


}
void NS_Comp_Svc_Statistique::CLservicesStatistique::ValeurStockVariation(System::String^ Marge_Commerciale, System::String^ Remise_Commerciale, System::String^ DemarqueInconnue, System::String^ TVA)
{

	this->oMappTB->setDemarqueInconnue(DemarqueInconnue);
	this->oMappTB->setMarge_Commerciale(Marge_Commerciale);
	this->oMappTB->setRemise_Commerciale(Remise_Commerciale);
	this->oMappTB->setTaux_TVA(TVA);


}