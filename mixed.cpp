#include <inttypes.h>


// needed for friend access to hw modules
class HWLayerBase {
};
class HWModuleBase {
friend class HWLayerBase;
};


// one hardware module

class HWButtons : HWModuleBase {
public:
	HWButtons(uint8_t number) {
		states = new uint8_t [number/8];
	}
	~HWButtons() {
		delete states;
	}
	bool getButtonState(uint8_t number) {
		return states[number/8] & (1<<number%8);
	}
	//void readButtonStates() { // this would have to be written individually for every hardware structure --> cant be implemented here
	//}
protected:
	uint8_t* states;
};


// the whole hw layer consists of different modules

class myHWLayer : HWLayerBase {
public:
	myHWLayer() {
		buttons = new HWButtons(10);
	}
	~myHWLayer() {
		delete buttons;
	}

	// modules
	HWButtons* buttons;
	//....

	void update() {
		//here goes the specific stuff for reading and writing to hardware
		uint8_t buttonBits ;//= PORTD; // easy example..
		buttons->states[0] = buttonBits; // we have to push the stuff there
	}
private:
};

myHWLayer hw;




