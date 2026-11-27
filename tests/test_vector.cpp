#include <gtest/gtest.h>
#include "../src/vector.h"

using namespace mds;

TEST(Vector, AllFunctions) {
	vector<int> v1;
	EXPECT_EQ(v1.size(), 0) << "vector() err";
	v1.push_back(5);
	EXPECT_EQ(v1.size(), 1) << "push_back() err";
	EXPECT_EQ(v1[0], 5) << "push_back() err";
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
		EXPECT_EQ(v1[i + 1], i) << "push_back() err";
	}
	EXPECT_EQ(v1.size(), 11) << "size() err";
	v1.pop_back();
	EXPECT_EQ(v1[9], 8) << "pop_back() err";
	EXPECT_EQ(v1.size(), 10) << "pop_back() err";

	vector<int> v2(v1);
	EXPECT_EQ(v1.size(), v2.size()) << "vector(const&) err";
	EXPECT_EQ(v1[0], v2[0]) << "vector(const&) err";
	EXPECT_EQ(v1[9], v2[9]) << "vector(const&) err";

	v1.clear();
	EXPECT_EQ(v1.size(), 0) << "clear() err";
	v1 = v2;
	EXPECT_EQ(v1.size(), 10) << "=(const&) err";
	vector<int> v3(std::move(v2));
	EXPECT_EQ(v3.size(), 10) << "vector(&&) err";
	EXPECT_EQ(v2.size(), 0) << "vector(&&) err";
	v2 = std::move(v1);
	EXPECT_EQ(v2.size(), 10) << "=(&&) err";
	EXPECT_EQ(v1.size(), 0) << "=(&&) err";
}

TEST(Vector, ConstructorsAndOperators) {
	vector<int> v1;

	EXPECT_EQ(v1.size(), 0) << "Default constructor err";

	vector<int> v2(v1);

	EXPECT_EQ(v2.size(), 0) << "vector(const vector& other) empty vector err";

	v2.push_back(1);

	EXPECT_EQ(v1.size(), 0) << "vector(const vector& other) empty vector err";

	vector<int> v3(5);
	EXPECT_EQ(v3.size(), 0) << "vector(size_t s) err";

	v3.push_back(1);
	EXPECT_EQ(v3.size(), 1) << "vector(size_t s) err";
	EXPECT_EQ(v3[0], 1) << "vector(size_t s) err";

	v1.push_back(1);
	v1.push_back(2);
	v1 = v3;
	
	EXPECT_EQ(v1.size(), 1) << "operator =(const vector& right) err";

	vector<int> v4(std::move(v1));

	EXPECT_EQ(v1.size(), 0) << "operator =(const vector& right) err";
	EXPECT_EQ(v4.size(), 1) << "operator =(const vector& right) err";

	v4.push_back(2);

	v1 = std::move(v4);

	EXPECT_EQ(v4.size(), 0) << "operator =(const vector& right) err";
	EXPECT_EQ(v1.size(), 2) << "operator =(const vector& right) err";
}

TEST(Vector, Accessors_OnEmptyVector) {
	vector<int> v;

	EXPECT_EQ(v.begin(), v.end()) << "logic of begin() and end() err";
	EXPECT_EQ(v.size(), 0) << "size() err";
	//front и back - неопределенное поведение, поэтому без теста
	EXPECT_EQ(v.empty(), true) << "empty() err";
}

TEST(Vector, Accessors_OnNonemptyVector) {
	vector<int> v;

	v.push_back(1);

	EXPECT_EQ(v.size(), 1) << "size() err";
	EXPECT_EQ(v.front(), 1) << "front() err";
	EXPECT_EQ(v.back(), 1) << "back() err";
	EXPECT_EQ(v.empty(), false) << "empty() err";
	EXPECT_EQ(v[0], 1) << "operator[] err";
	
	v.push_back(2);

	EXPECT_EQ(v.size(), 2) << "size() err";
	EXPECT_EQ(v.front(), 1) << "front() err";
	EXPECT_EQ(v.back(), 2) << "back() err";
	EXPECT_EQ(v[1], 2) << "operator[] err";
}

TEST(Vector, PushBack) {
	vector<int> v;
	v.push_back(1);

	EXPECT_EQ(v.size(), 1) << "PushBack on Empty vector err";
	EXPECT_EQ(v[0], 1) << "PushBack on not Empty vector err";

	v.push_back(2);

	EXPECT_EQ(v.size(), 2) << "PushBack on Empty vector err";
	EXPECT_EQ(v[1], 2) << "PushBack on not Empty vector err";

	v.clear();
	v.push_back(3);

	EXPECT_EQ(v.size(), 1) << "PushBack on Empty vector err";
	EXPECT_EQ(v[0], 3) << "PushBack after clear vector err";
}

TEST(Vector, Clear) {
	vector<int> v;
	v.clear();
	
	EXPECT_EQ(v.size(), 0) << "clear() on empty vector err";

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.clear();

	EXPECT_EQ(v.size(), 0) << "clear() on nonempty vector err";

	v.push_back(1);

	EXPECT_EQ(v.size(), 1) << "clear() on nonempty vector err";
}