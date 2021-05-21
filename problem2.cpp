#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility> 

using namespace std;





struct Line {
  string line;
  operator string() const { 
    return line;
  }

};

istream& operator>>(istream& lhs, Line& rhs) {
    getline(lhs, rhs.line); 
    return lhs;
}

string insert(){

  return " hallo";
}
//myFold template function

template<typename it>
int myFold(it begin, it end){
  if(begin == end) return *begin;
  else return *begin + myFold<it>(++begin, end);
};



// template <typename InputIt, typename OutputIt, typename UnaryOp, typename predic>
// OutputIt myTransform (InputIt first, InputIt last, OutputIt result, UnaryOp op, predic func){

// 	while(first != last){
//       *result = op(*first);

// 	  ++result; ++first;
// 	}

// 	return result;
// }

//the case where the predicate is always true

template <typename InputIt,typename OutputIt,typename UnaryOp>
OutputIt myTransform (InputIt first, InputIt last, OutputIt result, UnaryOp op)
{ 
  while (first != last) {
    result=op(*first); 
    ++result; ++first;
  }
  return result;
}


map<int, string>::iterator operation(string str){
    map<int, string> mymap;
		int first = stoi(str.substr(0, 5));
		string second = str.substr(7, 12);
		pair<int, string> p = make_pair(first, second);
    mymap.insert(mymap.begin(),p);
		return mymap.begin();
	}


int main(){

  map<int, string> m;
	ifstream ifs("phonebook.txt");
	set<string> b { istream_iterator<Line>{ifs}, istream_iterator<Line>{}};
  

 map<int, string>::iterator it;

	it = myTransform(b.begin(),b.end(),m.begin(), operation);

 
  pair<int, string> p;
  p.first=2;
  p.second = "two";
 
 cout<<m.begin()->first;

	return 0; 
}