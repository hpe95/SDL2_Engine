#ifndef __LAYER__
#define __LAYER__

class Layer{
public:
	virtual void update() = 0;
	virtual void render() = 0;

protected:
	//virtual ~Layer(){}
};

#endif