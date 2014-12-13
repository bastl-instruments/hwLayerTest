// Interface defintion

class IHWLayer {
public:
	virtual char getButtonState();
};


// HW Layer definition based on interface

class myHWLayer : public IHWLayer {
public:
	virtual char getButtonState() {return buttonState;}
	char buttonState;
};


// Class that needs to access the hardware
class myClass {
public:
	myClass(IHWLayer* hw) {hardware=hw;}
	void run() {hardware->getButtonState();}
private:
	IHWLayer* hardware;
};




int main2()  {

	myHWLayer myHWInstance;
	myClass   myClassInstance(&myHWInstance);

	myClassInstance.run();

	return 0;
}



