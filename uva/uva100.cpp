#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int n1, n2, count = 1, max, temp;
	vector<int> num1, num2;
	vector<int> maxcl;

	while (cin >> n1 >> n2)
	{
		num1.push_back(n1);
		num2.push_back(n2);

		if (n1 > n2)
		{
			n1 = n1 + n2;
			n2 = n1 - n2;
			n1 = n1 - n2;
		}

		while ((temp = n1) <= n2)
		{
			while (temp != 1)
			{
				if (temp % 2 != 0)
					temp = 3 * temp + 1;
				else
					temp = temp / 2;
				count++;
			}

			if (count > max)
				max = count;

			count = 1;
			n1++;
		}
		maxcl.push_back(max);
		max = 0;
	}
	
	for (int i = 0; i < maxcl.size(); i++)
		cout << num1[i] << " " << num2[i] << " " << maxcl[i] << endl;

	return 0;
}
