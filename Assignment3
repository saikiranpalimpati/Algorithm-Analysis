#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
using namespace std;
int CoinCtGreedy(vector<int> d, int x);
int CoinCtDP(vector<int> d, int x);
void swap(int &i, int& j);

void shuffle(int *arr, size_t n);
void main()
{

	srand(time(NULL));

	//shuffling the values in an array


	double m, k, ave = 0, totalAve = 0;
	for (int t = 100; t < 500; t++)
	{
		for (int j = 0; j < 100; j++)
		{
			int s = 100;
			//array used for have integer values from 1 to 100
			int *a = new int[s];
			for (int i = 0; i < s; i++)
			{
				a[i] = i + 1;
			}
			shuffle(a, s);
			vector<int> d;
			d.push_back(1);
			int n = 7;
			int i = 0;
			while (n > 1)
			{	//inserting the different numbers into a vector of denominations and checking whether the denominations has one as avalue in them
				if (a[i] == 1)
				{
					i = i + 1;
				}
				else {
					d.push_back(a[i]);
					i++;
					n--;
				}
			}
			m = CoinCtDP(d, t);
			k = CoinCtGreedy(d, t);
			ave += (m / k) * 100;
			delete[]a;
		}
		totalAve += ave / 100;
		ave = 0;
	}
	cout << (totalAve / 400);
	system("pause");
}

//greedy algorithm
int CoinCtGreedy(vector<int> d, int x)
{
	sort(d.begin(), d.end(), greater<int>());
	int numcoins = 0;//coin count
	while (x > 0)
	{
		//till the last denomination
		for (int coin : d)
		{
			//division
			numcoins = numcoins + x / coin;
			x %= coin;
		}
	}
	return numcoins;
}
int CoinCtDP(vector<int> d, int x)
{
	int *c = new int[x + 1];
	c[0] = 0;
	int number = 0;
	for (int p = 1; p <= x; p++)
	{
		int min = INT_MAX;
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] <= p)
			{
				if (1 + c[p - d[i]] < min)
					min = 1 + c[p - d[i]];
			}
		}
		c[p] = min;
		number = c[p];
	}
	delete[]c;
	return number;
}
void shuffle(int *arr, size_t n)
{
	int max = 99;
	if (n > 1)
	{
		int i;
		for (i = 0; i < n - 1; i++)
		{
			if (max > 1)
			{
				int j = rand() % max;
				swap(arr[j], arr[i]);
				max--;
			}
		}
	}
}
void swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}
