#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

// sort the array in ascending order
void AscSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// sort the array in descending order
void DescSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] < v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// sum of elements in the array
int SumElements(vector<int>& v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	return sum;
}

// Function to remove duplicates from the array and store unique elements in another array

void RemoveDuplicates(vector<int>& v, vector<int>& unique)
{
	for (int i = 0; i < v.size(); i++)
	{
		bool isDuplicate = false;
		for (int j = 0; j < unique.size(); j++)
		{
			if (v[i] == unique[j])
			{
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate)
		{
			unique.push_back(v[i]);
		}
	}
}

// Function to print the difference between two arrays (elements that are duplicates in the first array)
void PrintDifference(vector<int>& v1, vector<int>& v2)
{
	for (int i = 0; i < v1.size(); i++)
	{
		int count = 0;

		for (int j = 0; j < v1.size(); j++)
		{
			if (v1[i] == v1[j])
				count++;
		}

		if (count > 1)
			cout << v1[i] << " ";
	}

	cout << endl;
}

// Function to output results in JSON format
void JsonOut(ofstream& jout, int sum2, int sum3, int duplicatesCount, vector<int>& v1, vector<int>& v2)
{
	nlohmann::json j;

	j["S2"] = sum2;
	j["S3"] = sum3;
	j["S3 - S2"] = sum3 - sum2;
	j["duplicatesCount"] = duplicatesCount;
	j["V1"] = v1;
	j["V2"] = v2;

	jout << j.dump(4);
}