// Interface defintion

// --> not really there. It's defined implicitly. (=If it compiles its correct)


// HW Layer definition NOT based on interface

class myHWLayer {
public:
	char getButtonState() {return buttonState;}
	char buttonState;
};


// Class that needs to access the hardware, templated over hardware layer type
template <typename HWTYPE>
class myClass {
public:
	myClass(HWTYPE* hw) {hardware=hw;}
	void run() {hardware->getButtonState();}
private:
	HWTYPE* hardware;
};




int main()  {

	myHWLayer myHWInstance;
	myClass<myHWLayer> myClassInstance(&myHWInstance); // we compile myClass and replace HWTYPE by myHWLayer
													   // you could place anything here instead of myHWLayer, as long as it contains a method getButtonState()
													   // this is what is called implicit definition

	myClassInstance.run();
}



