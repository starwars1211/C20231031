#include <iostream>
using namespace std;



// 포인터 함수 (1번)
void Swap(int* PA, int* PB)
{
	int Temp = *PA;
	*PA = *PB;
	*PB = Temp;
}

// 구조체 (3번)
struct Player
{
	int X;
	int Y;
	int Z;
};

// 구조체 선언 (3번)
//	함수 사용을 위해서 main 밖에서 선언함. 실제 사용할 땐 내부에서 선언해도 됨
Player* PlayerPtr = new Player[10];

//		구조체 동적할당 확인용 프린트 함수 (3번)
void PrintStruct();



int main()
{

	// 1. 포인터 함수
	int A = 10;
	int B = 20;

	int* PA = &A;
	int* PB = &B;

	Swap(PA, PB);

	cout << A << ", " << B << endl;

	// 2. 포인터 동적할당 : 기본 포맷 -> 이대로 외워서 사용 권장
	//		메모리 생성/삭제 목적
	//		정적할당하는 경우 (포인터 없이 변수로 설정) 메모리 해제가 안됨
	int* ptr = new int[10]; // 메모리 동적 할당
	if (ptr)
	{
		// 처리
	}
	delete[] ptr; // 메모리 해제
	ptr = nullptr; // 초기화 (* dagling pointer)


	// 3. 구조체 (Struct)
	//			정적할당
	Player PlayerData;
	PlayerData.X = 20;
	PlayerData.Y = 30;
	cout << PlayerData.X << ", " << PlayerData.Y << endl;

	//			동적할당
	

	for (int i = 0; i < 10; i++)
	{
		(*(PlayerPtr + i)).X = i; // 구조체 포인터 가 가리키는 값에 접근하여 멤버변수 (X) 할당
		PlayerPtr[i].Y = i; // 구조체 포인터에 저장된 메모리 주소값에 접근하여 멤버변수 (Y) 할당
		(PlayerPtr + i)->Z = i; // Y 할당하는 것과 동일한 방법 (축약식)
		
	}

	PrintStruct(); // 동적할당된 값 출력

	delete[] PlayerPtr;
	PlayerPtr = nullptr;

	return 0;
}

void PrintStruct()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << "번째 X : " << (PlayerPtr + i)->X << endl;
		cout << i << "번째 Y : " << (PlayerPtr + i)->Y << endl;
		cout << i << "번째 X : " << (PlayerPtr + i)->Z << endl;
	}
}