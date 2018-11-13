// do not use standard container as member or base class
class array
{
	double* p;
	int n;
public:
	array();
	array(int size, double value);
	int size() const;
	double at(int index) const;
};
