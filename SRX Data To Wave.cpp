#include <iostream>
#include "ByteReader.h"
#include "RIAA.h"

#pragma warning(disable : 4996)

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;

int DataToInt(unsigned char* Data)
{
	return int((unsigned char)(Data[0]) << 24 |
		(unsigned char)(Data[1]) << 16 |
		(unsigned char)(Data[2]) << 8 |
		(unsigned char)(Data[3]));
}

short DataToShort(unsigned char* Data)
{
	return (short)((unsigned char)(Data[0]) << 8 |
		(unsigned char)(Data[1]));
}

#include <string>
#include <algorithm>

template <typename T>
T clip(const T& n, const T& lower, const T& upper) {
	return std::max(lower, std::min(n, upper));
}

int main()
{
	const char* filename_in = "../SD-20ROM.bin";
    float wavmax=0;
	FILE* f = fopen(filename_in, "rb");
	if (!f) {
		printf("Error: cannot open %s: %s\n", filename_in,
			strerror(errno));
		return 1;
	}

	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	u8* buf = (u8*)malloc(fsize);
	u8* outbuf = (u8*)malloc(fsize);
	fread(buf, fsize, 1, f);
	fclose(f);

	ByteReader ReaderStandart = ByteReader(buf, fsize);

	int WaveIndeficatorPosition = DataToInt(&buf[0x84]);
	int WaveIndeficatorSize = DataToInt(&buf[0x88]);

	unsigned short WaveCount = DataToShort(&buf[WaveIndeficatorPosition]);

	int SampleRate = 44100;
	int BitDepth = 32;


    float vol=0;
	for (int i = 0; i < WaveCount; i++)
	{
		int PositionFinal = WaveIndeficatorPosition + 12 + (24 * i);

		int StartWavePosition = DataToInt(&buf[PositionFinal + 12]);
		int StartWaveEnd = DataToInt(&buf[PositionFinal + 20]);
        int LoopPosition = DataToInt(&buf[PositionFinal + 16]);
        int after=StartWaveEnd-LoopPosition+1;
        int lc=0;
        int ll=after;
        if(after<=1){
            after=0;
        }else {
            lc=1;
        }
        if((2003<=i&&i<=2010)||(2206<=i&&i<=2211)){
            lc=0;
        }
        int yyy=0;
        if(449<=i&&i<=459){
            yyy=1;
        }
        if(i==437){
            yyy=1;
        }
        if(1971<=i&&i<=1981){
            yyy=1;
        }
        if(460<=i&&i<=468){
            yyy=1;
        }
        if(1537<=i&&i<=1542){
            yyy=1;
        }
        if(i==495){
            yyy=1;
        }
        if(i==1543){
            yyy=1;
        }
        if(1377<=i&&i<=1385){
            yyy=1;
        }
        if(555<=i&&i<=558){
            yyy=1;
        }
        if(573<=i&&i<=581){
            yyy=1;
        }
        if(785<=i&&i<=795){
            yyy=1;
        }
        if(903<=i&&i<=913){
            yyy=1;
        }
        if(1369<=i&&i<=1376){
            yyy=1;
        }
        if(2038<=i&&i<=2051){
            yyy=1;
        }
        if(1478<=i&&i<=1505){
            yyy=1;
        }
        if(1814<=i&&i<=1845){
            yyy=1;
        }
        if(799<=i&&i<=810){
            yyy=1;
        }
        if(811<=i&&i<=814){
            yyy=1;
        }
        if(1093<=i&&i<=1096){
            yyy=1;
        }
        if(886<=i&&i<=892){
            yyy=1;
        }
        if(i==1544){
            yyy=1;
        }
        if(1788<=i&&i<=1790){
            yyy=1;
        }
        if(1792<=i&&i<=1803){
            yyy=1;
        }
        if(1805<=i&&i<=1813){
            yyy=1;
        }
        if(893<=i&&i<=902){
            yyy=1;
        }
        if(i==1545){
            yyy=1;
        }
        if(1009<=i&&i<=1012){
            yyy=1;
        }
        if(i==1606){
            yyy=1;
        }
        if(1086<=i&&i<=1088){
            yyy=1;
        }
        if(477<=i&&i<=479){
            yyy=1;
        }
        if(1173<=i&&i<=1178){
            yyy=1;
        }
        if(i==42){
            yyy=1;
        }
        if(1601<=i&&i<=1602){
            yyy=1;
        }
        if(i==39){
            yyy=1;
        }
        if(i==1208){
            yyy=1;
        }
        if(i==191){
            yyy=1;
        }
        if(i==1223){
            yyy=1;
        }
        if(46<=i&&i<=47){
            yyy=1;
        }
        if(166<=i&&i<=169){
            yyy=1;
        }
        if(146<=i&&i<=159){
            yyy=1;
        }
        if(i==220){
            yyy=1;
        }
        if(81<=i&&i<=82){
            yyy=1;
        }
        if(176<=i&&i<=193){
            yyy=1;
        }
        if(i==15){
            yyy=1;
        }
        if(i==18){
            yyy=1;
        }
        if(i==39){
            //yyy=1;
        }
        if(i==43){
            yyy=1;
        }
        if(1192<=i&&i<=1193){
            yyy=1;
        }
        if(i==17){
            yyy=1;
        }
        if(1205<=i&&i<=1206){
            yyy=1;
        }
        if(i==1214){
            yyy=1;
        }


        //lc=0;
        //lc+=1;
        //printf("%d %d %d ",lc,ll,lc*ll);
        int ss=StartWaveEnd - StartWavePosition;
		int Size = StartWaveEnd - StartWavePosition+lc*ll;
		int RealSize = (Size+lc) * 4;









		u8* Wave2 = (u8*)malloc(Size);

		RiaaFilter rf1(32000, 15);
		RiaaFilter rf2(32000, 15);

		float* Wave2Float = (float*)malloc(RealSize);


        int xxx=1;
        float summ=0;
		for (int i1 = 0; i1 < Size; i1++)
		{
			int RealPosition = i1 * 3;
            int i2=i1;
            xxx=0;

            if(yyy==0||i2!=ss) {
                while (i2 >= ss) {

                    xxx = 1;
                    i2 -= ll;
                }
            }
			uint32_t sAddress = StartWavePosition + i2;


			int8_t data = buf[sAddress];
			uint32_t AddressA = (sAddress & 0xFFF00000 | (sAddress >> 5) & 0x7FFF);
			uint8_t sByte = buf[AddressA];
			uint8_t sNibble = (sAddress & 0x10) ? (sByte >> 4) : (sByte & 0x0F);
			int32_t final = ((data << sNibble) << 14);

			float ffinal = ((double)final / (double)(1<<30))/2.0;

			if(i1>0){
                //ffinal+=Wave2Float[i1-1];
            }
            //ffinal = rf1.apply(ffinal);
            //ffinal = rf2.apply(ffinal);

			Wave2Float[i1] = ffinal;
            if(xxx==1){
                Wave2Float[i1]=Wave2Float[i2];

                if(yyy==1){
                    Wave2Float[i1]=Wave2Float[ss*2-i1+1];
                }

            }




            if(abs(wavmax)<abs(ffinal)){
                wavmax=ffinal;
            }
            if(yyy==1){
                summ+=Wave2Float[i1];

            }
		}
        if((2003<=i&&i<=2010)||(2206<=i&&i<=2211)){
            float* Wave2Float_back = (float*)malloc(RealSize);
            for (int i1 = 0; i1 < Size; i1++) {
                Wave2Float_back[i1]=Wave2Float[i1];
            }
            for (int i1 = 0; i1 < Size; i1++) {
                Wave2Float[i1]=Wave2Float_back[Size-i1-1];
            }
        }
        for (int i1 = 0; i1 < Size; i1++) {
            //Wave2Float[i1] = rf1.apply(Wave2Float[i1]);
            //Wave2Float[i1] = rf2.apply(Wave2Float[i1]);
            if(i1>0){
            Wave2Float[i1]+=Wave2Float[i1-1];
            }
            if(lc==1) {
                if (yyy == 0 && i1 >= ss) {
                    Wave2Float[i1] = Wave2Float[i1 - ll];
                }
            }
        }
        vol+=abs(wavmax);
        if(lc==1){
            Wave2Float[Size]=Wave2Float[Size-ll-ll*yyy];
        }



		int HeaderSize = (4 * 5) + 4 + 8 + 4 + 8;
		unsigned int OutSize = RealSize + HeaderSize;
		u8* OutWaveFile = (u8*)malloc(OutSize);
		ByteReader FinalData = ByteReader(OutWaveFile, OutSize);

		FinalData.SetByte((u8)'R');
		FinalData.SetByte((u8)'I');
		FinalData.SetByte((u8)'F');
		FinalData.SetByte((u8)'F');

		FinalData.WriteInt(OutSize);

		FinalData.SetByte((u8)'W');
		FinalData.SetByte((u8)'A');
		FinalData.SetByte((u8)'V');
		FinalData.SetByte((u8)'E');

		FinalData.SetByte((u8)'f');
		FinalData.SetByte((u8)'m');
		FinalData.SetByte((u8)'t');
		FinalData.SetByte((u8)' ');

		FinalData.WriteInt(16);
		FinalData.WriteShort(3);
		FinalData.WriteShort(1);

		FinalData.WriteInt(SampleRate);

		FinalData.WriteInt((SampleRate * BitDepth) / 8);
		FinalData.WriteShort(BitDepth / 8);
		FinalData.WriteShort(BitDepth);

		FinalData.SetByte((u8)'d');
		FinalData.SetByte((u8)'a');
		FinalData.SetByte((u8)'t');
		FinalData.SetByte((u8)'a');

		FinalData.WriteInt(RealSize);

		memcpy(&FinalData.Data[FinalData.Position], Wave2Float, RealSize);


		std::string Folder = "../Sample/";
		Folder += "Wave";
		Folder += std::to_string(i);
		Folder += ".wav";

		const char* Path = Folder.c_str();

		//printf(Path);

		FILE* out = fopen(Path, "wb");
		if (!out) {
			printf("Error: cannot open %s: %s\n", Path,
				strerror(errno));
			return 1;
		}

		fwrite(FinalData.Data, OutSize, 1, out);
		fclose(out);
//        if(i>=1356 && i<=1364) {
//            printf("%d -> ", i);
//            printf("%d %d\n",StartWaveEnd-StartWavePosition,LoopPosition-StartWavePosition-1);
//        }
        //printf("%f\n",wavmax);
        //printf("%d\n",LoopPosition-StartWavePosition-1);
        //printf("%d %d %d %d\n",i,LoopPosition-StartWavePosition-1,ll,LoopPosition-StartWavePosition-1+ll*lc);
        if(lc==1) {
            printf("%d,%d,%d,%d,%d\n", i, StartWaveEnd - StartWavePosition, lc,LoopPosition - StartWavePosition-1,ll);
        }else{
            printf("%d,%d,%d,%d,%d\n", i, StartWaveEnd - StartWavePosition, lc,0,0);
        }
        wavmax=0;


	}
    //printf("avg %f\n",vol/WaveCount);
}

