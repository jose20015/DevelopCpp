#include <iostream>
#include <vector>

using namespace std;

class MyNumber
{
public:
    MyNumber(const initializer_list<int> &v) {
        for (auto itm : v) {
            mVec.push_back(itm);
        }
    }

    void print() {
	for (auto itm : mVec) {
	    cout << itm << " ";
	}
    }
private:
    vector<int> mVec;
};

int main()
{
    MyNumber m = { 1, 2, 3, 4 };
    m.print();  // 1 2 3 4
    cout<<endl;

    return 0;
}