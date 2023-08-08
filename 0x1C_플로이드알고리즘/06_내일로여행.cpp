#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int INF = 0x3F333333;
unordered_map<string, int> transports = {
	{"Subway", 0 },
	{"Bus", 1},
	{"Taxi", 2},
	{"Airplane", 3 },
	{"KTX", 4},
	{"S-Train", 5},
	{"V-Train", 6},
	{"ITX-Saemaeul", 7},
	{"ITX-Cheongchun", 8},
	{"Mugunghwa", 9}
};

int N, R, M, K;
unordered_map<string, int> cities;
int costsOrigin[101][101];
int costsNailo[101][101];
vector<string> path;
int cityCnt;

void floyd()
{
	for (int k = 0; k < cityCnt; ++k)
	{
		for (int i = 0; i < cityCnt; ++i)
		{
			for (int j = 0; j < cityCnt; ++j)
			{
				costsOrigin[i][j] = min(costsOrigin[i][j], costsOrigin[i][k] + costsOrigin[k][j]);
				costsNailo[i][j] = min(costsNailo[i][j], costsNailo[i][k] + costsNailo[k][j]);
			}
		}
	}
}

int main()
{
	cin >> N >> R;

	for (int i = 0; i < N; ++i)
	{
		string cityName;
		cin >> cityName;
		if (cities.find(cityName) == cities.end())
		{
			cities[cityName] = cityCnt++;
		}
	}
	for (int i = 0; i < cityCnt; ++i)
	{
		fill(costsOrigin[i], costsOrigin[i] + cityCnt, INF);
		fill(costsNailo[i], costsNailo[i] + cityCnt, INF);
		costsOrigin[i][i] = 0;
		costsNailo[i][i] = 0;
	}

	cin >> M;
	while (M--)
	{
		string cityName;
		cin >> cityName;
		path.push_back(cityName);
	}

	cin >> K;
	while (K--)
	{
		string transport, st, en;
		int cost;
		cin >> transport >> st >> en >> cost;
		cost *= 2;

		cost = min(costsOrigin[cities[st]][cities[en]], cost);
		costsOrigin[cities[st]][cities[en]] = costsOrigin[cities[en]][cities[st]] = cost;

		if (transports[transport] == 7 || transports[transport] == 8 || transports[transport] == 9)
		{
			cost = 0;
		}
		else if (transports[transport] == 5 || transports[transport] == 6)
		{
			cost /= 2;
		}

		cost = min(costsNailo[cities[st]][cities[en]], cost);
		costsNailo[cities[st]][cities[en]] = costsNailo[cities[en]][cities[st]] = cost;
	}

	floyd();

	int originTotal = 0;
	int nailoTotal = R * 2;
	for (int i = 0; i < path.size() - 1; ++i)
	{
		originTotal += costsOrigin[cities[path[i]]][cities[path[i + 1]]];
		nailoTotal += costsNailo[cities[path[i]]][cities[path[i + 1]]];
	}

	if (originTotal > nailoTotal)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
