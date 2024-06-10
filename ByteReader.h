#pragma once

class ByteReader
{
public:
	unsigned int Position = 0;
	unsigned int DataSize = 0;
	unsigned char* Data;

	ByteReader(unsigned char* Data, unsigned int DataSize)
	{
		this->Data = Data;
		this->DataSize = DataSize;
	}

	void Move(unsigned int Value)
	{
		Position += Value;
	}

	unsigned char GetByte()
	{
		unsigned char Byte = Data[Position];
		Move(1);
		return Byte;
	}

	unsigned char* GetBytes(unsigned int Size)
	{
		unsigned char* Array = new unsigned char[Size];
		for (unsigned int i = 0; i < Size; i++)
		{
			Array[i] = GetByte();
		}
		return Array;
	}

	void SetByte(unsigned char Byte)
	{
		Data[Position] = Byte;
		Move(1);
	}

	void SetBytes(unsigned char* Data, unsigned int Size)
	{
		for (unsigned int i = 0; i < Size; i++)
		{
			this->Data[Position] = Data[i];
			Move(1);

		}
	}

	void WriteInt(int Value)
	{
		unsigned char Bytes[4];
		memcpy(Bytes, &Value, sizeof(Value));

		SetBytes(Bytes, 4);
	}

	void WriteShort(short Value)
	{
		unsigned char Bytes[2];
		memcpy(Bytes, &Value, sizeof(Value));

		SetBytes(Bytes, 2);
	}

	void FloatOverlay(float Value,float Power)
	{
		unsigned char Bytes[4];
		memcpy(Bytes, &Value, sizeof(Value));
		for (unsigned int i = 0; i < 4; i++)
		{
			this->Data[Position] = Bytes[i]*Power;
			Move(1);
		}
	}

};