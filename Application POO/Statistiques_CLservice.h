#pragma once
#include "CAD.h"
#include "Statistiques_CLmapTB.h"

namespace NS_Comp_Svc_Statistique
{
	ref class CLservicesStatistique
	{
	private:
		NS_Comp_Data::CLcad^ oCad;
		NS_Comp_Mappage_Statistique::CLmapStatistique^ oMappTB;
	public:
		CLservicesStatistique(void);

		System::Data::DataSet^ Panier_Moyen(System::String^);
		System::Data::DataSet^ ProduitSousSeuil(System::String^);
		System::Data::DataSet^ BestVente(System::String^);
		System::Data::DataSet^ BADVente(System::String^);
		System::Data::DataSet^ ValeurStockCommercial(System::String^);
		System::Data::DataSet^ ValeurAchatStock(System::String^);
		System::Data::DataSet^ selectValeurStockVariation(System::String^);
		System::Data::DataSet^ selectMontantAchatClient(System::String^);
		System::Data::DataSet^ selectChiffreAffaireMois(System::String^);
		void ValeurStockVariation(System::String^, System::String^, System::String^, System::String^);
		void MontantAchatClient(System::String^, System::String^);
		void ChiffreAffaireMois(int);
		

	};
}
