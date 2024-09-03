/**
 * -e-
 *
 * vasatî - version 0.9
 * --------------------------------------------------------
 * Copyright (C) 1439-1440, by M.M.M. Samil R.T.Ü (muhammed.samil.albayrak@outlook.com)
 *
 * This software is licensed under T1. For details, see the end of this file.
 *
 * This software utilizes the pugixml parser.
 * [Copyright (C) 2006-2018, by Arseny Kapoulkine (arseny.kapoulkine@gmail.com)]
 */

#ifndef SOURCE_ZAMAN_CPP
#define SOURCE_ZAMAN_CPP

#include "zaman.hpp"


void zaman::tkvm_hrist_v_d()
{
	zaman::now = time(0);
	zaman::ltm = localtime(&now);
	zaman::dt = ctime(&now);

	zaman::hrist_rakam_gun_senenin = (1 + zaman::ltm->tm_yday);
};
void zaman::vkt_karisik_gecici()
{
	zaman::dosya_adresi = "include\\vakitler.xml";
	zaman::dosya.load_file(zaman::dosya_adresi);
	zaman::sehir = dosya.child("cityinfo");

	char buffer[5];
	std::sprintf(buffer, "%d", zaman::hrist_rakam_gun_senenin);
	const char *h_r_g_s_c_c = buffer;


	zaman::xml_bu_gun = zaman::sehir.find_child_by_attribute("prayertimes", "dayofyear", h_r_g_s_c_c).text().get();
	zaman::b_h_aksam = zaman::xml_bu_gun.substr(50, 5);

	int b_h_aksam_td = (std::stoi(b_h_aksam.substr(0, 2)) * 60) + (std::stoi(b_h_aksam.substr(3, 5)));

	int hrist_zaman_td = ((hrist_saat * 60) * 60) + (hrist_dakika * 60) + hrist_saniye;
	int hrist_zaman_td_t = ((1440 - b_h_aksam_td) * 60) + hrist_zaman_td;

	zaman::saat = int(((hrist_zaman_td_t / 60) / 60) % 12);
	zaman::dakika = int((hrist_zaman_td_t / 60) % 60);
	zaman::saniye = int((hrist_zaman_td_t) % 60);

	zaman::simdiki_zaman_turk.append(
		std::to_string(zaman::saat) +
		":" +
		std::to_string(zaman::dakika) +
		":" +
		std::to_string(zaman::saniye)
	);
};
void zaman::sat_hrist_v_d()
{
	zaman::hrist_saat = zaman::ltm->tm_hour;
	zaman::hrist_dakika = zaman::ltm->tm_min;
	zaman::hrist_saniye = zaman::ltm->tm_sec;
};

zaman::zaman()
{
	tkvm_hrist_v_d();
	sat_hrist_v_d();
	vkt_karisik_gecici();

	std::cout << "___ " << zaman::simdiki_zaman_turk << " ___" << std::endl;
}
zaman::~zaman()
{
}
#endif

/**
 * Copyright (C) 1439-1440, by M.M.M. Samil R.T.Ü (muhammed.samil.albayrak@outlook.com)
 *
 * T1 License Details:
 *
 * Redistribution and usage require notification to the developer.
 * Unauthorized use and development are prohibited. Rights may be revoked
 * if any hostility against Turkey is identified. This license and its
 * terms must be cited without omission in any redistributed or derivative
 * works. The code cannot be sold or used for commercial profit.
 * 
 * -e-
 */
