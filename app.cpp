#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class myNode
{
	public:
		int myNodeIndex = 0;
		double myNodeDistance = 0.0;
};

// Global Variable
vector<vector<int>> arrOfPoint;

vector<myNode*> indexVec;
//vector<double> distenceVec;

//vector<int> 
//Choose the point 
int num_to_find = 0;
int num_to_choose = 0;
//int x_coordinates = 0, y_coordinates = 0;
vector<int> tempToFind;
int num = 0;
int k_dimensional = 0;

//Global Function;

void mySort(vector<myNode*> &idx)
{
	double swapTemp = 0;
	int swapTempInt = 0;
	for (int q = 0; q < num; q++)
	{
		for (int p = q + 1; p < num; p++)
		{
			if (idx[q]->myNodeDistance > idx[p]->myNodeDistance)
			{
				swapTemp = idx[q]->myNodeDistance;
				idx[q]->myNodeDistance = idx[p]->myNodeDistance;
				idx[p]->myNodeDistance = swapTemp;
				swapTempInt = idx[q]->myNodeIndex;
				idx[q]->myNodeIndex = idx[p]->myNodeIndex;
				idx[p]->myNodeIndex = swapTempInt;
			}
		}
	}

}

double distenceCalculate(vector<int> &a, vector<int> &b)
{
	int deltaDistance = 0;
	double deltaDistanceDouble = 0;
	for (int h = 0; h < k_dimensional; h++)
	{
		deltaDistance += (a[h] - b[h])*(a[h] - b[h]);
	}
	deltaDistanceDouble = (double)deltaDistance;
	return deltaDistanceDouble = sqrt(deltaDistanceDouble);
}
void findClosestPoint(vector<int> temp)
{
	for (int i = 0; i < num; i++)
	{
		indexVec[i] = new myNode();
		indexVec[i]->myNodeDistance  = distenceCalculate(temp, arrOfPoint[i]);
		indexVec[i]->myNodeIndex = i;
	}

	mySort(indexVec);
}

int main()
{
	indexVec.resize(50000);
	arrOfPoint.resize(50000);

	cin >> num;
	cin >> k_dimensional;

	//int x_coordinates = 0, y_coordinates = 0;
	for (int i = 0; i < num; i++)
	{
		arrOfPoint[i].resize(5);
		for (int j = 0; j < k_dimensional; j++)
		{
			cin >> arrOfPoint[i][j];
		}
	}
	// input data over;

	cin >> num_to_choose;
	
	while (num_to_choose)
	{
		tempToFind.clear();
		tempToFind.resize(5);
		for (int z = 0; z < k_dimensional; z++)
		{
			
			cin >> tempToFind[z];

		}
		cin >> num_to_find;
		cout << "the closest " << num_to_find << " points are:" << endl;
		findClosestPoint(tempToFind);
		//TODO sort(); ----> hash();
		int i_x_temp = 0;
		
		while (num_to_find)
		{
			//TODO
			// cout << X_coordinats << " "<< Y_coordinates << endl; 
			// num_to_find --;
			//num_to_find;
			int j_x_temp = 0;
			cout << arrOfPoint[indexVec[i_x_temp]->myNodeIndex][j_x_temp];
			j_x_temp++;
			for ( ;j_x_temp < k_dimensional; j_x_temp++)
			{
				cout << " "<< arrOfPoint[indexVec[i_x_temp]->myNodeIndex][j_x_temp] ;
			}
			cout << endl;
			 
			// next closest points;
			i_x_temp ++;
			num_to_find--;
			
		}
		
		num_to_choose -- ;
		for (int op = 0; op < num; op++)
		{
			delete (indexVec[op]);
		}
	}

	//system("pause");
	return 0;

}
