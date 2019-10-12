#include <string>
#include <vector>
#include <map>
using namespace std;

multimap < int, string > sorted_map;

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	for (int i = 0; i < n; i++) {
		sorted_map.insert(make_pair(odo[i], plates[i]));
	}

	multimap < int, string > ::iterator iter;
	pair< map < int, string > ::iterator, map < int, string > ::iterator > iter_pair;
	int Min;
	string Temp;
	auto it = sorted_map.begin();

	for (int i = 0; i < k; i++) {
		it = sorted_map.begin();
		Min = it->first;
		Temp = it->second;
		iter_pair = sorted_map.equal_range(Min);

		if (sorted_map.count(Min) == 1) {
			sorted_map.erase(it);
		}
		else {
			for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
				if (Temp.compare(iter->second) > 0)
					Temp = iter->second;
			}

			for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
				if (Temp.compare(iter->second) == 0) {
					sorted_map.erase(iter);
					break;
				}
			}
		}
		Min += drives[i];
		sorted_map.insert(pair < int, string >(Min, Temp));
	}

	it = sorted_map.begin();
	Min = it->first;
	Temp = it->second;
	iter_pair = sorted_map.equal_range(Min);

	if (sorted_map.count(Min) == 1) {
		iter = sorted_map.find(Min);
		return iter->second;
	}
	else {
		for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
			if (Temp.compare(iter->second) > 0)
				Temp = iter->second;
		}

		for (iter = iter_pair.first; iter != iter_pair.second; ++iter) {
			if (Temp.compare(iter->second) == 0) {
				return iter->second;
			}
		}
	}

}