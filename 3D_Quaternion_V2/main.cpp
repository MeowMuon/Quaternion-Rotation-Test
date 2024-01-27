#include "IO/Graphic.h"
#include <iostream>
#include <time.h>

int main()
{
	Graphic::InitGraph(1024,768);

	Camera C;
	C.SetLocation(DVector(0, 0, 0));
	C.SetRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(0, DVector(1, 0, 0))));
	C.SetScale(DVector(1));
	//C.SetViewDistance(1024/2);
	C.SetViewAngle(30);
	C.SetMoveSpeed(10.0);
	C.SetRotateSpeed(1.0);

	std::vector<DVector> pointSet1 =
	{
		DVector(100, 100, 100),
		DVector(100, -100, 100),
		DVector(100, -100, -100),
		DVector(100, 100, -100),
		DVector(100, 100, 100)
	};
	std::vector<DVector> pointSet2 =
	{
		DVector(-100,100,100),
		DVector(-100,-100,100),
		DVector(-100,-100,-100),
		DVector(-100,100,-100),
		DVector(-100,100,100)
	};
	std::vector<DVector> pointSet3 =
	{
		DVector(100,100,100),
		DVector(-100,100,100),
		DVector(-100,100,-100),
		DVector(100,100,-100),
		DVector(100,100,100)
	};
	std::vector<DVector> pointSet4 =
	{
		DVector(100,-100,100),
		DVector(-100,-100,100),
		DVector(-100,-100,-100),
		DVector(100,-100,-100),
		DVector(100,-100,100)
	};

	Actor A;
	A.SetLocation(DVector(0, 0, 0));
	A.SetRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(30, DVector(1, 0, 0))));
	A.SetScale(DVector(1));
	A.SetPoints({});

	ActorComponent A1(&A);
	A1.SetRLocation(DVector(300, 0, 0));
	A1.SetPoints({ pointSet1 });
	ActorComponent A2(&A);
	A2.SetRLocation(DVector(-300, 0, 0));
	A2.SetPoints({ pointSet2 });
	ActorComponent A3(&A);
	A3.SetRLocation(DVector(0, 300, 0));
	A3.SetPoints({ pointSet3 });
	ActorComponent A4(&A);
	A4.SetRLocation(DVector(0, -300, 0));
	A4.SetPoints({ pointSet4 });

	Actor B;
	B.SetLocation(DVector(0, 0, 0));
	B.SetRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(30, DVector(1, 0, 0))));
	B.SetScale(DVector(1));
	B.SetPoints({});

	ActorComponent B1(&B);
	B1.SetPoints(pointSet1);
	B1.SetRRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(0 + 30, DVector(0, 0, 1))));
	ActorComponent B2(&B);
	B2.SetPoints(pointSet1);
	B2.SetRRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(90 + 30, DVector(0, 0, 1))));
	ActorComponent B3(&B);
	B3.SetPoints(pointSet1);
	B3.SetRRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(-180 + 30, DVector(0, 0, 1))));
	ActorComponent B4(&B);
	B4.SetPoints(pointSet1);
	B4.SetRRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(-90 + 30, DVector(0, 0, 1))));

	Actor ASmileFace;
	for (int i = 0; i <= 360 / 1; i++)
	{
		ASmileFace.AppendPoint(Calculator::RotatePQ(DVector(0, 0, 100), Calculator::MakeRotateQuaternion(1 * i, DVector(1, 0, 0))));
	}
	ASmileFace.SetLocation(DVector(300, 0, 0));
	ASmileFace.SetRotationQ(DQuaternion(Calculator::MakeRotateQuaternion(0, DVector(1, 0, 0))));
	ASmileFace.SetScale(DVector(1));

	ActorComponent AEye1(&ASmileFace);
	for (int i = 0; i <= 360 / 4; i++)
	{
		AEye1.AppendPoint(Calculator::RotatePQ(DVector(0, 0, 5), Calculator::MakeRotateQuaternion(4 * i, DVector(1, 0, 0))));
	}
	AEye1.SetRLocation(DVector(0, 40, 30));
	ActorComponent AEye2(&ASmileFace);
	for (int i = 0; i <= 360 / 4; i++)
	{
		AEye2.AppendPoint(Calculator::RotatePQ(DVector(0, 0, 5), Calculator::MakeRotateQuaternion(4 * i, DVector(1, 0, 0))));
	}
	AEye2.SetRLocation(DVector(0, -40, 30));
	ActorComponent AMouth(&ASmileFace);
	for (int i = 120 / 4; i <= 240 / 4; i++)
	{
		AMouth.AppendPoint(Calculator::RotatePQ(DVector(0, 0, 50), Calculator::MakeRotateQuaternion(4 * i, DVector(1, 0, 0))));
	}
	AMouth.SetRLocation(DVector(0, 0, 0));




	int tempS = 0;

	time_t FT;
	while (1)
	{
		FT = clock();
		Graphic::Erase();
		Graphic::DisplayA(&ASmileFace, &C);
		//Graphic::DisplayA(&A, &C);
		//Graphic::DisplayA(&B, &C);

		//A.RotateQ(DQuaternion(Calculator::MakeRotateQuaternion(1.44 / 4, DVector(-2, -3, -5))));
		//A1.RRotateQ(DQuaternion(Calculator::MakeRotateQuaternion(1.44 / 2, DVector(1, 0, 0))));
		//A2.SetRScale(DVector(1.0, 1 + (sin(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 2 + 0.0) / 1, 1 - (sin(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 2 + 0.0) / 1));
		//A3.RMove(DVector(0.0, 0 + (cos(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 1 + 0.0) / 0.2, 0.0));
		//A4.RMove(DVector(0.0, 0 + (cos(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 1 + 0.0) / 0.2, 0.0));
		//B.RotateQ(Calculator::MakeRotateQuaternion(1.44 / 2, DVector(0, 0, 1)));
		//B.SetScale(DVector(
		//	1 + (sin(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 2 + 0.0) / 1,
		//	1 + (-sin(Data_pi / 120 * tempS + 0 * Data_pi / 1.5) / 2 + 0.0) / 1,1
		//	//1 + (cos(Data_pi / 120 * tempS + 2 * Data_pi / 1.5) + 0.0) / 1
		//));
		ASmileFace.RotateQ(Calculator::MakeRotateQuaternion(1.44 / 2, DVector(0, 0, 1)));
		tempS++;
		//A.tick(1);
		//B.tick(1);
		ASmileFace.tick(1);
		C.tick(1);

		while (clock() < FT + 1000 / 30);
	}
	Graphic::CloseGraph();
}