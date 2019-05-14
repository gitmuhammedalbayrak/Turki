#include "Zaman.hpp"


void Zaman::tkvm_hrist_v_d()
{
	Zaman::now = time(0);
	Zaman::ltm = localtime(&now);
	Zaman::dt = ctime(&now);

	Zaman::hrist_rakam_gun_senenin = (1 + Zaman::ltm->tm_yday);
};
void Zaman::vkt_karisik_gecici()
{
	Zaman::dosya_adresi = "include\\Vakitler.xml";
	Zaman::dosya.load_file(Zaman::dosya_adresi);
	Zaman::sehir = dosya.child("cityinfo");

	char buffer[5];
	std::sprintf(buffer, "%d", Zaman::hrist_rakam_gun_senenin);
	const char *h_r_g_s_c_c = buffer;


	Zaman::xml_bu_gun = Zaman::sehir.find_child_by_attribute("prayertimes", "dayofyear", h_r_g_s_c_c).text().get();
	Zaman::b_h_aksam = Zaman::xml_bu_gun.substr(50, 5);

	int b_h_aksam_td = (std::stoi(b_h_aksam.substr(0, 2)) * 60) + (std::stoi(b_h_aksam.substr(3, 5)));

	int hrist_zaman_td = ((hrist_saat * 60) * 60) + (hrist_dakika * 60) + hrist_saniye;
	int hrist_zaman_td_t = ((1440 - b_h_aksam_td) * 60) + hrist_zaman_td;

	Zaman::saat = int(((hrist_zaman_td_t / 60) / 60) % 12);
	Zaman::dakika = int((hrist_zaman_td_t / 60) % 60);
	Zaman::saniye = int((hrist_zaman_td_t) % 60);

	Zaman::simdiki_zaman_turk.append(
		std::to_string(Zaman::saat) +
		":" +
		std::to_string(Zaman::dakika) +
		":" +
		std::to_string(Zaman::saniye)
	);
};
void Zaman::sat_hrist_v_d()
{
	Zaman::hrist_saat = Zaman::ltm->tm_hour;
	Zaman::hrist_dakika = Zaman::ltm->tm_min;
	Zaman::hrist_saniye = Zaman::ltm->tm_sec;
};

Zaman::Zaman()
{
	tkvm_hrist_v_d();
	sat_hrist_v_d();
	vkt_karisik_gecici();

	std::cout << "___ " << Zaman::simdiki_zaman_turk << " ___" << std::endl;
}
Zaman::~Zaman()
{
}