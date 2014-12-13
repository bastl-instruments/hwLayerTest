// Interface defintion

class IButtonHW {
public:
	virtual bool isButtonPressed();
};

class ILEDHW {
public:
	virtual void setLEDStatus(ILEDHW::LEDStatus status);
};

class ILEDHWv2 : public ILEDHW {
public:
	virtual void setLEDStatus(ILEDHW::LEDStatus status);
	virtual void playDiscotheque();
};

// HW Layer definition based on interface

class OldDeviceHWLayer : public ILEDHW, public IButtonHW {
public:
	virtual bool isButtonPressed() {return isButtonPressed_;}
	virtual void setLEDStatus(ILEDHW::LEDStatus status) {status_ = status};
	bool isButtonPressed_;
	ILEDHW::LEDStatus status_;
};

// HW Layer definition based on interface

class NewDeviceHWLayer : public ILEDHWv2, public IButtonHW {
public:
	virtual bool isButtonPressed() {return isButtonPressed_;}
	virtual void setLEDStatus(ILEDHW::LEDStatus status) {status_ = status};
	virtual void playDiscotheque() {raise(SIGSEGV)};
	bool isButtonPressed_;
	ILEDHW::LEDStatus status_;
};


// Class that needs to access LEDs
class myClass {
public:
	myClass(IButtonHW* hw) {hardware = hw;}
	void run() {hardware->isButtonPressed();}
private:
	IButtonHW* hardware;
};


int main()  {

	OldDeviceHWLayer myHWInstance;
	myClass   myClassInstance(&myHWInstance);

	myClassInstance.run();

	return 0;
}



