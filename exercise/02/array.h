// do not use standard container as member or base class
class array
{
	double* p;
	int n;
public:
	array() : n(0), p(nullptr) {};
	array(int size, double value);
	array(const array& other);
	array(array&& other) noexcept;
	array& operator=(array other);
	array& operator=(array&& other);
	~array();

	int size() const;
	double at(int index) const;
};
