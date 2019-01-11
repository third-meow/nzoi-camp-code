#include<bits/stdc++.h>
using namespace std;

void print_vec(vector<int> vec) {
	int end_ele = vec.back();
	vec.pop_back();
	for(auto e : vec)
		cout << e << " ";
	cout << end_ele << endl;
}

//uses selection sort to sort list of positive ints
void selc_sort(vector<int>& vec) {
	for(int i = vec.size(); i > 0; --i) {
		//find max
		int cmax = -1;
		int cmax_idx = -1;
		for(int j = 0; j < (vec.size() - i); ++j) {
			if (vec[j] > cmax){
				cmax = vec[j];
				cmax_idx = j;
			}
		}
		//swap end and max
		vec[cmax_idx] = vec[i];
		vec[i] = cmax;

	}
}

//uses quicksort to sort list of positive ints
void quicksort(vector<int>& vec) {
	if(vec.size() == 1)
		return;
	//select pivot point
	int pivot = vec[vec.size()/2];

	/*split vec into two sub vectors
			high = all elements higher than pivot
			low = all elements smaller than or equal to pivot
		note: high and low are not same size
	*/
	vector<int> low, high;
	for(auto e : vec)
		if(e > pivot)
			high.push_back(e);
		else 
			low.push_back(e);

	//sort sub vectors
	quicksort(high);
	quicksort(low);

	//set vec to low
	vec = low;
	//append high to vec
	vec.insert(vec.end(), high.begin(), high.end());

}


int main() {
	
	vector<int> a = {4,3,2,1};
	print_vec(a);
	quicksort(a);
	print_vec(a);



	return 0;
}

