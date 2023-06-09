#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class PERSON {
private:
	string name;
	float age;
public:
	void Read() { cin >> name >> age; }
	void Print() { cout << name << ' ' << age << endl; }
	friend bool fun_cmp(const class PERSON&, const class PERSON&);
	friend class PERSONS;	// may have an access to the private fields
};

bool fun_cmp(const class PERSON& p, const class PERSON& q)
{
	if (p.name == q.name) return (p.age < q.age);
	else return (p.name < q.name);
}

class PERSONS {
private:
	class PERSON* PA; // all persons
	class PERSON* NA; // representants of "persons" with avarege age only
	int size_pa;	// size of PA and NA
	void lines() { int i; string line; for (i=0;  getline(cin, line), !line.empty(); i++); cin.clear(); cin.seekg(0); size_pa = i; } // count non-empty lines
	void SetSize(int s) { size_pa = s; }
public:
	int GetSize() { return size_pa; }
	float GetAge(int i) { return PA[i].age; }
	void SetAgeNA(int i, float age) { NA[i].age = age; }
	void Sort() { sort(PA,PA+size_pa,fun_cmp); }
	bool CmpName(int i, int j) { return (PA[i].name==PA[j].name); }
	void Copy(int i, int j) { NA[i] = PA[j]; }
	void Print(int size) const { cout <<setprecision(2)<<fixed; for(int i=0; i < size; i++) NA[i].Print(); }
	void Read() {	lines(); PA = new class PERSON[size_pa]; for(int i=0; i < size_pa; i++) PA[i].Read(); NA = new class PERSON[size_pa]; }
};

int Calculate(class PERSONS& ps)
// begin: part 1, You are allowed to change the code ONLY between the brackets {} below
{
    
    int i = 0, j;
    int l = 0;
    ps.Sort();
    
    int counts[ps.GetSize()] = {0};
    int max_count = 0;
    for (i = 0; i < ps.GetSize(); i++) {
        counts[i] = 1;
        j = i + 1;
        while (j < ps.GetSize() && ps.CmpName(i, j)) {
            counts[i]++;
            j++;
        }
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
        i = j - 1;
    }

    for (i = 0; i < ps.GetSize(); i++) {
        if (counts[i] == max_count) {
            j = i + 1;
            float sum_ages = ps.GetAge(i);
            int count = 1;
            while (j < ps.GetSize() && ps.CmpName(i, j)) {
                sum_ages += ps.GetAge(j);
                count++;
                j++;
            }
            float avg_age = sum_ages / count;
            ps.Copy(l, i);
            ps.SetAgeNA(l, avg_age);
            l++;
            i = j - 1;
        }
    }

    return l;
}
// end: part 1

int main()
{
	PERSONS A;
	int size;

	A.Read();

	size = Calculate(A);

	A.Print(size);

	return 0;
}