#ifndef HEADER_ZAMAN_HPP
#define HEADER_ZAMAN_HPP

#include <iostream>
#include <string>
#include <ctime>
#include "pugixml.hpp"


class zaman
{
public:
	pugi::xml_document dosya;
	pugi::xml_node sehir;

	std::string bu_gun_deger;
	std::string xml_bu_gun;
	std::string b_h_aksam;
	std::string simdiki_zaman_turk;

	time_t now;
	tm *ltm;

	const char* dosya_adresi;
	const char* bu_gun_const;

	char* dt;

	unsigned int hrist_rakam_gun_senenin;
	unsigned int saat;
	unsigned int dakika;
	unsigned int saniye;
	unsigned int hrist_saat;
	unsigned int hrist_dakika;
	unsigned int hrist_saniye;


	void tkvm_hrist_v_d();
	void vkt_karisik_gecici();
	void sat_hrist_v_d();

	zaman();
	~zaman();
};

#endif