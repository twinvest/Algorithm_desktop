#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int index = 0;
	int alphabet[26] = {0,};
	char str[2000] = "APS ZU BMS THAAMT KB SOP CHAAPJ MQ LPUWHKX. K UHJ SM JMZ SMLHJ VJ QXKPBLU -- UM PCPB SOMZDO TP QHEP SOP LKQQKEZASKPU MQ SMLHJ HBL SMVMXXMT, K USKAA OHCP H LXPHV. KS KU H LXPHV LPPWAJ XMMSPL KB SOP HVPXKEHB LXPHV. K OHCP H LXPHV SOHS MBP LHJ SOKU BHSKMB TKAA XKUP ZW HBL AKCP MZS SOP SXZP VPHBKBD MQ KSU EXPPL: \"TP OMAL SOPUP SXZSOU SM IP UPAQ - PCKLPBS, SOHS HAA VPB HXP EXPHSPL PGZHA. \"K OHCP H LXPHV SOHS MBP LHJ MB SOP XPL OKAAU MQ DPMXDKH SOP UMBU MQ QMXVPX UAHCPU HBL SOP UMBU MQ QMXVPX UAHCP MTBPXU TKAA IP HIAP SM UKS LMTB SMDPSOPX HS SOP SHIAP MQ IXMSOPXOMML.K OHCP H LXPHV SOHS MBP LHJ PCPB SOP USHSP MQ VKUUKUUKWWK, H USHSP UTPASPXKBD TKSO SOP OPHS MQ KBFZUSKEP, UTPASPXKBD TKSO SOP OPHS MQ MWWXPUUKMB, TKAA IP SXHBUQMXVPL KBSM HB MHUKU MQ QXPPLMV HBL FZUSKEP.K OHCP H LXPHV SOHS VJ QMZX AKSSAP EOKALXPB TKAA MBP LHJ AKCP KB H BHSKMB TOPXP SOPJ TKAA BMS IP FZLDPL IJ SOP EMAMX MQ SOPKX URKB IZS IJ SOP EMBSPBS MQ SOPKX EOHXHESPX.K OHCP H LXPHV SMLHJ.K OHCP H LXPHV SOHS MBP LHJ LMTB KB HAHIHVH, TKSO KSU CKEKMZU XHEKUSU, TKSO KSU DMCPXBMX OHCKBD OKU AKWU LXKWWKBD TKSO SOP TMXLU MQ KBSPXWMUKSKMB HBL BZAAKQKEHSKMB -- MBP LHJ XKDOS SOPXP KB HAHIHVH AKSSAP IAHER IMJU HBL IAHER DKXAU TKAA IP HIAP SM FMKB OHBLU TKSO AKSSAP TOKSP IMJU HBL TOKSP DKXAU HU UKUSPXU HBL IXMSOPXU.K OHCP H LXPHV SMLHJ.K OHCP H LXPHV SOHS MBP LHJ PCPXJ CHAAPJ UOHAA IP PNHASPL, HBL PCPXJ OKAA HBL VMZBSHKB UOHAA IP VHLP AMT, SOP XMZDO WAHEPU TKAA IP VHLP WAHKB, HBL SOP EXMMRPL WAHEPU TKAA IP VHLP USXHKDOS, HBL SOP DAMXJ MQ SOP AMXL UOHAA IP XPCPHAPL HBL HAA QAPUO UOHAA UPP KS SMDPSOPX.";
	char str2[2000];
	char * p = str;
	strcpy(str2, str);
	for(; *p !=NULL; p++)
	{
		if (*p == 'A')
		{
			str2[index] = 'l';
			alphabet[0]++;
		}
			
		if (*p == 'B')
		{
			str2[index] = 'n';
			alphabet[1]++;
		}
		if (*p == 'C')
		{
			str2[index] = 'v';
			alphabet[2]++;
		}
			
		if (*p == 'D')
		{
			str2[index] = 'g';
			alphabet[3]++;
		}
			
		if (*p == 'E') {
			str2[index] = 'c';
			alphabet[4]++;
		}
			
		if (*p == 'F') {
			str2[index] = 'j';
			alphabet[5]++;
		}
			
		if (*p == 'G')
		{
			str2[index] = 'q';
			alphabet[6]++;
		}
			
		if (*p == 'H')
		{
			str2[index] = 'a';
			alphabet[7]++;
		}
			
		if (*p == 'I')
		{
			str2[index] = 'b';
			alphabet[8]++;
		}
			
		if (*p == 'J')
		{
			str2[index] = 'y';
			alphabet[9]++;
		}
			
		if (*p == 'K')
		{
			str2[index] = 'i';
			alphabet[10]++;
		}
			
		if (*p == 'L')
		{
			str2[index] = 'd';
			alphabet[11]++;
		}
			

		if (*p == 'M')
		{
			str2[index] = 'o';
			alphabet[12]++;

		}
			

		if (*p == 'N')
		{
			str2[index] = 'x';
			alphabet[13]++;
		}
			

		if (*p == 'O')
		{
			str2[index] = 'h';
			alphabet[14]++;
		}
			

		if (*p == 'P')
		{
			str2[index] = 'e';
			alphabet[15]++;
		}
			

		if (*p == 'Q')
		{
			str2[index] = 'f';
			alphabet[16]++;

		}
			

		if (*p == 'R') {
			str2[index] = 'k';
			alphabet[17]++;
		}
			

		if (*p == 'S')
		{
			str2[index] = 't';
			alphabet[18]++;
		}
		
		if (*p == 'T')
		{
			str2[index] = 'w';
			alphabet[19]++;
		}
			
		if (*p == 'U')
		{
			str2[index] = 's';
			alphabet[20]++;
		}
			
		if (*p == 'V') {
			str2[index] = 'm';
			alphabet[21]++;
		}
			
		if (*p == 'W')
		{
			str2[index] = 'p';
			alphabet[22]++;
		}
			
		if (*p == 'X') {
			str2[index] = 'r';
			alphabet[23]++;
		}
			
		if (*p == 'Y')
			alphabet[24]++;
		if (*p == 'Z')
		{
			str2[index] = 'u';
			alphabet[25]++;
		}
		index++;
	}
	printf("%s\n", str2);
	char tmp = 'A';
	p = &tmp;
	for (int i = 0; i < sizeof(alphabet) / sizeof(int); i++)
	{
		printf("%c : %d\n", (*p) + i, alphabet[i]);
	}
	//printf("%d", str.length());
	//cout << str << endl;
}