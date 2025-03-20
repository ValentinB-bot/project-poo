#pragma once
namespace NS_Comp_Mappage_Statistique
{
	ref class CLmapStatistique
	{
	private:
		System::String^ sSql;
		System::String^ Designation_Article;
		System::Int16^ Quantite_Article;
		System::Int16^ Seuil_Reapprovisionnement;
		System::Decimal^ Prix_Article;
		System::String^ DemarqueInconnue;
		System::String^ Marge_Commerciale;
		System::String^ Remise_Commerciale;
		System::Decimal^ Prix_HT_Article;
		System::String^ Taux_TVA;
		System::String^ Nom_Client;
		System::String^ Prenom_Client;
		int Date_Emission;

	public:

		System::String^ Select_Panier_Moyen(void);
		System::String^ Select_ChiffreAffaireMois(void);
		System::String^ Select_ProduitSousSeuil(void);
		System::String^ Select_BestVente(void);
		System::String^ Select_BadVente(void);
		System::String^ Select_ValeurStockCommercial(void);
		System::String^ Select_ValeurAchatStock(void);
		System::String^ Select_ValeurStockVariation(void);
		System::String^ Select_MontantAchatClient(void);

		void setDate_Emission(int);
		void setNom_Client(System::String^);
		void setPrenom_CLient(System::String^);
		void setMarge_Commerciale(System::String^);
		void setRemise_Commerciale(System::String^);
		void setDemarqueInconnue(System::String^);
		void setTaux_TVA(System::String^);
	};
}
