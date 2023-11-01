#include <iostream>
using namespace std;



// ������ �Լ� (1��)
void Swap(int* PA, int* PB)
{
	int Temp = *PA;
	*PA = *PB;
	*PB = Temp;
}

// ����ü (3��)
struct Player
{
	int X;
	int Y;
	int Z;
};

// ����ü ���� (3��)
//	�Լ� ����� ���ؼ� main �ۿ��� ������. ���� ����� �� ���ο��� �����ص� ��
Player* PlayerPtr = new Player[10];

//		����ü �����Ҵ� Ȯ�ο� ����Ʈ �Լ� (3��)
void PrintStruct();



int main()
{

	// 1. ������ �Լ�
	int A = 10;
	int B = 20;

	int* PA = &A;
	int* PB = &B;

	Swap(PA, PB);

	cout << A << ", " << B << endl;

	// 2. ������ �����Ҵ� : �⺻ ���� -> �̴�� �ܿ��� ��� ����
	//		�޸� ����/���� ����
	//		�����Ҵ��ϴ� ��� (������ ���� ������ ����) �޸� ������ �ȵ�
	int* ptr = new int[10]; // �޸� ���� �Ҵ�
	if (ptr)
	{
		// ó��
	}
	delete[] ptr; // �޸� ����
	ptr = nullptr; // �ʱ�ȭ (* dagling pointer)


	// 3. ����ü (Struct)
	//			�����Ҵ�
	Player PlayerData;
	PlayerData.X = 20;
	PlayerData.Y = 30;
	cout << PlayerData.X << ", " << PlayerData.Y << endl;

	//			�����Ҵ�
	

	for (int i = 0; i < 10; i++)
	{
		(*(PlayerPtr + i)).X = i; // ����ü ������ �� ����Ű�� ���� �����Ͽ� ������� (X) �Ҵ�
		PlayerPtr[i].Y = i; // ����ü �����Ϳ� ����� �޸� �ּҰ��� �����Ͽ� ������� (Y) �Ҵ�
		(PlayerPtr + i)->Z = i; // Y �Ҵ��ϴ� �Ͱ� ������ ��� (����)
		
	}

	PrintStruct(); // �����Ҵ�� �� ���

	delete[] PlayerPtr;
	PlayerPtr = nullptr;

	return 0;
}

void PrintStruct()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << "��° X : " << (PlayerPtr + i)->X << endl;
		cout << i << "��° Y : " << (PlayerPtr + i)->Y << endl;
		cout << i << "��° X : " << (PlayerPtr + i)->Z << endl;
	}
}