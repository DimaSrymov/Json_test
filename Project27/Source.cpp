#include "Header.h"

int main()
{
    srand(time(0));

    ofstream out("e.txt");
    ofstream jout("data.json");

    int size;
    int n;

    cout << "Enter size of array: ";
    cin >> size;

 
    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
        v1[i] = rand() % 99 + 1;
    }


    cout << "Array V1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Enter n: ";
    cin >> n;

	// Summing every n numbers and outputting the results to a file
    out << "Summed numbers:" << endl;
    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i + j < v1.size()) {
                sum += v1[i + j];
            }
        }
        out << sum << endl;
    }
    cout << endl;
	// Sorting the array in ascending order and calculating the sum of its elements
    AscSort(v1);
    cout << "Sorted array V1 with ASC: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "Sum of elements with ASC: " << SumElements(v1);
    int sum2 = SumElements(v1);
    cout << endl;
    cout << endl;

	// Sorting the array in descending order and calculating the sum of its elements
    DescSort(v1);
    cout << "Sorted array V1 with DESC: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "Sum of elements (DESC): " << SumElements(v1);
    cout << endl;
    cout << endl;

	// Removing duplicates from the array and calculating the sum of unique elements
    vector<int> copyV1 = v1;
    RemoveDuplicates(v1, v2);


    int sum3 = SumElements(v2);
    cout << endl;


  
    cout << "Difference of sums S3 - S2: " << sum3 - sum2 << endl;

 
    int sizeV2 = v2.size();
    int duplicatesCount = size - sizeV2;

    
    cout << "Difference of arrays |V1 - V2|: ";
    PrintDifference(copyV1, v2);
    cout << endl;

	// Outputting results in JSON format
    JsonOut(jout, sum2, sum3, duplicatesCount, v1, v2);

    
    out.close();
    jout.close();
}