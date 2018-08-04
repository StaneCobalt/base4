class ConvertBase {
	private:
		unsigned base;
	public:
		ConvertBase();
		ConvertBase(unsigned base);
		unsigned getBase() const;
		void setBase(unsigned base);
		void toNewBase(unsigned input);
		char getLetter(unsigned n);
};
